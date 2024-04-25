#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <assimp/Importer.hpp>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


}


void MainWindow::on_btnFileChoose_clicked()
{
    auto file1Name = QFileDialog::getOpenFileName(this,
             tr("Open Model File"), "", tr("Model Files (*.obj)"));

    if (!fileName.isEmpty())
    {
        ui->editFilePath->setText(file1Name);
    }

}

