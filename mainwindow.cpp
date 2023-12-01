#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    asdf();
}

MainWindow::~MainWindow()
{
    delete ui;


}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    asdf();
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    asdf();
}


void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    asdf();
}

void MainWindow::asdf(){
    f1 = ui->doubleSpinBox->value();
    f2 = ui->doubleSpinBox_2->value();
    f3 = ui->doubleSpinBox_3->value();

    fx = f1 * qCos(qDegreesToRadians(60)) - f3 * qSin(qDegreesToRadians(30));
    fy = -(f1 * qSin(qDegreesToRadians(60))) - f2 - f3 * qCos(qDegreesToRadians(30));
    fr = qSqrt((fx*fx)+(fy*fy));
    fa = ((-(f1 * qSin(qDegreesToRadians(60))) * 2 - 300 * 6 - f3 * qCos(qDegreesToRadians(30)) * 9 - 1500) / fy) - 6;

    ui->textBrowser->setText("");
    ui->textBrowser->append("ΣFx\t" + QString::number(fx) + " N");
    ui->textBrowser->append("ΣFy\t" + QString::number(fy) + " N");
    ui->textBrowser->append("ΣFr\t" + QString::number(fr) + " N");
    ui->textBrowser->append("ΣFa\t" + QString::number(fa) + " meters off point B");




}
