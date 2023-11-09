
#include "celldialog.h"

#include "ui_celldialog.h"

CellDialog::CellDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CellDialog) {
    ui->setupUi(this);
}

CellDialog::~CellDialog() {
    delete ui;
}

QString CellDialog::getName() {
    return ui->nameLe->text();
}

QString CellDialog::getIp() {
    return ui->ipLe->text();
}

void CellDialog::setName(const QString &name) {
    ui->nameLe->setText(name);
}

void CellDialog::setIp(const QString &ip) {
    ui->ipLe->setText(ip);
}
