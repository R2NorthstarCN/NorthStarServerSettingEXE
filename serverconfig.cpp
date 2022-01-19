/*
 * @Author: HK560
 * @Date: 2022-01-14 19:06:51
 * @LastEditTime: 2022-01-19 11:29:01
 * @LastEditors: HK560
 * @Description:
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\serverconfig.cpp
 * \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\serverconfig.cpp
 */
#include "serverconfig.h"

ServerConfig::ServerConfig() {
    cliMap.insert("ns_server_name", "[CN]Server");
    cliMap.insert("ns_server_desc", "Welcome everyone");
    cliMap.insert("ns_server_password", "");
    cliMap.insert("ns_report_server_to_masterserver", "1");
    cliMap.insert("ns_report_sp_server_to_masterserver", "0");
    cliMap.insert("ns_auth_allow_insecure", "0");
    cliMap.insert("ns_erase_auth_info", "1");
    cliMap.insert("ns_player_auth_port", "8081");
    cliMap.insert("ns_masterserver_hostname", "tf2cn.wolf109909.top");
    cliMap.insert("everything_unlocked", "1");
    cliMap.insert("ns_should_return_to_lobby", "1");
    cliMap.insert("net_chan_limit_mode", "2");
    cliMap.insert("net_chan_limit_msec_per_sec", "100");
    cliMap.insert("sv_querylimit_per_sec", "15");
    cliMap.insert("base_tickinterval_mp", "0.016667");
    cliMap.insert("sv_updaterate_mp", "20");
    cliMap.insert("sv_minupdaterate", "20");
    cliMap.insert("sv_max_snapshots_multiplayer", "300");
    cliMap.insert("net_data_block_enabled", "0");
    cliMap.insert("host_skip_client_dll_crc", "1");
}

bool ServerConfig::writeToCfg() {
    qDebug() << "writeToCfg";
    QFileInfo file = this->filePath;
    Q_ASSERT(file.isReadable());

    QTextCodec *codec = QTextCodec::codecForName("UTF8");

    QFile configfile;
    configfile.setFileName(file.filePath());
    // configfile.setFileName("./test.cfg");


    qDebug() << configfile.fileName();

    if (configfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        configfile.write(QString("//EditByNorthStarServerConfigEXE\n").toUtf8());
        for (auto i = cliMap.begin(); i != cliMap.end(); i++) {
            QString input;
            if (cliStringList.contains(i.key())) {
                //is string
                input= QString("%1 \"%2\"\n").arg(i.key()).arg(i.value());
                qDebug() << "going to input:" << input;
            } else {
                //is num
                input = QString("%1 %2\n").arg(i.key()).arg(i.value());
                qDebug() << "going to input:" << input;
            }
            Q_ASSERT(!input.isEmpty());
            configfile.write(input.toUtf8());
        }
    }else
        qDebug()<<"cant open file:"<<configfile.fileName();
    return true;
}

bool ServerConfig::readFromCfg() {
    qDebug() << "readFromcfg";

    QFileInfo file = this->filePath;
    Q_ASSERT(file.isReadable());

    QTextCodec *codec = QTextCodec::codecForName("UTF8");
    QRegExp rxCliName("(\\w+)");
    QRegExp rxCliValue("(\"[\\S\\s]*\")|\\d+");

    QFile configfile;
    configfile.setFileName(file.filePath());

    qDebug() << configfile.fileName();

    if (configfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //        QTextStream in(&configfile);
        while (!configfile.atEnd()) {
            QString lineText = codec->toUnicode(configfile.readLine());
            lineText = lineText.simplified();
            if (!lineText.isEmpty()) {
                // QStringList nowlineList=lineText.split(rx);
                rxCliName.indexIn(lineText, 0);
                rxCliValue.indexIn(lineText, 0);
                QString cliName = rxCliName.cap(0);
                QString cliValue = rxCliValue.cap(0);
                cliValue.replace(QRegExp("\""), "");
                qDebug() << cliName << cliValue;
                setConfigValue(cliName, cliValue);
            }
        }

    } else
        qDebug() << "打开失败";

    return true;
}

bool ServerConfig::writeToSaveFile(QFileInfo file) { 
    QSettings setting(file.fileName(),QSettings::IniFormat);
    setting.setIniCodec("UTF8");

    for(auto i=cliMap.begin();i!=cliMap.end();i++){
        QString saveCliName=i.key();
        QString saveCliValue=i.value();
        setting.setValue(QString("ServerConfig/%1").arg(saveCliName),saveCliValue);
    }

    return true; 
}

bool ServerConfig::readFromSaveFile(QFileInfo file) { return true; }

bool ServerConfig::setConfigValue(QString name, QString value) {
    qDebug() << "setConfigValue:"
             << "NowCliname:" << name << "Value:" << value;
    if (cliMap.find(name) != cliMap.end() || cliMap.end().key() == name) {
        cliMap[name] = value;
    } else {
        qDebug() << "cant find" << name << "in cliMap";
        return false;
    }
    return true;
}

void ServerConfig::setFilePath(QFileInfo path) { this->filePath = path; }

void ServerConfig::configReset() {
    qDebug() << "configReset()";
    cliMap["ns_server_name"] = "[CN]ServerName";
    cliMap["ns_server_desc"] = "Welcome everyone";
    cliMap["ns_server_password"] = "";
    cliMap["ns_report_server_to_masterserver"] = "1";
    cliMap["ns_report_sp_server_to_masterserver"] = "0";
    cliMap["ns_auth_allow_insecure"] = "0";
    cliMap["ns_erase_auth_info"] = "1";
    cliMap["ns_player_auth_port"] = "8081";
    cliMap["ns_masterserver_hostname"] = "tf2cn.wolf109909.top";
    cliMap["everything_unlocked"] = "1";
    cliMap["ns_should_return_to_lobby"] = "1";
    cliMap["net_chan_limit_mode"] = "2";
    cliMap["net_chan_limit_msec_per_sec"] = "100";
    cliMap["sv_querylimit_per_sec"] = "15";
    cliMap["base_tickinterval_mp"] = "0.016667";
    cliMap["sv_updaterate_mp"] = "20";
    // sv_minupdaterate unused
    cliMap["sv_max_snapshots_multiplayer"] = "300";
    // net_data_block_enabled unused
    cliMap["host_skip_client_dll_crc"] = "1";
}
