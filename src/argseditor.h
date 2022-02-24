/*
 * @Author: HK560
 * @Date: 2022-02-23 16:18:39
 * @LastEditTime: 2022-02-24 16:35:00
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\argseditor.h
 */
/*
 * @Author: HK560
 * @Date: 2022-02-23 16:18:39
 * @LastEditTime: 2022-02-24 16:33:57
 * @LastEditors: HK560
 * @Description: 
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSettingEXE\src\argseditor.h
 */
#ifndef ARGSEDITOR_H
#define ARGSEDITOR_H

#include <QDialog>
#include"argsconfig.h"

namespace Ui {
class ArgsEditor;
}

class ArgsEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ArgsEditor(QWidget *parent = nullptr,ArgsConfig *argsConfig=nullptr);
    ~ArgsEditor();

private:
    Ui::ArgsEditor *ui;
};

#endif // ARGSEDITOR_H
