/*
 * @Author: HK560
 * @Date: 2022-01-14 19:06:51
 * @LastEditTime: 2022-01-16 13:33:15
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\serverconfig.cpp
 */
#include "serverconfig.h"

ServerConfig::ServerConfig()
{

}

bool ServerConfig::writeToCfg(QFileInfo file)
{
    return true;
}

bool ServerConfig::readFromCfg(QFileInfo file)
{   
    qDebug()<<"readFromcfg";
    
    Q_ASSERT(file.isReadable());
    QTextCodec *codec = QTextCodec::codecForName("UTF8");
    QFile configfile;
    configfile.setFileName(file.filePath());
    qDebug() << configfile.fileName();
    if (configfile.open(QIODevice::ReadWrite|QIODevice::Text))
    {
//        QTextStream in(&configfile);
        while(!configfile.atEnd()){
            QString lineText=codec->toUnicode(configfile.readLine());
            lineText=lineText.simplified();
            QStringList nowlineList=lineText.split(" ");
            qDebug()<<nowlineList;
        }

    }
    else qDebug() << "打开失败";
    


    return true;
}

bool ServerConfig::writeToSaveFile(QFileInfo file)
{
    return true;
}

bool ServerConfig::readFromSaveFile(QFileInfo file)
{
    return true;
}
