
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cell.h"
#include "celldialog.h"

#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    createToolBar();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createToolBar() {
    auto toolBar = new QToolBar(this);

    m_addAction = toolBar->addAction(QIcon(":/plus-solid.svg"), tr("Add"));
    connect(m_addAction, &QAction::triggered, this, &MainWindow::slotAddWidget);

    m_reloadAction = toolBar->addAction(QIcon(":/rotate-right-solid.svg"), tr("Reload"));
    connect(m_reloadAction, &QAction::triggered, this, &MainWindow::slotReloadWidget);

    addToolBar(toolBar);
}

void MainWindow::slotAddWidget() {

    CellDialog dialog(this);
    auto state = dialog.exec();

    if(state == QDialog::Accepted) {
        auto cell = new Cell(this);

        cell->setName(dialog.getName());
        cell->setIp(dialog.getIp());

        connect(cell, &Cell::editRequest, this, &MainWindow::editCell);
        connect(cell, &Cell::deleteRequest, this, &MainWindow::deleteCell);

        ui->cellLayout->insertWidget(0, cell);
        m_cells.append(cell);
    }
}

void MainWindow::slotReloadWidget() {
    for(int i {0}; i < m_cells.size(); i++) {
        auto it = m_cells.at(i);
        delete it;
    }
    m_cells.clear();
}

void MainWindow::editCell(Cell* c) {
    auto index = m_cells.indexOf(c);
    auto cell  = m_cells.at(index);

    CellDialog dialog(this);
    dialog.setName(cell->getName());
    dialog.setIp(cell->getIp());
    auto state = dialog.exec();

    if(state == QDialog::Accepted) {
        cell->setName(dialog.getName());
        cell->setIp(dialog.getIp());
    }
}

void MainWindow::deleteCell(Cell *c) {
    auto index = m_cells.indexOf(c);
    auto cell  = m_cells.at(index);

    m_cells.removeAt(index);
    delete cell;
}

