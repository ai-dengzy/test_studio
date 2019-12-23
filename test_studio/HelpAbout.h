#pragma once

#include <QWidget>
#include <qpixmap.h>
#include "ui_HelpAbout.h"
#include "qmovie.h"

class HelpAbout : public QWidget
{
	Q_OBJECT

public:
	HelpAbout(QWidget *parent = Q_NULLPTR);
	~HelpAbout();

private:
	Ui::HelpAbout ui;
};
