/*
 * @Author: HK560
 * @Date: 2022-02-25 16:02:05
 * @LastEditTime: 2022-02-25 17:24:50
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\argsdediconfig.h
 */
#ifndef ARGSDEDICONFIG_H
#define ARGSDEDICONFIG_H
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

class ArgsDediConfig
{
public:
    ArgsDediConfig();

    QString otherArgs;
    QMap<QString,QString> argsMap;
    QMap<QString,bool> argsSetMap;


    bool writeToArgs();
    bool readFromArgs();
    bool writeToSaveFile(QFileInfo file);//写入到保存的配置文件
    bool readFromSaveFile(QFileInfo file);//读入到保存的配置文件
    bool setArgsValue(QString name,QString value);//设置参数值
    void setFilePath(QFileInfo path);//设置文件路径
    void argsReset();//恢复默认设置
    void setOtherArgsValue(QString text);//设置其他参数
    
    QStringList argsNameList{
        "+setplaylist",
        "-port",
        "+mp_gamemode",
        "-maxplayersplaylist",
        "+setplaylistvaroverrides",
    };

private:
   QFileInfo filePath;//cfg文件路径
};

#endif // ARGSDEDICONFIG_H
