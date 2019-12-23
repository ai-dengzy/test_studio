#include "HistoryQuery.h"

HistoryQuery::HistoryQuery(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("��ʷ��¼��ѯ"));
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
	//һ���ڰ�ť
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
	//1���ڰ�ť
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
	//3���ڰ�ť
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
	//6���ڰ�ť
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
	//��ѯ��ť
	connect(ui.pushButton_8, &QPushButton::clicked, this, [=]() {
		//��ȡɸѡ����������������ѯ
		QString start_str = ui.dateEdit->text();
		QString end_str = ui.dateEdit_2->text();
		QString param_str = ui.comboBox_2->currentText();
		QString param = param_str.replace("(A/m)", "");
		if (param=="H")
		{
			param = "set_magnetization";
		}
		datebase.queryCondition(ui.tableWidget, start_str.replace("-",""), end_str.replace("-", ""),ui.lineEdit_2->text(),ui.lineEdit->text(), param,ui.doubleSpinBox->text(),ui.doubleSpinBox_2->text());
		//��׼�ƽ��ֵ��ʾ
		datebase.showStandard_Avg(ui.tableView);
	});
	connect(ui.pushButton_7, &QPushButton::clicked, this, [=]() {
		qDebug() << "����";
		datebase.querySaveTestDate(ui);
	});
	//�Ƿ���ʾ��׼�ƽ��ֵѡ��ť
	connect(ui.checkBox, &QCheckBox::stateChanged, this, [=](int state) {
		if (state==2)//ѡ��Ϊ2��
		{
			ui.tableView->show();
		}
		else if (state == 0)//δѡ��Ϊ0
		{
			ui.tableView->hide();
		}
	});
	//��׼�ƽ��ֵ��ʾ
	datebase.showStandard_Avg(ui.tableView);
}

HistoryQuery::~HistoryQuery()
{
}
