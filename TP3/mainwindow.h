#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QVector>

#include "stroketraining.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addTemplate(GestureTemplate nTemp){gestTemplates.append(nTemp);}


private:
    Ui::MainWindow *ui;
    QVector<GestureTemplate> gestTemplates;

signals:

public slots:

};

#endif // MAINWINDOW_H
