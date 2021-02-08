#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

struct Account
{
    QString displayName;
    QString userName;
    QString password;

    friend QDataStream& operator <<(QDataStream& arch, const Account& object)
    {
        arch << object.displayName;
        arch << object.userName;
        arch << object.password;

        return arch;
    }

    friend QDataStream& operator >>(QDataStream& arch, Account& object)
    {
        arch >> object.displayName;
        arch >> object.userName;
        arch >> object.password;

        return arch;
    }
};

#endif // ACCOUNT_H
