/*
 * @Author: HK560
 * @Date: 2022-02-24 18:03:48
 * @LastEditTime: 2022-02-24 19:58:34
 * @LastEditors: HK560
 * @Description:
 * @FilePath: \NorthStarCN_WIKId:\github\ttf\NorthStarServerSettingEXE\src\argsdediconfig.cpp
 * \NorthStarCN_WIKId:\github\ttf\NorthStarServerSettingEXE\src\argsdediconfig.cpp
 */
#include "argsdediconfig.h"

ArgsDediConfig::ArgsDediConfig() {
    argsMap.insert("+setplaylist","private_match");
    argsMap.insert("-port","");
    argsMap.insert("+mp_gamemode","");
    argsMap.insert("-maxplayersplaylist","");

    argsMap.insert("+setplaylistvaroverrides","");
    argsMap.insert("max_players","");
    argsMap.insert("custom_air_accel_pilot","");
    argsMap.insert("timelimit","");
    argsMap.insert("scorelimit","");
    argsMap.insert("roundtimelimit","");
    argsMap.insert("roundscorelimit","");
    argsMap.insert("respawn_delay","");
    argsMap.insert("pilot_health_multiplier","");

    argsMap.insert("boosts_enabled","");
    
}

bool ArgsDediConfig::writeToArgs() { return true; }

bool ArgsDediConfig::readFromArgs() {
    qDebug() << "readFromArgs";

    QFileInfo file = this->filePath;
    Q_ASSERT(file.isReadable());

    QTextCodec *codec = QTextCodec::codecForName("UTF8");

    otherArgs.clear();
    QFile argsFile;
    argsFile.setFileName(file.fileName());

    if (argsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //        QTextStream in(&argsFile);
        // while (!argsFile.atEnd()) {
        QString lineText = codec->toUnicode(argsFile.readLine());//读行
        lineText = lineText.simplified();
        if (!lineText.isEmpty()) {
            // QStringList nowlineList=lineText.split(rx);
            rxCliName.indexIn(lineText, 0);
            rxCliValue.indexIn(lineText, 0);
            QString cliName = rxCliName.cap(0);
            QString cliValue = rxCliValue.cap(0);
            cliValue.replace(QRegExp("\""), "");
            qDebug() << cliName << cliValue;
            if (!setConfigValue(cliName, cliValue)) {
                setOtherConfigValue(lineText);
            };
            // }
        }

    } else {
        qDebug() << "打开失败";
        QMessageBox::warning(
            NULL, "错误",
            QString("无法打开%1\n读取配置失败！").arg(argsFile.fileName()));
    }

    return true;
}

bool ArgsDediConfig::writeToSaveFile(QFileInfo file) { return true; }

bool ArgsDediConfig::readFromSaveFile(QFileInfo file) { return true; }

bool ArgsDediConfig::setArgsValue(QString name, QString value) { return true; }

void ArgsDediConfig::setFilePath(QFileInfo path) { this->filePath = path; }

void ArgsDediConfig::argsReset() {}

void ArgsDediConfig::setOtherArgsValue(QString text) {}