#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Function declarations
void gameIntro();
void menuFunc();
void stgameFunc();
bool userExists(const char codename[]);
bool loginUser(const char codename[], const char password[]);
void registerUser(const char codename[], const char password[]);
void instrucFunc();


// GAME INTRO
void gameIntro()
{
    cout << "WELCOME TO THE!";
    cout << "\n############################################";
    cout << "\n#                                          #";
    cout << "\n#          BOMB DIFFUSER GAME              #";
    cout << "\n#                                          #";
    cout << "\n############################################\n";
}

// MAIN MENU
void menuFunc()
{
    int choice;
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
}

// START GAME (LOGIN / REGISTER)
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
            // Game logic goes here
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

// CHECK IF USER EXISTS
bool userExists(const char codename[])
{
    ifstream file("users.txt");
    char u[25], p[50];

    while (file >> u >> p)
    {
        if (strcmp(u, codename) == 0)
            return true;
    }
    return false;
}

// LOGIN USER
bool loginUser(const char codename[], const char password[])
{
    ifstream file("users.txt");
    char u[25], p[50];

    while (file >> u >> p)
    {
        if (strcmp(u, codename) == 0 && strcmp(p, password) == 0)
            return true;
    }
    return false;
}

// REGISTER USER
void registerUser(const char codename[], const char password[])
{
    ofstream file("users.txt", ios::app);
    file << codename << " " << password << endl;
    cout << "\n✅ Registration Successful!\n";
}

// INSTRUCTIONS
void instrucFunc()
{
    cout << "\nINSTRUCTIONS:";
    cout << "\n- Login or register to play";
    cout << "\n- Complete challenges to diffuse the bomb";
    cout << "\n- Think fast. Time matters!\n";
}
