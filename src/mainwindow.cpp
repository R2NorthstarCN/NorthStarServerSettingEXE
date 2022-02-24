/*
 * @Author: HK560
 * @Date: 2022-02-21 12:45:00
 * @LastEditTime: 2022-02-24 18:50:51
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKId:\github\ttf\NorthStarServerSettingEXE\src\mainwindow.cpp
 */
/*
 * @Author: HK560
 * @Date: 2022-01-14 16:28:21
 * @LastEditTime: 2022-02-22 20:31:03
 * @LastEditors: HK560
 * @Description:
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\mainwindow.cpp
 * \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\mainwindow.cpp
 * \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\mainwindow.cpp
 */
#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QIcon ico(":/icon/avatar_nscnEdit");
    setWindowIcon(ico);
    init();  // important!!

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::closeEvent(QCloseEvent* event){
    exit(0);
}

void MainWindow::init() {
    config = new ServerConfig;
    argsConfig=new ArgsConfig;
    argsDediConfig=new ArgsDediConfig;


    exeCfgFile.setFile(NS_EXECONFIG_PATH);
    cfgFile.setFile(NS_CONFIG_TEST_PATH);  // NS_CONFIG_TEST_PATH NS_CONFIG_PATH
    argsFile.setFile(NS_CONFIG_ARGS_PATH);
    argsDediFile.setFile(NS_CONFIG_ARGS_DEDI_PATH);



    if (false) {  //用于测试
        if (QFile("Titanfall2.exe").exists() == false) {
            QMessageBox::warning(this, NS_SERVERCONFIG_TITLE "错误",

                                 "检测到没有运行在游戏根目录下\n请把本程序放在"
                                 "泰坦陨落2根目录下再运行！");
            qDebug() << "检测到没有运行在游戏根目录";
            exit(0);
        }
        if (QFile("NorthstarLauncher.exe").exists() == false) {
            QMessageBox::warning(
                this, NS_SERVERCONFIG_TITLE "错误",

                "没有检测到NorthStarLancher\n请确保已安装了北极星客户端！");
            qDebug() << "没有检测到NorthStarLancher";
            exit(0);
        }
        
    }
    //checkFile
    if (!cfgFile.isFile()) {
        QMessageBox::warning(
            this, NS_SERVERCONFIG_TITLE "错误",
            NS_SERVERCONFIG_INFO
            "没有找到autoexec_ns_server.cfg文件\n请确保正确安装了北极星客户端");
        qDebug() << "找不到autoexec_ns_server.cfg";
        exit(0);
    }
    qDebug() << "成功找到autoexec_ns_server.cfg";

    if (!argsFile.isFile()) {
        QMessageBox::warning(
            this, NS_SERVERCONFIG_TITLE "错误",
            NS_SERVERCONFIG_INFO
            "没有找到ns_startup_args.txt文件\n请确保正确安装了北极星客户端");
        qDebug() << "找不到ns_startup_args";
        exit(0);
    }
    qDebug() << "成功找到ns_startup_args";

    if (!argsDediFile.isFile()) {
        QMessageBox::warning(
            this, NS_SERVERCONFIG_TITLE "错误",
            NS_SERVERCONFIG_INFO
            "没有找到ns_startup_args_dedi.txt文件\n请确保正确安装了北极星客户端");
        qDebug() << "找不到ns_startup_args_dedi.txt";
        exit(0);
    }
    qDebug() << "成功找到ns_startup_args_dedi.txt";


    config->setFilePath(cfgFile);
    config->readFromCfg();

    argsConfig->setFilePath(argsFile);
    // argsConfig->readFromArgs();

    argsDediConfig->setFilePath(argsDediFile);
    // argsDediConfig->readFromArgs();

    // cfgEditor=new CfgEditor();
    setConfigToGui();
    // cfgEditor.setConfigToGui();

}


void MainWindow::outputCfgTextToGUI(QMap<QString, QString> cMap){
    Q_ASSERT(!cMap.isEmpty());

    ui->cfgText->clear();
    ui->cfgText->setWordWrapMode(QTextOption::NoWrap);
    ui->cfgText->setReadOnly(true);
    //读取config到textedit
    for(auto i=cMap.begin();i!=cMap.end();i++){
        if(i.value().isEmpty())
            continue;
        ui->cfgText->append(QString("%1\t%2").arg(i.key()).arg(i.value()));
    }
    //设置光标
    QTextCursor textCursor;
    textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    ui->cfgText->setTextCursor(textCursor);
}

bool MainWindow::setConfigToGui() {
    QMap<QString, QString> cMap = config->cliMap;
    ui->serverNameValue->setText(cMap["ns_server_name"]);
    // ui->serverNameEdit->setText(cMap["ns_server_name"]);
    ui->serverDescValue->setText(cMap["ns_server_desc"]);
    ui->serverPasswordValue->setText(cMap["ns_server_password"]);
    // ui->reportServerToMSCheckbox->setChecked(
    //     cMap["ns_report_server_to_masterserver"].toInt());
    // ui->reportServerToMSinSPCheckbox->setChecked(
    //     cMap["ns_report_sp_server_to_masterserver"].toInt());
    // ui->nsAuthAllowInsecureCheckBox->setChecked(
    //     cMap["ns_auth_allow_insecure"].toInt());
    // ui->nsEraseAuthInfoCheckBox->setChecked(cMap["ns_erase_auth_info"].toInt());
    ui->nsPlayerAuthPortValue->setText(cMap["ns_player_auth_port"]);
    ui->nsMasterServerHostNameValue->setText(cMap["ns_masterserver_hostname"]);
    // ui->everythingUnlockedCheckBox->setChecked(
    //     cMap["everything_unlocked"].toInt());
    // ui->returnToLobbyCheckBox->setChecked(
    //     cMap["ns_should_return_to_lobby"].toInt());
    // ui->netChanLimitModeSpinBox->setValue(cMap["net_chan_limit_mode"].toInt());
    // ui->netChanLimitMsecSpinBox->setValue(
    //     cMap["net_chan_limit_msec_per_sec"].toInt());
    // ui->svQuerylimitPerSecSpinBox->setValue(
    //     cMap["sv_querylimit_per_sec"].toInt());
    // ui->baseTickintervalMpSpinBox->setValue(
    //     cMap["base_tickinterval_mp"].toDouble());
    // ui->svUpdaterateMpSpinBox->setValue(cMap["sv_updaterate_mp"].toInt());
    // // sv_minupdaterate unused
    // ui->svMaxSnapshotsMultiplayerSpinBox->setValue(
    //     cMap["sv_max_snapshots_multiplayer"].toInt());
    // // net_data_block_enabled unused
    // ui->hostSkipClientDllCrcCheckBox->setChecked(
    //     cMap["host_skip_client_dll_crc"].toInt());
    // ui->otherCliEdit->clear();
    // qDebug() << config->otherCli;
    // ui->otherCliEdit->setText(config->otherCli);

    outputCfgTextToGUI(cMap);

    //args
    //argsDedi
    return true;
}

bool MainWindow::setGuiToConfig(QMap<QString, QString> &cMap) {
    // cMap["ns_server_name"] = ui->serverNameEdit->text();
    // cMap["ns_server_desc"] = ui->serverDescEdit->text();
    // cMap["ns_server_password"] = ui->serverPasswordEdit->text();
    // cMap["ns_report_server_to_masterserver"] =
    //     QString::number(ui->reportServerToMSCheckbox->checkState());
    // cMap["ns_report_sp_server_to_masterserver"] =
    //     QString::number(ui->reportServerToMSinSPCheckbox->checkState());
    // cMap["ns_auth_allow_insecure"] =
    //     QString::number(ui->nsAuthAllowInsecureCheckBox->checkState());
    // cMap["ns_erase_auth_info"] =
    //     QString::number(ui->nsEraseAuthInfoCheckBox->checkState());
    // cMap["ns_player_auth_port"] =
    //     QString::number(ui->nsPlayerAuthPortSpinBox->value());
    // cMap["ns_masterserver_hostname"] = ui->nsMasterServerHostNameEdit->text();
    // cMap["everything_unlocked"] =
    //     QString::number(ui->everythingUnlockedCheckBox->checkState());
    // cMap["ns_should_return_to_lobby"] =
    //     QString::number(ui->returnToLobbyCheckBox->checkState());
    // cMap["net_chan_limit_mode"] =
    //     QString::number(ui->netChanLimitModeSpinBox->value());
    // cMap["net_chan_limit_msec_per_sec"] =
    //     QString::number(ui->netChanLimitMsecSpinBox->value());
    // cMap["sv_querylimit_per_sec"] =
    //     QString::number(ui->svQuerylimitPerSecSpinBox->value());
    // cMap["base_tickinterval_mp"] =
    //     QString::number(ui->baseTickintervalMpSpinBox->value());
    // cMap["sv_updaterate_mp"] =
    //     QString::number(ui->svUpdaterateMpSpinBox->value());
    // // sv_minupdaterate unused
    // cMap["sv_max_snapshots_multiplayer"] =
    //     QString::number(ui->svUpdaterateMpSpinBox->value() * 15);  // important
    // // net_data_block_enabled unused
    // cMap["host_skip_client_dll_crc"] =
    //     QString::number(ui->hostSkipClientDllCrcCheckBox->checkState());
    // config->otherCli = ui->otherCliEdit->toPlainText();
    return true;
}

void MainWindow::checkoutNewVer() {
    qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();
    QNetworkAccessManager
        *manager;  //定义网络请求对象int parse_UpdateJSON(QString str);
                   ////解析数据函数的声明
    void replyFinished(QNetworkReply * reply);  //网络数据接收完成槽函数的声明
    QString CurVerison = "V1.1";                //定义当前软件的版本号

    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    connect(manager, SIGNAL(finished(QNetworkReply *)), this,
            SLOT(replyFinished(QNetworkReply *)));  //关联信号和槽
    
    QNetworkRequest quest;    
    quest.setUrl(QUrl("https://gitee.com/hk560/program-config/raw/master/config/NS_ServerConfig_Editor.json")); //包含最新版本软件的下载地址    
    quest.setHeader(QNetworkRequest::UserAgentHeader,"RT-Thread ART");    
    manager->get(quest);    //发送get网络请求
}

void MainWindow::replyFinished(QNetworkReply *reply) {
    QString str = reply->readAll();  //读取接收到的数据
    qDebug() << str;
    parse_UpdateJSON(str);  //文件保存到本地/*
    QFile file("software_update.json");
    if (!file.open(QIODevice::WriteOnly |
                   QIODevice::Text))  // append 内容追加在文件后面
    {
        QMessageBox::critical(this, "错误", "文件打开失败，信息未写入", "确定");
        return;
    }
    QTextStream out(&file);
    out << str;                   //输出到文件
    file.close();                 //关闭文件
    qDebug() << "文件保存成功!";  //
    file.remove();                //
    qDebug() << "文件已经删除";
    reply->deleteLater();  //销毁请求对象
}

int MainWindow::parse_UpdateJSON(QString str) {
    //    QMessageBox msgBox;
    QJsonParseError err_rpt;
    QJsonDocument root_Doc =
        QJsonDocument::fromJson(str.toUtf8(), &err_rpt);  //字符串格式化为JSON
    if (err_rpt.error != QJsonParseError::NoError) {  //
        qDebug() << "root格式错误";
        QMessageBox::critical(this, "检查失败",
                              "服务器地址错误或JSON格式错误!");
        return -1;
    }
    if (root_Doc.isObject()) {
        QJsonObject root_Obj = root_Doc.object();  //创建JSON对象，不是字符串
        QJsonObject NS_OBJ = root_Obj.value("NS_SERVERCONFIG_EDITOR").toObject();
        QString verison = NS_OBJ.value("LatestVerison").toString();  // 
        QString url =
         NS_OBJ.value("Url")
                .toString();  // https://wcc-blog.oss-cn-beijing.aliyuncs.com/uFun_Pulse_v1.0.exe
        QString updateTime = NS_OBJ.value("UpdateTime").toString();
        QString releaseNote = NS_OBJ.value("ReleaseNote").toString();
        QString verInfoFromJSON="JSON版本信息："+verison+"\t"+updateTime+"\t"+releaseNote;
        qDebug()<<verInfoFromJSON;
        if (verison > NS_SERVERCONFIG_VER) {
            QString warningStr = "检测到新版本!\n版本号：" + verison + "\n" +
                                 "更新时间：" + updateTime + "\n" +
                                 "更新说明：" + releaseNote;
            int ret = QMessageBox::warning(this, "检查更新", warningStr,
                                           "下载", "取消");
            if (ret == 0)  //点击更新
            {
                QDesktopServices::openUrl(QUrl(url));
            }
        } else
            QMessageBox::information(this, "检查更新", "当前已经是最新版本!");
    }
    return 0;
}

void MainWindow::on_readNSconfigBtn_clicked() {
    config->readFromCfg();
    setConfigToGui();
    // cfgEditor.setConfigToGui();

}

void MainWindow::on_applyToNSBtn_clicked() {
    setGuiToConfig(config->cliMap);
    // cfgEditor.setGuiToConfig(config->cliMap);
    
    config->writeToCfg();
    config->readFromCfg();
    setConfigToGui();
    // cfgEditor.setConfigToGui();

    QMessageBox::information(NULL, "提示", QString("应用成功！"));
}

void MainWindow::on_resetBtn_clicked() {
    config->configReset();
    setConfigToGui();
    // cfgEditor.setConfigToGui();

}

void MainWindow::on_saveConfigBtn_clicked() {
    setGuiToConfig(config->cliMap);
    // cfgEditor.setGuiToConfig(config->cliMap);

    config->writeToSaveFile(exeCfgFile);
}

void MainWindow::on_loadConfigBtn_clicked() {
    if (config->readFromSaveFile(exeCfgFile)) {
        setConfigToGui();
        // cfgEditor.setConfigToGui();

        QMessageBox::information(NULL, "提示", QString("读取成功！"));
    };
}

void MainWindow::on_aboutBtn_clicked() {
    //    QMessageBox::about(this,"关于","作者：HK560");
    aboutNS ab;
    ab.exec();
}

void MainWindow::on_checkoutUpdateBtn_clicked()
{
    checkoutNewVer();
}


void MainWindow::on_cfgditortn_clicked()
{
    CfgEditor cfgEditor(this,config);
    // cfgEditor.setSConfig(config);
    cfgEditor.exec();
    setConfigToGui();
}


void MainWindow::on_argsBtn_clicked()
{
    ArgsEditor argsEditor;
    argsEditor.exec();
    setConfigToGui();
}




void MainWindow::on_argsDediBtn_clicked()
{
    ArgsDediEditor argsDediEditor;
    argsDediEditor.exec();
    setConfigToGui();

}

