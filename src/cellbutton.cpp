
#include "cellbutton.h"
#include "cellbuttoneventfilter.h"

#include <QFile>

CellButton::CellButton(QWidget *parent) : QPushButton(parent) {

    m_eventFilter = new CellButtonEventFilter(this);
    installEventFilter(m_eventFilter);

    QFile styleFile;
    styleFile.setFileName("cellbutton.qss");

    if(styleFile.exists()) {
        styleFile.open(QFile::ReadOnly);
        setStyleSheet((QString) styleFile.readAll());
    } else {
        qWarning("File not found!!!");
    }
}

void CellButton::toHoverState() {
    setIcon(m_hoverIcon);
}

void CellButton::toDefaultState() {
    setIcon(m_defaultIcon);
}

void CellButton::setHoverIcon(const QIcon &icon) {
    m_hoverIcon = icon;
}

void CellButton::setDefaultIcon(const QIcon &icon) {
    m_defaultIcon = icon;
}
