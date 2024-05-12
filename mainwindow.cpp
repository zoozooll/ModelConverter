#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QDialog>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>
#include <QtDebug>
#include <iostream>
#include "configsdialog.h"

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
//    if (!filePath.isEmpty())
//    {
//        string filePathData = filePath.toStdString();
//        Model model(filePathData);
//        model.convert();
//    }

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
//        model->appendRow(fields);
    }

    file.close();

    auto about = new ConfigsDialog();
    about->show();
}

