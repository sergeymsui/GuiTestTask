
#include "cell.h"
#include "ui_cell.h"

#include <QFile>

Cell::Cell(QWidget *parent) : QPushButton(parent), ui(new Ui::Cell) {
    ui->setupUi(this);

    setFixedSize({230, 120});

    ui->nameLbl->setText("NAME");
    ui->ipLbl->setText("IP");

    // Default
    ui->pencil->setDefaultIcon(QIcon(":/pencil-solid.svg"));
    ui->trash->setDefaultIcon(QIcon(":/trash-solid.svg"));

    // Hover
    ui->pencil->setHoverIcon(QIcon(":/pencil-solid-hover.svg"));
    ui->trash->setHoverIcon(QIcon(":/trash-solid-hover.svg"));

    ui->pencil->toDefaultState();
    ui->trash->toDefaultState();

    connect(ui->pencil, &QPushButton::clicked, this, &Cell::slotEditPressed);
    connect(ui->trash, &QPushButton::clicked, this, &Cell::slotTrashPressed);

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
