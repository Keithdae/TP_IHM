#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QSize>
#include <QColor>
#include <QPen>


#include <QDebug>

#include "shape.h"

class drawArea : public QWidget
{
    Q_OBJECT
public:
    explicit drawArea(QWidget *parent = 0);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void mousePressEvent(QMouseEvent* e );
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void paintEvent(QPaintEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);

private:
    std::vector<shape> shapes;
    shape currentShape;

    bool released;

    QPen pen;
    int type;

    void drawShape(shape figure, QPainter & painter);


signals:

public slots:
    void changeColor(int newColor);
    void changeColor(QColor nCol);
    void changeLineWidth(int newWidth);
    void changeLineStyle(int newStyle);

    void selectType(int newType);

    void deleteLastLine();
    void clearAllLines();

};

#endif // DRAWAREA_H
