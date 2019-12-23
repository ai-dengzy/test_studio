#include "test_studio.h"

using namespace std;

test_studio::test_studio(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//resize(800,600);
	setWindowTitle(QString::fromLocal8Bit("CTM��Ų��Ͻ���������ϵͳV1.0"));
	QApplication::setWindowIcon(QIcon(":/test_studio/Resources/linkjoin_icon.jpg"));
	QDesktopWidget *desk = QApplication::desktop();
	QRect rect = desk->availableGeometry();
	resize(rect.width() - 15, rect.height() - 35);
	showchart();
	//QLabel *locationLabel;
	QLabel *locationLabel = new QLabel(QString::fromLocal8Bit("��ӭʹ������ϵͳ!"));
	locationLabel->setAlignment(Qt::AlignCenter);
	locationLabel->setMinimumSize(locationLabel->sizeHint());
	//QLabel *aixLabel;
	//QLabel *aixLabel = new QLabel("\"CTRL + H\" for help");
	//Optional
	statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // ���ò���ʾlabel�ı߿�
	statusBar()->setSizeGripEnabled(false); //�����Ƿ���ʾ�ұߵĴ�С���Ƶ�
	statusBar()->addWidget(locationLabel);
	
	for (size_t i = 1; i < 11; i++)
	{
		QString str = QString::number(i);
	}
	
	//����
	connect(ui.actioncreat, &QAction::triggered, this, [=]() {
		// ģ̬�Ի��� �������Զ��������ڽ��в����� ��ģ̬�Ի��� �����Զ��������ڲ�����
		        QDialog dlg(this);
		        dlg.resize(200,100);
		        dlg.exec(); //����
	});

	//��
	connect(ui.actionopen_2, &QAction::triggered, this, [=]() {
        QString path =  QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("���ļ�"),"D:");
		QMessageBox::information(NULL, "Title", "Content");
        qDebug() << path;
	});

	//���Ϊ
	connect(ui.actionsaveas, &QAction::triggered, this, [=]() {
		QFileDialog fileDialog;
		QString fileName = fileDialog.getSaveFileName(this,QString::fromLocal8Bit("���Ϊ"),"D:", tr("(*.XLS)"));
		if(fileName == "")
		{
			return;
		}
		QFile file(fileName);
		if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QMessageBox::warning(this,tr("����"),tr("���ļ�ʧ��"));
			return;
		}
		else
		{
			QTextStream textStream(&file);
			//QString str = textEdit->toPlainText();
			//textStream<<str;
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�����ļ��ɹ�"));
			/*Last_filecontent = str;
			last_filename = filename;
			flag_isnew = 0;*/
			file.close();
		}
	});

	//ͳ��
	connect(ui.actionmeasure, &QAction::triggered, this, [=]() {
		//QDialog dlg(this);
		//dlg.resize(200, 100);
		//dlg.exec(); //����
		//qDebug() << "����ͳ�ƶԻ���";
		son = new QtSon();
		son->show();
	});
	//����ѡ��
	connect(ui.actionsettting_option, &QAction::triggered, this, [=]() {
		setting_option = new SettingOption();
		setting_option->show();
	});	
	//��ʷ��¼��ѯ
	connect(ui.actiondata_history, &QAction::triggered, this, [=]() {
		history_query = new HistoryQuery();
		history_query->show();
	});
	//����
	connect(ui.actionhelp_about, &QAction::triggered, this, [=]() {
		help_about = new HelpAbout();
		help_about->show();
	});
	//�û�ע��
	connect(ui.actionhelp_register, &QAction::triggered, this, [=]() {
		userRegister = new UserRegister();
		userRegister->show();
	});
	//������򿪹���
	connect(ui.actionhelp_website, &QAction::triggered, this, []() {
		QString URL = "http://www.linkjoin.com/";
		QDesktopServices::openUrl(QUrl(URL.toLatin1()));
	}); 
	
	//��ʼ����
	connect(ui.toolButton_2, &QToolButton::clicked, this, [=]() {
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ʼ����"));
		/*��ȡ��������������������Hc��������Hm���ų�ǿ�����֣�������>���浽�����*/
		//��ȡ�������
		SAVE_TYPE_INT = OPEN_TEST;
		gotoSave();
	});
	//ֹͣ����
	connect(ui.toolButton_3, &QToolButton::clicked, this, [=]() {
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ֹͣ����"));
	});
	//��������
	connect(ui.toolButton_4, &QToolButton::clicked, this, [=]() {
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��������"));
	});
	//��������
	connect(ui.toolButton, &QToolButton::clicked, this, [=]() {
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��������"));
	});
	//���������
	connect(ui.pushButton_save_programme, &QPushButton::clicked, this, [=]() {
		SAVE_TYPE_INT = SAVE_MEASURE;
		gotoSave();
	});
	//ui.tabWidget_2->setCornerWidget(ui.pushButton, Qt::BottomLeftCorner);
	
	//�ұ߲�������
	new initLayout(ui);
	//���ʻ����ݿ⡢��ȡ���ݿ���Ϣչʾ����
	executesql();
}

void test_studio::showchart() {
	// generate some data:
	QVector<double> x(301), y(301); // initialize with entries 0..100
	for (int i = 0; i < 301; ++i)
	{
		x[i] = i ; // x goes from -1 to 1
		y[i] = 3; // let's plot a quadratic function��Y����һ�����η���ֵ��
	}
	// create graph and assign data to it:
	ui.customPlot->addGraph();
	ui.customPlot->graph(0)->setData(x, y);
	// give the axes some labels:const QString &str
	ui.customPlot->xAxis->setLabel(QString::fromLocal8Bit("�ų�ǿ��"));
	ui.customPlot->yAxis->setLabel(QString::fromLocal8Bit("��ͨ"));
	// set axes ranges, so we see all data:��x��y������ݷ�Χ��
	ui.customPlot->xAxis->setRange(-180, 200);
	ui.customPlot->yAxis->setRange(-4.5, 5);
	ui.customPlot->replot();
}

void test_studio::on_FileButton_clicked()
{
}


void test_studio::executesql() {
	datebase = sqldb();
	datebase.showInfo(ui);
	datebase.querySaveTestDate(ui);
}

void test_studio::saveMeasureDataSql(QTableView *table1, QTableView *table2, QTableView *table3, QTableView *table4, QTableView *table5, QTableView *table6, QTableView *table7)
{
	QAbstractItemModel *model1 = table1->model();
	QModelIndex code_index = model1->index(0, 1);
	QLineEdit *code = qobject_cast<QLineEdit *>(table1->indexWidget(code_index));  //����ת��Ϊ��ť����
	//int num = QString(code->text()).toInt();
	QString num = code->text();
	QModelIndex name_index = model1->index(1, 1);
	QLineEdit *name_ = qobject_cast<QLineEdit *>(table1->indexWidget(name_index));
	QString name = name_->text();
	QModelIndex pici_index = model1->index(2, 1);
	QLineEdit *pici = qobject_cast<QLineEdit *>(table1->indexWidget(pici_index));
	QString  batch = pici->text();
	QModelIndex material_index= model1->index(3, 1);
	QLineEdit *material_ = qobject_cast<QLineEdit *>(table1->indexWidget(material_index));
	QString material = material_->text();

	QAbstractItemModel *model2 = table2->model();
	QModelIndex temperature_index = model2->index(0, 1);
	QLineEdit *temperature_ = qobject_cast<QLineEdit *>(table2->indexWidget(temperature_index));
	QString temperature = temperature_->text();

	QAbstractItemModel *model3 = table3->model();
	QModelIndex tester_index = model3->index(0, 1);
	QLineEdit *tester_ = qobject_cast<QLineEdit *>(table3->indexWidget(tester_index));
	QString tester = tester_->text();
	QModelIndex date_index = model3->index(1, 1);
	QDateEdit *date_ = qobject_cast<QDateEdit *>(table3->indexWidget(date_index));
	QString date = date_->text();
	QModelIndex remarker_index = model3->index(2, 1);
	QLineEdit *remarker = qobject_cast<QLineEdit *>(table3->indexWidget(remarker_index));
	QString  remarks = remarker->text();

	QAbstractItemModel *model4 = table4->model();
	QModelIndex measure_method_index = model4->index(0, 1);
	QComboBox *cb_measure_method = qobject_cast<QComboBox *>(table4->indexWidget(measure_method_index));  //����ת��Ϊ��ť����
	QString measure_method = cb_measure_method->currentText();
	QModelIndex magnetization_model_index = model4->index(1, 1);
	QComboBox *cb_magnetization_model = qobject_cast<QComboBox *>(table4->indexWidget(magnetization_model_index));  
	QString magnetization_model = cb_magnetization_model->currentText();
	QModelIndex sample_shape_index = model4->index(2, 1);
	QComboBox *cb_sample_shape = qobject_cast<QComboBox *>(table4->indexWidget(sample_shape_index)); 
	QString sample_shape = cb_sample_shape->currentText();
	QModelIndex sample_specification_index = model4->index(3, 1);
	QLineEdit *cb_sample_specification = qobject_cast<QLineEdit *>(table4->indexWidget(sample_specification_index));  
	QString sample_specification = cb_sample_specification->text();

	QAbstractItemModel *model5 = table5->model();
	QModelIndex set_magnetization_index = model5->index(0, 1);
	QComboBox *cb_set_magnetization = qobject_cast<QComboBox *>(table5->indexWidget(set_magnetization_index));  //����ת��Ϊ��ť����
	QString set_magnetization = cb_set_magnetization->currentText();
	QModelIndex measure_times_index = model5->index(1, 1);
	QComboBox *cb_measure_times = qobject_cast<QComboBox *>(table5->indexWidget(measure_times_index));  //����ת��Ϊ��ť����
	QString measure_times = cb_measure_times->currentText();
	QModelIndex delay_index = model5->index(2, 1);
	QLineEdit *cb_delay = qobject_cast<QLineEdit *>(table5->indexWidget(delay_index));
	QString delay = cb_delay->text();

	QAbstractItemModel *model6 = table6->model();
	QModelIndex estimate_index_1 = model6->index(0, 1);
	QLineEdit *estimate_1_ = qobject_cast<QLineEdit *>(table6->indexWidget(estimate_index_1));
	QString estimate_1 = estimate_1_->text();
	QModelIndex estimate_index_2 = model6->index(0, 3);
	QLineEdit *estimate_2_ = qobject_cast<QLineEdit *>(table6->indexWidget(estimate_index_2));
	QString estimate_2 = estimate_2_->text();
	
	QAbstractItemModel *model7 = table7->model();
	QModelIndex top_limit_index = model7->index(0, 1);
	QLineEdit *top_limit = qobject_cast<QLineEdit *>(table7->indexWidget(top_limit_index));
	QString limit_top = top_limit->text();
	QModelIndex bottom_limit_index = model7->index(0, 3);
	QLineEdit *bottom_limit = qobject_cast<QLineEdit *>(table7->indexWidget(bottom_limit_index));
	QString limit_bottom = bottom_limit->text();
	qDebug() << "table_index:"<<table_index;
	boolean id_existence = datebase.queryId(table_index);
	switch (SAVE_TYPE_INT)
	{
	case SAVE_MEASURE:
		if (id_existence) {
			//�����ǰ���б���Ĳ��Է�����id���ڣ�ִ�и���
			qDebug() << QString::fromLocal8Bit("ִ�и������ݲ���") << "111111111111-----:" << measure_method;
			datebase.updateSql(table_index, num, name, batch, material, temperature, tester, date, remarks, measure_method, magnetization_model, sample_shape,
				sample_specification, set_magnetization, measure_times, delay, estimate_1, estimate_2, limit_top, limit_bottom);
		}
		else
		{
			//id������ִ�б������
			datebase.saveSql(table_index, num, name, batch, material, temperature, tester, date, remarks, measure_method, magnetization_model, sample_shape,
				sample_specification, set_magnetization, measure_times, delay, estimate_1, estimate_2, limit_top, limit_bottom);
		}
		break;
	case OPEN_TEST:
		//�������Hc����Hm;��ʵ�������Ҫ����TCP��������ʵ����
		qDebug() << QString::fromLocal8Bit("����������֣�")<<GetRandomNumber();
		//GOTO:���Ͳ��������ݸ���λ�������ؽ���ɹ��󱣴����ݵ����ݿ�
		//�������ݵ����ݿ�
		datebase.saveTestSql(num, name, batch, material, temperature, tester, date, remarks, measure_method, magnetization_model, sample_shape,
			sample_specification, set_magnetization, measure_times, delay, estimate_1, estimate_2, limit_top, limit_bottom,QString::number(GetRandomNumber()),QString::number(GetRandomNumber()));
		
		break;
	}
}

void test_studio::gotoSave()
{
	table_index = ui.tabWidget->currentIndex();
	//��������Ϣ���浽���ݿ���
	switch (table_index)
	{
	case 0:
		saveMeasureDataSql(ui.tableView_72, ui.tableView_73, ui.tableView_77, ui.tableView_76, ui.tableView_74, ui.tableView_71, ui.tableView_75);
		break;
	case 1:
		saveMeasureDataSql(ui.tableView_14, ui.tableView_13, ui.tableView_11, ui.tableView_10, ui.tableView_12, ui.tableView_9, ui.tableView_8);
		break;
	case 2:
		saveMeasureDataSql(ui.tableView_21, ui.tableView_20, ui.tableView_18, ui.tableView_17, ui.tableView_19, ui.tableView_16, ui.tableView_15);
		break;
	case 3:
		saveMeasureDataSql(ui.tableView_28, ui.tableView_27, ui.tableView_25, ui.tableView_24, ui.tableView_26, ui.tableView_23, ui.tableView_22);
		break;
	case 4:
		saveMeasureDataSql(ui.tableView_35, ui.tableView_34, ui.tableView_32, ui.tableView_31, ui.tableView_33, ui.tableView_30, ui.tableView_29);
		break;
	case 5:
		saveMeasureDataSql(ui.tableView_42, ui.tableView_41, ui.tableView_39, ui.tableView_38, ui.tableView_40, ui.tableView_37, ui.tableView_36);
		break;
	case 6:
		saveMeasureDataSql(ui.tableView_49, ui.tableView_48, ui.tableView_46, ui.tableView_45, ui.tableView_47, ui.tableView_44, ui.tableView_43);
		break;
	case 7:
		saveMeasureDataSql(ui.tableView_56, ui.tableView_55, ui.tableView_53, ui.tableView_52, ui.tableView_54, ui.tableView_51, ui.tableView_50);
		break;
	case 8:
		saveMeasureDataSql(ui.tableView_63, ui.tableView_62, ui.tableView_60, ui.tableView_59, ui.tableView_61, ui.tableView_58, ui.tableView_57);
		break;
	case 9:
		saveMeasureDataSql(ui.tableView_67, ui.tableView_68, ui.tableView_66, ui.tableView_69, ui.tableView_64, ui.tableView_65, ui.tableView_70);
		break;
	}
}

int test_studio::GetRandomNumber()
{
	int RandomNumber;
	srand((unsigned)time(NULL));//time()��ϵͳʱ���ʼ���֡�Ϊrand()���ɲ�ͬ��������ӡ�
	RandomNumber = rand() % 100 + 1;//����1~100�����
	return RandomNumber;
}

test_studio::~test_studio() {
	
}