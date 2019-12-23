#include "initLayout.h"
#include <qdebug.h>
initLayout::initLayout(Ui::test_studioClass ui)
{
	//tableview 1~10
	table_1(ui);
	table_2(ui);
	table_3(ui);
	table_4(ui);
	table_5(ui);
	table_6(ui);
	table_7(ui);
	table_8(ui);
	table_9(ui);
	table_10(ui);
}

void initLayout::table_1(Ui::test_studioClass ui)
{
	init(ui.tableView_72, ui.tableView_73, ui.tableView_77, ui.tableView_76, ui.tableView_74, ui.tableView_71, ui.tableView_75);
}

void initLayout::table_2(Ui::test_studioClass ui)
{
	init(ui.tableView_14, ui.tableView_13, ui.tableView_11, ui.tableView_10, ui.tableView_12, ui.tableView_9, ui.tableView_8);
}

void initLayout::table_3(Ui::test_studioClass ui)
{
	init(ui.tableView_21, ui.tableView_20, ui.tableView_18, ui.tableView_17, ui.tableView_19, ui.tableView_16, ui.tableView_15);
}

void initLayout::table_4(Ui::test_studioClass ui)
{
	init(ui.tableView_28, ui.tableView_27, ui.tableView_25, ui.tableView_24, ui.tableView_26, ui.tableView_23, ui.tableView_22);
}

void initLayout::table_5(Ui::test_studioClass ui)
{
	init(ui.tableView_35, ui.tableView_34, ui.tableView_32, ui.tableView_31, ui.tableView_33, ui.tableView_30, ui.tableView_29);
}

void initLayout::table_6(Ui::test_studioClass ui)
{
	init(ui.tableView_42, ui.tableView_41, ui.tableView_39, ui.tableView_38, ui.tableView_40, ui.tableView_37, ui.tableView_36);
}

void initLayout::table_7(Ui::test_studioClass ui)
{
	init(ui.tableView_49, ui.tableView_48, ui.tableView_46, ui.tableView_45, ui.tableView_47, ui.tableView_44, ui.tableView_43);
}

void initLayout::table_8(Ui::test_studioClass ui)
{
	init(ui.tableView_56, ui.tableView_55, ui.tableView_53, ui.tableView_52, ui.tableView_54, ui.tableView_51, ui.tableView_50);
}

void initLayout::table_9(Ui::test_studioClass ui)
{
	init(ui.tableView_63, ui.tableView_62, ui.tableView_60, ui.tableView_59, ui.tableView_61, ui.tableView_58, ui.tableView_57);
}

void initLayout::table_10(Ui::test_studioClass ui)
{
	init(ui.tableView_67, ui.tableView_68, ui.tableView_66, ui.tableView_69, ui.tableView_64, ui.tableView_65, ui.tableView_70);
}

void initLayout::init(QTableView *table1, QTableView *table2, QTableView *table3, QTableView *table4, QTableView *table5, QTableView *table6, QTableView *table7)
{
	QStandardItemModel *model = new QStandardItemModel();
	table1->horizontalHeader()->hide();
	table1->verticalHeader()->hide();
	table1->setModel(model);
	QString str_bianhao;
	str_bianhao.append(QString::fromLocal8Bit("编"));
	for (size_t i = 0; i < 6; i++)
	{
		str_bianhao.append(" ");
	}
	str_bianhao.append(QString::fromLocal8Bit("号"));
	model->setItem(0, 0, new QStandardItem(str_bianhao)); model->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	table1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	QString str_mingcheng;
	str_mingcheng.append(QString::fromLocal8Bit("名"));
	for (size_t i = 0; i < 6; i++)
	{
		str_mingcheng.append(" ");
	}
	str_mingcheng.append(QString::fromLocal8Bit("称"));
	model->setItem(1, 0, new QStandardItem(str_mingcheng)); model->item(1, 0)->setTextAlignment(Qt::AlignCenter);

	QString str_pici;
	str_pici.append(QString::fromLocal8Bit("批"));
	for (size_t i = 0; i < 6; i++)
	{
		str_pici.append(" ");
	}
	str_pici.append(QString::fromLocal8Bit("次"));
	model->setItem(2, 0, new QStandardItem(str_pici)); model->item(2, 0)->setTextAlignment(Qt::AlignCenter);

	QString str_cailiao;
	str_cailiao.append(QString::fromLocal8Bit("材"));
	for (size_t i = 0; i < 6; i++)
	{
		str_cailiao.append(" ");
	}
	str_cailiao.append(QString::fromLocal8Bit("料"));
	model->setItem(3, 0, new QStandardItem(str_cailiao)); model->item(3, 0)->setTextAlignment(Qt::AlignCenter);
	model->setColumnCount(2);

	ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate();
	table1->setItemDelegateForColumn(0, readOnlyDelegate); //设置某列只读
	int width = table1->width();
	table1->setIndexWidget(model->index(0, 1), new QLineEdit());
	table1->setIndexWidget(model->index(1, 1), new QLineEdit());
	table1->setIndexWidget(model->index(2, 1), new QLineEdit());
	table1->setIndexWidget(model->index(3, 1), new QLineEdit());
	table1->setColumnWidth(0, width / 3);
	table1->setColumnWidth(1, (width / 3) * 2);

	QStandardItemModel *model7 = new QStandardItemModel();
	table2->horizontalHeader()->hide();
	table2->verticalHeader()->hide();
	table2->setModel(model7);
	table2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	QString str_wendu;
	str_wendu.append(QString::fromLocal8Bit("温"));
	for (size_t i = 0; i < 6; i++)
	{
		str_wendu.append(" ");
	}
	str_wendu.append(QString::fromLocal8Bit("度"));
	model7->setColumnCount(3);
	model7->setItem(0, 0, new QStandardItem(str_wendu)); model7->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	model7->setItem(0, 2, new QStandardItem(QString::fromLocal8Bit("℃"))); model7->item(0, 2)->setTextAlignment(Qt::AlignCenter);
	ReadOnlyDelegate* readOnlyDelegate7 = new ReadOnlyDelegate();
	table2->setItemDelegateForColumn(0, readOnlyDelegate); //设置某列只读
	table2->setItemDelegateForColumn(2, readOnlyDelegate); //设置某列只读
	table2->setIndexWidget(model7->index(0, 1), new QLineEdit());
	int width7 = table2->width();
	table2->setColumnWidth(0, (width7 / 6) * 2 + 1);
	table2->setColumnWidth(1, (width7 / 6) * 3 - 3);
	table2->setColumnWidth(2, (width7 / 6) + 5);

	QStandardItemModel *model2 = new QStandardItemModel();
	table3->horizontalHeader()->hide();
	table3->verticalHeader()->hide();
	table3->setModel(model2);
	QString str_ceshiyuan;
	table3->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	str_ceshiyuan.append(QString::fromLocal8Bit("测"));
	str_ceshiyuan.append("  ");
	str_ceshiyuan.append(QString::fromLocal8Bit("试"));
	str_ceshiyuan.append(" ");
	str_ceshiyuan.append(QString::fromLocal8Bit("员"));
	model2->setItem(0, 0, new QStandardItem(str_ceshiyuan)); model2->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	QString str_riqi;
	str_riqi.append(QString::fromLocal8Bit("日"));
	for (size_t i = 0; i < 6; i++)
	{
		str_riqi.append(" ");
	}
	str_riqi.append(QString::fromLocal8Bit("期"));
	model2->setItem(1, 0, new QStandardItem(str_riqi)); model2->item(1, 0)->setTextAlignment(Qt::AlignCenter);

	QString str_beizhu;
	str_beizhu.append(QString::fromLocal8Bit("备"));
	for (size_t i = 0; i < 6; i++)
	{
		str_beizhu.append(" ");
	}
	str_beizhu.append(QString::fromLocal8Bit("注"));
	model2->setItem(2, 0, new QStandardItem(str_beizhu)); model2->item(2, 0)->setTextAlignment(Qt::AlignCenter);
	model2->setColumnCount(2);
	ReadOnlyDelegate* readOnlyDelegate2 = new ReadOnlyDelegate();
	table3->setItemDelegateForColumn(0, readOnlyDelegate2); //设置某列只读
	//添加日期控件
	QDateTime curDateTime = QDateTime::currentDateTime();
	QDateEdit *dateEdit = new QDateEdit();
	dateEdit->setDate(curDateTime.date());
	dateEdit->setCalendarPopup(true);
	QWidget *widget1 = new QWidget;
	QCalendarWidget *calendarWidget1 = new QCalendarWidget(widget1);
	QString style1 = "QWidget#qt_calendar_navigationbar { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #3399ff, stop: 1 #3399ff); }"
		"QToolButton {background-color: qlineargradient(x1:0, y1:0, x2:0,"
		"y2:1, stop: 0 #3399ff, stop: 1 #3399ff);"
		"height: 25px;  }";

	QString style = "QMenu { font-size:16px; width: 150px; left: 20px;"
		"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #cccccc, stop: 1 #333333);}"
		"QToolButton {background-color: qlineargradient(x1:0, y1:0, x2:0,"
		"y2:1, stop: 0 #cccccc, stop: 1 #333333);"
		"height: 20px; width:100px;}"
		"QToolButton::menu-indicator{width: 50px;}"
		"QToolButton::menu-indicator:open{top:10px; left: 10px;}"
		"QSpinBox::up-button { subcontrol-origin: border;"
		"subcontrol-position: top right; width:50px; }"
		"QSpinBox::down-button {subcontrol-origin: border; subcontrol-position: bottom right;";
	calendarWidget1->setStyleSheet(style1);
	dateEdit->setCalendarWidget(calendarWidget1);
	dateEdit->setDisplayFormat("yyyy-MM-dd");
	//添加日历控件
	/*QDateTime curDateTime = QDateTime::currentDateTime();
	QDateEdit *dateEdit = ui.dateEdit;
	dateEdit->setDate(curDateTime.date());
	dateEdit->setCalendarPopup(true);
	QWidget *widget = new QWidget;
	QCalendarWidget *calendarWidget = new QCalendarWidget(widget);
	QString style = "QToolButton {background-color: qlineargradient(stop: 0 #ccccff, stop: 1 #333003);"
	" } ";

	calendarWidget->setStyleSheet(style);
	dateEdit->setCalendarWidget(calendarWidget);
	dateEdit->setDisplayFormat("yyyy-MM-dd");*/
	table3->setIndexWidget(model2->index(0, 1), new QLineEdit());
	table3->setIndexWidget(model2->index(1, 1), dateEdit);
	table3->setIndexWidget(model2->index(2, 1), new QLineEdit());
	int width2 = table3->width();
	qDebug() << width2;
	table3->setColumnWidth(0, width2 / 3);
	table3->setColumnWidth(1, (width2 / 3) * 2);

	QStandardItemModel *model3 = new QStandardItemModel();
	table4->horizontalHeader()->hide();
	table4->verticalHeader()->hide();
	table4->setModel(model3);
	table4->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	model3->setColumnCount(2);
	model3->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("测量方式"))); model3->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	model3->setItem(1, 0, new QStandardItem(QString::fromLocal8Bit("磁化模式"))); model3->item(1, 0)->setTextAlignment(Qt::AlignCenter);
	model3->setItem(2, 0, new QStandardItem(QString::fromLocal8Bit("样品形状"))); model3->item(2, 0)->setTextAlignment(Qt::AlignCenter);
	model3->setItem(3, 0, new QStandardItem(QString::fromLocal8Bit("样品规格"))); model3->item(3, 0)->setTextAlignment(Qt::AlignCenter);
	//tableview中添加控件
	QComboBox *combox4_measurmodel = new QComboBox();
	combox4_measurmodel->addItem(QString::fromLocal8Bit("手动模式"));
	combox4_measurmodel->addItem(QString::fromLocal8Bit("智能模式"));
	combox4_measurmodel->addItem(QString::fromLocal8Bit("快速模式"));
	table4->setIndexWidget(model3->index(0, 1), combox4_measurmodel);
	QComboBox *combox4_magnetization_model = new QComboBox();
	combox4_magnetization_model->addItem(QString::fromLocal8Bit("正常模式"));
	combox4_magnetization_model->addItem(QString::fromLocal8Bit("预磁化模式"));
	table4->setIndexWidget(model3->index(1, 1), combox4_magnetization_model);
	QComboBox *combox4_sample_shape = new QComboBox();
	combox4_sample_shape->addItem(QString::fromLocal8Bit("棒状"));
	combox4_sample_shape->addItem(QString::fromLocal8Bit("异形"));
	table4->setIndexWidget(model3->index(2, 1), combox4_sample_shape);
	table4->setIndexWidget(model3->index(3, 1), new QLineEdit());
	ReadOnlyDelegate* readOnlyDelegate3 = new ReadOnlyDelegate();
	table4->setItemDelegateForColumn(0, readOnlyDelegate3); //设置某列只读
	int width3 = table4->width();
	table4->setColumnWidth(0, width3 / 3);
	table4->setColumnWidth(1, (width3 / 3) * 2);

	QStandardItemModel *model5 = new QStandardItemModel();
	table5->horizontalHeader()->hide();
	table5->verticalHeader()->hide();
	table5->setModel(model5);
	table5->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	model5->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("设定磁场"))); model5->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	model5->setItem(0, 2, new QStandardItem(QString::fromLocal8Bit("A/m"))); model5->item(0, 2)->setTextAlignment(Qt::AlignCenter);
	model5->setItem(1, 0, new QStandardItem(QString::fromLocal8Bit("测量次数"))); model5->item(1, 0)->setTextAlignment(Qt::AlignCenter);
	model5->setItem(1, 2, new QStandardItem(QString::fromLocal8Bit("次"))); model5->item(1, 2)->setTextAlignment(Qt::AlignCenter);
	QString str_yanshi;
	str_yanshi.append(QString::fromLocal8Bit("延"));
	for (size_t i = 0; i < 6; i++)
	{
		str_yanshi.append(" ");
	}
	str_yanshi.append(QString::fromLocal8Bit("时"));
	model5->setItem(2, 0, new QStandardItem(str_yanshi)); model5->item(2, 0)->setTextAlignment(Qt::AlignCenter);
	model5->setItem(2, 2, new QStandardItem("ms")); model5->item(2, 2)->setTextAlignment(Qt::AlignCenter);
	model5->setColumnCount(3);
	ReadOnlyDelegate* readOnlyDelegate5 = new ReadOnlyDelegate();
	table5->setItemDelegateForColumn(0, readOnlyDelegate5); //设置某列只读
	table5->setItemDelegateForColumn(2, readOnlyDelegate5); //设置某列只读
	QComboBox *combox5_set_magnetic = new QComboBox();
	combox5_set_magnetic->addItem("10000");
	combox5_set_magnetic->addItem("20000");
	combox5_set_magnetic->addItem("30000");
	table5->setIndexWidget(model5->index(0, 1), combox5_set_magnetic);
	QComboBox *combox5_measure_times = new QComboBox();
	combox5_measure_times->addItem("1");
	combox5_measure_times->addItem("2");
	combox5_measure_times->addItem("3");
	combox5_measure_times->addItem("4");
	combox5_measure_times->addItem("5");
	combox5_measure_times->addItem("6");
	combox5_measure_times->addItem("7");
	combox5_measure_times->addItem("8");
	combox5_measure_times->addItem("9");
	combox5_measure_times->addItem("10");
	table5->setIndexWidget(model5->index(1, 1), combox5_measure_times);
	table5->setIndexWidget(model5->index(2, 1), new QLineEdit());
	int width5 = table5->width();
	table5->setColumnWidth(0, (width5 / 6) * 2 + 1);
	table5->setColumnWidth(1, (width5 / 6) * 3 - 3);
	table5->setColumnWidth(2, (width5 / 6) + 5);

	QStandardItemModel *model4 = new QStandardItemModel();
	table6->horizontalHeader()->hide();
	table6->verticalHeader()->hide();
	table6->setModel(model4);
	table6->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	model4->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("预估范围"))); model4->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	model4->setItem(0, 2, new QStandardItem(QString::fromLocal8Bit("~"))); model4->item(0, 2)->setTextAlignment(Qt::AlignCenter);
	model4->setItem(0, 4, new QStandardItem(QString::fromLocal8Bit("A/m"))); model4->item(0, 4)->setTextAlignment(Qt::AlignCenter);
	model4->setColumnCount(5);
	ReadOnlyDelegate* readOnlyDelegate4 = new ReadOnlyDelegate();
	table6->setItemDelegateForColumn(0, readOnlyDelegate4); //设置某列只读
	table6->setItemDelegateForColumn(2, readOnlyDelegate4); //设置某列只读
	table6->setItemDelegateForColumn(4, readOnlyDelegate4); //设置某列只读
	table6->setIndexWidget(model4->index(0, 1), new QLineEdit());
	table6->setIndexWidget(model4->index(0, 3), new QLineEdit());
	int width4 = table6->width();
	table6->setColumnWidth(0, (width4 / 6) * 2);
	table6->setColumnWidth(1, (width4 / 6));
	table6->setColumnWidth(2, (width4 / 6));
	table6->setColumnWidth(3, (width4 / 6) - 2);
	table6->setColumnWidth(4, (width4 / 6) + 5);

	QStandardItemModel *model6 = new QStandardItemModel();
	table7->horizontalHeader()->hide();
	table7->verticalHeader()->hide();
	table7->setModel(model6);
	table7->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
	model6->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("上限值"))); model6->item(0, 0)->setTextAlignment(Qt::AlignCenter);
	model6->setItem(0, 2, new QStandardItem(QString::fromLocal8Bit("下限值"))); model6->item(0, 2)->setTextAlignment(Qt::AlignCenter);
	model6->setColumnCount(4);
	ReadOnlyDelegate* readOnlyDelegate6 = new ReadOnlyDelegate();
	table7->setItemDelegateForColumn(0, readOnlyDelegate6); //设置某列只读
	table7->setItemDelegateForColumn(2, readOnlyDelegate6); //设置某列只读
	table7->setIndexWidget(model6->index(0, 1), new QLineEdit());
	table7->setIndexWidget(model6->index(0, 3), new QLineEdit());
	int width6 = table7->width();
	table7->setColumnWidth(0, (width6 / 6) * 2);
	table7->setColumnWidth(1, (width6 / 6));
	table7->setColumnWidth(2, (width6 / 6) * 2 - 1);
	table7->setColumnWidth(3, (width6 / 6) + 4);
	//"border:rgb(230, 230, 230);} "
	"QTableView::tab:selected{color: black;background-color:rbg(100,200,255);} ";
	QString str =
		"gridline-color: rgb(230, 230, 230);"
		"border:rgb(230, 230, 230);"
		"selection-background-color:white;"
		"selection-color:rgb(0,0,0);"
		;
	table1->setStyleSheet(str);
	table2->setStyleSheet(str);
	table3->setStyleSheet(str);
	table4->setStyleSheet(str);
	table5->setStyleSheet(str);
	table6->setStyleSheet(str);
	table7->setStyleSheet(str);
}

initLayout::~initLayout()
{
	
}
