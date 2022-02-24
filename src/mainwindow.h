/*
 * @Author: HK560
 * @Date: 2022-01-14 16:28:21
 * @LastEditTime: 2022-02-24 16:33:25
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\mainwindow.h
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include<QFile>
#include"serverconfig.h"
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
#include"aboutns.h"
#include"cfgeditor.h"
#include"define.h"
#include"argsconfig.h"
#include"argsdediconfig.h"
#include"argseditor.h"
#include"argsdedieditor.h"

//网络相关头文件
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <qdesktopservices.h>

//JSON相关头文件
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event);//重写关闭事件
private slots:


    void on_readNSconfigBtn_clicked();

    void on_applyToNSBtn_clicked();

    void on_resetBtn_clicked();

    void on_saveConfigBtn_clicked();

    void on_loadConfigBtn_clicked();

    void on_aboutBtn_clicked();


    void on_checkoutUpdateBtn_clicked();

    void replyFinished(QNetworkReply *reply);//处理网络请求槽函数
    void on_cfgditortn_clicked();

    void on_argsBtn_clicked();

    void on_argsDediBtn_clicked();

private:
    void init();    
    bool setConfigToGui();//读取config的climap配置到gui
    bool setGuiToConfig(QMap<QString,QString> &cMap);//读取gui设置到config

    void checkoutNewVer();//检查新版本

    int parse_UpdateJSON(QString str);

    Ui::MainWindow *ui;
    ServerConfig *config;
    ArgsConfig *argsConfig;
    ArgsDediConfig *argsDediConfig;
    
    QFileInfo cfgFile;//cfg配置文件路径
    QFileInfo exeCfgFile;//ini设置保存文件路径
    QFileInfo argsFile;//args文件路径
    QFileInfo argsDediFile;//argsDedi文件路径


    // CfgEditor cfgEditor;
    
    void outputCfgTextToGUI(QMap<QString, QString> cMap);//输出config的内容到文本框

};
#endif // MAINWINDOW_H
