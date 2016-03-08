#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPen>

#include <vector>

#define LINE 1
#define RECTANGLE 2
#define ELLIPSE 3
#define POLYLINE 4
#define POLYGON 5

class shape
{
    public:
        shape();

        void setStart(QPoint nStart){start = nStart;}
        void setEnd(QPoint nEnd){end = nEnd;}
        void setPen(QPen nPen){pen = nPen;}
        void setType(int nType){type = nType;}

        QPoint getStart(){return start;}
        QPoint getEnd(){return end;}
        QPen getPen(){return pen;}
        int getType(){return type;}

        void addPoint(QPoint nPoint){points.push_back(nPoint);}
        std::vector<QPoint> getPoints(){return points;}
        void clearPoints(){points.clear();}


    private:
        QPen pen;
        QPoint start;
        QPoint end;
        int type;

        std::vector<QPoint> points;
};

#endif // SHAPE_H
