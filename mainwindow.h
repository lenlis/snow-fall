#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QRandomGenerator>
#include <QPushButton>
#include <QCursor>
#include <QWidget>
#include <QPalette>

class QPushButton;
class QTimer;
class QRandomGenerator;
class QCursor;
class QPalette;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTimer *m_timer;
    QRandomGenerator *rnd;
    QCursor *cursor;



};
#endif // MAINWINDOW_H
