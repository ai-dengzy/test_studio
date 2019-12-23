#include "QtSon.h"
#include "ui_QtSon.h"
#include "qdebug.h"
QtSon::QtSon(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QtSon();
	ui->setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("测量方案管理"));

	ui->textBrowser->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");
	ui->textBrowser_2->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");
	ui->textBrowser_3->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");

	ui->comboBox_para_name->addItem("H");
	ui->comboBox_para_name->addItem("Hc");
	ui->comboBox_para_name->addItem("Hm");
	ui->comboBox_para_unit->addItem("A/m");
	ui->comboBox_para_sorting->addItem(QString::fromLocal8Bit("不分选"));
	ui->comboBox_para_sorting->addItem(QString::fromLocal8Bit("x≤上限"));
	ui->comboBox_para_sorting->addItem(QString::fromLocal8Bit("下限≤x"));
	ui->comboBox_para_sorting->addItem(QString::fromLocal8Bit("下限≤x≤上限"));
	
	QTableView *tableView_pararesult = ui->tableView_2;
	QStringList labels_pararesult = QString::fromLocal8Bit("名称,单位,分选,下限,上限").simplified().split(",");
	QStringList labels_pararesult_content = QString::fromLocal8Bit("H,Hc,Hm)").simplified().split(",");
	QStringList labels_pararesult_ableedit = QString::fromLocal8Bit("A/m,A/m,A/m").simplified().split(",");
	QStringList labels_pararesult_souting = QString::fromLocal8Bit("不分轩,不分选,不分选").simplified().split(",");
	QStringList labels_pararesult_top = QString::fromLocal8Bit("0,0,0").simplified().split(",");
	QStringList labels_pararesult_bottom = QString::fromLocal8Bit("0,0,0").simplified().split(",");
	for (size_t i = 0; i < labels_pararesult_content.size(); i++)
	{
		model_pararesult->setItem(i, 0, new QStandardItem(labels_pararesult_content[i]));
		model_pararesult->item(i, 0)->setTextAlignment(Qt::AlignCenter);
	}
	for (size_t i = 0; i < labels_pararesult_ableedit.size(); i++)
	{
		model_pararesult->setItem(i, 1, new QStandardItem(labels_pararesult_ableedit[i]));
		model_pararesult->item(i, 1)->setTextAlignment(Qt::AlignCenter);
	}
	for (size_t i = 0; i < labels_pararesult_souting.size(); i++)
	{
		model_pararesult->setItem(i, 2, new QStandardItem(labels_pararesult_souting[i]));
		model_pararesult->item(i, 2)->setTextAlignment(Qt::AlignCenter);
	}
	for (size_t i = 0; i < labels_pararesult_top.size(); i++)
	{
		model_pararesult->setItem(i, 3, new QStandardItem(labels_pararesult_top[i]));
		model_pararesult->item(i, 3)->setTextAlignment(Qt::AlignCenter);
	}
	for (size_t i = 0; i < labels_pararesult_bottom.size(); i++)
	{
		model_pararesult->setItem(i, 4, new QStandardItem(labels_pararesult_bottom[i]));
		model_pararesult->item(i, 4)->setTextAlignment(Qt::AlignCenter);
	}
	model_pararesult->setHorizontalHeaderLabels(labels_pararesult);
	tableView_pararesult->setModel(model_pararesult);
	tableView_pararesult->show();
	ReadOnlyDelegate *readOnlyDelegate_pararesult = new ReadOnlyDelegate();
	tableView_pararesult->setItemDelegateForColumn(0, readOnlyDelegate_pararesult); //设置某列只读
	tableView_pararesult->setItemDelegateForColumn(1, readOnlyDelegate_pararesult); //设置某列只读
	tableView_pararesult->setItemDelegateForColumn(2, readOnlyDelegate_pararesult); //设置某列只读
	tableView_pararesult->setItemDelegateForColumn(3, readOnlyDelegate_pararesult); //设置某列只读
	tableView_pararesult->setItemDelegateForColumn(4, readOnlyDelegate_pararesult); //设置某列只读
	int width_pararesult = tableView_pararesult->width();
	int column_size = labels_pararesult.size();
	tableView_pararesult->setColumnWidth(0, (width_pararesult / labels_pararesult.size())-8);
	tableView_pararesult->setColumnWidth(1, (width_pararesult / labels_pararesult.size())-8);
	tableView_pararesult->setColumnWidth(2, (width_pararesult / labels_pararesult.size())-8);
	tableView_pararesult->setColumnWidth(3, (width_pararesult / labels_pararesult.size())-8);
	tableView_pararesult->setColumnWidth(4, (width_pararesult / labels_pararesult.size())-8);
	//tableView_pararesult->selectRow(1);
	//connect(tableView_pararesult, &QTableView::clicked,this, &QtSon::handleTableClick);
	tableView_pararesult->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中模式为选中行
	/*connect(ui->tableView->selectionModel(),
		SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
		this, SLOT(showOperationDetails(const QModelIndex &, const QModelIndex &)));*/
	
	QTableView *tableview = ui->tableView;
	QStandardItemModel *model = new QStandardItemModel(); 
	QStringList labels = QString::fromLocal8Bit("参数名称,内容(默认值),编辑").simplified().split(",");
	QStringList labels_content = QString::fromLocal8Bit("编号,名称,批次,材料,温度,测试员,日期,备注").simplified().split(",");
	QStringList labels_ableedit = QString::fromLocal8Bit("可编辑,可编辑,可编辑,可编辑,不可编辑,可编辑,可编辑,可编辑").simplified().split(",");
	for (size_t i = 0; i < labels_ableedit.size(); i++)
	{
		model->setItem(i, 2, new QStandardItem(labels_ableedit[i]));
		model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
	}
	model->setHorizontalHeaderLabels(labels);
	ui->tableView->setModel(model);
	ui->tableView->show();
	model->setItem(0, 0, new QStandardItem(labels_content[0])); 
	model->setItem(1, 0, new QStandardItem(labels_content[1])); 
	model->setItem(2, 0, new QStandardItem(labels_content[2])); 
	model->setItem(3, 0, new QStandardItem(labels_content[3])); 
	model->setItem(4, 0, new QStandardItem(labels_content[4])); 
	model->setItem(5, 0, new QStandardItem(labels_content[5])); 
	model->setItem(6, 0, new QStandardItem(labels_content[6])); 
	model->setItem(7, 0, new QStandardItem(labels_content[7])); 
	tableview->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	ReadOnlyDelegate *readOnlyDelegate = new ReadOnlyDelegate();
	tableview->setItemDelegateForColumn(2, readOnlyDelegate); //设置某列只读
	int width = tableview->width();
	tableview->setColumnWidth(0, (width / 8)*2);
	tableview->setColumnWidth(1, (width / 8)*5-18);
	tableview->setColumnWidth(2, (width / 8));

	connect(ui->pushButton_save, &QPushButton::clicked, this, [=]() {
		QMessageBox::information(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit( "已保存"));
		this->close();
	});
	connect(ui->pushButton_exit, &QPushButton::clicked, this, [=]() {
		this->close();
	});
	connect(ui->pushButton_logo, &QPushButton::clicked, this, [=]() {
		QString path = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择LOGO"), "D:");
		QMessageBox::information(NULL, "Title", "Content");
	});
	connect(ui->pushButton_delete, &QPushButton::clicked, this, [=]() {
		QModelIndex index = ui->tableView_2->selectionModel()->currentIndex();
		int row = index.row();
		qDebug() << row;
		model_pararesult->removeRow(row);
	});
	connect(ui->pushButton_add_modify, &QPushButton::clicked, this, [=]() {
		//ui->tableWidget->insertRow(0);
		//ui->tableWidget->setItem(0, 0, new QTableWidgetItem("赵云"));
		//ui->tableWidget->setItem(0, 1, new QTableWidgetItem("男"));
		//ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(20)));
		//QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("有了！"));
		//model_pararesult->appendRow(new QStandardItem());setItem(i, 0, new QStandardItem(labels_pararesult_content[i]));
		//model_pararesult->insertRow();
		
		addRowParaResult();
	});
}
void QtSon::addRowParaResult() {
	int rowIndex = model_pararesult->rowCount();
	//model_pararesult->setRowCount(rowIndex + 1);//总行数增加1
	QStandardItem *item1 = new QStandardItem(ui->comboBox_para_name->currentText());
	QStandardItem *item2 = new QStandardItem(ui->comboBox_para_unit->currentText());
	QStandardItem *item3 = new QStandardItem(ui->comboBox_para_sorting->currentText());
	double value_top = ui->doubleSpinBox_top->value();
	double value_bottom = ui->doubleSpinBox_botom->value();
	QStandardItem *item4 = new QStandardItem(QString::number(value_top));
	QStandardItem *item5 = new QStandardItem(QString::number(value_bottom));
	model_pararesult->setItem(rowIndex, 0, item1);	 model_pararesult->item(rowIndex, 0)->setTextAlignment(Qt::AlignCenter);
	model_pararesult->setItem(rowIndex, 1, item2);	 model_pararesult->item(rowIndex, 1)->setTextAlignment(Qt::AlignCenter);
	model_pararesult->setItem(rowIndex, 2, item3);	 model_pararesult->item(rowIndex, 2)->setTextAlignment(Qt::AlignCenter);
	model_pararesult->setItem(rowIndex, 3, item4);	 model_pararesult->item(rowIndex, 3)->setTextAlignment(Qt::AlignCenter);
	model_pararesult->setItem(rowIndex, 4, item5);	 model_pararesult->item(rowIndex, 4)->setTextAlignment(Qt::AlignCenter);
}

QtSon::~QtSon()
{
	delete ui;
}
