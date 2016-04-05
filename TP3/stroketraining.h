#ifndef STROKETRAINING_H
#define STROKETRAINING_H

#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

#include "strokedrawer.h"
#include "gesturetemplate.h"
#include "mainwindow.h"


class MainWindow;

class StrokeTraining : public StrokeDrawer
{
    Q_OBJECT
public:
    StrokeTraining();
    StrokeTraining(MainWindow* parent);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;



protected:
    void mousePressEvent(QMouseEvent* e );
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);

private:
    bool pressed;
    void initInterface();
    QLineEdit* gestName;
    MainWindow* window;

signals:

public slots:
    void addTemplate();
};

#endif // STROKETRAINING_H
