#include "argseditor.h"
#include "ui_argseditor.h"

ArgsEditor::ArgsEditor(QWidget *parent,ArgsConfig *argsConfig) :
    QDialog(parent),
    ui(new Ui::ArgsEditor)
{
    ui->setupUi(this);
}

ArgsEditor::~ArgsEditor()
{
    delete ui;
}
