/*
 * @Author: HK560
 * @Date: 2022-02-24 18:03:48
 * @LastEditTime: 2022-02-24 18:56:32
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKId:\github\ttf\NorthStarServerSettingEXE\src\argsdedieditor.cpp
 */
#include "argsdedieditor.h"
#include "ui_argsdedieditor.h"

ArgsDediEditor::ArgsDediEditor(QWidget *parent,ArgsDediConfig *argsDediConfig) :
    QDialog(parent),
    ui(new Ui::ArgsDediEditor)
{
    ui->setupUi(this);
    ui->linkLabel->setOpenExternalLinks(true);
}

ArgsDediEditor::~ArgsDediEditor()
{
    delete ui;
}
