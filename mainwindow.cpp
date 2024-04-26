#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>
#include <QtDebug>
#include <iostream>

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
        auto filePathData = filePath.toStdString();
        Assimp::Importer importer;
        const aiScene* pScene = importer.ReadFile(filePathData, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace | aiProcess_EmbedTextures);

        Assimp::Exporter exporter;

        std::filesystem::path p(filePathData);
        auto outPath = p.replace_extension().string() + ".assbin";
        auto rs = exporter.Export(pScene, "assbin", outPath);
        switch (rs)	{
        case aiReturn_SUCCESS:
            qDebug() << ("Export result SUCCESS\n");
            break;
        default:
            std::cout << "Export result failed " << exporter.GetErrorString() << std::endl;
            break;
        }
    }
}

