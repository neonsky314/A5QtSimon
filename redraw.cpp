#include "redraw.h"
#include <QApplication>

Redraw::Redraw()
{

}

void Redraw::redrawScreen() {
    qApp->processEvents();
}
