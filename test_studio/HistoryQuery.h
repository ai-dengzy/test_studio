#pragma once

#include <QWidget>
#include "ui_HistoryQuery.h"
#include "sqldb.h"
class HistoryQuery : public QWidget
{
	Q_OBJECT

public:
	HistoryQuery(QWidget *parent = Q_NULLPTR);

	sqldb datebase;

	~HistoryQuery();

private:
	Ui::HistoryQuery ui;
};
