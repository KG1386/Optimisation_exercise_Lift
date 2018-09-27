#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "string"
#include <array>
#include "misc.h"
#include <future>
#include <pthread.h>
#include <chrono>
#include <curses.h>

using namespace std;


// Creates instances of lifts that operate in building
class lift {
private:
    unsigned int liftSize = 0;
public:
    void setLiftSize(unsigned int size){
        liftSize = size;
    }
    void showLiftParams(){
        cout << liftSize << endl;
    }
};

// Stores some parameters for the building we operate in
class building {
private:
    unsigned int numOfPeople = 0;
    unsigned int numOfStories = 0;
public:
    void setNumOfPeople(unsigned int people_num){
        numOfPeople = people_num;
    }
    void setStoriesNum( unsigned int stories_num){
        numOfStories = stories_num;
    }
};

char userInt(){
    initscr();
    timeout(-1);
    int c = getch();
    //endwin();
    return c;
}

void startLifts() {
    cout << "Hey there, lifts started" << endl;
    while (userInt() != 0){
        timeout(3000);
        cout << "here we float" << endl;
    }
    exit(0);
}

bool checkUserInput(int questionNo, string input) {

    switch (questionNo) {
        // Start the initialisation process for lifts?
        case 0:
            if (input == "Y" || input == "y") {
                return true;
            }
        // Number of lifts
        case 1:
            cout << stoi(input) <<endl;
            if (stoi(input) >= 1 && stoi(input) <= 100) {
                return true;
            }
        // Lift size (in number of people)
        case 2:
            if (stoi(input) >= 3 && stoi(input) <= 16) {
                return true;
            }
        // Number of people in building
        case 3:
            if (stoi(input) >= 10 && stoi(input) <= 1000) {
                return true;
            }
        //Number of levels in building
        case 4:
            if (stoi(input) >= 2 && stoi(input) <= 500) {
                return true;
            }
    }
    return false;
}

int main() {
    startLifts();
    cout << getPersonWeight(70.0, 20.0, 20.0, 200.0) << endl;
    bool startLifts_flag = true;
    string userInput;
    string numOfLifts;
    unsigned int numOfStories;
    unsigned int numOfPeople;
    lift L[16];
    while (startLifts_flag) {
        for (int i = 0; i <= 4; i++) {
            if (i == 0) {
                cout << "Start lift initialisation?(Y/N)" << endl;
                cin >> userInput;
                if (checkUserInput(i, userInput)) {
                    cout << "Accepted" << endl;
                } else {
                    cout << "Parameter declined, try again" << endl;
                    break;
                }
            }
            if (i == 1) {
                cout << "Enter number of lifts (1 to 16)" << endl;
                cin >> numOfLifts;
                if (checkUserInput(i, numOfLifts)) {
                    cout << "Accepted" << endl;
                    lift L[stoi(numOfLifts)]; // create an array of lift objects
                } else {
                    cout << "Parameter declined, try again" << endl;
                    break;
                }
            }
            if (i == 2) {
                cout << "Enter sizes of lifts (1 to 16)" << endl;
                for (int i = 1; i <= stoi(numOfLifts); i++) {
                    cout << "Enter size of lift " << i << endl;
                    cin >> userInput;
                    if (checkUserInput(i, userInput)) {
                        cout << "Accepted" << endl;
                        L[i].setLiftSize(stoi(userInput));
                    } else {
                        cout << "Parameter declined, try again" << endl;
                        break;
                    }
                }
            }
            if (i == 3) {
                cout << "Enter number of people in building" << endl;
                cin >> userInput;
                if (checkUserInput(i, userInput)) {
                    cout << "Accepted" << endl;
                    numOfPeople = stoi(userInput);
                } else {
                    cout << "Parameter declined, try again" << endl;
                    break;
                }
            }
            if (i == 4) {
                cout << "Enter number of stories in building" << endl;
                cin >> userInput;
                if (checkUserInput(i, userInput)) {
                    cout << "Accepted" << endl;
                    numOfStories = stoi(userInput);
                }
                else {
                    cout << "Parameter declined, try again" << endl;
                    break;
                }
            }
        }
        startLifts_flag = false;
    }
    for (int i = 0; i <= stoi(numOfLifts); i++) {
        L[i].showLiftParams();
    }
    startLifts();
    return 0;
}