#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplashScreen>
#include <QTreeWidget>
#include "connectdlg.h"
#include "channelconfig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QSplashScreen *screen,QWidget *parent = 0);
    ~MainWindow();
    ConnectDlg* m_connect;
    ChannelConfig* m_channelCfg;

private:
    Ui::MainWindow *ui;
    void initialUi(void);
    void createConnections();
    QTreeWidgetItem* addTreeRoot(QString name,QIcon icon);
    void addTreeChild(QTreeWidgetItem *parent,QString name,QIcon icon);

public slots:
  void onTreeWidgetItemClicked(QTreeWidgetItem *item,int column);
};

#endif // MAINWINDOW_H
