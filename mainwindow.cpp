#include "mainwindow.h"
#include "ui_mainwindow.h"

#define NS_SERVERCONFIG_INFO "NorthStarCN ServerConfig :\n"
#define NS_SERVERCONFIG_TITLE "NorthStarCN ServerConfig \t"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config=new ServerConfig;
    QFileInfo gameExeFile("lan.docx");
    QFile file("lan.docx");
    qDebug()<<gameExeFile.absoluteFilePath();
    if (QFile("Titanfall2.exe").exists()==false){
        QMessageBox::warning(this,NS_SERVERCONFIG_TITLE"错误",NS_SERVERCONFIG_INFO"检测到没有运行在游戏根目录下\n请把本程序放在泰坦陨落2根目录下再运行！");
        qDebug()<<"检测到没有运行在游戏根目录";
        exit(0);
    }
        if (QFile("NorthstarLauncher.exe").exists()==false){
        QMessageBox::warning(this,NS_SERVERCONFIG_TITLE"错误",NS_SERVERCONFIG_INFO"没有检测到NorthStarLancher\n请确保已安装了北极星客户端！");
        qDebug()<<"检测到没有运行在游戏根目录";
        exit(0);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

