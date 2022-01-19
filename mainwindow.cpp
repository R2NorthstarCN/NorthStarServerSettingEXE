/*
 * @Author: HK560
 * @Date: 2022-01-14 16:28:21
 * @LastEditTime: 2022-01-19 10:23:27
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\mainwindow.cpp
 */
#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    init();//important!!

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::init()
{
    config = new ServerConfig;

    if (false) {//用于测试
        if (QFile("Titanfall2.exe").exists() == false) {
            QMessageBox::warning(this, NS_SERVERCONFIG_TITLE "错误",
                                 NS_SERVERCONFIG_INFO
                                 "检测到没有运行在游戏根目录下\n请把本程序放在"
                                 "泰坦陨落2根目录下再运行！");
            qDebug() << "检测到没有运行在游戏根目录";
            exit(0);
        }
        if (QFile("NorthstarLauncher.exe").exists() == false) {
            QMessageBox::warning(
                this, NS_SERVERCONFIG_TITLE "错误",
                NS_SERVERCONFIG_INFO
                "没有检测到NorthStarLancher\n请确保已安装了北极星客户端！");
            qDebug() << "没有检测到NorthStarLancher";
            exit(0);
        }
    }

    cfgFile.setFile(NS_CONFIG_TEST_PATH);
    if (!cfgFile.isFile()) {
        QMessageBox::warning(
            this, NS_SERVERCONFIG_TITLE "错误",
            NS_SERVERCONFIG_INFO
            "没有找到autoexec_ns_server.cfg文件\n请确保正确安装了北极星客户端");
        qDebug() << "找不到autoexec_ns_server.cfg";
        exit(0);
    }
    qDebug()<<"成功找到autoexec_ns_server.cfg";
    config->setFilePath(cfgFile);
    config->readFromCfg();
    setConfigToGui();
}

bool MainWindow::setConfigToGui()
{
    QMap<QString,QString> cMap=config->cliMap;

    ui->serverNameEdit->setText(cMap["ns_server_name"]);
    ui->serverDescEdit->setText(cMap["ns_server_desc"]);
    ui->serverPasswordEdit->setText(cMap["ns_server_password"]);
    ui->reportServerToMSCheckbox->setChecked(cMap["ns_report_server_to_masterserver"].toInt());
    ui->reportServerToMSinSPCheckbox->setChecked(cMap["ns_report_sp_server_to_masterserver"].toInt());
    ui->nsAuthAllowInsecureCheckBox->setChecked(cMap["ns_auth_allow_insecure"].toInt());
    ui->nsEraseAuthInfoCheckBox->setChecked(cMap["ns_erase_auth_info"].toInt());
    ui->nsPlayerAuthPortSpinBox->setValue(cMap["ns_player_auth_port"].toInt());
    ui->nsMasterServerHostNameEdit->setText(cMap["ns_masterserver_hostname"]);
    ui->everythingUnlockedCheckBox->setChecked(cMap["everything_unlocked"].toInt());
    ui->returnToLobbyCheckBox->setChecked(cMap["ns_should_return_to_lobby"].toInt());
    ui->netChanLimitModeSpinBox->setValue(cMap["net_chan_limit_mode"].toInt());
    ui->netChanLimitMsecSpinBox->setValue(cMap["net_chan_limit_msec_per_sec"].toInt());
    ui->svQuerylimitPerSecSpinBox->setValue(cMap["sv_querylimit_per_sec"].toInt());
    ui->baseTickintervalMpSpinBox->setValue(cMap["base_tickinterval_mp"].toInt());
    ui->svUpdaterateMpSpinBox->setValue(cMap["sv_updaterate_mp"].toInt());
    // sv_minupdaterate unused
    ui->svMaxSnapshotsMultiplayerSpinBox->setValue(cMap["sv_max_snapshots_multiplayer"].toInt());
    //net_data_block_enabled unused
    ui->hostSkipClientDllCrcCheckBox->setChecked(cMap["host_skip_client_dll_crc"].toInt());

    return true;
}

bool MainWindow::setGuiToConfig(QMap<QString,QString> &cMap)
{
    cMap["ns_server_name"]=ui->serverNameEdit->text();
    cMap["ns_server_desc"]=ui->serverDescEdit->text();
    cMap["ns_server_password"]=ui->serverPasswordEdit->text();
    cMap["ns_report_server_to_masterserver"]=QString::number(ui->reportServerToMSCheckbox->checkState());
    cMap["ns_report_sp_server_to_masterserver"]=QString::number(ui->reportServerToMSinSPCheckbox->checkState());
    cMap["ns_auth_allow_insecure"]=QString::number(ui->nsAuthAllowInsecureCheckBox->checkState());
    cMap["ns_erase_auth_info"]=QString::number(ui->nsEraseAuthInfoCheckBox->checkState());
    cMap["ns_player_auth_port"]=QString::number(ui->nsPlayerAuthPortSpinBox->value());
    cMap["ns_masterserver_hostname"]=ui->nsMasterServerHostNameEdit->text();
    cMap["everything_unlocked"]=QString::number(ui->everythingUnlockedCheckBox->checkState());
    cMap["ns_should_return_to_lobby"]=QString::number(ui->returnToLobbyCheckBox->checkState());
    cMap["net_chan_limit_mode"]=QString::number(ui->netChanLimitModeSpinBox->value());
    cMap["net_chan_limit_msec_per_sec"]=QString::number(ui->netChanLimitMsecSpinBox->value());
    cMap["sv_querylimit_per_sec"]=QString::number(ui->svQuerylimitPerSecSpinBox->value());
    cMap["base_tickinterval_mp"]=QString::number(ui->baseTickintervalMpSpinBox->value());
    cMap["sv_updaterate_mp"]=QString::number(ui->svUpdaterateMpSpinBox->value());
    // sv_minupdaterate unused
    cMap["sv_max_snapshots_multiplayer"]=QString::number(ui->svMaxSnapshotsMultiplayerSpinBox->value());
    //net_data_block_enabled unused
    cMap["host_skip_client_dll_crc"]=QString::number(ui->hostSkipClientDllCrcCheckBox->checkState());
    return true;
    
}




void MainWindow::on_readNSconfigBtn_clicked()
{
   setConfigToGui();
}


void MainWindow::on_applyToNSBtn_clicked()
{
    setGuiToConfig(config->cliMap);
}

