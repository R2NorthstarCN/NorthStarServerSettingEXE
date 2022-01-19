/*
 * @Author: HK560
 * @Date: 2022-01-14 16:28:21
 * @LastEditTime: 2022-01-19 10:39:12
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\mainwindow.h
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define NS_SERVERCONFIG_INFO "NorthStarCN ServerConfig :\n"
#define NS_SERVERCONFIG_TITLE "NorthStarCN ServerConfig \t"
#define NS_CONFIG_PATH "./R2Northstar/mods/Northstar.CustomServers/mod/cfg/autoexec_ns_server.cfg"
#define NS_CONFIG_TEST_PATH "autoexec_ns_server.cfg"


#include <QMainWindow>
#include<QFile>
#include"serverconfig.h"
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_readNSconfigBtn_clicked();

    void on_applyToNSBtn_clicked();

    void on_resetBtn_clicked();

private:
    void init();    
    bool setConfigToGui();//读取config的climap配置到gui
    bool setGuiToConfig(QMap<QString,QString> &cMap);

    Ui::MainWindow *ui;
    ServerConfig *config;
    QFileInfo cfgFile;
};
#endif // MAINWINDOW_H
