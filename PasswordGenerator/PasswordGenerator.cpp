#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h> 
#include <string>
#include "PasswordGenerator.h"

const int PasswordLength = 20;

void ClearPassword(char password[PasswordLength], int numberOfOverwrites)
{
    while (numberOfOverwrites--)
    {
        for (int i = 0; i < PasswordLength; i++)
        {
            password[i] = '0';
        }
    }
}

void PrintPassword(char password[PasswordLength])
{
    for (int i = 0; i < PasswordLength; i++)
    {
        printf("%c", password[i]);
    }
    printf("\n");
}

void GenerateRandomPassword(char* password)
{
    srand((time(NULL)));

    char charactersUsedInGeneration[] = "0123456789abcdefghijklmnoqprstuvwyzxABCDEFGHIJKLMNOQPRSTUYWVZX!@#$^&*?-_";

    for (int i = 0; i < PasswordLength; i++)
    {
        password[i] = charactersUsedInGeneration[rand() % sizeof(charactersUsedInGeneration)];
    }
}

void GenerateEmptyPassword(char* password)
{
    for (int i = 0; i < PasswordLength; i++)
    {
        password[i] = '0';
    }
}

void CopyPasswordToClipboard(char password[PasswordLength])
{
    HWND hwnd = GetConsoleWindow();
    OpenClipboard(hwnd);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, PasswordLength + 1);
    memcpy(GlobalLock(hg), password, PasswordLength + 1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    ClearHGlobal(hg);
}

void ClearHGlobal(const HGLOBAL& hg)
{
    char clearedPassword[PasswordLength];
    GenerateEmptyPassword(clearedPassword);
    memcpy(GlobalLock(hg), clearedPassword, PasswordLength + 1);
    GlobalUnlock(hg);
    GlobalFree(hg);
}

void PrintMessageAndWaitToClear()
{
    printf("The password is now in the clipboard. \n");
    printf("After pasting the password press enter to clear the password from memory including the clipboard.\n");
    char c = getchar();
}

void ClearClipBoard()
{
    HWND hwnd = GetConsoleWindow();
    OpenClipboard(hwnd);
    EmptyClipboard();
    CloseClipboard();
}

void PrintClearedMessage()
{
    printf("The password has been cleared. \n");
}

int main()
{
    char password[PasswordLength];
    GenerateRandomPassword(password);
    CopyPasswordToClipboard(password);
    PrintMessageAndWaitToClear();
    ClearClipBoard();
    ClearPassword(password, 5);
    PrintClearedMessage();

    return 0;
}


