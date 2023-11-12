#pragma once

#include <QObject>

class CellButtonEventFilter : public QObject {
    Q_OBJECT
public:
    explicit CellButtonEventFilter(QObject* parent = nullptr);

    bool eventFilter(QObject *obj, QEvent *event);
private:
    QObject* m_parent;
};
