// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
using namespace std;

class Hacker {
    public:
    Hacker();   // default constructor
    Hacker(string, int);    // parameterized constructor

    // getters
    string getHackerName();     // returns the hackers name
    int getHackerLevel();       // returns the hackers level

    // setters
    void setHackerName(string);       // sets the hackers name
    void setHackerLevel(int);         // sets the hacker level

    // display
    void displayHacker();             // displays hacker info

    // fight hacker
    double fightHacker(int internet, int numVPN, int roomLev);

    private:
    string hackerName;
    int hackerLevel;
};
