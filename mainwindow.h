#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QList>
#include <QFileDialog>
#include <QSignalMapper>
#include <QClipboard>

#include "account.h"
#include "accountmodel.h"
#include "steam.h"
#include "accountdialog.h"
#include "settings.h"

Q_DECLARE_METATYPE(QList<Account>)

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_accounts_doubleClicked(const QModelIndex& index);
    void addAccount();
    void showContextMenu(const QPoint& pos);
    void deleteItem(int index);
    void copyPassword(int index);

private:
    Ui::MainWindow* ui;
    AccountModel* model;
    AccountDialog* accountDialog;
    QSignalMapper* createMapper(QObject* action, int arg);
};
#endif // MAINWINDOW_H
