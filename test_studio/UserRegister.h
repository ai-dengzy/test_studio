#pragma once

#include <QWidget>
#include "ui_UserRegister.h"
#include <QFileDialog>
class UserRegister : public QWidget
{
	Q_OBJECT

public:
	UserRegister(QWidget *parent = Q_NULLPTR);
	~UserRegister();

private:
	Ui::UserRegister ui;
};
