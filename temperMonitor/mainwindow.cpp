#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSplashScreen *screen,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showMaximized();//setWindowState(Qt::WindowMaximized);是一样的功能
}

MainWindow::~MainWindow()
{
    delete ui;
}
