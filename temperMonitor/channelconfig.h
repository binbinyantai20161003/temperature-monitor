#ifndef CHANNELCONFIG_H
#define CHANNELCONFIG_H

#include <QWidget>
#include <QMap>

namespace Ui {
class ChannelConfig;
}

typedef struct CHANNELCFGST
{
    QString device;
    Qt::ItemFlags scan;
    QString name;
    Qt::ItemFlags calibrate;
}ChannelCfgSt;

class ChannelConfig : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelConfig(QWidget *parent = 0);
    ~ChannelConfig();

public:
    //void AddCfgInfo(const ChannelCfgSt& cfg);

    void initUi();

//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

//    //设置某一列为可选角色，绘画出QCheckBox
//    Qt::ItemFlags flags(const QModelIndex &index) const;

//    //根据界面选择QCheckbox，修改Model中的数据
//    bool setData(const QModelIndex &index, const QVariant &value, int role);

//signals:
//    void ScanIsChecked();

private:
    Ui::ChannelConfig *ui;
//    int totalColumn;
//    int colNumberWithCheckBox;
//    QMap<int, Qt::CheckState> rowCheckStateMap;

//    //定义表格中数据结构
//    typedef QVector<ChannelCfgSt> VecChannelCfgSt;
//    VecChannelCfgSt Vcfg;

};

#endif // CHANNELCONFIG_H
