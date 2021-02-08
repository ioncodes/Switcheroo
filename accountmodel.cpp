#include "accountmodel.h"

AccountModel::AccountModel(QObject* parent)
    : QAbstractListModel(parent)
{
    this->accounts = Settings::getAccounts();
}

int AccountModel::rowCount(const QModelIndex& parent) const
{
    return accounts.size();
}

QVariant AccountModel::data(const QModelIndex& index, int role) const
{
    auto account = accounts.at(index.row());

    switch (role)
    {
    case Qt::DisplayRole:
        return QString("%1 / %2").arg(account.displayName, account.userName);

    case Qt::DecorationRole:
        return QIcon(":/icons/steam.png");

    default:
        return QVariant();
    }
}

void AccountModel::add(const Account& account)
{
    accounts.append(account);
}

const Account& AccountModel::get(const QModelIndex& index)
{
    return accounts.at(index.row());
}

const QList<Account>& AccountModel::all()
{
    return accounts;
}

void AccountModel::remove(int index)
{
    accounts.removeAt(index);
}
