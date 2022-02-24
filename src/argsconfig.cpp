/*
 * @Author: HK560
 * @Date: 2022-02-23 16:10:13
 * @LastEditTime: 2022-02-24 19:31:44
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKId:\github\ttf\NorthStarServerSettingEXE\src\argsconfig.cpp
 */
#include "argsconfig.h"

ArgsConfig::ArgsConfig()
{
    // 
}

bool ArgsConfig::writeToArgs()
{
    return true;

}

bool ArgsConfig::readFromArgs()
{
    qDebug() << "readFromArgs";

    return true;
}

bool ArgsConfig::writeToSaveFile(QFileInfo file)
{
    return true;
}

bool ArgsConfig::readFromSaveFile(QFileInfo file)
{
    return true;
}

bool ArgsConfig::setArgsValue(QString name, QString value)
{
    return true;
}

void ArgsConfig::setFilePath(QFileInfo path)
{
    this->filePath = path;
}

void ArgsConfig::argsReset()
{

}

void ArgsConfig::setOtherArgsValue(QString text)
{

}
