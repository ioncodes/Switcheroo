#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      model(new AccountModel),
      accountDialog(new AccountDialog)
{
    ui->setupUi(this);

    auto steamPath = Settings::getSteamPath();

    if(!QFile::exists(steamPath))
    {
        steamPath = QFileDialog::getOpenFileName(this, tr("Open steam.exe"), "C:\\Program Files (x86)\\Steam\\", tr("steam.exe (*.exe)"));
        Settings::setSteamPath(steamPath);
    }

    ui->accounts->setModel(model);
    ui->accounts->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->accounts, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenu(const QPoint&)));
    connect(ui->actionAdd, SIGNAL(triggered()), this, SLOT(addAccount()));

    // QInputDialog for password
}

MainWindow::~MainWindow()
{
    auto accounts = model->all();
    Settings::setAccounts(accounts);

    delete ui;
    delete model;
    delete accountDialog;
}

void MainWindow::on_accounts_doubleClicked(const QModelIndex& index)
{
    auto account = model->get(index);

    Steam::kill();
    Steam::launch(account.userName, account.password);
}

void MainWindow::addAccount()
{
    accountDialog->exec();

    auto account = accountDialog->getAccount();

    if(!account.userName.isEmpty() && !account.displayName.isEmpty() && !account.password.isEmpty())
    {
        model->add(account);
        model->layoutChanged();
    }
}

void MainWindow::showContextMenu(const QPoint& pos)
{
    auto index = ui->accounts->indexAt(pos);

    if(index.isValid())
    {
        auto menu = new QMenu(ui->accounts);
        auto deleteAction = menu->addAction(QIcon(":/icons/cross.png"), "Delete");
        auto copyPasswordAction = menu->addAction(QIcon(":/icons/clipboard.png"), "Copy Password");

        auto deleteItemMapper = createMapper(deleteAction, index.row());
        connect(deleteItemMapper, SIGNAL(mapped(int)), this, SLOT(deleteItem(int)));

        auto copyPasswordMapper = createMapper(copyPasswordAction, index.row());
        connect(copyPasswordMapper, SIGNAL(mapped(int)), this, SLOT(copyPassword(int)));

        menu->exec(QCursor::pos());
    }
}

void MainWindow::deleteItem(int index)
{
   model->remove(index);
   model->layoutChanged();
}

void MainWindow::copyPassword(int index)
{
    auto password = model->all()[index].password;
    auto clipboard = QApplication::clipboard();

    clipboard->setText(password);
}

QSignalMapper* MainWindow::createMapper(QObject* action, int arg)
{
    auto signalMapper = new QSignalMapper(this);

    connect(action, SIGNAL(triggered()), signalMapper, SLOT(map()));
    signalMapper->setMapping(action, arg);

    return signalMapper;
}
