//*************************//
//用于获取url.xml 		//
//得到电影路径			//
//*************************//

#include "open.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QStringList>
const static QString URLFRONT = "http://10.168.200.1/mov/";
const static QString URLBACK = "/url.xml";
const static QString FILEPATH = "../url.xml";
const static QString BASEFILEPATH = "../Total.xml";

int main(int argc,char* argv[])
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	printf("kx ^_^...\n");
	QApplication a(argc,argv);
	open o;
	o.setbasefile(BASEFILEPATH);
	QStringList r = o.find(argv[1]);
	
	if(r.size() != 1)
	{
		qDebug()<<r.size();
		qDebug()<<"find failed.";
		qApp->exit();
	}
	o.geturlxml(URLFRONT + r.at(0) + URLBACK,FILEPATH);
	printf("geturl ok\n");
	return a.exec();	
}



