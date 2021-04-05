//
// Created by ivantretyak on 05.04.2021.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <string>
#include "../../include/evolutiong_game/Field.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *tmr;
    Field f = Field(50);
private slots:
    void updateField();
    void on_startButton_clicked();
    void on_pauseButon_clicked();
};
#endif // MAINWINDOW_H

