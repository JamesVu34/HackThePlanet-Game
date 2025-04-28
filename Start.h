// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
using namespace std;

class Start {
    public:
    Start();                   // default constructor
    Start(string, int, int);   // parameterized constructor
    
    // getters
    string getName();          // returns the players name
    int getFrustLevel();       // returns the players frustration leve
    int getVirus();

    // setters
    void setName(string);         // set the player name to user input
    void setFrustLevel(int);      // sets the players frustration level
    void setVirus(int);

    void display();            // displays the players details
    int misfortuneGen();       // generates a mis fortune number

    int puzzle1();            // the first puzzle
    int puzzle2();            // the second puzzle
    int puzzle3();            // the third puzzle
    int puzzle4();            // the fourth puzzle
    int puzzle5();            // the fifth puzzle

    private:
    string name;
    int frustrationLevel;
    int virus;
};