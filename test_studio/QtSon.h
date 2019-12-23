#pragma once
#include <qstandarditemmodel.h>
#include <qmessagebox.h>
#include <QWidget>
#include "ReadOnlyDelegate.h"
#include <QFileDialog>
namespace Ui { class QtSon; };

class QtSon : public QWidget
{
	Q_OBJECT

public:
	QStandardItemModel *model_pararesult = new QStandardItemModel();

	QtSon(QWidget *parent = Q_NULLPTR);
	
	void addRowParaResult();
	
	~QtSon();

	
private:
	Ui::QtSon *ui;
};
