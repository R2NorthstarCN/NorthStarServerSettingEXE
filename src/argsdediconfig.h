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

#endif // ARGSDEDICONFIG_H
