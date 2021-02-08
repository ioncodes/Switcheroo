#include "settings.h"

Q_DECLARE_METATYPE(QList<Account>)

QString Settings::getSteamPath()
{
    QSettings settings("Layle", "Switcheroo");
    return settings.value("steam", "C:\\Program Files (x86)\\Steam\\steam.exe").value<QString>();
}

void Settings::setSteamPath(const QString& steamPath)
{
    QSettings settings("Layle", "Switcheroo");
    settings.setValue("steam", steamPath);
    settings.sync();
}

QList<Account> Settings::getAccounts()
{
    QSettings settings("Layle", "Switcheroo");
    return settings.value("accounts", QVariant::fromValue(QList<Account>())).value<QList<Account>>();
}

void Settings::setAccounts(const QList<Account>& accounts)
{
    QSettings settings("Layle", "Switcheroo");
    settings.setValue("accounts", QVariant::fromValue(accounts));
    settings.sync();
}
