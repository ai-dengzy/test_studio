#pragma once

#include <QWidget>
#include "ui_SettingOption.h"
#include <qstandarditemmodel.h>
#include <qmessagebox.h>
#include <QWidget>
#include "ReadOnlyDelegate.h"
#include <QFileDialog>
namespace Ui { class SettingOption; };
class SettingOption : public QWidget
{
	Q_OBJECT

public:
	SettingOption(QWidget *parent = Q_NULLPTR);
	~SettingOption();

private:
	Ui::SettingOption ui;
};
