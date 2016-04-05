#include "stroketraining.h"

StrokeTraining::StrokeTraining()
{
    pressed = false;
    initInterface();
    window = NULL;
}

StrokeTraining::StrokeTraining(MainWindow *parent)
{
    pressed = false;
    initInterface();
    window = parent;
}


void StrokeTraining::initInterface()
{
    QLabel* label = new QLabel(this);
    label->setText("Training");

    QLabel* gestLabel = new QLabel(this);
    gestLabel->setText("Template name :");
    gestLabel->move(0,20);

    this->gestName = new QLineEdit(this);
    gestName->move(110,20);
    QPushButton* saveButton = new QPushButton(this);
    saveButton->setText("Save template");
    saveButton->move(240,20);
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(addTemplate()));
}

QSize StrokeTraining::sizeHint() const
{
    return QSize(600,600);
}

QSize StrokeTraining::minimumSizeHint() const
{
    return QSize(400,400);
}



void StrokeTraining::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        pressed = true;
        clear();
        stroke << e->pos();
    }
}


void StrokeTraining::mouseMoveEvent(QMouseEvent* e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        if(pressed)
        {
            stroke << e->pos();
            update(this->rect());
        }
    }
}

void StrokeTraining::mouseReleaseEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(pressed)
        {
            pressed = false;
            stroke << e->pos();
            update(this->rect());
        }
    }
}


void StrokeTraining::addTemplate()
{
    if(window != NULL)
    {
        if(stroke.size() > 20)
        {
            GestureTemplate temp(stroke);
            QString str = gestName->text();
            if(str.size() > 0)
            {
                temp.setName(str);
                temp.normalize();
                window->addTemplate(temp);
            }
        }
    }
}
