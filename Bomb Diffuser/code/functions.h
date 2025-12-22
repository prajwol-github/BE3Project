#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void gameIntro();
void menuFunc();
void stgameFunc();
bool userExists(const char codename[]);
bool loginUser(const char codename[], const char password[]);
void registerUser(const char codename[], const char password[]);
void instrucFunc();
void levelFunc();
void drawMap(int remainingTime);
void movePlayer();

#endif
