// PasswordGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

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


int main()
{
    char password[PasswordLength];
    GenerateRandomPassword(password);
    PrintPassword(password);
    ClearPassword(password, 5);

    return 0;
}


