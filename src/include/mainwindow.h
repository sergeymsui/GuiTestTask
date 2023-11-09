#pragma once

#include <QMainWindow>

QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(Cell)

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    QAction* m_addAction;
    QAction* m_reloadAction;
    QVector<Cell*> m_cells;
private:
    void createToolBar();
private slots:
    void slotAddWidget();
    void slotReloadWidget();
public slots:
    void editCell(Cell*);
    void deleteCell(Cell*);
};
