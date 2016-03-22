#include "drawarea.h"

drawArea::drawArea(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    currentShape = shape();
    type = 1;
}

QSize drawArea::sizeHint() const
{
    return QSize(600, 600);
}

QSize drawArea::minimumSizeHint() const
{
    return QSize(400, 400);
}



void drawArea::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        released = false;
        if(currentShape.getStart().isNull())
        {
            currentShape.setStart(e->pos());
            currentShape.setPen(this->pen);
            currentShape.setType(this->type);
        }
    }
}


void drawArea::mouseMoveEvent(QMouseEvent* e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        currentShape.setEnd(e->pos());
        update(this->rect());
    }
}

void drawArea::mouseReleaseEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(this->type == POLYLINE || this->type == POLYGON)
        {
            currentShape.addPoint(e->pos());
        }
        else
        {
            currentShape.setEnd(e->pos());
            shapes.push_back(currentShape);
            currentShape.clearPoints();
            released = true;
        }
        update(this->rect());
    }
}

void drawArea::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(!released)
    {
        if(e->button() == Qt::RightButton)
        {
            currentShape.setEnd(currentShape.getPoints().back());
            shapes.push_back(currentShape);
            currentShape.clearPoints();
            released = true;
            update(this->rect());
        }
    }
}


void drawArea::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);

    for(unsigned int i=0; i<shapes.size(); i++)
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
        shape s = shapes[i];
        drawShape(s, painter);
    }

    if(!released)
    {
        painter.setRenderHint(QPainter::Antialiasing, true);
        drawShape(currentShape, painter);
    }

}


void drawArea::drawShape(shape figure, QPainter & painter)
{
    int t = figure.getType();
    painter.setPen(figure.getPen());
    QPainterPath path;
    QRectF rect;
    switch (t) {
    case LINE:
        painter.drawLine(figure.getStart(), figure.getEnd());
        break;
    case RECTANGLE:
        rect = QRectF(figure.getStart(), figure.getEnd());
        path.addRect(rect);
        painter.drawPath(path);
        break;
    case ELLIPSE:
        rect = QRectF(figure.getStart(), figure.getEnd());
        path.addEllipse(rect);
        painter.drawPath(path);
        break;
    case POLYLINE:
    {
        path = QPainterPath(figure.getStart());
        std::vector<QPoint> points = figure.getPoints();
        for(unsigned int i=0; i<points.size(); i++)
        {
            path.lineTo(points[i]);
        }
        if(!figure.getEnd().isNull())
            path.lineTo(figure.getEnd());
        painter.drawPath(path);
        break;
    }
    case POLYGON:
    {
        path = QPainterPath(figure.getStart());
        std::vector<QPoint> points = figure.getPoints();
        for(unsigned int i=0; i<points.size(); i++)
        {
            path.lineTo(points[i]);
        }
        if(!figure.getEnd().isNull())
            path.lineTo(figure.getEnd());
        path.lineTo(figure.getStart());
        painter.drawPath(path);
        break;
    }
    }

}

void drawArea::changeColor(int newColor)
{
    this->pen.setColor((Qt::GlobalColor) newColor);
}

void drawArea::changeColor(QColor nCol)
{
    this->pen.setColor(nCol);
}

void drawArea::changeLineStyle(int newStyle)
{
    this->pen.setStyle((Qt::PenStyle) newStyle);
}

void drawArea::changeLineWidth(int newWidth)
{
    this->pen.setWidth(newWidth);
}

void drawArea::selectType(int newType)
{
    this->type = newType;
}

void drawArea::deleteLastLine()
{
    if(shapes.size() > 0)
        shapes.pop_back();
    update();
}

void drawArea::clearAllLines()
{
    shapes.clear();
    update();
}
