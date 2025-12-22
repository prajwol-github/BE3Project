#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function declarations
void gameIntro();
void menuFunc();
void stgameFunc();
bool userExists(const char codename[]);
bool loginUser(const char codename[], const char password[]);
void registerUser(const char codename[], const char password[]);
void instrucFunc();

#endif
