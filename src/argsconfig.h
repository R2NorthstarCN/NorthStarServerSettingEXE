/*
 * @Author: HK560
 * @Date: 2022-02-23 16:10:12
 * @LastEditTime: 2022-02-24 17:08:47
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\argsconfig.h
 */
#ifndef ARGSCONFIG_H
#define ARGSCONFIG_H
#include<QString>
#include<QVector>
#include<QFileInfo>
#include<QStringList>
#include<QDebug>
#include<QTextCodec>
#include <QRegularExpression>
#include <QRegExp>
#include<QMap>
#include<QSettings>
#include<QMessageBox>
#include"define.h"

class ArgsConfig
{
public:
    ArgsConfig();

    QMap<QString,QString> argsMap;
    QString otherCli;

    bool writeToArgs();
    bool readFromArgs();
    bool writeToSaveFile(QFileInfo file);//写入到保存的配置文件
    bool readFromSaveFile(QFileInfo file);//读入到保存的配置文件
    bool setArgsValue(QString name,QString value);//设置参数值
    void setFilePath(QFileInfo path);//设置文件路径
    void argsReset();//恢复默认设置
    void setOtherArgsValue(QString text);//设置其他参数
    
private:
   QFileInfo filePath;//cfg文件路径
};

#endif // ARGSCONFIG_H
