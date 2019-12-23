#pragma once

#include <QWidget>
#include "ui_test_statistics.h"

class test_statistics : public QWidget
{
	Q_OBJECT

public:
	test_statistics(QWidget *parent = Q_NULLPTR);
	~test_statistics();

private:
	Ui::test_statistics ui;
};
