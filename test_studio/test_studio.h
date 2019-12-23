#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_test_studio.h"
#include "test_statistics.h"
#include "ReadOnlyDelegate.h"
#include "QtSon.h"
#include "SettingOption.h"
#include "HistoryQuery.h"
#include "HelpAbout.h"
#include "UserRegister.h"
#include "sqldb.h"
#include <QFileDialog>
#include "initLayout.h"
class test_studio : public QMainWindow
{
	Q_OBJECT
	
public:
	test_studio(QWidget *parent = Q_NULLPTR);
	~test_studio();

	enum SAVE_TYPE { SAVE_MEASURE=0, OPEN_TEST=1};//定义枚举类型weekday
	int SAVE_TYPE_INT=0;
	void showchart();
	void on_FileButton_clicked();
	void executesql();
	void saveMeasureDataSql(QTableView *table1, QTableView *table2, QTableView *table3, QTableView *table4, QTableView *table5, QTableView *table6, QTableView *table7);
	void gotoSave();
	int GetRandomNumber();

	Ui::test_studioClass ui;
	test_statistics *statistics;
	QtSon *son;
	SettingOption *setting_option;
	HistoryQuery *history_query;
	HelpAbout *help_about;
	UserRegister *userRegister;
	sqldb datebase;
	int table_index;//当前选择的样品页面索引
};
