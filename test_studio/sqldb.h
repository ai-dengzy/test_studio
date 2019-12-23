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
	//������Ʒ��������
	void saveSql(int id, QString num,QString name, QString batch, QString material, QString temperature, QString tester,
		QString date, QString remarks, QString measure_method, QString magnetization_model,
		QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay,
		QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom);
	//������Ʒ��������
	void updateSql(int id, QString num, QString name, QString batch, QString material, QString temperature, QString tester,
		QString date, QString remarks, QString measure_method, QString magnetization_model,
		QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay,
		QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom);
	//�����������
	void saveTestSql(QString num, QString name, QString batch, QString material, QString temperature, QString tester,
		QString date, QString remarks, QString measure_method, QString magnetization_model,
		QString sample_shape, QString sample_specification, QString set_magnetization, QString measure_times, QString delay,
		QString estimate_1, QString estimate_2, QString limit_top, QString limit_bottom, QString Hc, QString Hm);
	//չʾ��������
	void showData(QTableView *table1, QTableView *table2, QTableView *table3, QTableView *table4, QTableView *table5, QTableView *table6, QTableView *table7);
	
	void showInfo(Ui::test_studioClass &ui);//չʾ10�ֲ�����Ʒ�Ĳ�������
	bool queryId(int table_index);//��ѯID
	void querySaveTestDate(Ui::test_studioClass &ui_);//��ҳ��ѯ��������չʾ
	void querySaveTestDate(Ui::HistoryQuery &ui_);//��ʷ��ѯҳ�桪������ѯ ��ѯ��������չʾ
	void showStandard_Avg(QTableView *qtw);//������ѯ����ʾ��׼���ƽ��ֵ
	void queryCondition(QTableWidget *qtw,QString start_time,QString end_time,QString sample_name, QString num,QString param,QString bottom_param,QString top_param);//������ѯ
	QList<long> qlist_H;
	QList<long> qlist_Hc;
	QList<long> qlist_Hm;
	long getAvgFromData(QList<long>);//��ƽ��ֵ
	long getVarianceFromData(QList<long> qlist,long avg);//�󷽲�
	~sqldb();
};