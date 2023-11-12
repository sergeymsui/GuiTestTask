#pragma once

#include <QPushButton>

class CellButtonEventFilter;

class CellButton : public QPushButton {
    Q_OBJECT
public:
    explicit CellButton(QWidget* parent = nullptr);

    void toHoverState();
    void toDefaultState();

    void setHoverIcon(const QIcon& icon);
    void setDefaultIcon(const QIcon& icon);
private:
    CellButtonEventFilter* m_eventFilter;

    QIcon m_hoverIcon;
    QIcon m_defaultIcon;
};


