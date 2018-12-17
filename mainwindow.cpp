#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAstroid_clicked()
{
    //change background color for the render area
    this->ui->renderArea->setBackgroundColor(Qt::red);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::green);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::yellow);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setBackgroundColor(Qt::black);
    this->ui->renderArea->repaint();
}
