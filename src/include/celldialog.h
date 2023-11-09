#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class CellDialog; }
QT_END_NAMESPACE

class CellDialog : public QDialog {
    Q_OBJECT
public:
    explicit CellDialog(QWidget* parent = nullptr);
    ~CellDialog();

    QString getName();
    QString getIp();

    void setName(const QString& name);
    void setIp(const QString& ip);
private:
    Ui::CellDialog* ui;
};
