#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QAbstractListModel>
#include <QIcon>
#include <QSettings>
#include <QList>

#include "account.h"
#include "settings.h"

class AccountModel : public QAbstractListModel
{
    Q_OBJECT

public:
    AccountModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    const Account& get(const QModelIndex& index);
    void add(const Account& account);
    const QList<Account>& all();
    void remove(int index);
private:
    QList<Account> accounts;
};

#endif // ACCOUNTMODEL_H
