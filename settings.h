#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QList>
#include <QSettings>
#include <QVariant>

#include "account.h"

class Settings
{
public:
    static QString getSteamPath();
    static QList<Account> getAccounts();
    static void setAccounts(const QList<Account>& accounts);
    static void setSteamPath(const QString& steamPath);
};

#endif // SETTINGS_H
