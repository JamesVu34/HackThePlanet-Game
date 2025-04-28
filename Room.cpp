// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
#include "Room.h"
using namespace std;

// Default Constructor
Room::Room() {
    roomName = "";
    roomLevel = 0;
}

// Parameterized Constructor
Room::Room(string n, int l) {
    roomName = n;
    roomLevel = l;
}

// GETTER gets the room name
string Room::getRoomName() {
    return roomName;
}

// GETTER gets the room level
int Room::getRoomLevel() {
    return roomLevel;
}

// SETTER sets the room name
void Room::setRoomName(string n) {
    roomName = n;
}

// SETTER sets the room level
void Room::setRoomLevel(int l) {
    roomLevel = l;
}

// DISPLAY room info
void Room::displayRoomInfo() {
    cout << "Room Name: " << roomName << endl;
    cout << "Room Level: " << roomLevel << endl;
}