#include "steam.h"

void Steam::kill()
{
    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);

    auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32FirstW(snapshot, &entry) == TRUE)
    {
        while (Process32NextW(snapshot, &entry) == TRUE)
        {
            if (lstrcmpiW(entry.szExeFile, L"steam.exe") == 0)
            {
                auto process = OpenProcess(PROCESS_TERMINATE, 0, entry.th32ProcessID);

                if (process != NULL)
                {
                    TerminateProcess(process, 9);
                    CloseHandle(process);
                }

                break;
            }
        }
    }

    CloseHandle(snapshot);
}

void Steam::launch(QString username, QString password)
{
    auto steamPath = Settings::getSteamPath();
    auto steamDir = QFileInfo(steamPath).dir().canonicalPath();

    QProcess::startDetached(steamPath, {"-login", username, password}, steamDir);
}
