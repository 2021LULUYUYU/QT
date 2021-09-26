#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QPixmap>

QStringList files;
int i = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_next->setEnabled(false);
    ui->pushButton_prev->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_prev_clicked()
{
    if(i == 0)
    {
        i = files.length() - 1;
    }
    else
        i--;
    ui->label->setPixmap(QPixmap(files[i]).scaled(ui->label->width(), ui->label->height()));
}

void MainWindow::on_pushButton_getpic_clicked()
{
    files = QFileDialog::getOpenFileNames(
                              this,
                              "Select one or more files to open",
                              "/home",
                              "Images (*.png *.xpm *.jpg)");

    if(!files.isEmpty())
    {
        ui->pushButton_next->setEnabled(true);
        ui->pushButton_prev->setEnabled(true);
    }
}

void MainWindow::on_pushButton_next_clicked()
{
    if(i == files.length() - 1)
    {
        i = 0;
    }
    else
        i++;
    ui->label->setPixmap(QPixmap(files[i]).scaled(ui->label->width(), ui->label->height()));
}

