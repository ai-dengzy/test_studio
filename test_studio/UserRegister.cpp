#include "UserRegister.h"

UserRegister::UserRegister(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle(QString::fromLocal8Bit("ÓÃ»§×¢²á(213049876-H3366117600)"));
	connect(ui.pushButton_register, &QPushButton::clicked, this, [=]() {
		this->close();
	});
	connect(ui.pushButton_cancel, &QPushButton::clicked, this, [=]() {
		this->close();
	});
}

UserRegister::~UserRegister()
{
}
