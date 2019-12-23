#include "HistoryQuery.h"

HistoryQuery::HistoryQuery(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("历史记录查询"));
	datebase = sqldb();
	datebase.querySaveTestDate(ui);
	QDateTime time = QDateTime::currentDateTime();
	ui.dateEdit_2->setDateTime(time);
	ui.dateEdit_2->setDisplayFormat("yyyy-MM-dd");
	QDateTime time_7 = time.addMonths(-6);
	ui.dateEdit->setDateTime(time_7);
	ui.dateEdit->setDisplayFormat("yyyy-MM-dd");
	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit_2->setCalendarPopup(true);
	ui.tableWidget->verticalHeader()->setHidden(true);
	ui.tableView->verticalHeader()->setHidden(true);
	ui.tableView->hide();
	//一周内按钮
	connect(ui.pushButton, &QPushButton::clicked, this, [=]() {
		QDateTime time = QDateTime::currentDateTime();
		ui.dateEdit_2->setDateTime(time);
		ui.dateEdit_2->setDisplayFormat("yyyy-MM-dd");
		QDateTime time_7 = time.addDays(-7);
		ui.dateEdit->setDateTime(time_7);
		ui.dateEdit->setDisplayFormat("yyyy-MM-dd");
		ui.dateEdit->setCalendarPopup(true);
		ui.dateEdit_2->setCalendarPopup(true);
	});
	//1月内按钮
	connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {
		QDateTime time = QDateTime::currentDateTime();
		ui.dateEdit_2->setDateTime(time);
		ui.dateEdit_2->setDisplayFormat("yyyy-MM-dd");
		QDateTime time_1 = time.addMonths(-1);
		ui.dateEdit->setDateTime(time_1);
		ui.dateEdit->setDisplayFormat("yyyy-MM-dd");
		ui.dateEdit->setCalendarPopup(true);
		ui.dateEdit_2->setCalendarPopup(true);
	});
	//3月内按钮
	connect(ui.pushButton_3, &QPushButton::clicked, this, [=]() {
		QDateTime time = QDateTime::currentDateTime();
		ui.dateEdit_2->setDateTime(time);
		ui.dateEdit_2->setDisplayFormat("yyyy-MM-dd");
		QDateTime time_3 = time.addMonths(-3);
		ui.dateEdit->setDateTime(time_3);
		ui.dateEdit->setDisplayFormat("yyyy-MM-dd");
		ui.dateEdit->setCalendarPopup(true);
		ui.dateEdit_2->setCalendarPopup(true);
	});
	//6月内按钮
	connect(ui.pushButton_4, &QPushButton::clicked, this, [=]() {
		QDateTime time = QDateTime::currentDateTime();
		ui.dateEdit_2->setDateTime(time);
		ui.dateEdit_2->setDisplayFormat("yyyy-MM-dd");
		QDateTime time_6 = time.addMonths(-6);
		ui.dateEdit->setDateTime(time_6);
		ui.dateEdit->setDisplayFormat("yyyy-MM-dd");
		ui.dateEdit->setCalendarPopup(true);
		ui.dateEdit_2->setCalendarPopup(true);
	});
	//查询按钮
	connect(ui.pushButton_8, &QPushButton::clicked, this, [=]() {
		//获取筛选参数，进行条件查询
		QString start_str = ui.dateEdit->text();
		QString end_str = ui.dateEdit_2->text();
		QString param_str = ui.comboBox_2->currentText();
		QString param = param_str.replace("(A/m)", "");
		if (param=="H")
		{
			param = "set_magnetization";
		}
		datebase.queryCondition(ui.tableWidget, start_str.replace("-",""), end_str.replace("-", ""),ui.lineEdit_2->text(),ui.lineEdit->text(), param,ui.doubleSpinBox->text(),ui.doubleSpinBox_2->text());
		//标准差、平均值显示
		datebase.showStandard_Avg(ui.tableView);
	});
	connect(ui.pushButton_7, &QPushButton::clicked, this, [=]() {
		qDebug() << "重置";
		datebase.querySaveTestDate(ui);
	});
	//是否显示标准差、平均值选框按钮
	connect(ui.checkBox, &QCheckBox::stateChanged, this, [=](int state) {
		if (state==2)//选中为2；
		{
			ui.tableView->show();
		}
		else if (state == 0)//未选中为0
		{
			ui.tableView->hide();
		}
	});
	//标准差、平均值显示
	datebase.showStandard_Avg(ui.tableView);
}

HistoryQuery::~HistoryQuery()
{
}
