#ifndef ARGSDEDIEDITOR_H
#define ARGSDEDIEDITOR_H

#include <QDialog>
#include"argsdediconfig.h"

namespace Ui {
class ArgsDediEditor;
}

class ArgsDediEditor : public QDialog
{
    Q_OBJECT

public:
    explicit ArgsDediEditor(QWidget *parent = nullptr,ArgsDediConfig *argsDediConfig=nullptr);
    ~ArgsDediEditor();

private:
    Ui::ArgsDediEditor *ui;
};

#endif // ARGSDEDIEDITOR_H
