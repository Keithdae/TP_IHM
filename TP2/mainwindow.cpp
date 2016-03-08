#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawarea.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ui->setupUi(this);

    // Creation des menus
    QMenuBar* myMenuBar = menuBar();
    QMenu* fileMenu = myMenuBar->addMenu( tr("&File") );
    QToolBar* fileToolBar = addToolBar(tr("File"));
    QToolBar* widthBar = addToolBar(tr("Width"));
    QToolBar* styleBar = addToolBar(tr("Styles"));
    QToolBar* operationBar = addToolBar(tr("Operations"));
    QToolBar* typeBar = addToolBar(tr("Types"));
    addToolBarBreak();
    QToolBar* colorBar = new QToolBar(tr("Colors"), this);
    addToolBar(Qt::LeftToolBarArea, colorBar);

    // Creation des actions
    QAction* open = new QAction(QIcon(":/icons/images/open.png"), tr("&Open..."), this);
    open->setShortcut(tr("Ctrl+O"));
    open->setToolTip(tr("Open File"));
    open->setStatusTip(tr("Open File"));

    QAction* save = new QAction(QIcon(":/icons/images/save.png"), tr("&Save..."), this);
    save->setShortcut(tr("Ctrl+S"));
    save->setToolTip(tr("Save File"));
    save->setStatusTip(tr("Save File"));

    QAction* quit = new QAction(QIcon(":/icons/images/quit.png"), tr("&Quit..."), this);
    quit->setShortcut(tr("Ctrl+Q"));
    quit->setToolTip(tr("Quit Application"));
    quit->setStatusTip(tr("Quit Application"));

    // Ajout des actions aux menus
    fileMenu->addAction(open);
    fileMenu->addAction(save);
    fileMenu->addAction(quit);
    fileToolBar->addAction(open);
    fileToolBar->addAction(save);
    fileToolBar->addAction(quit);

    // Connecte les signaux au slot pour réaliser les actions
    connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(quit, SIGNAL(triggered()), this, SLOT(quitApp()));

    // On ajoute une zone de texte centrale
    drawArea* draw = new drawArea(this);
    setCentralWidget(draw);

    /*
    // Ajout des boutons pour choisir la couleur
    QButtonGroup* colorGroup = new QButtonGroup(this);
    QToolButton* redButton = new QToolButton();
    QToolButton* blueButton = new QToolButton();
    colorGroup->addButton(redButton,7) ;
    colorGroup->addButton(blueButton,9);
    colorBar->addWidget(redButton);
    colorBar->addWidget(blueButton);

    connect(colorGroup, SIGNAL(buttonClicked(int)), draw, SLOT(changeColor(int)));*/


    // Ajout des boutons pour choisir le style
    QButtonGroup* styleGroup = new QButtonGroup(this);
    QPushButton* solidLineButton = new QPushButton("Solid Line");
    QPushButton* dashLineButton = new QPushButton("Dash Line");
    styleGroup->addButton(solidLineButton,1) ;
    styleGroup->addButton(dashLineButton,2);
    styleBar->addWidget(solidLineButton);
    styleBar->addWidget(dashLineButton);

    connect(styleGroup, SIGNAL(buttonClicked(int)), draw, SLOT(changeLineStyle(int)));

    // Ajout d'une boite de dialogue pour choisir la couleur
    QColorDialog* colorDial = new QColorDialog(this);
    colorDial->setWindowFlags(Qt::Widget);
    colorDial->setOptions(QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
    colorBar->addWidget(colorDial);

    connect(colorDial, SIGNAL(currentColorChanged(QColor)), draw, SLOT(changeColor(QColor)));

    // Ajout du menu pour la selection de l'epaisseur de trait
    QSlider* widthSlider = new QSlider(this);
    widthSlider->setMinimum(1);
    widthSlider->setSingleStep(1);
    widthSlider->setMaximum(10);
    widthBar->addWidget(widthSlider);
    widthSlider->setOrientation(Qt::Horizontal);
    widthSlider->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    connect(widthSlider, SIGNAL(valueChanged(int)), draw, SLOT(changeLineWidth(int)));

    // Ajout de la toolbar pour les operations (clear, delete last)
    QPushButton* clearButton = new QPushButton("Clear window");
    QPushButton* deleteLastButton = new QPushButton("Delete last shape");
    operationBar->addWidget(clearButton);
    operationBar->addWidget(deleteLastButton);

    connect(clearButton, SIGNAL(clicked()), draw, SLOT(clearAllLines()));
    connect(deleteLastButton, SIGNAL(clicked()), draw, SLOT(deleteLastLine()));


    // Ajout d'un menu pour selectionner le type de figure que l'on peut tracer
    QButtonGroup* typeGroup = new QButtonGroup(this);
    QPushButton* lineButton = new QPushButton("Line");
    QPushButton* rectangleButton = new QPushButton("Rectangle");
    QPushButton* ellipseButton = new QPushButton("Ellipse");
    QPushButton* polylineButton = new QPushButton("Polyline");
    QPushButton* polygonButton = new QPushButton("Polygon");
    typeGroup->addButton(lineButton, LINE) ;
    typeGroup->addButton(rectangleButton, RECTANGLE);
    typeGroup->addButton(ellipseButton, ELLIPSE);
    typeGroup->addButton(polylineButton, POLYLINE);
    typeGroup->addButton(polygonButton, POLYGON);
    typeBar->addWidget(lineButton);
    typeBar->addWidget(rectangleButton);
    typeBar->addWidget(ellipseButton);
    typeBar->addWidget(polylineButton);
    typeBar->addWidget(polygonButton);

    connect(typeGroup, SIGNAL(buttonClicked(int)), draw, SLOT(selectType(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName( this,
                                                    tr("Open File"), // titre
                                                    "~/", // répertoire initial
                                                    tr("Html Files (*.html)") // filtre
                                                    );
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Ouverture reussie du fichier en lecture : " << fileName;
        QTextStream stream(&file);
        QString content = stream.readAll();
        QTextEdit* textEdit = this->findChild<QTextEdit*>();
        textEdit->setHtml(content);
    }
    else
    {
        qDebug() << "Ouverture du fichier impossible";
    }
}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getOpenFileName( this,
                                                    tr("Save File"), // titre
                                                    "~/", // répertoire initial
                                                    tr("Html Files (*.html)") // filtre
                                                    );
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Ouverture reussie du fichier en ecriture : " << fileName;
        QTextEdit* textEdit = this->findChild<QTextEdit*>();
        QString text = textEdit->toHtml();
        QTextStream stream(&file);
        stream << text;
    }
    else
    {
        qDebug() << "Ouverture du fichier impossible";
    }
}

void MainWindow::quitApp()
{
    this->close();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox msgBox;
    msgBox.setText("Quit application ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

