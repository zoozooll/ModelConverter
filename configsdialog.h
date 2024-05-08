#ifndef CONFIGSDIALOG_H
#define CONFIGSDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigsDialog;
}

class ConfigsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigsDialog(QWidget *parent = nullptr);
    ~ConfigsDialog();

private:
    Ui::ConfigsDialog *ui;
};

#endif // CONFIGSDIALOG_H
