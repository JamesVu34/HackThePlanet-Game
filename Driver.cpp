// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
#include "Start.h"
#include "BestBuy.h"
#include "Hacker.h"
#include "Room.h"
#include "Game.h"
using namespace std;

/*   DRIVER FILE    */

int main(){
    // test start class
    // Start s = Start();
    
    // // default constructor
    // cout << "Player Name: " << s.getName() << endl;
    // cout << "Frustration Level: " << s.getFrustLevel() << endl;

    // // checking setter for name
    // s.setName("James");
    // cout << "Player Name: " << s.getName() << endl;

    // // checking setter for frustration level
    // s.setFrustLevel(50);
    // cout << "Frustration Level: " << s.getFrustLevel() << endl;

    // // parameterized constructor
    // Start s2 = Start("Someone", 50);
    // cout << "Player Name: " << s2.getName() << endl;
    // cout << "Frustration Level: " << s2.getFrustLevel() << endl;

    // // checking display
    // s2.display();

    /////////////////////////////////

    // test best buy class
    // BestBuy b = BestBuy();

    // // default constructor
    // cout << "Doge Coins: " << b.getDogeCoins() << endl;
    // cout << "Computer: " << b.getComp() << endl;
    // cout << "VPN: " << b.getVPN() << endl;
    // cout << "Internet: " << b.getInternet() << endl;

    // // checking setter for doge coins
    // b.setDogeCoins(100);
    // cout << "Doge Coins: " << b.getDogeCoins() << endl;

    // // checking setter for computer
    // b.setComp(2);
    // cout << "Computer: " << b.getComp() << endl;

    // // checking setter for VPN
    // b.setVPN(2);
    // cout << "VPN: " << b.getVPN() << endl;

    // // checking setter for internet
    // b.setInternet(2);
    // cout << "Internet: " << b.getInternet() << endl;

    // // parameterized constructor
    // BestBuy b2 = BestBuy(350, 2, 1, 1);
    // cout << "Doge Coins: " << b2.getDogeCoins() << endl;
    // cout << "Computer: " << b2.getComp() << endl;
    // cout << "VPN: " << b2.getVPN() << endl;
    // cout << "Internet: " << b2.getInternet() << endl;

    // // checking display
    // b2.displayInfo();

    // // checking buyCPU
    // if there is any error with the object check the parameters
    // BestBuy b = BestBuy(15, 1, 1, 1, 0, 0);

    // b.buyCPU(1);
    // cout << "CPU: " << b.getCPU() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // // checking buyGPU
    // BestBuy b = BestBuy(30, 1, 1, 1, 0, 0);

    // b.buyGPU(2);
    // cout << "GPU: " << b.getGPU() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking Power Supply Units
    // BestBuy b = BestBuy(5, 1, 1, 1, 0, 0, 0);
    // b.buyPSU(1);
    // cout << "Power Supply Units: " << b.getPSU() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking buyCompCase
    // BestBuy b = BestBuy(45, 1, 1, 1, 0, 0, 0, 0);
    // b.buyCompCase(6);
    // cout << "Computer Cases: " << b.getCompCase() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking buyIntCard
    // BestBuy b = BestBuy(45, 1, 1, 1, 0, 0, 0, 0, 0);
    // b.buyIntCard(-1);
    // cout << "Internet cards: " << b.getIntCard() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking buyKeyMouse
    // BestBuy b = BestBuy(45, 1, 1, 1, 0, 0, 0, 0, 0, 0);
    // b.buyKeyMouse(9);
    // cout << "Keyboard and Mouses: " << b.getKeyMouse() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // test buyPremadeComp
    // BestBuy b = BestBuy(200, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0);
    // b.buyPremadeComp(2);
    // cout << "Premade Computers: " << b.getPremadeComp() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking buyAVS
    // BestBuy b = BestBuy(100, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    // b.buyAVS(50);
    // cout << "Antivirus Software: " << b.getAVS() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking buyVPN
    // BestBuy b = BestBuy(20, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    // b.buyVPN(1);
    // cout << "VPN: " << b.getVPN() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;

    // checking buyInt
    // BestBuy b = BestBuy(20, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0);
    // b.buyInt(5);
    // cout << "Internet Provider Level: " << b.getInternet() << endl;
    // cout << "DogeCoins: " << b.getDogeCoins() << endl;
    

    // /////////////////////////////////

    // // test Hacker class
    // Hacker h = Hacker();

    // // default constructor
    // cout << "Hacker Name; " << h.getHackerName() << endl;
    // cout << "Hacker Level: " << h.getHackerLevel() << endl;

    // // checking setter for name
    // h.setHackerName("John");
    // cout << "Hacker Name; " << h.getHackerName() << endl;

    // // checking setter for level
    // h.setHackerLevel(3);
    // cout << "Hacker Level: " << h.getHackerLevel() << endl;

    // // parameterized constructor
    // Hacker h2 = Hacker("Jimmy", 4);
    // cout << "Hacker Name; " << h2.getHackerName() << endl;
    // cout << "Hacker Level: " << h2.getHackerLevel() << endl;

    // // testing display
    // h2.displayHacker();


    // /////////////////////////////////

    // // testing Room class
    // Room r = Room();

    // // default constructor
    // cout << "Room Name: " << r.getRoomName() << endl;
    // cout << "Room Level: " << r.getRoomLevel() << endl;

    // // checking setter for name
    // r.setRoomName("Test Room");
    // cout << "Room Name: " << r.getRoomName() << endl;

    // // checking setter for level
    // r.setRoomLevel(3);
    // cout << "Room Level: " << r.getRoomLevel() << endl;

    // // parameterized constructor
    // Room r2 = Room("T2 Room", 4);
    // cout << "Room Name: " << r2.getRoomName() << endl;
    // cout << "Room Level: " << r2.getRoomLevel() << endl;

    // // checking display
    // r2.displayRoomInfo();


    // /////////////////////////////////

    // CHECKING GAME CLASS
    
    // checking buymenu
    


    return 0;
}