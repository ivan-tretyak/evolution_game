//
// Created by ivantretyak on 05.04.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i=0; i<50; i++)
        for(int j=0;j<50;j++)
        {
            QTableWidgetItem *t = new QTableWidgetItem("");
            ui->field->setItem(i,j,t);
        }
    ui->pauseButon->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateField()
{
    int countPredator = 0;
    int countHerbivor = 0;
    int countGrass = 0;
    int countMeat = 0;
    int countEmpty = 0;
    auto fieldf = f.getField();
    for (int y = 0; y < 50; y++){
        for (int x = 0; x < 50; x++) {
            switch (fieldf[y][x].getType()) {
                case cell_hebivor:
                    ui->field->item(y, x)->setBackground(Qt::cyan);
                    countHerbivor++;
                    break;
                case cell_predator:
                    ui->field->item(y, x)->setBackground(Qt::magenta);
                    countPredator++;
                    break;
                case food_grass:
                    ui->field->item(y, x)->setBackground(Qt::green);
                    countGrass++;
                    break;
                case food_meat:
                    ui->field->item(y, x)->setBackground(Qt::red);
                    countMeat++;
                    break;
                case border:
                    ui->field->item(y, x)->setBackground(Qt::darkGray);
                    break;
                case empty:
                    ui->field->item(y, x)->setBackground(Qt::white);
                    countEmpty++;
            }
        }
    }
    f.move();
    ui->num_steps->setText(QString::number(f.getSteps()));
    ui->num_predator->setText(QString::number(countPredator));
    ui->num_herbivor->setText(QString::number(countHerbivor));
    ui->num_grass->setText(QString::number(countGrass));
    ui->num_meat->setText(QString::number(countMeat));
    ui->num_empty->setText(QString::number(countEmpty));
}

void MainWindow::on_startButton_clicked()
{
    f = Field(50);
    tmr = new QTimer();
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateField()));
    tmr->start();
    ui->startButton->setDisabled(true);
    ui->pauseButon->setDisabled(false);
    ui->pauseButon->setText("Пауза");
}

void MainWindow::on_pauseButon_clicked()
{
    if (tmr->isActive()){
        tmr->stop();
        ui->pauseButon->setText("Продолжить");
        ui->startButton->setDisabled(false);
    } else {
        tmr->start();
        ui->pauseButon->setText("Пауза");
        ui->startButton->setDisabled(true);

    }
}