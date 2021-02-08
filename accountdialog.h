#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>

#include "account.h"

namespace Ui {
class AccountDialog;
}

class AccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDialog(QWidget* parent = nullptr);
    ~AccountDialog();

    Account getAccount();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AccountDialog* ui;
    QString username;
    QString displayName;
    QString password;
    void clear();
};

#endif // ACCOUNTDIALOG_H
