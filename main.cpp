#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QTranslator>
#include <QDebug>
#include <QList>
#include <QListWidgetItem>
#include <QMetaType>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    a.setFont(QFont("WenQuanYi Zen Hei", 12));
    qApp->setFont(QFont("WenQuanYi Zen Hei", 12));

    //call format:QTranslator::load(filename,directory, delim, suffix )
    QTranslator translator(0);
    bool ret = translator.load("filemanager_zh",":/fonts/",".","qm");
    a.installTranslator(&translator);
    qDebug()<<"load filemanager_zh ok;";

    QTranslator qttranslator(0);
    ret = qttranslator.load("qt_zh_CN",":/fonts/",".","qm");
    a.installTranslator(&qttranslator);
    qDebug()<<"load qt_zh_CN ok;";

    QTranslator fileinfotranslator(0);
    ret = fileinfotranslator.load("qfile_zh",":/fonts/",".","qm");
    a.installTranslator(&fileinfotranslator);
    qDebug()<<"load qfile_zh ok;";

    qRegisterMetaType<QList<QListWidgetItem*> >("QList<QListWidgetItem*>");

    MainWindow w;
    w.show();
    return a.exec();
}
