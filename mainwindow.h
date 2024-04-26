#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Mesh;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnFileChoose_clicked();

    void on_btnConvert_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
