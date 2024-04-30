#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>
#include <QtDebug>
#include <iostream>

#include "model.h"

using std::string;

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

void MainWindow::on_btnFileChoose_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this,
             tr("Open Model File"), "", tr("Model Files (*.obj)"));

    if (!fileName.isEmpty())
    {
        ui->editFilePath->setText(fileName);
    }

}


void MainWindow::on_btnConvert_clicked()
{
    auto filePath = ui->editFilePath->text();
    if (!filePath.isEmpty())
    {
        string filePathData = filePath.toStdString();
        Model model(filePathData);
//        model.loadModel();

        model.convert();
    }
}

