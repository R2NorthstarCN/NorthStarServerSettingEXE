/*
 * @Author: HK560
 * @Date: 2022-02-24 18:03:48
 * @LastEditTime: 2022-02-26 11:34:08
 * @LastEditors: HK560
 * @Description:
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\argsdediconfig.cpp
 * \NorthStarCN_WIKId:\github\ttf\NorthStarServerSettingEXE\src\argsdediconfig.cpp
 */
#include "argsdediconfig.h"

ArgsDediConfig::ArgsDediConfig() {
    //argsMap
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
    
    //argsSetMap
    argsSetMap.insert("+setplaylist",false);
    argsSetMap.insert("-port",false);
    argsSetMap.insert("+mp_gamemode",false);
    argsSetMap.insert("-maxplayersplaylist",false);

    argsSetMap.insert("+setplaylistvaroverrides",false);
    argsSetMap.insert("max_players",false);
    argsSetMap.insert("custom_air_accel_pilot",false);
    argsSetMap.insert("timelimit",false);
    argsSetMap.insert("scorelimit",false);
    argsSetMap.insert("roundtimelimit",false);
    argsSetMap.insert("roundscorelimit",false);
    argsSetMap.insert("respawn_delay",false);
    argsSetMap.insert("pilot_health_multiplier",false);

    argsSetMap.insert("boosts_enabled",false);
}

bool ArgsDediConfig::writeToArgs() { return true; }

bool ArgsDediConfig::readFromArgs() {
    qDebug() << "readFromArgs";

    QFileInfo file = this->filePath;
    Q_ASSERT(file.isReadable());

    QTextCodec *codec = QTextCodec::codecForName("UTF8");

    otherArgs.clear();
// \+setplaylist[\s]+[\S]+([\s]+|)
// \+setplaylist[\s]+((".+")|[\S]+([\s]+|))

    QFile argsFile;
    argsFile.setFileName(file.fileName());

    if (argsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //        QTextStream in(&argsFile);
        // while (!argsFile.atEnd()) {
        QString lineText = codec->toUnicode(argsFile.readLine());//读行
        lineText = lineText.simplified();
        if (!lineText.isEmpty()) {
            // QStringList nowlineList=lineText.split(rx);
            qDebug()<<lineText;
            for(auto i=argsNameList.begin();i!=argsNameList.end();i++){
                //\+mp_gamemode\s*?".*?"|\+mp_gamemode\s*?(?!\+)\S+|\+mp_gamemode(?=\s)*
                QString rxArgsNameStr=QString("\\%1(?!\\S)\\s+\"[^\"]*\"|\\%1(?!\\S)\\s+(?!\\+|\\-)\\S+|\\%1(?!\\S)(?=\\s)*").arg(*i);// (\\%1[\\s]*?((\".*?\")))|(\\%1[\\s]*?(?!\\+)\\S+)|(\\%1(?=\\s)*)
                QRegExp rxArgsName(rxArgsNameStr);
//                rxArgsName.setMinimal(true);
                qDebug()<<"nowRX"<<rxArgsName.pattern();
                
                if(rxArgsName.indexIn(lineText)==-1){
                    qDebug()<<"nofound";
                };
                QString argsName = rxArgsName.cap(0);
                qDebug()<<"GetArgsName:"<<argsName;
                if(!argsName.isEmpty()){
                    argsSetMap[*i]=true;
                    // \+mp_gamemode[\s]*((".*?")|([^\+\-][\S]+([\s]+|))|)
                    // ([\s]+".+")|([\s]+[\S]+)
                    // \+mp_gamemode[\s]*?((".*?")|([^+]\S+))
                    // (\+mp_gamemode[\s]*?((".*?")))|(\+mp_gamemode[\s]*?(?!\+)\S+)|(\+mp_gamemode(?=\s)*)
                    if(*i!="+setplaylistvaroverrides"){
                    QRegExp rxArgsValue("([\\s]+\".+\")|([\\s]+[\\S]+)");
                    rxArgsValue.indexIn(argsName,0);
                    QString argsValue=rxArgsValue.cap(0);
                    qDebug()<<"GetArgsValue:"<<argsValue.simplified();
                    }
                }
            }
            // rxCliValue.indexIn(lineText, 0);
            
            // QString cliValue = rxCliValue.cap(0);
            // cliValue.replace(QRegExp("\""), "");
            // qDebug() << cliName << cliValue;
            // if (!setConfigValue(cliName, cliValue)) {
            //     setOtherConfigValue(lineText);
            // };
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
