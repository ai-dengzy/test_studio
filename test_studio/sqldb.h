#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QDebug>
#include <iostream>
#include <QSqlQueryModel> 
#include <QList> 
#include <QSqlTableModel> 
#include "ui_test_studio.h"
#include "ui_HistoryQuery.h"
#include "ReadOnlyDelegate.h"
#include<numeric>
#include<cmath>
#pragma once
class sqldb
{
	
public:
	sqldb();
	QSqlQuery *query;
	Ui::test_studioClass ui;
	Ui::HistoryQuery history_query_ui;
	QSqlDatabase db1;
	bool commitDB(QSqlQuery& qsQuery);
	//保存样品测量参数
	void saveSql(int id, QString num,QString name, QString batch, QString material, QString temperature, QString tester,
		QString date, QString remarks, QString measure_method, QString magnetization_model,
		QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay,
		QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom);
	//更新样品测量参数
	void updateSql(int id, QString num, QString name, QString batch, QString material, QString temperature, QString tester,
		QString date, QString remarks, QString measure_method, QString magnetization_model,
		QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay,
		QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom);
	//保存测试数据
	void saveTestSql(QString num, QString name, QString batch, QString material, QString temperature, QString tester,
		QString date, QString remarks, QString measure_method, QString magnetization_model,
		QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay,
		QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom, QString Hc, QString Hm);
	//展示测量数据
	void showData(QTableView *table1, QTableView *table2, QTableView *table3, QTableView *table4, QTableView *table5, QTableView *table6, QTableView *table7);
	
	void showInfo(Ui::test_studioClass &ui);//展示10种测试样品的测量参数
	bool queryId(int table_index);//查询ID
	void querySaveTestDate(Ui::test_studioClass &ui_);//首页查询测试数据展示
	void querySaveTestDate(Ui::HistoryQuery &ui_);//历史查询页面—条件查询 查询测试数据展示
	void showStandard_Avg(QTableView *qtw);//条件查询中显示标准差和平均值
	void queryCondition(QTableWidget *qtw,QString start_time,QString end_time,QString sample_name, QString num,QString param,QString bottom_param,QString top_param);//条件查询
	QList<long> qlist_H;
	QList<long> qlist_Hc;
	QList<long> qlist_Hm;
	long getAvgFromData(QList<long>);//求平均值
	long getVarianceFromData(QList<long> qlist,long avg);//求方差
	~sqldb();
};