
#include "cellbutton.h"
#include "cellbuttoneventfilter.h"

#include <QEvent>

CellButtonEventFilter::CellButtonEventFilter(QObject *parent) : QObject(parent), m_parent(parent) {}

bool CellButtonEventFilter::eventFilter(QObject *obj, QEvent *event) {

    auto pb = dynamic_cast<CellButton*>(m_parent);

    if (obj == pb) {
        if (event->type() == QEvent::HoverEnter)
            pb->setHoverState();
        else if(event->type() == QEvent::HoverLeave)
            pb->setDefaultState();
    }

    return QObject::eventFilter(obj, event);
}
