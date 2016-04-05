#include "strokedrawer.h"

StrokeDrawer::StrokeDrawer(QWidget *parent) :
    QWidget(parent)
{
}


QSize StrokeDrawer::sizeHint() const
{
    QRectF rect = stroke.boundingRect();
    return QSize(qMax(rect.width(), rect.height()),qMax(rect.width(), rect.height()));
}

QSize StrokeDrawer::minimumSizeHint() const
{
    QRectF rect = stroke.boundingRect();
    return QSize(qMax(rect.width(), rect.height()),qMax(rect.width(), rect.height()));
}

void StrokeDrawer::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawPolyline(this->stroke);
}
