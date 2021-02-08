#include "accountdialog.h"
#include "ui_accountdialog.h"

AccountDialog::AccountDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AccountDialog)
{
    ui->setupUi(this);
}

AccountDialog::~AccountDialog()
{
    delete ui;
}

Account AccountDialog::getAccount()
{
    auto account = Account{displayName, username, password};

    clear();

    return account;
}

void AccountDialog::on_buttonBox_accepted()
{
    username = ui->username->text();
    displayName = ui->displayName->text();
    password = ui->password->text();
}

void AccountDialog::clear()
{
    username = "";
    displayName = "";
    password = "";

    ui->username->setText("");
    ui->displayName->setText("");
    ui->password->setText("");
}
