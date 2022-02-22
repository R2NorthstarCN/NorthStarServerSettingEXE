/*
 * @Author: HK560
 * @Date: 2022-02-21 18:23:17
 * @LastEditTime: 2022-02-22 20:33:03
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\cfgeditor.cpp
 */
#include "cfgeditor.h"
#include "ui_cfgeditor.h"

CfgEditor::CfgEditor(QWidget *parent,ServerConfig* config) :
    QDialog(parent),
    ui(new Ui::CfgEditor)
{
    ui->setupUi(this);
    this->config=config;
    setConfigToGui();
}

CfgEditor::~CfgEditor()
{
    delete ui;
}

ServerConfig* CfgEditor::setSConfig(ServerConfig* config){
    return this->config=config;
}

bool CfgEditor::setConfigToGui()
{

    Q_ASSERT(!config->cliMap.isEmpty());
    
    
    QMap<QString, QString> cMap = config->cliMap;

    ui->serverNameEdit->setText(cMap["ns_server_name"]);
    ui->serverDescEdit->setText(cMap["ns_server_desc"]);
    ui->serverPasswordEdit->setText(cMap["ns_server_password"]);
    ui->reportServerToMSCheckbox->setChecked(
        cMap["ns_report_server_to_masterserver"].toInt());
    ui->reportServerToMSinSPCheckbox->setChecked(
        cMap["ns_report_sp_server_to_masterserver"].toInt());
    ui->nsAuthAllowInsecureCheckBox->setChecked(
        cMap["ns_auth_allow_insecure"].toInt());
    ui->nsEraseAuthInfoCheckBox->setChecked(cMap["ns_erase_auth_info"].toInt());
    ui->nsPlayerAuthPortSpinBox->setValue(cMap["ns_player_auth_port"].toInt());
    ui->nsMasterServerHostNameEdit->setText(cMap["ns_masterserver_hostname"]);
    ui->everythingUnlockedCheckBox->setChecked(
        cMap["everything_unlocked"].toInt());
    ui->returnToLobbyCheckBox->setChecked(
        cMap["ns_should_return_to_lobby"].toInt());
    ui->netChanLimitModeSpinBox->setValue(cMap["net_chan_limit_mode"].toInt());
    ui->netChanLimitMsecSpinBox->setValue(
        cMap["net_chan_limit_msec_per_sec"].toInt());
    ui->svQuerylimitPerSecSpinBox->setValue(
        cMap["sv_querylimit_per_sec"].toInt());
    ui->baseTickintervalMpSpinBox->setValue(
        cMap["base_tickinterval_mp"].toDouble());
    ui->svUpdaterateMpSpinBox->setValue(cMap["sv_updaterate_mp"].toInt());
    // sv_minupdaterate unused
    ui->svMaxSnapshotsMultiplayerSpinBox->setValue(
        cMap["sv_max_snapshots_multiplayer"].toInt());
    // net_data_block_enabled unused
    ui->hostSkipClientDllCrcCheckBox->setChecked(
        cMap["host_skip_client_dll_crc"].toInt());
    ui->otherCliEdit->clear();
    qDebug() << config->otherCli;
    ui->otherCliEdit->setText(config->otherCli);

    //v1.0.0 add
    ui->onlyHostChangeSettingSpinBox->setValue(cMap["ns_private_match_only_host_can_change_settings"].toInt());
    ui->countdownLengthSpinBox->setValue(cMap["ns_private_match_countdown_length"].toInt());
    ui->lastModeLineEdit->setText(cMap["ns_private_match_last_mode"]);
    ui->lastMapLineEdit->setText(cMap["ns_private_match_last_map"]);
    ui->disallowedWeaponLineEdit->setText(cMap["ns_disallowed_weapons"]);
    ui->weaponReplaceLineEdit->setText(cMap["ns_disallowed_weapon_primary_replacement"]);
    ui->printUnknowCLiChkBox->setChecked(cMap["ns_should_log_unknown_clientcommands"].toInt());

    return true;

}

bool CfgEditor::setGuiToConfig(QMap<QString, QString> &cMap){
    Q_ASSERT(!cMap.isEmpty());

    cMap["ns_server_name"] = ui->serverNameEdit->text();
    cMap["ns_server_desc"] = ui->serverDescEdit->text();
    cMap["ns_server_password"] = ui->serverPasswordEdit->text();
    cMap["ns_report_server_to_masterserver"] =
        QString::number(ui->reportServerToMSCheckbox->checkState());
    cMap["ns_report_sp_server_to_masterserver"] =
        QString::number(ui->reportServerToMSinSPCheckbox->checkState());
    cMap["ns_auth_allow_insecure"] =
        QString::number(ui->nsAuthAllowInsecureCheckBox->checkState());
    cMap["ns_erase_auth_info"] =
        QString::number(ui->nsEraseAuthInfoCheckBox->checkState());
    cMap["ns_player_auth_port"] =
        QString::number(ui->nsPlayerAuthPortSpinBox->value());
    cMap["ns_masterserver_hostname"] = ui->nsMasterServerHostNameEdit->text();
    cMap["everything_unlocked"] =
        QString::number(ui->everythingUnlockedCheckBox->checkState());
    cMap["ns_should_return_to_lobby"] =
        QString::number(ui->returnToLobbyCheckBox->checkState());
    cMap["net_chan_limit_mode"] =
        QString::number(ui->netChanLimitModeSpinBox->value());
    cMap["net_chan_limit_msec_per_sec"] =
        QString::number(ui->netChanLimitMsecSpinBox->value());
    cMap["sv_querylimit_per_sec"] =
        QString::number(ui->svQuerylimitPerSecSpinBox->value());
    cMap["base_tickinterval_mp"] =
        QString::number(ui->baseTickintervalMpSpinBox->value());
    cMap["sv_updaterate_mp"] =
        QString::number(ui->svUpdaterateMpSpinBox->value());
    // sv_minupdaterate unused
    cMap["sv_max_snapshots_multiplayer"] =
        QString::number(ui->svUpdaterateMpSpinBox->value() * 15);  // important
    // net_data_block_enabled unused
    cMap["host_skip_client_dll_crc"] =
        QString::number(ui->hostSkipClientDllCrcCheckBox->checkState());
    config->otherCli = ui->otherCliEdit->toPlainText();

    //v1.0.0 add
    cMap["ns_private_match_only_host_can_change_settings"] =QString::number(ui->onlyHostChangeSettingSpinBox->value());
    cMap["ns_private_match_countdown_length"] =QString::number(ui->countdownLengthSpinBox->value());
    cMap["ns_private_match_last_mode"] = ui->lastModeLineEdit->text();
    cMap["ns_private_match_last_map"] = ui->lastMapLineEdit->text();
    cMap["ns_disallowed_weapons"] = ui->disallowedWeaponLineEdit->text();
    cMap["ns_disallowed_weapon_primary_replacement"] = ui->weaponReplaceLineEdit->text();
    cMap["ns_should_log_unknown_clientcommands"] = QString::number(ui->printUnknowCLiChkBox->checkState());

    return true;

}

void CfgEditor::on_closeBtn_clicked()
{
    this->close();
}


void CfgEditor::on_okBtn_clicked()
{
    setGuiToConfig(config->cliMap);
    this->close();
    // this->quit();
}

