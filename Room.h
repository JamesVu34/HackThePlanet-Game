// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
using namespace std;

class Room
{
    public:
    Room();     // default constructor
    Room(string, int);  // parameterized constructor

    // getters
    string getRoomName();   // returns the room name
    int getRoomLevel();     // returns the room level

    // setters
    void setRoomName(string);   // sets the room name
    void setRoomLevel(int);     // sets the room level

    // display
    void displayRoomInfo();     // displays the room info

    private:
    string roomName;
    int roomLevel;
};