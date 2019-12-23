#include "HelpAbout.h"

HelpAbout::HelpAbout(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QMovie *movie = new QMovie(":/test_studio/Resources/linkjoin_icon.jpg");
	ui.label->setMovie(movie);
	movie->start();

	//ui.label->setPixmap(QPixmap(":/test_studio/Resources/linkjoin_icon.jpg"));
	ui.label->setScaledContents(true);
	//ui.textBrowser->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");
	ui.textBrowser->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");
	//ÉèÖÃ±³¾°Í¸Ã÷
	QPalette palette = ui.textBrowser->palette();
	palette.setBrush(QPalette::Base, QBrush(Qt::NoBrush));
	ui.textBrowser->setPalette(palette);
}

HelpAbout::~HelpAbout()
{

}
