#include "configsdialog.h"
#include "ui_configsdialog.h"

ConfigsDialog::ConfigsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigsDialog)
{
    ui->setupUi(this);
}

ConfigsDialog::~ConfigsDialog()
{
    delete ui;
}
