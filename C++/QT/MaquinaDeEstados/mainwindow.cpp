#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    machine = new QStateMachine(this);

    s1 = new QState();
    s1->assignProperty(ui ->stateLabel, "text", "Current State: 1");
    s1->assignProperty(ui->pushButton_2, "geometry" , QRect(50, 200, 100, 50));

    s2 = new QState();
    s2->assignProperty(ui ->stateLabel, "text", "Current State: 2");
    s2->assignProperty(ui->pushButton_2, "geometry" , QRect(50, 200, 100, 50));

    // Create Animation

    animation = new QPropertyAnimation(ui->pushButton_2, "geometry");
    animation->setEasingCurve(QEasingCurve::OutElastic);

    //Adding Event Transition
    QEventTransition *t1 = new QEventTransition(ui->changeState, QEvent::MouseButtonPress);
    t1 ->setTargetState(s2);
    t1 ->addAnimation(animation);
    s1 ->addTransition(t1);

    QEventTransition *t2 = new QEventTransition(ui->changeState, QEvent::MouseButtonPress);
    t2 ->setTargetState(s1);
    t2 ->addAnimation(animation);
    s2 ->addTransition(t2);

    machine->addState(s1);
    machine->addState(s2);
    machine->setInitialState(s1);
    machine->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

