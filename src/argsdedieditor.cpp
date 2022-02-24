#include "argsdedieditor.h"
#include "ui_argsdedieditor.h"

ArgsDediEditor::ArgsDediEditor(QWidget *parent,ArgsDediConfig *argsDediConfig) :
    QDialog(parent),
    ui(new Ui::ArgsDediEditor)
{
    ui->setupUi(this);
}

ArgsDediEditor::~ArgsDediEditor()
{
    delete ui;
}
