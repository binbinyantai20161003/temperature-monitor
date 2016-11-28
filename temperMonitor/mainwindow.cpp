#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globaldef.h"


MainWindow::MainWindow(QSplashScreen *screen,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化界面包括树等
    initialUi();
    createConnections();

    //设置窗口标题
    setWindowTitle(QString::fromWCharArray(L"googoltech"));//深圳东河仪表软件有限公司
    //窗口输出最大化
    showMaximized();//setWindowState(Qt::WindowMaximized);是一样的功能
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialUi()
{
    m_connect = NULL;
    m_channelCfg = NULL;

    QWidget *stackWidget=NULL;
    //删除多余的widget
    while(ui->stackedWidget->count()>0)
    {
      stackWidget=ui->stackedWidget->currentWidget();
      ui->stackedWidget->removeWidget(stackWidget);
    }
    //清空treeWidget
    ui->treeWidget->clear();
    //隐藏树结构的头
    //ui->treeWidget->setHeaderHidden(true);

    // Set the headers
    ui->treeWidget->setHeaderLabels(QStringList(QString::fromWCharArray(L"导航栏")));

    // Set the number of columns in the tree
    ui->treeWidget->setColumnCount(1);

    //初始化树结构
    //根结点1
    QTreeWidgetItem * tmp;
    tmp = addTreeRoot(QString::fromWCharArray(L"配置"),QIcon(RESOURCE_FILE_PATH+ICON_CONFIGTREE));
    addTreeChild(tmp,QString::fromWCharArray(L"通信配置"),QIcon(RESOURCE_FILE_PATH+ICON_CHILD));
    addTreeChild(tmp,QString::fromWCharArray(L"通道配置"),QIcon(RESOURCE_FILE_PATH+ICON_CHILD));

    //根结点2
    tmp = addTreeRoot(QString::fromWCharArray(L"数据"),QIcon(RESOURCE_FILE_PATH+ICON_CONFIGTREE));
    addTreeChild(tmp,QString::fromWCharArray(L"实时数据"),QIcon(RESOURCE_FILE_PATH+ICON_CHILD));
    addTreeChild(tmp,QString::fromWCharArray(L"数据波形"),QIcon(RESOURCE_FILE_PATH+ICON_CHILD));

    //根结点3
    tmp = addTreeRoot(QString::fromWCharArray(L"设备"),QIcon(RESOURCE_FILE_PATH+ICON_CONFIGTREE));

    //设置当前的item
    ui->treeWidget->setCurrentItem(ui->treeWidget->topLevelItem(0)->child(0));
    //展开所有
    ui->treeWidget->expandAll();
    //列宽度按照内容给定设置
    ui->treeWidget->resizeColumnToContents(0);
}

void MainWindow::createConnections()
{
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(onTreeWidgetItemClicked(QTreeWidgetItem*,int)));
}

QTreeWidgetItem * MainWindow::addTreeRoot(QString name,QIcon icon)
{
   QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

   // QTreeWidgetItem::setText(int column, const QString & text)
   treeItem->setText(0, name);
   treeItem->setIcon(0,icon);
   return treeItem;
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent, QString name,QIcon icon)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setIcon(0,icon);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
}
void MainWindow::onTreeWidgetItemClicked(QTreeWidgetItem *item, int column)
{
    /*切换页面*/

    QString st;
    st  =   item->text(0);
    int index;
    /////////////////////////////////////////////////////////////

    if(st == QString::fromWCharArray(L"通信配置"))
    {
        index = 0;
        if(m_connect == NULL)
        {
            m_connect = new ConnectDlg();

            ui->stackedWidget->insertWidget(index,m_connect);
            ui->stackedWidget->setCurrentIndex(index);
            ui->stackedWidget->setCurrentWidget(m_connect);

        }
        else
        {
            ui->stackedWidget->setCurrentIndex(index);
            ui->stackedWidget->setCurrentWidget(m_connect);
        }
        ui->stackedWidget->currentWidget()->setVisible(true);
    }
    else
    {
        index = 0;
        int now;
        now = ui->stackedWidget->currentIndex();
        if(now == index)
        {
           ui->stackedWidget->currentWidget()->hide();
        }
    }

    /////////////////////////////////////////////////////////////
    if(st == QString::fromWCharArray(L"通道配置"))
    {
        index = 1;
        if(m_channelCfg == NULL)
        {
            m_channelCfg = new ChannelConfig();

            ui->stackedWidget->insertWidget(index,m_channelCfg);
            ui->stackedWidget->setCurrentIndex(index);
            ui->stackedWidget->setCurrentWidget(m_channelCfg);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(index);
            ui->stackedWidget->setCurrentWidget(m_channelCfg);
        }
        ui->stackedWidget->currentWidget()->setVisible(true);
    }
    else
    {
        index = 1;
        int now;
        now = ui->stackedWidget->currentIndex();
        if(now == index)
        {
           ui->stackedWidget->currentWidget()->hide();
        }
    }
    /////////////////////////////////////////////////////////////

}
