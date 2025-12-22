#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <windows.h> // required for Sleep()
#include "functions.h"

using namespace std;

// Shared global variables
const int ROWS = 10;
const int COLS = 20;
int playerX = 1, playerY = 1;
int bombX = 7, bombY = 15;
int timerSeconds = 10;

// ------------------- GAME INTRO -------------------
void gameIntro()
{
    cout << "WELCOME TO THE!";
    cout << "\n############################################";
    cout << "\n#                                          #";
    cout << "\n#          BOMB DIFFUSER GAME              #";
    cout << "\n#                                          #";
    cout << "\n############################################\n";
}

// ------------------- MAIN MENU -------------------
void menuFunc()
{
    int choice;
    do
    {
        cout << "\nMAIN MENU";
        cout << "\n1. Start Game";
        cout << "\n2. Instructions";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            stgameFunc();
            break;
        case 2:
            instrucFunc();
            break;
        case 3:
            cout << "Exiting Game. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

// ------------------- START GAME -------------------
void stgameFunc()
{
    char codename[25], password[50];
    cout << "\nEnter your Code Name: ";
    cin >> codename;
    cout << "Enter Your Password: ";
    cin >> password;

    if (userExists(codename))
    {
        if (loginUser(codename, password))
        {
            cout << "\n✅ Login Successful! Starting Game...\n";
            levelFunc();
        }
        else
        {
            cout << "\n❌ Incorrect Password. Access Denied.\n";
        }
    }
    else
    {
        char choice;
        cout << "\nUser Not Found. Register? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            registerUser(codename, password);
        }
        else
        {
            cout << "Exiting...\n";
        }
    }
}

// ------------------- USER FUNCTIONS -------------------
bool userExists(const char codename[])
{
    ifstream file("users.txt");
    if (!file)
        return false;
    char u[25], p[50];
    while (file >> u >> p)
        if (strcmp(u, codename) == 0)
            return true;
    return false;
}

bool loginUser(const char codename[], const char password[])
{
    ifstream file("users.txt");
    char u[25], p[50];
    while (file >> u >> p)
        if (strcmp(u, codename) == 0 && strcmp(p, password) == 0)
            return true;
    return false;
}

void registerUser(const char codename[], const char password[])
{
    ofstream file("users.txt", ios::app);
    file << codename << " " << password << endl;
    cout << "\n✅ Registration Successful!\n";
}

// ------------------- INSTRUCTIONS -------------------
void instrucFunc()
{
    cout << "\nINSTRUCTIONS:";
    cout << "\n- Login or register to play";
    cout << "\n- Reach the bomb 'B' before time runs out";
    cout << "\n- Use Arrow Keys or WASD to move your player 'P'\n";
}

// ------------------- LEVEL FUNCTION -------------------
void levelFunc()
{
    int levelChoice;
    cout << "\nSelect Level ";
    cout << "\n1. Easy ";
    cout << "\n2. Medium ";
    cout << "\n3. Hard \n";
    cout << "\nEnter your choice: ";
    cin >> levelChoice;

    switch (levelChoice)
    {
    case 1:
    {
        playerX = 1;
        playerY = 1;
        auto start = chrono::steady_clock::now();

        while (true)
        {
            // Calculate remaining time
            auto now = chrono::steady_clock::now();
            int elapsed = chrono::duration_cast<chrono::seconds>(now - start).count();
            int remainingTime = timerSeconds - elapsed;

            if (remainingTime <= 0)
            {
                system("cls");
                cout << "💥 Time's up! The bomb exploded!\n";
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            }

            // Check player movement
            movePlayer();

            // Draw the map
            drawMap(remainingTime);

            // Check if player reached bomb
            if (playerX == bombX && playerY == bombY)
            {
                system("cls");
                cout << "✅ Bomb diffused successfully! You win!\n";
                cout << "\nPress any key to return to menu...";
                _getch();
                break;
            }

            Sleep(50); // smooth loop
        }
        break;
    }
    case 2:
        cout << "\nMedium Level Coming Soon!\n";
        break;
    case 3:
        cout << "\nHard Level Coming Soon!\n";
        break;
    default:
        cout << "\nInvalid Choice. Returning to Menu.\n";
    }
}

// ------------------- DRAW MAP -------------------
void drawMap(int remainingTime)
{
    system("cls");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == playerX && j == playerY)
                cout << "P";
            else if (i == bombX && j == bombY)
                cout << "B";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << "\nTime Remaining: " << remainingTime << " seconds";
    cout << "\nUse Arrow Keys or WASD To Reach The Bomb!\n";
}

// ------------------- MOVE PLAYER -------------------
void movePlayer()
{
    if (_kbhit())
    {
        char key = _getch();

        // Arrow keys
        if (key == 224)
        {
            char arrow = _getch();
            switch (arrow)
            {
            case 72:
                if (playerX > 0)
                    playerX--;
                break; // Up
            case 80:
                if (playerX < ROWS - 1)
                    playerX++;
                break; // Down
            case 75:
                if (playerY > 0)
                    playerY--;
                break; // Left
            case 77:
                if (playerY < COLS - 1)
                    playerY++;
                break; // Right
            }
        }
        else
        {
            // WASD keys
            switch (key)
            {
            case 'w':
            case 'W':
                if (playerX > 0)
                    playerX--;
                break;
            case 's':
            case 'S':
                if (playerX < ROWS - 1)
                    playerX++;
                break;
            case 'a':
            case 'A':
                if (playerY > 0)
                    playerY--;
                break;
            case 'd':
            case 'D':
                if (playerY < COLS - 1)
                    playerY++;
                break;
            }
        }
    }
}
