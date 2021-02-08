#ifndef STEAM_H
#define STEAM_H

#include <QString>
#include <QSettings>
#include <QProcess>
#include <QFileInfo>
#include <QDir>
#include <Windows.h>
#include <Tlhelp32.h>

#include "settings.h"

class Steam
{
public:
    void static kill();
    void static launch(QString username, QString password);
};

#endif // STEAM_H
