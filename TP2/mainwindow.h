#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QToolButton>
#include <QPushButton>
#include <QDockWidget>
#include <QSlider>
#include <QColorDialog>

#include <QDebug>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *);

public slots:
    void openFile();
    void saveFile();
    void quitApp();

};

#endif // MAINWINDOW_H
