#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(300, 600);
    this->m_timer = new QTimer(this);
    this->rnd = new QRandomGenerator();
    connect(this->m_timer, &QTimer::timeout, this, [this](){
        this->m_timer->setInterval(this->rnd->bounded(100, 1000));
        this->m_timer->start();
    });
    connect(this->m_timer, &QTimer::timeout, this, [this](){
        auto button = new QPushButton("*",this);
        button->setGeometry(this->rnd->bounded(0,this->frameGeometry().width()-22),rnd->bounded(1, 78),22,22);
        auto b_timer = new QTimer(button);
        auto apdate_timer = new QTimer(button);
        apdate_timer->setInterval(10);
        apdate_timer->start();
        bool flag = false;
        connect(apdate_timer, &QTimer::timeout, button, [button, this, b_timer, flag, apdate_timer]() mutable{
            if(!flag && button->underMouse()){
                auto inter = b_timer->interval();
                b_timer->setInterval(inter/2);
                b_timer->start();
                flag = true;
            }
            if(button->y() > this->frameGeometry().height()-22){
                QPalette palette;
                palette.setBrush(this->backgroundRole(), Qt::red);
                this->setPalette(palette);
                this->setWindowTitle("You Loose!");
                apdate_timer->stop();
            }
        });
        button->show();
        b_timer->setInterval(this->rnd->bounded(20,100));
        connect(b_timer, &QTimer::timeout, button, [button](){
            button->move(button->x(),button->y()+2);
        });
        connect(button,&QPushButton::clicked, button, [button](){
            button->~QPushButton();
        });
        b_timer->start();
    });
    this->m_timer->start();
}

MainWindow::~MainWindow()
{

}
