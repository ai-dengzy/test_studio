#include "test_studio.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test_studio w;
	w.show();
	return a.exec();
}
