#include "SettingOption.h"

SettingOption::SettingOption(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("ÉèÖÃ"));
	connect(ui.pushButton_ok, &QPushButton::clicked, this, [=]() {
		this->close();
	});
	connect(ui.pushButton_cancel, &QPushButton::clicked, this, [=]() {
		this->close();
	});
}

SettingOption::~SettingOption()
{

}
