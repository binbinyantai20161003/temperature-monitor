#include "channelconfig.h"
#include "ui_channelconfig.h"
#include <QAbstractTableModel>

ChannelConfig::ChannelConfig(QWidget *parent):QWidget(parent),ui(new Ui::ChannelConfig)
{
    ui->setupUi(this);
    initUi();
}

ChannelConfig::~ChannelConfig()
{
    delete ui;
}

void ChannelConfig::initUi()
{
    int row  = 100;
    int col  = 16;
    ui->tableWidget->setRowCount(row);     //设置行数为100
    ui->tableWidget->setColumnCount(col);   //设置列数为16
    ui->tableWidget->setWindowTitle(QString::fromWCharArray(L"通道配置"));
    ui->tableWidget->verticalHeader()->setHidden(true); //隐藏行号
    ui->tableWidget->horizontalHeader()->setHidden(true); //隐藏列号

    //合并表头，因为表头不好做合并，所以隐藏表头，用下面两个作为表头使用
    ui->tableWidget->setSpan(0,1,1,2);
    ui->tableWidget->setSpan(0,3,1,4);
    ui->tableWidget->setSpan(0,7,1,4);
    ui->tableWidget->setSpan(0,11,1,5);
    //////////////////////////////////////////////////////////////////////
    //第一行
    QTableWidgetItem* tmp = new QTableWidgetItem(QString::fromWCharArray(L"通道"));
    ui->tableWidget->setItem(0,0,tmp);
    ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem* tmp1 = new QTableWidgetItem(QString::fromWCharArray(L"启用通道"));
    ui->tableWidget->setItem(0,1,tmp1);
    ui->tableWidget->item(0,1)->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem* tmp2 = new QTableWidgetItem(QString::fromWCharArray(L"测量"));
    ui->tableWidget->setItem(0,3,tmp2);
    ui->tableWidget->item(0,3)->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem* tmp3 = new QTableWidgetItem(QString::fromWCharArray(L"定标{Mx+B}"));
    ui->tableWidget->setItem(0,7,tmp3);
    ui->tableWidget->item(0,7)->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem* tmp4 = new QTableWidgetItem(QString::fromWCharArray(L"报警限值"));
    ui->tableWidget->setItem(0,11,tmp4);
    ui->tableWidget->item(0,11)->setTextAlignment(Qt::AlignCenter);

    /////////////////////////////////////////////////////////////////
    //第二行
    QTableWidgetItem* tmp10 = new QTableWidgetItem(QString::fromWCharArray(L"仪器"));
    ui->tableWidget->setItem(1,0,tmp10);
    QTableWidgetItem* tmp11 = new QTableWidgetItem(QString::fromWCharArray(L"扫描"));
    ui->tableWidget->setItem(1,1,tmp11);
    QTableWidgetItem* tmp12 = new QTableWidgetItem(QString::fromWCharArray(L"名称"));
    ui->tableWidget->setItem(1,2,tmp12);
    QTableWidgetItem* tmp13 = new QTableWidgetItem(QString::fromWCharArray(L"功能"));
    ui->tableWidget->setItem(1,3,tmp13);
    QTableWidgetItem* tmp14 = new QTableWidgetItem(QString::fromWCharArray(L"量程"));
    ui->tableWidget->setItem(1,4,tmp14);
    QTableWidgetItem* tmp15 = new QTableWidgetItem(QString::fromWCharArray(L"分辨率"));
    ui->tableWidget->setItem(1,5,tmp15);
    QTableWidgetItem* tmp16 = new QTableWidgetItem(QString::fromWCharArray(L"更多"));
    ui->tableWidget->setItem(1,6,tmp16);
    QTableWidgetItem* tmp17 = new QTableWidgetItem(QString::fromWCharArray(L"定标"));
    ui->tableWidget->setItem(1,7,tmp17);
    QTableWidgetItem* tmp18 = new QTableWidgetItem(QString::fromWCharArray(L"增益{M}"));
    ui->tableWidget->setItem(1,8,tmp18);
    QTableWidgetItem* tmp19 = new QTableWidgetItem(QString::fromWCharArray(L"偏移{B}"));
    ui->tableWidget->setItem(1,9,tmp19);
    QTableWidgetItem* tmp110 = new QTableWidgetItem(QString::fromWCharArray(L"标签"));
    ui->tableWidget->setItem(1,10,tmp110);
    QTableWidgetItem* tmp111 = new QTableWidgetItem(QString::fromWCharArray(L"测试"));
    ui->tableWidget->setItem(1,11,tmp111);
    QTableWidgetItem* tmp112 = new QTableWidgetItem(QString::fromWCharArray(L"低"));
    ui->tableWidget->setItem(1,12,tmp112);
    QTableWidgetItem* tmp113 = new QTableWidgetItem(QString::fromWCharArray(L"高"));
    ui->tableWidget->setItem(1,13,tmp113);
    QTableWidgetItem* tmp114 = new QTableWidgetItem(QString::fromWCharArray(L"硬件报警"));
    ui->tableWidget->setItem(1,14,tmp114);
    QTableWidgetItem* tmp115 = new QTableWidgetItem(QString::fromWCharArray(L"更多"));
    ui->tableWidget->setItem(1,15,tmp115);

    ui->tableWidget->show();
}
//QVariant ChannelConfig::data( const QModelIndex &index, int role ) const
//{
//   if (role == Qt::CheckStateRole)
//   {
//        if (index.column() == colNumberWithCheckBox)
//        {
//            if (rowCheckStateMap.contains(index.row()))
//            {
//                return rowCheckStateMap[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked;
//            }
//            return Qt::Unchecked;
//        }
//   }
//   return QVariant();
//}
//Qt::ItemFlags ChannelConfig::flags( const QModelIndex &index ) const
//{
//    if(!index.isValid())
//    {
//            return 0;
//    }
//    if (index.column() == colNumberWithCheckBox)
//    {
//        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
//    }
//    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable;
//}
//bool ChannelConfig::setData( const QModelIndex &index, const QVariant &value, int role )
//{
//    if(!index.isValid())
//        return false;

//    if (role == Qt::CheckStateRole && index.column() == colNumberWithCheckBox)
//    {
//        if (value == Qt::Checked) //
//        {
//            rowCheckStateMap[index.row()] = Qt::Checked;
//            if(Vcfg.size() > index.row())
//            {
//                emit ScanIsChecked();
//            }
//            else
//            {
//                rowCheckStateMap[index.row()] = Qt::Unchecked;
//            }
//        }
//        return true;
//    }
//}

