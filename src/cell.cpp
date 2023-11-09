
#include <QFile>

#include "cell.h"
#include "ui_cell.h"

Cell::Cell(QWidget *parent) : QPushButton(parent), ui(new Ui::Cell) {
    ui->setupUi(this);

    setFixedSize({230, 120});

    ui->nameLbl->setText("NAME");
    ui->ipLbl->setText("IP");

    connect(ui->pencil, &ClickableLabel::clicked, this, &Cell::slotEditPressed);
    connect(ui->trash, &ClickableLabel::clicked, this, &Cell::slotTrashPressed);

    QFile styleFile;
    styleFile.setFileName("cell.qss");

    if(styleFile.exists()) {
        styleFile.open(QFile::ReadOnly);
        setStyleSheet((QString) styleFile.readAll());
    } else {
        qWarning("File not found!!!");
    }
}

Cell::~Cell() {
    delete ui;
}

void Cell::setName(const QString &name) {
    ui->nameLbl->setText(name);
}

void Cell::setIp(const QString &ip) {
    ui->ipLbl->setText(ip);
}

QString Cell::getName() {
    return ui->nameLbl->text();
}

QString Cell::getIp() {
    return ui->ipLbl->text();
}

void Cell::slotTrashPressed() {
    emit deleteRequest(this);
}

void Cell::slotEditPressed() {
    emit edutRequest(this);
}
