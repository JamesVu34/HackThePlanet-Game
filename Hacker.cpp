// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
#include "Hacker.h"
using namespace std;

// Default Constructor
Hacker::Hacker() { 
    hackerName = "";
    hackerLevel = 0;
}

// Parameterized Constructor
Hacker::Hacker(string n, int l) {
    hackerName = n;
    hackerLevel = l;
}

// GETTER gets the hacker name
string Hacker::getHackerName() {
    return hackerName;
}

// GETTER gets the hacker level
int Hacker::getHackerLevel() {
    return hackerLevel;
}

// SETTER sets the hacker name
void Hacker::setHackerName(string n) {
    hackerName = n;
}

// SETTER sets the hackers level
void Hacker::setHackerLevel(int l) {
    hackerLevel = l;
}

// DISPLAY the hacker info
void Hacker::displayHacker() {
    cout << "Hacker Name: " << hackerName << endl;
    cout << "Hacker Level: " << hackerLevel << endl;
}

// fight hacker fnc
double Hacker::fightHacker(int internetLev, int numVPN, int roomLev) {
    // declare variables
    srand(time(NULL));
    double output;
    double f;
    double s;

    f = ((rand() % 6 + 1) * internetLev);
    s = ((rand() % 6 + 1) * roomLev) * (1 / numVPN);
    output = f - s;
    
    return output;
}