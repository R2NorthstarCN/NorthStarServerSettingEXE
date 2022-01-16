#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
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
    config->readFromCfg(cfgFile);
}

MainWindow::~MainWindow() { delete ui; }
