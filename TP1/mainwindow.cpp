#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ui->setupUi(this);

    // Creation des menus
    QMenuBar* myMenuBar = menuBar();
    QMenu* fileMenu = myMenuBar->addMenu( tr("&File") );
    QToolBar* fileToolBar = addToolBar(tr("File"));

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
    QTextEdit* textEdit = new QTextEdit( this );
    setCentralWidget( textEdit );
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
