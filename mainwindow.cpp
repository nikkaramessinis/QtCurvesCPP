#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->spinScale->setValue(this->ui->renderArea->scale());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui(){
     this->ui->spinScale->setValue(this->ui->renderArea->scale());
     this->ui->spinScale->setValue(this->ui->renderArea->intervalLength());
     this->ui->spinCount->setValue(this->ui->renderArea->stepCount());
}
void MainWindow::on_btnAstroid_clicked()
{
    //change background color for the render area
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();

}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HygensCicloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCicloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}

void MainWindow::on_spinInterval_valueChanged(double interval)
{
    this->ui->renderArea->setInterval(interval);
}

void MainWindow::on_spinCount_valueChanged(int count)
{
    this->ui->renderArea->setStepCount(count);
}

void MainWindow::on_btnBackground_clicked()
{
    QColor color=QColorDialog::getColor(ui->renderArea->backgroundColor(),this,"Select Color");
    ui->renderArea->setBackgroundColor(color);

}

void MainWindow::on_btnLineColor_clicked()
{
    QColor linecolor=QColorDialog::getColor(ui->renderArea->shapeColor(),this,"Select Color");
    ui->renderArea->setShapeColor(linecolor);
}
