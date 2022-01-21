#ifndef ABOUTNS_H
#define ABOUTNS_H

#include <QDialog>

namespace Ui {
class aboutNS;
}

class aboutNS : public QDialog
{
    Q_OBJECT

public:
    explicit aboutNS(QWidget *parent = nullptr);
    ~aboutNS();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::aboutNS *ui;
};

#endif // ABOUTNS_H
