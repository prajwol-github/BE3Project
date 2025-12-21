#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// Function to handle login
bool loginsystem() {
    string username, password;

    // Default credentials
    string correctuser = "Hariram";
    string correctpassword = "bomb123";

    int attempts = 3;

    cout << "\n----- BOMB DIFFUSER LOGIN SYSTEM -----\n";

    while (attempts > 0) {
        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        if (username == correctuser && password == correctpassword) {
            cout << "\nAccess Granted!";
            cout << "\nLogin Successful!\n";
            return true;
        } else {
            attempts--;
            cout << "\nInvalid Credentials!";
            cout << "\nRemaining Attempts: " << attempts << endl;
        }
    }

    cout << "\nAccess Denied! Too many failed attempts.\n";
    return false;
}

// Intro screen
void introFunc() {
    cout << "==============================\n";
    cout << "        BOMB DIFFUSER         \n";
    cout << "==============================\n";
    cout << "You are the bomb diffuser expert.\n";
    cout << "Diffuse the bomb before it explodes!\n";
    cout << "Good Luck!\n\n";
}

// exploison timer
void explodeBomb(){
	cout<<"\n BOOM! bomb exploded!\n ";
}

// Play game with levels
void playGame() {
    int level;
    int timelimit;
    int answer;
    time_t startTime, endTime;

    cout << "\nSELECT LEVEL TO PLAY\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "Enter Level Choice: ";
    cin >> level;

  if(level == 1){
  	timelimit = 30;
  }
  else if (level == 2){
  	timelimit = 25;
  }
  else if(level == 3){
  	timelimit = 20;
  }
  else{
  	cout<<"Invalid Level! \n";
  	return;
  }
  
 cout << "\nYou have " << timelimit << " seconds to solve puzzles!\n" << endl;
  
  //start timer
  startTime = time(0);
  
  /*-------Puzzles Based on level-------*/

    // Ask puzzle
    if (level == 1){
    	cout << "Solve: 10 + 5 = ?\n";
	}
	
    else if (level == 2){
    	cout << "Solve: 12 x 4 = ?\n";
	}
    else if (level == 3){
    	cout << "Solve: (20 / 4) + 6 = ?\n";
	}

    cin >> answer;

    // End timer
    endTime = time(0);

    // Check if player took too long
    if (difftime(endTime, startTime) > timelimit) {
        explodeBomb();
        return;
    }

    // Check correct answer
    if ((level == 1 && answer == 15) ||
        (level == 2 && answer == 48) ||
        (level == 3 && answer == 11)) {
        cout << " Correct Answer! Bomb Defused!\n";
    } else {
        explodeBomb();
    }
}

// Menu function
void menuFunc() {
    int ch;

    cout << "GAME MENU SYSTEM\n";
    cout << "1. Play Game\n";
    cout << "2. Play Tournament\n";
    cout << "3. Game Instructions\n";
    cout << "4. Show Leaderboard\n";
    cout << "Enter Your Choice: ";
    cin >> ch;

    switch (ch) {
        case 1:
            if (loginsystem()) {
                playGame();
            } else {
                cout << "\nExiting Game...\n";
            }
            break;

        case 2:
            cout << "\nTournament Mode Coming Soon!\n";
            break;

        case 3:
            cout << "\nInstructions:\n";
            cout << "- Choose difficulty level\n";
            cout << "- Diffuse bomb before time runs out\n";
            cout << "- Wrong move may explode the bomb\n";
            break;

        case 4:
            cout << "\nLeaderboard Feature Coming Soon!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
    }
}

int main() {

    introFunc();
    menuFunc();
    return 0;
}

