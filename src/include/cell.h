#pragma once

#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Cell; }
QT_END_NAMESPACE

class Cell : public QPushButton {
    Q_OBJECT
public:
    explicit Cell(QWidget* parent = nullptr);
    ~Cell();

    void setName(const QString &name);
    void setIp(const QString &ip);

    QString getName();
    QString getIp();
private:
    Ui::Cell* ui;
private slots:
    void slotTrashPressed();
    void slotEditPressed();
signals:
    void deleteRequest(Cell*);
    void editRequest(Cell*);
};
