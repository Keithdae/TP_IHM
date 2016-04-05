#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "stroketraining.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    QWidget* centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    QVBoxLayout* vLayout1 = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(vLayout1);

    // Galerie templates
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollWidget = new QWidget();
    QHBoxLayout* scrollLayout = new QHBoxLayout();
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    vLayout1->addWidget(scrollArea);


    QHBoxLayout* gestLayout = new QHBoxLayout();
    vLayout1->addLayout(gestLayout);

    QVBoxLayout* trainingLayout = new QVBoxLayout();
    QVBoxLayout* testLayout = new QVBoxLayout();
    gestLayout->addLayout(trainingLayout);
    gestLayout->addLayout(testLayout);

    StrokeTraining* trainingWidget = new StrokeTraining(this);
    trainingLayout->addWidget(trainingWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
