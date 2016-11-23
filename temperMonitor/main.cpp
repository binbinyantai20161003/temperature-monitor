#include "mainwindow.h"

//add start
//for startup picture
#include <QSplashScreen>
#include "globaldef.h"
#include <QDateTime>
#include <QDebug>
//add end

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /////////////////////////////////////////////////////////////
    //add start
    //for startup picture
    QSplashScreen *splashScreen = new QSplashScreen;
    QString pic = RESOURCE_FILE_PATH+ICON_STARTUP;
    QPixmap map(pic);
    splashScreen->setPixmap(map);
    splashScreen->showMessage("LOVE",Qt::AlignCenter, Qt::red);
    splashScreen->show();
    //add end
    /////////////////////////////////////////////////////////////




    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        a.processEvents();
    } while (n.secsTo(now)<=1);//2为需要延时的秒数

    MainWindow *w=new MainWindow(splashScreen,0);
    w->show();

    /////////////////////////////////////////////////////////////
    //add start
    //close startup picture
    splashScreen->finish(w);
    delete splashScreen;
    //add end
    /////////////////////////////////////////////////////////////

    return a.exec();
}
