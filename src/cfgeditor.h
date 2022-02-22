/*
 * @Author: HK560
 * @Date: 2022-02-21 18:23:17
 * @LastEditTime: 2022-02-22 19:05:14
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\cfgeditor.h
 */
#ifndef CFGEDITOR_H
#define CFGEDITOR_H

#include <QWidget>

#include <QMainWindow>
#include<QFile>
#include"serverconfig.h"
#include<QDebug>
#include<QFileInfo>
#include<QMessageBox>
#include"aboutns.h"
namespace Ui {
class CfgEditor;
}

class CfgEditor : public  QDialog
{
    Q_OBJECT

public:
    explicit CfgEditor(QWidget *parent = nullptr,ServerConfig* config=nullptr);
    ~CfgEditor();

    ServerConfig* setSConfig(ServerConfig *config);
    bool setConfigToGui();//读取config的climap配置到gui
    bool setGuiToConfig(QMap<QString, QString> &cMap);//读取gui设置到config
 
private slots:
    void on_closeBtn_clicked();

    void on_okBtn_clicked();

private:
    Ui::CfgEditor *ui;
    ServerConfig *config;

   
};

#endif // CFGEDITOR_H
