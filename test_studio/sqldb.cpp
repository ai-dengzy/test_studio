#include "sqldb.h"
#include <QList> 
bool outPutTableInfo(QString tabNmae)
{
	QSqlQuery query;
	QString strTableNmae = tabNmae;
	QString str = "PRAGMA table_info(" + strTableNmae + ")";

	query.prepare(str);
	if (query.exec())
	{
		while (query.next())
		{
			qDebug() << QString(QString::fromLocal8Bit("�ֶ���:%1     �ֶ���:%2     �ֶ�����:%3")).arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
		}
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
	return true;
}
bool outputDatabaseInfo(QSqlDatabase database)
{
	if (database.open())
	{
		qDebug() << "Open database success!";
		QStringList tables = database.tables();  //��ȡ���ݿ��еı�
		qDebug() << QString::fromLocal8Bit("��ĸ����� %1").arg(tables.count()); //��ӡ��ĸ���
		QStringListIterator itr(tables);
		while (itr.hasNext())
		{
			QString tableNmae = itr.next().toLocal8Bit();
			qDebug() << QString::fromLocal8Bit("������") + tableNmae;

			outPutTableInfo(tableNmae);
		}
	}
	else
	{
		qDebug() << "Open database failed!";
		return false;
	}
	return true;
}


sqldb::sqldb()
{
	qDebug() << "Date:";
	//db1 = QSqlDatabase::addDatabase( "QSQLITE","dzy");
	//if (QSqlDatabase::contains("dzy")) {
	//	db1 = QSqlDatabase::database("dzy");
	//}
	//else {
	//	db1 = QSqlDatabase::addDatabase("QSQLITE", "dzy");
	//}
	db1 = QSqlDatabase::addDatabase("QSQLITE");
	db1.setDatabaseName("database.db");
	if (!db1.open()) {
		qDebug() << db1.lastError();
		qFatal("failed to connect.");
		db1.close();
	}
	else {
		qDebug() <<"open success...";
		query = new QSqlQuery(db1);
		QStringList tables = db1.tables();  //��ȡ���ݿ��еı�
		int tables_nums = tables.count();
		//query->exec("SELECT * FROM sample"); 
		//query->exec("drop table sample"); 
		//query->exec("drop table measure"); 
	    if (tables_nums<1) {
			query->exec("create table sample (id int primary key not null, "
				"num varchar(20),"
				"name varchar(20),"
				"batch varchar(20),"
				"material varchar(20),"
				"temperature varchar(20),"
				"tester varchar(20),"
				"date varchar(20),"
				"remarks varchar(20),"
				"meature_method varchar(20),"
				"magnetization_model varchar(20),"
				"sample_shape varchar(20),"
				"sample_specification varchar(20),"
				"set_magnetization varchar(20),"
				"measure_times varchar(20),"
				"delay varchar(20),"
				"estimate_1 varchar(20),"
				"estimate_2 varchar(20),"
				"limit_top varchar(20),"
				"limit_bottom varchar(20))");

			query->exec("create table measure (id int primary key , "
				"num varchar(20),"
				"name varchar(20),"
				"batch varchar(20),"
				"material varchar(20),"
				"temperature varchar(20),"
				"tester varchar(20),"
				"date long,"
				"remarks varchar(20),"
				"meature_method varchar(20),"
				"magnetization_model varchar(20),"
				"sample_shape varchar(20),"
				"sample_specification varchar(20),"
				"set_magnetization varchar(20),"
				"measure_times varchar(20),"
				"delay varchar(20),"
				"estimate_1 varchar(20),"
				"estimate_2 varchar(20),"
				"limit_top varchar(20),"
				"limit_bottom varchar(20),"
				"Hc double,"
				"Hm double)");
		}
		outputDatabaseInfo(db1);
		outPutTableInfo("sample");
		outPutTableInfo("measure");
	}
}


void sqldb::saveSql(int id, QString num, QString name, QString batch,QString material, QString temperature, QString tester, QString date, QString remarks, QString measure_method, QString magnetization_model, QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay, QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom)
{
	QString strSqlText = "INSERT INTO sample (id,num,name,batch,material,temperature,tester,date,remarks,meature_method,magnetization_model,sample_shape,sample_specification,set_magnetization,measure_times,delay,estimate_1,estimate_2,limit_top,limit_bottom) \
                 VALUES (:id,:num, :name,:batch,:material,:temperature,:tester,:date,:remarks,:measure_method,:magnetization_model,:sample_shape,:sample_specification,:set_magnetization,:measure_times,:delay,:estimate_1,:estimate_2,:limit_top,:limit_bottom)";
	query->prepare(strSqlText);
	query->bindValue(":id", id);
	query->bindValue(":num", num);
	query->bindValue(":name", name);
	query->bindValue(":batch", batch);
	query->bindValue(":material", material);
	query->bindValue(":temperature", temperature);
	query->bindValue(":tester", tester);
	query->bindValue(":date", date);
	query->bindValue(":remarks", remarks);
	query->bindValue(":measure_method", measure_method);
	query->bindValue(":magnetization_model", magnetization_model);
	query->bindValue(":sample_shape", sample_shape);
	query->bindValue(":sample_specification", sample_specification);
	query->bindValue(":set_magnetization", set_magnetization);
	query->bindValue(":measure_times", measure_times);
	query->bindValue(":delay", delay);
	query->bindValue(":estimate_1", estimate_1);
	query->bindValue(":estimate_2", estimate_2);
	query->bindValue(":limit_top", limit_top);
	query->bindValue(":limit_bottom", limit_bottom);
	query->exec();
	bool flag = commitDB(*query);
	if (flag)
	{
		qDebug() << "save success";
		QMessageBox::about(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�ѱ���"));
		//showInfo();
	}
	else
	{
		qDebug() << db1.lastError();
		qFatal("failed to connect.");
		QMessageBox::about(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ʧ��"));
	}
}

void sqldb::updateSql(int id, QString num, QString name, QString batch, QString material, QString temperature, QString tester, QString date, QString remarks, QString measure_method, QString magnetization_model, QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay, QString estimate_1, QString estimate_2,QString limit_top, QString limit_bottom)
{
	QString strSqlText = "UPDATE sample SET num = :num ,name=:name,batch=:batch,material=:material,temperature=:temperature,tester=:tester,date=:date,remarks=:remarks,meature_method=:measure_method,magnetization_model=:magnetization_model,sample_shape=:sample_shape,sample_specification=:sample_specification,set_magnetization=:set_magnetization,measure_times=:measure_times,delay=:delay,estimate_1=:estimate_1,estimate_2=:estimate_2,limit_top=:limit_top,limit_bottom=:limit_bottom\
		WHERE id = :id";
	query->prepare(strSqlText);
	query->bindValue(":id", id);
	query->bindValue(":num", num);
	query->bindValue(":name", name);
	query->bindValue(":batch", batch);
	query->bindValue(":material", material);
	query->bindValue(":temperature", temperature);
	query->bindValue(":tester", tester);
	query->bindValue(":date", date);
	query->bindValue(":remarks", remarks);
	query->bindValue(":measure_method", measure_method);
	query->bindValue(":magnetization_model", magnetization_model);
	query->bindValue(":sample_shape", sample_shape);
	query->bindValue(":sample_specification", sample_specification);
	query->bindValue(":set_magnetization", set_magnetization);
	query->bindValue(":measure_times", measure_times);
	query->bindValue(":delay", delay);
	query->bindValue(":estimate_1", estimate_1);
	query->bindValue(":estimate_2", estimate_2);
	query->bindValue(":limit_top", limit_top);
	query->bindValue(":limit_bottom", limit_bottom);
	query->exec();
	bool flag = commitDB(*query);
	if (flag)
	{
		qDebug() << "save success";
		QMessageBox::about(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�ѱ���"));
		//showInfo();
	}
	else
	{
		qDebug() << db1.lastError();
		//qFatal("failed to connect.");
		QMessageBox::about(NULL, QString::fromLocal8Bit("ʧ��"), db1.lastError().text());
	}
}

void sqldb::saveTestSql(QString num, QString name, QString batch, QString material, QString temperature, QString tester, QString date, QString remarks, QString measure_method, QString magnetization_model, QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay, QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom, QString Hc, QString Hm)
{
	QString strSqlText = "INSERT INTO measure (num,name,batch,material,temperature,tester,date,remarks,meature_method,magnetization_model,sample_shape,sample_specification,set_magnetization,measure_times,delay,estimate_1,estimate_2,limit_top,limit_bottom,Hc,Hm) \
                 VALUES (:num, :name,:batch,:material,:temperature,:tester,:date,:remarks,:measure_method,:magnetization_model,:sample_shape,:sample_specification,:set_magnetization,:measure_times,:delay,:estimate_1,:estimate_2,:limit_top,:limit_bottom,:Hc,:Hm)";
	query->prepare(strSqlText);
	query->bindValue(":num", num);
	query->bindValue(":name", name);
	query->bindValue(":batch", batch);
	query->bindValue(":material", material);
	query->bindValue(":temperature", temperature);
	query->bindValue(":tester", tester);
	date.replace("-","");
	query->bindValue(":date", date);
	query->bindValue(":remarks", remarks);
	query->bindValue(":measure_method", measure_method);
	query->bindValue(":magnetization_model", magnetization_model);
	query->bindValue(":sample_shape", sample_shape);
	query->bindValue(":sample_specification", sample_specification);
	query->bindValue(":set_magnetization", set_magnetization);
	query->bindValue(":measure_times", measure_times);
	query->bindValue(":delay", delay);
	query->bindValue(":estimate_1", estimate_1);
	query->bindValue(":estimate_2", estimate_2);
	query->bindValue(":limit_top", limit_top);
	query->bindValue(":limit_bottom", limit_bottom);
	query->bindValue(":Hc", Hc);
	query->bindValue(":Hm", Hm);
	query->exec();
	//bool flag = commitDB(*query);
	//if (flag)
	//{
		qDebug() << "save test_data success";
		//�������ݱ�
		querySaveTestDate(ui);
	//}
	//else
	//{
		//qDebug() << db1.lastError();
		//qFatal("failed to connect.");
		//QMessageBox::about(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�������ݱ���ʧ��"));
	//}
}

void sqldb::showInfo(Ui::test_studioClass &ui)
{
	query->exec("SELECT * FROM sample");
	while (query->next()) {
		int table_index = query->value(0).toInt();
		//��������Ϣ���浽���ݿ���
		switch (table_index)
		{
		case 0:
			showData(ui.tableView_72, ui.tableView_73, ui.tableView_77, ui.tableView_76, ui.tableView_74, ui.tableView_71, ui.tableView_75);
			break;
		case 1:
			showData(ui.tableView_14, ui.tableView_13, ui.tableView_11, ui.tableView_10, ui.tableView_12, ui.tableView_9, ui.tableView_8);
			break;
		case 2:
			showData(ui.tableView_21, ui.tableView_20, ui.tableView_18, ui.tableView_17, ui.tableView_19, ui.tableView_16, ui.tableView_15);
			break;
		case 3:
			showData(ui.tableView_28, ui.tableView_27, ui.tableView_25, ui.tableView_24, ui.tableView_26, ui.tableView_23, ui.tableView_22);
			break;
		case 4:
			showData(ui.tableView_35, ui.tableView_34, ui.tableView_32, ui.tableView_31, ui.tableView_33, ui.tableView_30, ui.tableView_29);
			break;
		case 5:
			showData(ui.tableView_42, ui.tableView_41, ui.tableView_39, ui.tableView_38, ui.tableView_40, ui.tableView_37, ui.tableView_36);
			break;
		case 6:
			showData(ui.tableView_49, ui.tableView_48, ui.tableView_46, ui.tableView_45, ui.tableView_47, ui.tableView_44, ui.tableView_43);
			break;
		case 7:
			showData(ui.tableView_56, ui.tableView_55, ui.tableView_53, ui.tableView_52, ui.tableView_54, ui.tableView_51, ui.tableView_50);
			break;
		case 8:
			showData(ui.tableView_63, ui.tableView_62, ui.tableView_60, ui.tableView_59, ui.tableView_61, ui.tableView_58, ui.tableView_57);
			break;
		case 9:
			showData(ui.tableView_67, ui.tableView_68, ui.tableView_66, ui.tableView_69, ui.tableView_64, ui.tableView_65, ui.tableView_70);
			break;
		}
	}
}

void sqldb::showData(QTableView * table1, QTableView * table2, QTableView * table3, QTableView * table4, QTableView * table5, QTableView * table6, QTableView * table7)
{	//��š����ơ����Ρ�����				
	QAbstractItemModel *model1 = table1->model();
	QModelIndex code_index = model1->index(0, 1);
	QLineEdit *code_ = qobject_cast<QLineEdit *>(table1->indexWidget(code_index));
	code_->setText(query->value(1).toString());
	QModelIndex name_index = model1->index(1, 1);
	QLineEdit *name_ = qobject_cast<QLineEdit *>(table1->indexWidget(name_index));
	name_->setText(query->value(2).toString());
	QModelIndex pici_index = model1->index(2, 1);
	QLineEdit *pici = qobject_cast<QLineEdit *>(table1->indexWidget(pici_index));
	pici->setText(query->value(3).toString());
	QModelIndex material_index = model1->index(3, 1);
	QLineEdit *material_ = qobject_cast<QLineEdit *>(table1->indexWidget(material_index));
	material_->setText(query->value(4).toString());
	//�¶�
	QAbstractItemModel *model2 = table2->model();
	QModelIndex temperature_index = model2->index(0, 1);
	QLineEdit *temperature_ = qobject_cast<QLineEdit *>(table2->indexWidget(temperature_index));
	temperature_->setText(query->value(5).toString());
	//����Ա�����ڡ���ע
	QAbstractItemModel *model3 = table3->model();
	QModelIndex tester_index = model3->index(0, 1);
	QLineEdit *tester_ = qobject_cast<QLineEdit *>(table3->indexWidget(tester_index));
	tester_->setText(query->value(6).toString());
	QModelIndex date_index = model3->index(1, 1);
	QDateEdit *date_ = qobject_cast<QDateEdit *>(table3->indexWidget(date_index));
	QDateTime time = QDateTime::fromString(query->value(7).toString(),"yyyy-MM-dd");
	date_->setDateTime(time);
	QModelIndex remarker_index = model3->index(2, 1);
	QLineEdit *remarker = qobject_cast<QLineEdit *>(table3->indexWidget(remarker_index));
	remarker->setText(query->value(8).toString());
	//����ģʽ���Ż�ģʽ����Ʒ��״����Ʒ���
	QAbstractItemModel *model4 = table4->model();
	QModelIndex measure_method_index = model4->index(0, 1);
	QComboBox *cb_measure_method = qobject_cast<QComboBox *>(table4->indexWidget(measure_method_index));  
	std::string measure_model_str = query->value(9).toString().toStdString();
	if (measure_model_str ==QString::fromLocal8Bit("�ֶ�ģʽ").toStdString())
	{
		cb_measure_method->setCurrentIndex(0);
	}
	else if (measure_model_str == QString::fromLocal8Bit("����ģʽ").toStdString()) {
		cb_measure_method->setCurrentIndex(1);
	}
	else if (measure_model_str == QString::fromLocal8Bit("����ģʽ").toStdString())
	{
		cb_measure_method->setCurrentIndex(2);
	}
	QModelIndex magnetization_model_index = model4->index(1, 1);
	QComboBox *cb_magnetization_model = qobject_cast<QComboBox *>(table4->indexWidget(magnetization_model_index));
	std::string magnetization_model_str = query->value(10).toString().toStdString();
	if (magnetization_model_str == QString::fromLocal8Bit("����ģʽ").toStdString())
	{
		cb_magnetization_model->setCurrentIndex(0);
	}
	else if (magnetization_model_str == QString::fromLocal8Bit("Ԥ�Ż�ģʽ").toStdString()) {
		cb_magnetization_model->setCurrentIndex(1);
	}
	QModelIndex sample_shape_index = model4->index(2, 1);
	QComboBox *cb_sample_shape = qobject_cast<QComboBox *>(table4->indexWidget(sample_shape_index));
	std::string sample_shape_str = query->value(11).toString().toStdString();
	if (sample_shape_str == QString::fromLocal8Bit("��״").toStdString())
	{
		cb_sample_shape->setCurrentIndex(0);
	}
	else if (sample_shape_str == QString::fromLocal8Bit("����").toStdString()) {
		cb_sample_shape->setCurrentIndex(1);
	}
	QModelIndex sample_specification_index = model4->index(3, 1);
	QLineEdit *cb_sample_specification = qobject_cast<QLineEdit *>(table4->indexWidget(sample_specification_index));
	cb_sample_specification->setText(query->value(12).toString());
	//�趨�ų���������������ʱ
	QAbstractItemModel *model5 = table5->model();
	QModelIndex set_magnetization_index = model5->index(0, 1);
	QComboBox *cb_set_magnetization = qobject_cast<QComboBox *>(table5->indexWidget(set_magnetization_index));  
    cb_set_magnetization->setCurrentText(query->value(13).toString());
	QModelIndex measure_times_index = model5->index(1, 1);
	QComboBox *cb_measure_times = qobject_cast<QComboBox *>(table5->indexWidget(measure_times_index));  
	cb_measure_times->setCurrentText(query->value(14).toString());
	QModelIndex delay_index = model5->index(2, 1);
	QLineEdit *cb_delay = qobject_cast<QLineEdit *>(table5->indexWidget(delay_index));
	cb_delay->setText(query->value(15).toString());
	//Ԥ����Χ
	QAbstractItemModel *model6 = table6->model();
	QModelIndex estimate_index_1 = model6->index(0, 1);
	QLineEdit *estimate_1_ = qobject_cast<QLineEdit *>(table6->indexWidget(estimate_index_1));
	estimate_1_->setText(query->value(16).toString());
	QModelIndex estimate_index_2 = model6->index(0, 3);
	QLineEdit *estimate_2_ = qobject_cast<QLineEdit *>(table6->indexWidget(estimate_index_2));
	estimate_2_->setText(query->value(17).toString());
	//����ֵ������ֵ
	QAbstractItemModel *model7 = table7->model();
	QModelIndex top_limit_index = model7->index(0, 1);
	QLineEdit *top_limit = qobject_cast<QLineEdit *>(table7->indexWidget(top_limit_index));
	top_limit->setText(query->value(18).toString());
	QModelIndex bottom_limit_index = model7->index(0, 3);
	QLineEdit *bottom_limit = qobject_cast<QLineEdit *>(table7->indexWidget(bottom_limit_index));
	bottom_limit->setText(query->value(19).toString());
	qDebug() << query->value(0).toInt() << query->value(1).toString() << query->value(2).toString() << query->value(3).toString()
		<< query->value(4).toString() << query->value(5).toString() << query->value(6).toString() << query->value(7).toString() << query->value(8).toString()
		<< query->value(9).toString() << query->value(10).toString() << query->value(11).toString() << query->value(12).toString() << query->value(13).toString()
		<< query->value(14).toString() << query->value(15).toString() << query->value(16).toString() << query->value(17).toString() << query->value(18).toString() << query->value(19).toString();
}

bool sqldb::queryId(int table_index)
{
	bool flag = false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ;
	//��ѯ��¼
	QString strSqlText("select * from sample  \
                       WHERE id = :id");
	query->prepare(strSqlText);
	query->bindValue(":id", table_index);
	query->exec();
	//commitDB(*query);
	qDebug() << "find id success";
	QSqlRecord rec = query->record();
	if (query->next())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void sqldb::querySaveTestDate(Ui::test_studioClass &ui_)
{
	ui = ui_;
	//���ñ���ͷ
	QStringList list;
	list << QString::fromLocal8Bit("���") << QString::fromLocal8Bit("����") << "H(A/m)" << "Hc(A/m)"
		<< "Hm(A/m)" << QString::fromLocal8Bit("�¶ȡ�") << QString::fromLocal8Bit("����Ա")
		<< QString::fromLocal8Bit("����") << QString::fromLocal8Bit("��ע");
	ui.tableWidget->setColumnCount(list.size());
	//����ˮƽͷ
	ui.tableWidget->setHorizontalHeaderLabels(list);
	//��ȡ�������...�˷�����̫�ã����Ż�
	QList<QList<QString>> FList;
	query->exec("SELECT num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks FROM measure");
	QSqlQueryModel *queryModel = new QSqlQueryModel();
	queryModel->setQuery(*query);
	int nRecordCount = queryModel->rowCount();
	//��������
	ui.tableWidget->setRowCount(nRecordCount);

	query->exec("SELECT num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks FROM measure");
	QSqlRecord rec = query->record();
	while (query->next())
	{	
		QList<QString> qlist;
		for (int i = 0; i < rec.count(); i++) {
			//׼������
			if (i == 7)//��ʱ����Ӹ�ʽ
			{
				QString date_str = query->value(i).toString();
				date_str.insert(4, "-");
				date_str.insert(7, "-");
				qlist << date_str;
			}
			else {
				qlist << query->value(i).toString();
			}
		}
		FList.append(qlist);
	}
	bool flag = commitDB(*query);
	int i,j = 0;
	if (flag)
	{
		qDebug() << "open test data success";
		for (i = 0; i < FList.size(); i++)
		{
			QList<QString> qlist_item = FList.at(i);
			qDebug() << qlist_item;
			for (j = 0; j < qlist_item.size(); j++)
			{
				ui.tableWidget->setItem(i, j, new QTableWidgetItem(qlist_item[j]));
			}
		}
		//ui.tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
		ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
		//������ʾ��ײ�
		ui.tableWidget->scrollToBottom();
	}
	else
	{
		qDebug() << db1.lastError();
		//qFatal("failed to connect.");
		QMessageBox::about(NULL, QString::fromLocal8Bit("ʧ��"), db1.lastError().text());
	}
}

void sqldb::querySaveTestDate(Ui::HistoryQuery &ui_)
{
	history_query_ui = ui_;
	//���ñ���ͷ
	QStringList list;
	list << QString::fromLocal8Bit("���") << QString::fromLocal8Bit("����") << "H(A/m)" << "Hc(A/m)"
		<< "Hm(A/m)" << QString::fromLocal8Bit("�¶ȡ�") << QString::fromLocal8Bit("����Ա")
		<< QString::fromLocal8Bit("����") << QString::fromLocal8Bit("��ע");
	history_query_ui.tableWidget->setColumnCount(list.size());
	//����ˮƽͷ
	history_query_ui.tableWidget->setHorizontalHeaderLabels(list);
	//��ȡ�������...�˷�����̫�ã����Ż�
	query->exec("SELECT * FROM measure");
	QSqlQueryModel *queryModel = new QSqlQueryModel();
	queryModel->setQuery(*query);
	int nRecordCount = queryModel->rowCount();
	qDebug() << "nRecordCount::::" << nRecordCount;
	//��������
	history_query_ui.tableWidget->setRowCount(nRecordCount);
	QList<QList<QString>> FList;
	query->exec("SELECT num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks FROM measure");
	QSqlRecord rec = query->record();
	while (query->next())
	{
		QList<QString> qlist;
		for (int i = 0; i < rec.count(); i++) {
			//׼������
			if (i==7)//��ʱ����Ӹ�ʽ
			{
				QString date_str = query->value(i).toString();
				date_str.insert(4,"-");
				date_str.insert(7,"-");
				qlist << date_str;
			}
			else {
				qlist << query->value(i).toString();
			}
		}
		FList.append(qlist);
	}
	bool flag = commitDB(*query);
	int i, j = 0;
	if (flag)
	{
		qDebug() << "querySaveTestDate:open test data success";
		for (i = 0; i < FList.size(); i++)
		{
			QList<QString> qlist_item = FList.at(i);
			//qDebug() << qlist_item;
			for (j = 0; j < qlist_item.size(); j++)
			{
				if (j==2)
				{
					qlist_H << qlist_item[j].toLong();
				}
				else if (j==3)
				{
					qlist_Hc << qlist_item[j].toLong();
				}
				else if (j==4)
				{
					qlist_Hm << qlist_item[j].toLong();
				}
				history_query_ui.tableWidget->setItem(i, j, new QTableWidgetItem(qlist_item[j]));
			}
		}
		//history_query_ui.tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
		history_query_ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
		//������ʾ��ײ�
		//history_query_ui.tableWidget->scrollToBottom();
	}
	else
	{
		qDebug() << db1.lastError();
		//qFatal("failed to connect.");
		QMessageBox::about(NULL, QString::fromLocal8Bit("ʧ��"), db1.lastError().text());
	}
}

void sqldb::showStandard_Avg(QTableView *table6)
{
	QStandardItemModel *model4 = new QStandardItemModel();
	table6->horizontalHeader()->hide();
	//table6->verticalHeader()->hide();
	table6->setModel(model4);
	table6->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
	table6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	model4->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("��׼�"))); model4->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	model4->setItem(1, 0, new QStandardItem(QString::fromLocal8Bit("ƽ��ֵ��"))); model4->item(1, 0)->setTextAlignment(Qt::AlignCenter);
	

	long age_h = getAvgFromData(qlist_H);
	long age_hc = getAvgFromData(qlist_Hc);
	long age_hm = getAvgFromData(qlist_Hm); 
	model4->setItem(0, 2, new QStandardItem(QString::number(getVarianceFromData(qlist_H,age_h)))); 
	model4->setItem(1, 2, new QStandardItem(QString::number(age_h, 10))); 
	model4->setItem(0, 3, new QStandardItem(QString::number(getVarianceFromData(qlist_Hc, age_hc)))); 
	model4->setItem(1, 3, new QStandardItem(QString::number(age_hc, 10)));
	model4->setItem(0, 4, new QStandardItem(QString::number(getVarianceFromData(qlist_Hm, age_hm))));
	model4->setItem(1, 4, new QStandardItem(QString::number(age_hm, 10)));

	model4->setColumnCount(9);
	ReadOnlyDelegate* readOnlyDelegate4 = new ReadOnlyDelegate();
	table6->setItemDelegateForColumn(0, readOnlyDelegate4); //����ĳ��ֻ��
	table6->setItemDelegateForColumn(2, readOnlyDelegate4); //����ĳ��ֻ��
	table6->setItemDelegateForColumn(4, readOnlyDelegate4); //����ĳ��ֻ��
	/*int width4 = table6->width();
	qDebug() << "width4::" << width4;
	table6->setColumnWidth(0, (width4 / 6) * 2);
	table6->setColumnWidth(1, (width4 / 6));
	table6->setColumnWidth(2, (width4 / 6));
	table6->setColumnWidth(3, (width4 / 6) - 2);
	table6->setColumnWidth(4, (width4 / 6) + 5);*/

	model4->item(0, 2)->setTextAlignment(Qt::AlignCenter);
	model4->item(1, 2)->setTextAlignment(Qt::AlignCenter);
	model4->item(0, 3)->setTextAlignment(Qt::AlignCenter);
	model4->item(1, 3)->setTextAlignment(Qt::AlignCenter);
	model4->item(0, 4)->setTextAlignment(Qt::AlignCenter);
	model4->item(1, 4)->setTextAlignment(Qt::AlignCenter);
}

void sqldb::queryCondition(QTableWidget * qtw, QString start_time, QString end_time, QString name, QString num, QString param, QString bottom_param, QString top_param)
{    
	
	QString strSqlText;
	/*QString strSqlText("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure  \
                       WHERE date BETWEEN :start_time AND :end_time and :param BETWEEN :bottom_param AND :top_param; ");*/
	if (name=="") {//��Ʒ���Ʋ�ѯΪ��
		qDebug() << "00000000000000";
		if (num == "")//û�����ţ������б�Ų�ѯ
		{
			if (bottom_param == "0.00"&&top_param == "0.00") {//û���������������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE time-temp^ BETWEEN :start_time AND :end_time ;");
			}
			else {//û�б�ţ���������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE param-temp^ BETWEEN :bottom_param AND :top_param and time-temp^ BETWEEN :start_time AND :end_time ;");
			}
		}
		else {//���б�ŵĲ�ѯ
			if (bottom_param == "0.00"&&top_param == "0.00") {//û���������������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE time-temp^ BETWEEN :start_time AND :end_time and num=:num ;");
			}
			else {//����ţ���������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE param-temp^ BETWEEN :bottom_param AND :top_param and time-temp^ BETWEEN :start_time AND :end_time and num=:num ;");
			}
		}
	}
	else {//������Ʒ����ʱ
		qDebug() << "11111111111111";
		if (num == "")//û�����ţ������б�Ų�ѯ
		{
			qDebug() << "222222222";
			if (bottom_param == "0.00"&&top_param == "0.00") {//û���������������Χ�Ĳ�ѯ
				qDebug() << "444444444";
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE time-temp^ BETWEEN :start_time AND :end_time and name=:name ;");
			}
			else {//û�б�ţ���������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE param-temp^ BETWEEN :bottom_param AND :top_param and time-temp^ BETWEEN :start_time AND :end_time and name=:name ;");
			}
		}
		else {//���б�ŵĲ�ѯ
			qDebug() << "3333333";
			if (bottom_param == "0.00"&&top_param == "0.00") {//û���������������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE time-temp^ BETWEEN :start_time AND :end_time and num=:num and name=:name;");
			}
			else {//����ţ���������Χ�Ĳ�ѯ
				strSqlText = ("select num,name,set_magnetization,Hc,Hm,temperature,tester,date,remarks from measure WHERE param-temp^ BETWEEN :bottom_param AND :top_param and time-temp^ BETWEEN :start_time AND :end_time and num=:num and name=:name;");
			}
		}
	}
	qDebug() << "name::"<< name;
	strSqlText.replace("param-temp^",param);
	strSqlText.replace("time-temp^","date");
	//strSqlText.replace("num-temp^","date");
	//strSqlText.replace("name-temp^",name);
	query->prepare(strSqlText);
	query->bindValue(":start_time", start_time);
	query->bindValue(":end_time", end_time);
	query->bindValue(":bottom_param", bottom_param);
	query->bindValue(":top_param", top_param);
	query->bindValue(":num", num);
	query->bindValue(":name", name);
	query->exec();
	bool flag = commitDB(*query);
	if (flag)
	{
		qDebug() << "queryCondition success";
		/*�������ݱ�*/
		//���ñ���ͷ
		QStringList list;
		list << QString::fromLocal8Bit("���") << QString::fromLocal8Bit("����") << "H(A/m)" << "Hc(A/m)"
			<< "Hm(A/m)" << QString::fromLocal8Bit("�¶ȡ�") << QString::fromLocal8Bit("����Ա")
			<< QString::fromLocal8Bit("����") << QString::fromLocal8Bit("��ע");
		history_query_ui.tableWidget->setColumnCount(list.size());
		//����ˮƽͷ
		history_query_ui.tableWidget->setHorizontalHeaderLabels(list);
		//��ȡ�������...�˷�����̫�ã����Ż�
		QSqlQueryModel *queryModel = new QSqlQueryModel();
		queryModel->setQuery(*query);
		int nRecordCount = queryModel->rowCount();
		qDebug() << "conditionQueryCount::::" << nRecordCount;
		//��������
		history_query_ui.tableWidget->setRowCount(nRecordCount);
		QList<QList<QString>> FList;
		FList.clear();
		query->prepare(strSqlText);
		query->bindValue(":start_time", start_time);
		query->bindValue(":end_time", end_time);
		query->bindValue(":bottom_param", bottom_param);
		query->bindValue(":top_param", top_param);
		query->bindValue(":num", num);
		query->bindValue(":name", name);
		qDebug() << "strSqlText:" << strSqlText;
		query->exec();
		QSqlRecord rec = query->record();
		while (query->next())
		{
			QList<QString> qlist;
			for (int i = 0; i < rec.count(); i++) {
				//׼������
				if (i == 7)//��ʱ����Ӹ�ʽ
				{
					QString date_str = query->value(i).toString();
					date_str.insert(4, "-");
					date_str.insert(7, "-");
					qlist << date_str;
				}
				else {
					qlist << query->value(i).toString();
				}
			}
			FList.append(qlist);
		}
		int i, j = 0;
		
		qDebug() << "conditionQuery open data success";
		qlist_H.clear();
		qlist_Hc.clear();
		qlist_Hm.clear();
		for (i = 0; i < FList.size(); i++)
		{
			QList<QString> qlist_item = FList.at(i);
			//qDebug() << qlist_item;
			for (j = 0; j < qlist_item.size(); j++)
			{
				if (j == 2)
				{
					qlist_H << qlist_item[j].toLong();
				}
				else if (j == 3)
				{
					qlist_Hc << qlist_item[j].toLong();
				}
				else if (j == 4)
				{
					qlist_Hm << qlist_item[j].toLong();
				}
				history_query_ui.tableWidget->setItem(i, j, new QTableWidgetItem(qlist_item[j]));
			}
		}
		//history_query_ui.tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
		history_query_ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//������
		history_query_ui.tableWidget->scrollToTop();//��ѯ���ƶ�������
	}
	else
	{
		qDebug() << db1.lastError();
		qFatal("failed to connect.");
		QMessageBox::about(NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ݲ�ѯʧ��"));
	}
	//commitDB(*query);
	/*qDebug() << "queryCondition success";
	QSqlRecord rec = query->record();
	while (query->next()) {
		qDebug() << "queryCondition success111111111111111111";
		for (int i = 0; i < rec.count(); i++) {
			qDebug() << "condition::"<<query->value(i).toString();
		}
	}*/

}

bool sqldb::commitDB(QSqlQuery &qsQuery)
{
	if (qsQuery.isActive())//�ɹ�ִ��sql��� isActive�᷵��true,���򷵻�false
	{
		db1.commit();
		return true;
	}
	else
	{
		db1.rollback();
		return false;
	}
}

long sqldb::getAvgFromData(QList<long> qlist)
{
	if (qlist.size()>0) {
		long temp_age = 0;
		for (size_t i = 0; i < qlist.size(); i++)
		{
			temp_age = temp_age + qlist[i];
		}
		long age_value = temp_age / qlist.size();
		return age_value;
	}
	else
	{
		return 0;
	}
	
}


long sqldb::getVarianceFromData(QList<long> qlist, long ave)
{
	long temp_age=0;
	if (qlist.size()>0)
	{
		for (size_t i = 0; i < qlist.size(); i++)
		{
			temp_age += (qlist[i] - ave)*(qlist[i] - ave);
		}
		double vari = (temp_age) / qlist.size();
		return sqrt(vari);
	}
	else {
		return 0;
	}
	
}

sqldb::~sqldb()
{

}