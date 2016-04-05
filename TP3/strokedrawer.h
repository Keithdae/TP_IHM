#ifndef STROKEDRAWER_H
#define STROKEDRAWER_H

#include <QWidget>
#include <QPolygonF>
#include <QPainter>

class StrokeDrawer : public QWidget
{
    Q_OBJECT
public:
    explicit StrokeDrawer(QWidget *parent = 0);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;


    QPolygonF getStroke(){return this->stroke;}
    void setStroke(QPolygonF nStroke){this->stroke = nStroke;}
    void clear(){this->stroke.clear();}

protected:
    void paintEvent(QPaintEvent* e);
    QPolygonF stroke;

private:


signals:

public slots:

};

#endif // STROKEDRAWER_H
