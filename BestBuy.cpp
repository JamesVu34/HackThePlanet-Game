// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
#include "BestBuy.h"
using namespace std;

// Default Constructor
BestBuy::BestBuy() {
    dogeCoins = 200;
    computer = 1;
    VPN = 1;
    internet = 1;
    CPU = 0;
    GPU = 0;
    PSU = 0;
    compCase = 0;
    internetCard = 0;
    keyMouse = 0;
    premadeComp = 0;
    AVS = 0;
    compMaintenceLev = 100;
}

// Parameterized Constructor
BestBuy::BestBuy(double coins, int comp, int vpnLevel, int internetLevel, int numCPU, int numGPU, int numPSU, int numCompCase, int numIntCard, int numKeyMouse, int numPremadeComp, int numAVS, int cMaintienceLev) {
    dogeCoins = coins;
    computer = comp;
    VPN = vpnLevel;
    internet = internetLevel;
    CPU = numCPU;
    GPU = numGPU;
    PSU = numPSU;
    compCase = numCompCase;
    internetCard = numIntCard;
    keyMouse = numKeyMouse;
    premadeComp = numPremadeComp;
    AVS = numAVS;
    compMaintenceLev = cMaintienceLev;
}

// GETTER to get the players dogeCoins
double BestBuy::getDogeCoins() {
    return dogeCoins;
}

// GETTER to get the players computer
int BestBuy::getComp() {
    if (computer > 0 && computer < 3){
        return computer;
    }
    else {
        cout << "You cannot have more than 2 computers." << endl;
    }

    return computer;
}

// GETTER to get the players VPN level
int BestBuy::getVPN() {
    if (VPN > 0 && VPN < 3) {
        return VPN;
    }
    else {
        cout << "You cannot have more than 2 VPNs." << endl;
    }
    return VPN;
}

// GETTER to get players internet level
int BestBuy::getInternet() {
    return internet;
}

// GETTER to get the players CPU amount
int BestBuy::getCPU() {
    return CPU;
}

// GETTER to get the player GPU amount
int BestBuy::getGPU() {
    return GPU;
}

// GETTER returns the player PSU amount
int BestBuy::getPSU() {
    return PSU;
}

// GETTER returns the player Computer Case amount
int BestBuy::getCompCase() {
    return compCase;
}

// GETTER returns the players internet card amount
int BestBuy::getIntCard() {
    return internetCard;
}

// GETTER returns the players keyboards and mouses
int BestBuy::getKeyMouse() {
    return keyMouse;
}

// GETTER returns the players premade computers
int BestBuy::getPremadeComp() {
    return premadeComp;
}

// GETTER returns the players amount of antivirus software
int BestBuy::getAVS() {
    return AVS;
}

// GETTER returns the computer maintence level
int BestBuy::getCompMaintenceLev() {
    return compMaintenceLev;
}

// SETTER to set the players amount of dogeCoins
void BestBuy::setDogeCoins(double numDogeCoin) {
    if (dogeCoins > 0){
        dogeCoins = numDogeCoin;
    }
    else if (dogeCoins == 0) {
        cout << "You have no more DogeCoins!" << endl;
    }
    else {
        cout << "Error: No money left." << endl;
    }
}

// SETTER to set the computer
void BestBuy::setComp(int comp) {
    computer = comp;
} 

// SETTER to set VPN level
void BestBuy::setVPN(int vpnLevel) {
    VPN += vpnLevel;
}

// SETTER to set interenet level
void BestBuy::setInternet(int internetLevel) {
    internet = internetLevel;
}

// SETTER to set players CPU
void BestBuy::setCPU(int c) {
    CPU = c;
}

// SETTER to set players GPU
void BestBuy::setGPU(int g) {
    GPU = g;
}

// SETTER sets the players PSU
void BestBuy::setPSU(int p) {
    PSU = p;
}

// SETTER sets the players Computer Case
void BestBuy::setCompCase(int c) {
    compCase = c;
}

// SETTER sets the player Internet Card
void BestBuy::setIntCard(int i) {
    internetCard = i;
}

// SETTER sets the player keyboards and mouses
void BestBuy::setKeyMouse(int k) {
    keyMouse = k;
}

// SETTER sets the players premade computer
void BestBuy::setPremadeComp(int c) {
    premadeComp = c;
}

// SETTER sets the players antivirus software number
void BestBuy::setAVS(int a) {
    AVS = a;
}

// SETTER sets the computers maintence lev
void BestBuy::setCompMaintenceLev(int c) {
    compMaintenceLev = c;
}

// DISPLAY
void BestBuy::displayInfo() {
    cout << "Doge Coins: " << dogeCoins << endl;
    cout << "Computer: " << computer << endl;
    cout << "VPN Level: " << VPN << endl;
    cout << "Internet Level: " << internet << endl;
    cout << "CPU: " << CPU << endl;
    cout << "GPU: " << GPU << endl;
    cout << "Power Supply Unit: " << PSU << endl;
    cout << "Computer Case: " << compCase << endl;
    cout << "Internet Card: " << internetCard << endl;
    cout << "Keyboard and Mouse: " << keyMouse << endl;
    cout << "Premade Computer: " << premadeComp << endl;
    cout << "Antivirus Software: " << AVS << endl;
}

// DISPLAY TEXT
void BestBuy::displayTxt() {
    cout << "You have 200 dogecoins, 1 computer and 1 VPN. You will need to spend the rest of your money on the following items:" << endl;
    cout << endl;
    cout << "- COMPUTER PARTS. If your computer breaks, you need 5 computer parts to make a new one." << endl;
    cout << "- ANTIVIRUS SOFTWARE. If your computer is infected with a virus, use the antivirus software to get rid of it." << endl;
    cout << "- VIRTUAL PRIVATE NETWORK (VPN). The more VPNs you have the harder it is for a hacker to infect your computer with a virus." << endl;
    cout << "- INTERNET PROVIDER. The better the internet provider, the more reliable your hacking will be." << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on a different electronics site along the way. But beware, some of the websites online are shady, and they won’t always give you a fair price..." << endl;
}

// BUY a cpu
void BestBuy::buyCPU(int n) {
    // declare variable
    int moneyTaken = n * 10;

    if (CPU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= 30){   // make sure they have enough money to buy
                    setCPU(getCPU() + n);  // set the cpu 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < 30){   // if they don't have enough doge coins
                    cout << "You do not have enough money to buy 3 CPU's." << endl;
                }
            }

            else if (dogeCoins > 10){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= 20){
                        setCPU(getCPU() + n);  // set CPU
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setCPU(getCPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < 10){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase any CPU's." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 CPU's
            cout << "You cannot buy more than 3 CPU's." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else {
        cout << "You cannot buy any more CPU's." << endl;
    }
}

// BUY a GPU
void BestBuy::buyGPU(int n) {
    // declare variable
    int moneyTaken = n * 20;

    if (GPU < 3) {  // only do it if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 GPU's

            if (n == 3){    // if they try to purchase 3

                if (dogeCoins >= 60){ // make sure they have enough money
                    setGPU(getGPU() + n); 
                    setDogeCoins(dogeCoins - moneyTaken);
                }

                else {  // if they don't have enough money
                    cout << "You do not have enough money to buy 3 GPU's." << endl;
                }
            }

            else if (dogeCoins >= 20){
                
                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= 40){   // make sure they have enough money
                        setGPU(getGPU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else {
                    setGPU(getGPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins > 20){   // if they don't have enough money to buy any
                cout << "You don't have enough money to buy any GPU's." << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 GPU's. " << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more GPU's." << endl;
    }
}

// BUY a Power Supply Unit
void BestBuy::buyPSU(int n) {
    // declare variable
    int moneyTaken = n * 5;

    if (PSU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= 15){   // make sure they have enough money
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < 15){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= 5) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= 10) {  // make sure they have enough
                        setPSU(getPSU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < 5) {
                cout << "You do not have enough money to buy any Power Supply Units." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Power Supply Units." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Power Supply Units." << endl;
    }
}

// BUY a computer case
void BestBuy::buyCompCase(int n) {
    // declare variables
    int moneyTaken = n * 15;

    if (compCase < 3) { // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make it so they can only purchase 3

            if (n == 3){    // when they try to buy 3
                if (dogeCoins >= 45){   // make sure they have enough money
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < 45){   // when they dont have enough money
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= 15){
                if (n == 2) {   // for when they buy 2
                    if (dogeCoins >= 30) {  // make sure they have enough money
                        setCompCase(getCompCase() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {  // when they dont have enough
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else if (dogeCoins >= 15){
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < 15) {  // if they dont have enough money in general
                cout << "You don't have enough money to buy any Computer Case!" << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Computer Cases." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy anymore Computer Cases." << endl;
    }
}

// BUY a internet card
void BestBuy::buyIntCard(int n) {
    // declare variable
    int moneyTaken = n * 5;

    if (internetCard < 3){  // only do it when they have less than 3 
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= 15){   // make sure they have enough money
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < 15){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= 5) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= 10) {  // make sure they have enough
                        setIntCard(getIntCard() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < 5) {
                cout << "You do not have enough money to buy any Internet Cards." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Internet Cards." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Internet Cards." << endl;
    }
}

// BUY a keyboard and mouse
void BestBuy::buyKeyMouse(int n) {
    // declare variable
    int moneyTaken = n * 10;

    if (keyMouse < 3){ // only do it if they have less than 3 
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= 30){   // make sure they have enough money to buy
                    setKeyMouse(getKeyMouse() + n);  // set the keymouse 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < 30){   // if they don't have enough doge coins
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins > 10){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= 20){
                        setKeyMouse(getKeyMouse() + n);  // set keymouse
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setKeyMouse(getKeyMouse() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < 10){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase a Keyboard and Mouse." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 keymouse's
            cout << "You cannot buy more than 3 Keyboards and Mouses." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else if (keyMouse > 3){
        cout << "You cannot have more than 3 Keyboard and Mouses." << endl;
    }
}

// BUY a premade computer
void BestBuy::buyPremadeComp(int n) {
    // declare variables
    int moneyTaken = n * 100;

    if (premadeComp == 0){    // only do it if they have 0 premade computers
        if (n == 1){    // only make it so they can buy 1 premade comp

            if (dogeCoins >= 100) { // make it so they have to have enough money to buy
                setPremadeComp(getPremadeComp() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }

            else {
                cout << "You do not have enough money to buy a Premade Computer." << endl;
            }
        }
        else if (n == 0) {  // they don't want to buy
            setPremadeComp(getPremadeComp() + n);
        }
        else if (n > 1) {   // if they try to buy more than 1
            cout << "You cannot buy more then 1 premade computer." << endl;
        }
        else if (n < 0) {   // if they input a negative num
            cout << "Invalid Input. Please enter a positive computer." << endl;
        }
    }
    else {
        cout << "You can only have 1 Premade Computer." << endl;
    }
}

// BUY antivirus software
void BestBuy::buyAVS(int n) {
    // declare variables
    int moneyTaken = n * 10;

    if (n > 0) {    // only do it when input is greater than 0
        if (moneyTaken <= dogeCoins){    // if they have enough money then buy
            setAVS(getAVS() + n);
            setDogeCoins(dogeCoins - moneyTaken);
        }
        else if (moneyTaken > dogeCoins) {   // they dont have enough money
            cout << "You do not have enough money to buy Antivirus Software." << endl;
        }
    }
    else {  
        cout << "Invalid input. Please enter a positive number." << endl;
    }
}

// BUY vpn
void BestBuy::buyVPN(int n) {
    // declare variable
    int moneyTaken = n * 20;

    if (VPN < 2){   // only buy if they have less than 2 vpns
        if (n == 1) {
            if (moneyTaken <= dogeCoins) {
                setVPN(getVPN() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }
            else if (moneyTaken > dogeCoins){
                cout << "You do not have enough money to buy a VPN." << endl;
            }
        }
        else if (n > 1) {
            cout << "You cannot buy more then 1 VPN." << endl;
        }
        else if (n == 0){
            cout << "" << endl;
        }
        else {
            cout << "Invalid Input. Please enter another number." << endl;
        }
    }
    else if (VPN >= 2) {
        cout << "You cannot buy any more VPN's." << endl;
    } 
}

// BUY internet level
void BestBuy::buyInt(int n) {
    // make a switch to see what option they choose 
    switch (n) 
    {
        case 2: // if they choose to buy level 2 internet
        if (dogeCoins >= 10) {  // make sure they have enough money
            setInternet(2);
            setDogeCoins(dogeCoins - 10);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;
        
        case 3: // if they choose to buy level 3 internet
        if (dogeCoins >= 25) {  // make sure they have enough money
            setInternet(3);
            setDogeCoins(dogeCoins - 25);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 4: // if they choose to buy level 4 internet
        if (dogeCoins >= 40) {  // make sure they have enough money
            setInternet(4);
            setDogeCoins(dogeCoins - 40);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 5: // if they choose to buy level 5 internet
        if (dogeCoins >= 50) {  // make sure they have enough money
            setInternet(5);
            setDogeCoins(dogeCoins - 50);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        default:
        cout << "Invalid Input." << endl;
        cout << "Please enter a number (2-5)." << endl;
    }
}

// BUY a cpu room 2
void BestBuy::buyCPURoom2(int n) {
    // declare variable
    int moneyTaken = (n * 11);

    if (CPU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setCPU(getCPU() + n);  // set the cpu 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money to buy 3 CPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setCPU(getCPU() + n);  // set CPU
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setCPU(getCPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase any CPU's." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 CPU's
            cout << "You cannot buy more than 3 CPU's." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else {
        cout << "You cannot buy any more CPU's." << endl;
    }
}

// BUY a GPU
void BestBuy::buyGPURoom2(int n) {
    // declare variable
    int moneyTaken = n * 22;

    if (GPU < 3) {  // only do it if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 GPU's

            if (n == 3){    // if they try to purchase 3

                if (dogeCoins >= moneyTaken){ // make sure they have enough money
                    setGPU(getGPU() + n); 
                    setDogeCoins(dogeCoins - moneyTaken);
                }

                else {  // if they don't have enough money
                    cout << "You do not have enough money to buy 3 GPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                
                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){   // make sure they have enough money
                        setGPU(getGPU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else {
                    setGPU(getGPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins > moneyTaken){   // if they don't have enough money to buy any
                cout << "You don't have enough money to buy any GPU's." << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 GPU's. " << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more GPU's." << endl;
    }
}

// BUY a Power Supply Unit
void BestBuy::buyPSURoom2(int n) {
    // declare variable
    double moneyTaken = n * 5.50;

    if (PSU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setPSU(getPSU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Power Supply Units." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Power Supply Units." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Power Supply Units." << endl;
    }
}

// BUY a computer case
void BestBuy::buyCompCaseRoom2(int n) {
    // declare variables
    double moneyTaken = n * 16.50;

    if (compCase < 3) { // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make it so they can only purchase 3

            if (n == 3){    // when they try to buy 3
                if (dogeCoins >= 45){   // make sure they have enough money
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < 45){   // when they dont have enough money
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= 15){
                if (n == 2) {   // for when they buy 2
                    if (dogeCoins >= 30) {  // make sure they have enough money
                        setCompCase(getCompCase() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {  // when they dont have enough
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else if (dogeCoins >= 15){
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < 15) {  // if they dont have enough money in general
                cout << "You don't have enough money to buy any Computer Case!" << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Computer Cases." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy anymore Computer Cases." << endl;
    }
}

// BUY a internet card
void BestBuy::buyIntCardRoom2(int n) {
    // declare variable
    double moneyTaken = n * 5.50;

    if (internetCard < 3){  // only do it when they have less than 3 
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= 15){   // make sure they have enough money
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < 15){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= 5) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= 10) {  // make sure they have enough
                        setIntCard(getIntCard() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < 5) {
                cout << "You do not have enough money to buy any Internet Cards." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Internet Cards." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Internet Cards." << endl;
    }
}

// BUY a keyboard and mouse
void BestBuy::buyKeyMouseRoom2(int n) {
    // declare variable
    int moneyTaken = n * 11;

    if (keyMouse < 3){ // only do it if they have less than 3 
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= 33){   // make sure they have enough money to buy
                    setKeyMouse(getKeyMouse() + n);  // set the keymouse 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < 33){   // if they don't have enough doge coins
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= 22){
                        setKeyMouse(getKeyMouse() + n);  // set keymouse
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setKeyMouse(getKeyMouse() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase a Keyboard and Mouse." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 keymouse's
            cout << "You cannot buy more than 3 Keyboards and Mouses." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else if (keyMouse > 3){
        cout << "You cannot have more than 3 Keyboard and Mouses." << endl;
    }
}

// BUY a premade computer
void BestBuy::buyPremadeCompRoom2(int n) {
    // declare variables
    int moneyTaken = n * 110;

    if (premadeComp == 0){    // only do it if they have 0 premade computers
        if (n == 1){    // only make it so they can buy 1 premade comp

            if (dogeCoins >= moneyTaken) { // make it so they have to have enough money to buy
                setPremadeComp(getPremadeComp() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }

            else {
                cout << "You do not have enough money to buy a Premade Computer." << endl;
            }
        }
        else if (n == 0) {  // they don't want to buy
            setPremadeComp(getPremadeComp() + n);
        }
        else if (n > 1) {   // if they try to buy more than 1
            cout << "You cannot buy more then 1 premade computer." << endl;
        }
        else if (n < 0) {   // if they input a negative num
            cout << "Invalid Input. Please enter a positive computer." << endl;
        }
    }
    else {
        cout << "You can only have 1 Premade Computer." << endl;
    }
}

// BUY antivirus software
void BestBuy::buyAVSRoom2(int n) {
    // declare variables
    int moneyTaken = n * 11;

    if (n > 0) {    // only do it when input is greater than 0
        if (moneyTaken <= dogeCoins){    // if they have enough money then buy
            setAVS(getAVS() + n);
            setDogeCoins(dogeCoins - moneyTaken);
        }
        else if (moneyTaken > dogeCoins) {   // they dont have enough money
            cout << "You do not have enough money to buy Antivirus Software." << endl;
        }
    }
    else {  
        cout << "Invalid input. Please enter a positive number." << endl;
    }
}

// BUY vpn
void BestBuy::buyVPNRoom2(int n) {
    // declare variable
    int moneyTaken = n * 22;

    if (VPN < 2){   // only buy if they have less than 2 vpns
        if (n == 1) {
            if (moneyTaken <= dogeCoins) {
                setVPN(getVPN() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }
            else if (moneyTaken > dogeCoins){
                cout << "You do not have enough money to buy a VPN." << endl;
            }
        }
        else if (n > 1) {
            cout << "You cannot buy more then 1 VPN." << endl;
        }
        else if (n == 0){
            cout << "" << endl;
        }
        else {
            cout << "Invalid Input. Please enter another number." << endl;
        }
    }
    else if (VPN >= 2) {
        cout << "You cannot buy any more VPN's." << endl;
    } 
}

// BUY internet level
void BestBuy::buyIntRoom2(int n) {
    // make a switch to see what option they choose 
    switch (n) 
    {
        case 2: // if they choose to buy level 2 internet
        if (dogeCoins >= 11) {  // make sure they have enough money
            setInternet(2);
            setDogeCoins(dogeCoins - 11);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;
        
        case 3: // if they choose to buy level 3 internet
        if (dogeCoins >= 27.50) {  // make sure they have enough money
            setInternet(3);
            setDogeCoins(dogeCoins - 27.50);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 4: // if they choose to buy level 4 internet
        if (dogeCoins >= 44) {  // make sure they have enough money
            setInternet(4);
            setDogeCoins(dogeCoins - 44);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 5: // if they choose to buy level 5 internet
        if (dogeCoins >= 55) {  // make sure they have enough money
            setInternet(5);
            setDogeCoins(dogeCoins - 55);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        default:
        cout << "Invalid Input." << endl;
        cout << "Please enter a number (2-5)." << endl;
    }
}

// BUY a cpu room 3
void BestBuy::buyCPURoom3(int n) {
    // declare variable
    int moneyTaken = (n * 12);

    if (CPU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setCPU(getCPU() + n);  // set the cpu 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money to buy 3 CPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setCPU(getCPU() + n);  // set CPU
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setCPU(getCPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase any CPU's." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 CPU's
            cout << "You cannot buy more than 3 CPU's." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else {
        cout << "You cannot buy any more CPU's." << endl;
    }
}

// BUY a GPU
void BestBuy::buyGPURoom3(int n) {
    // declare variable
    int moneyTaken = n * 24;

    if (GPU < 3) {  // only do it if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 GPU's

            if (n == 3){    // if they try to purchase 3

                if (dogeCoins >= moneyTaken){ // make sure they have enough money
                    setGPU(getGPU() + n); 
                    setDogeCoins(dogeCoins - moneyTaken);
                }

                else {  // if they don't have enough money
                    cout << "You do not have enough money to buy 3 GPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                
                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){   // make sure they have enough money
                        setGPU(getGPU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else {
                    setGPU(getGPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins > moneyTaken){   // if they don't have enough money to buy any
                cout << "You don't have enough money to buy any GPU's." << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 GPU's. " << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more GPU's." << endl;
    }
}

// BUY a Power Supply Unit
void BestBuy::buyPSURoom3(int n) {
    // declare variable
    int moneyTaken = n * 6;

    if (PSU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setPSU(getPSU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Power Supply Units." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Power Supply Units." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Power Supply Units." << endl;
    }
}

// BUY a computer case
void BestBuy::buyCompCaseRoom3(int n) {
    // declare variables
    double moneyTaken = n * 18;

    if (compCase < 3) { // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make it so they can only purchase 3

            if (n == 3){    // when they try to buy 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they dont have enough money
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                if (n == 2) {   // for when they buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough money
                        setCompCase(getCompCase() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {  // when they dont have enough
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else if (dogeCoins >= moneyTaken){
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {  // if they dont have enough money in general
                cout << "You don't have enough money to buy any Computer Case!" << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Computer Cases." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy anymore Computer Cases." << endl;
    }
}

// BUY a internet card
void BestBuy::buyIntCardRoom3(int n) {
    // declare variable
    double moneyTaken = n * 6;

    if (internetCard < 3){  // only do it when they have less than 3 
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setIntCard(getIntCard() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Internet Cards." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Internet Cards." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Internet Cards." << endl;
    }
}

// BUY a keyboard and mouse
void BestBuy::buyKeyMouseRoom3(int n) {
    // declare variable
    int moneyTaken = n * 12;

    if (keyMouse < 3){ // only do it if they have less than 3 
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setKeyMouse(getKeyMouse() + n);  // set the keymouse 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setKeyMouse(getKeyMouse() + n);  // set keymouse
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setKeyMouse(getKeyMouse() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase a Keyboard and Mouse." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 keymouse's
            cout << "You cannot buy more than 3 Keyboards and Mouses." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else if (keyMouse > 3){
        cout << "You cannot have more than 3 Keyboard and Mouses." << endl;
    }
}

// BUY a premade computer
void BestBuy::buyPremadeCompRoom3(int n) {
    // declare variables
    int moneyTaken = n * 120;

    if (premadeComp == 0){    // only do it if they have 0 premade computers
        if (n == 1){    // only make it so they can buy 1 premade comp

            if (dogeCoins >= moneyTaken) { // make it so they have to have enough money to buy
                setPremadeComp(getPremadeComp() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }

            else {
                cout << "You do not have enough money to buy a Premade Computer." << endl;
            }
        }
        else if (n == 0) {  // they don't want to buy
            setPremadeComp(getPremadeComp() + n);
        }
        else if (n > 1) {   // if they try to buy more than 1
            cout << "You cannot buy more then 1 premade computer." << endl;
        }
        else if (n < 0) {   // if they input a negative num
            cout << "Invalid Input. Please enter a positive computer." << endl;
        }
    }
    else {
        cout << "You can only have 1 Premade Computer." << endl;
    }
}

// BUY antivirus software
void BestBuy::buyAVSRoom3(int n) {
    // declare variables
    int moneyTaken = n * 12;

    if (n > 0) {    // only do it when input is greater than 0
        if (moneyTaken <= dogeCoins){    // if they have enough money then buy
            setAVS(getAVS() + n);
            setDogeCoins(dogeCoins - moneyTaken);
        }
        else if (moneyTaken > dogeCoins) {   // they dont have enough money
            cout << "You do not have enough money to buy Antivirus Software." << endl;
        }
    }
    else {  
        cout << "Invalid input. Please enter a positive number." << endl;
    }
}

// BUY vpn
void BestBuy::buyVPNRoom3(int n) {
    // declare variable
    int moneyTaken = n * 24;

    if (VPN < 2){   // only buy if they have less than 2 vpns
        if (n == 1) {
            if (moneyTaken <= dogeCoins) {
                setVPN(getVPN() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }
            else if (moneyTaken > dogeCoins){
                cout << "You do not have enough money to buy a VPN." << endl;
            }
        }
        else if (n > 1) {
            cout << "You cannot buy more then 1 VPN." << endl;
        }
        else if (n == 0){
            cout << "" << endl;
        }
        else {
            cout << "Invalid Input. Please enter another number." << endl;
        }
    }
    else if (VPN >= 2) {
        cout << "You cannot buy any more VPN's." << endl;
    } 
}

// BUY internet level
void BestBuy::buyIntRoom3(int n) {
    // make a switch to see what option they choose 
    switch (n) 
    {
        case 2: // if they choose to buy level 2 internet
        if (dogeCoins >= 12) {  // make sure they have enough money
            setInternet(2);
            setDogeCoins(dogeCoins - 12);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;
        
        case 3: // if they choose to buy level 3 internet
        if (dogeCoins >= 30) {  // make sure they have enough money
            setInternet(3);
            setDogeCoins(dogeCoins - 30);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 4: // if they choose to buy level 4 internet
        if (dogeCoins >= 48) {  // make sure they have enough money
            setInternet(4);
            setDogeCoins(dogeCoins - 48);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 5: // if they choose to buy level 5 internet
        if (dogeCoins >= 60) {  // make sure they have enough money
            setInternet(5);
            setDogeCoins(dogeCoins - 60);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        default:
        cout << "Invalid Input." << endl;
        cout << "Please enter a number (2-5)." << endl;
    }
}

// BUY a cpu room 4
void BestBuy::buyCPURoom4(int n) {
    // declare variable
    double moneyTaken = (n * 12.50);

    if (CPU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setCPU(getCPU() + n);  // set the cpu 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money to buy 3 CPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setCPU(getCPU() + n);  // set CPU
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setCPU(getCPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase any CPU's." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 CPU's
            cout << "You cannot buy more than 3 CPU's." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else {
        cout << "You cannot buy any more CPU's." << endl;
    }
}

// BUY a GPU
void BestBuy::buyGPURoom4(int n) {
    // declare variable
    int moneyTaken = n * 25;

    if (GPU < 3) {  // only do it if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 GPU's

            if (n == 3){    // if they try to purchase 3

                if (dogeCoins >= moneyTaken){ // make sure they have enough money
                    setGPU(getGPU() + n); 
                    setDogeCoins(dogeCoins - moneyTaken);
                }

                else {  // if they don't have enough money
                    cout << "You do not have enough money to buy 3 GPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                
                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){   // make sure they have enough money
                        setGPU(getGPU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else {
                    setGPU(getGPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins > moneyTaken){   // if they don't have enough money to buy any
                cout << "You don't have enough money to buy any GPU's." << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 GPU's. " << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more GPU's." << endl;
    }
}

// BUY a Power Supply Unit
void BestBuy::buyPSURoom4(int n) {
    // declare variable
    double moneyTaken = n * 6.25;

    if (PSU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setPSU(getPSU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Power Supply Units." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Power Supply Units." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Power Supply Units." << endl;
    }
}

// BUY a computer case
void BestBuy::buyCompCaseRoom4(int n) {
    // declare variables
    double moneyTaken = n * 18.75;

    if (compCase < 3) { // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make it so they can only purchase 3

            if (n == 3){    // when they try to buy 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setCompCase(getCompCase() + 1);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they dont have enough money
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                if (n == 2) {   // for when they buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough money
                        setCompCase(getCompCase() + 1);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {  // when they dont have enough
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else if (dogeCoins >= moneyTaken){
                    setCompCase(getCompCase() + 1);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {  // if they dont have enough money in general
                cout << "You don't have enough money to buy any Computer Case!" << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Computer Cases." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy anymore Computer Cases." << endl;
    }
}

// BUY a internet card
void BestBuy::buyIntCardRoom4(int n) {
    // declare variable
    double moneyTaken = n * 6.25;

    if (internetCard < 3){  // only do it when they have less than 3 
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setIntCard(getIntCard() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Internet Cards." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Internet Cards." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Internet Cards." << endl;
    }
}

// BUY a keyboard and mouse
void BestBuy::buyKeyMouseRoom4(int n) {
    // declare variable
    double moneyTaken = n * 12.50;

    if (keyMouse < 3){ // only do it if they have less than 3 
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setKeyMouse(getKeyMouse() + n);  // set the keymouse 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setKeyMouse(getKeyMouse() + n);  // set keymouse
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setKeyMouse(getKeyMouse() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase a Keyboard and Mouse." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 keymouse's
            cout << "You cannot buy more than 3 Keyboards and Mouses." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else if (keyMouse > 3){
        cout << "You cannot have more than 3 Keyboard and Mouses." << endl;
    }
}

// BUY a premade computer
void BestBuy::buyPremadeCompRoom4(int n) {
    // declare variables
    int moneyTaken = n * 125;

    if (premadeComp == 0){    // only do it if they have 0 premade computers
        if (n == 1){    // only make it so they can buy 1 premade comp

            if (dogeCoins >= moneyTaken) { // make it so they have to have enough money to buy
                setPremadeComp(getPremadeComp() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }

            else {
                cout << "You do not have enough money to buy a Premade Computer." << endl;
            }
        }
        else if (n == 0) {  // they don't want to buy
            setPremadeComp(getPremadeComp() + n);
        }
        else if (n > 1) {   // if they try to buy more than 1
            cout << "You cannot buy more then 1 premade computer." << endl;
        }
        else if (n < 0) {   // if they input a negative num
            cout << "Invalid Input. Please enter a positive computer." << endl;
        }
    }
    else {
        cout << "You can only have 1 Premade Computer." << endl;
    }
}

// BUY antivirus software
void BestBuy::buyAVSRoom4(int n) {
    // declare variables
    double moneyTaken = n * 12.50;

    if (n > 0) {    // only do it when input is greater than 0
        if (moneyTaken <= dogeCoins){    // if they have enough money then buy
            setAVS(getAVS() + n);
            setDogeCoins(dogeCoins - moneyTaken);
        }
        else if (moneyTaken > dogeCoins) {   // they dont have enough money
            cout << "You do not have enough money to buy Antivirus Software." << endl;
        }
    }
    else {  
        cout << "Invalid input. Please enter a positive number." << endl;
    }
}

// BUY vpn
void BestBuy::buyVPNRoom4(int n) {
    // declare variable
    int moneyTaken = n * 25;

    if (VPN < 2){   // only buy if they have less than 2 vpns
        if (n == 1) {
            if (moneyTaken <= dogeCoins) {
                setVPN(getVPN() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }
            else if (moneyTaken > dogeCoins){
                cout << "You do not have enough money to buy a VPN." << endl;
            }
        }
        else if (n > 1) {
            cout << "You cannot buy more then 1 VPN." << endl;
        }
        else if (n == 0){
            cout << "" << endl;
        }
        else {
            cout << "Invalid Input. Please enter another number." << endl;
        }
    }
    else if (VPN >= 2) {
        cout << "You cannot buy any more VPN's." << endl;
    } 
}

// BUY internet level
void BestBuy::buyIntRoom4(int n) {
    // make a switch to see what option they choose 
    switch (n) 
    {
        case 2: // if they choose to buy level 2 internet
        if (dogeCoins >= 12.50) {  // make sure they have enough money
            setInternet(2);
            setDogeCoins(dogeCoins - 12.50);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;
        
        case 3: // if they choose to buy level 3 internet
        if (dogeCoins >= 31.25) {  // make sure they have enough money
            setInternet(3);
            setDogeCoins(dogeCoins - 31.25);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 4: // if they choose to buy level 4 internet
        if (dogeCoins >= 50) {  // make sure they have enough money
            setInternet(4);
            setDogeCoins(dogeCoins - 50);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 5: // if they choose to buy level 5 internet
        if (dogeCoins >= 62.50) {  // make sure they have enough money
            setInternet(5);
            setDogeCoins(dogeCoins - 62.50);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        default:
        cout << "Invalid Input." << endl;
        cout << "Please enter a number (2-5)." << endl;
    }
}

// BUY a cpu
void BestBuy::buyCPURoom5(int n) {
    // declare variable
    double moneyTaken = n * 13;

    if (CPU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setCPU(getCPU() + n);  // set the cpu 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money to buy 3 CPU's." << endl;
                }
            }

            else if (dogeCoins > moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setCPU(getCPU() + n);  // set CPU
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setCPU(getCPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase any CPU's." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 CPU's
            cout << "You cannot buy more than 3 CPU's." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else {
        cout << "You cannot buy any more CPU's." << endl;
    }
}

// BUY a GPU
void BestBuy::buyGPURoom5(int n) {
    // declare variable
    double moneyTaken = n * 26;

    if (GPU < 3) {  // only do it if they have less than 3
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 GPU's

            if (n == 3){    // if they try to purchase 3

                if (dogeCoins >= moneyTaken){ // make sure they have enough money
                    setGPU(getGPU() + n); 
                    setDogeCoins(dogeCoins - moneyTaken);
                }

                else {  // if they don't have enough money
                    cout << "You do not have enough money to buy 3 GPU's." << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                
                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){   // make sure they have enough money
                        setGPU(getGPU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else {
                    setGPU(getGPU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins > moneyTaken){   // if they don't have enough money to buy any
                cout << "You don't have enough money to buy any GPU's." << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 GPU's. " << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more GPU's." << endl;
    }
}

// BUY a Power Supply Unit
void BestBuy::buyPSURoom5(int n) {
    // declare variable
    double moneyTaken = n * 6.50;

    if (PSU < 3) {  // only buy if they have less than 3
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setPSU(getPSU() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setPSU(getPSU() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Power Supply Units." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Power Supply Units." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Power Supply Units." << endl;
    }
}

// BUY a computer case
void BestBuy::buyCompCaseRoom5(int n) {
    // declare variables
    double moneyTaken = n * 19.50;

    if (compCase < 3) { // only buy if they have less than 3
        if (n <= 3 && n > 0) {  // make it so they can only purchase 3

            if (n == 3){    // when they try to buy 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they dont have enough money
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken){
                if (n == 2) {   // for when they buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough money
                        setCompCase(getCompCase() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {  // when they dont have enough
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else if (dogeCoins >= moneyTaken){
                    setCompCase(getCompCase() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {  // if they dont have enough money in general
                cout << "You don't have enough money to buy any Computer Case!" << endl;
            }

        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Computer Cases." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy anymore Computer Cases." << endl;
    }
}

// BUY a internet card
void BestBuy::buyIntCardRoom5(int n) {
    // declare variable
    double moneyTaken = n * 6.50;

    if (internetCard < 3){  // only do it when they have less than 3 
        if (n <= 3 && n > 0){ // make it so they can only purchase 3

            if (n == 3) {   // when they try to purchase 3
                if (dogeCoins >= moneyTaken){   // make sure they have enough money
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
                else if (dogeCoins < moneyTaken){   // when they don't have enough
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins >= moneyTaken) {
                if (n == 2) {   // when they try to buy 2
                    if (dogeCoins >= moneyTaken) {  // make sure they have enough
                        setIntCard(getIntCard() + n);
                        setDogeCoins(dogeCoins - moneyTaken);
                    }
                    else {
                        cout << "You do not have enough money!" << endl;
                    }
                }
                else {
                    setIntCard(getIntCard() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }
            }

            else if (dogeCoins < moneyTaken) {
                cout << "You do not have enough money to buy any Internet Cards." << endl;
            }
        }
        else if (n > 3) {// if they try to buy more than 3 
            cout << "You cannot buy more than 3 Internet Cards." << endl;
        }
        else if (n <= 0) {  // if they input a number less than or equal to 0
            cout << "Invalid Input. Please enter a positive number." << endl;
        }
    }
    else {
        cout << "You cannot buy more Internet Cards." << endl;
    }
}

// BUY a keyboard and mouse
void BestBuy::buyKeyMouseRoom5(int n) {
    // declare variable
    int moneyTaken = n * 13;

    if (keyMouse < 3){ // only do it if they have less than 3 
        if (n <= 3 && n > 0) {  // make sure they can't buy more than 3 CPU's

            if (n == 3){    // if they try to buy 3 CPU's

                if (dogeCoins >= moneyTaken){   // make sure they have enough money to buy
                    setKeyMouse(getKeyMouse() + n);  // set the keymouse 
                    setDogeCoins(dogeCoins - moneyTaken);   // set the doge coins
                }

                else if (dogeCoins < moneyTaken){   // if they don't have enough doge coins
                    cout << "You do not have enough money!" << endl;
                }
            }

            else if (dogeCoins > moneyTaken){     // make sure player has money to buy

                if (n == 2){    // if they try to buy 2
                    if (dogeCoins >= moneyTaken){
                        setKeyMouse(getKeyMouse() + n);  // set keymouse
                        setDogeCoins(dogeCoins - moneyTaken);   // set new doge coin amount
                    }
                    else {  // if they dont have enough
                        cout << "You don't have enough DogeCoins!" << endl;
                    }
                }
                else { 
                    setKeyMouse(getKeyMouse() + n);
                    setDogeCoins(dogeCoins - moneyTaken);
                }

            }

            else if (dogeCoins < moneyTaken){   // if they don't have enough money to purchase anything
                cout << "You don't have enough money to purchase a Keyboard and Mouse." << endl;
            }
        }
        else if (n > 3) {   // if player wants to buy more than 3 keymouse's
            cout << "You cannot buy more than 3 Keyboards and Mouses." << endl;
        }
        else if (n <= 0){
            cout << "Invalid Input. Please enter a positive number." << endl;
        } 
    }
    else if (keyMouse > 3){
        cout << "You cannot have more than 3 Keyboard and Mouses." << endl;
    }
}

// BUY a premade computer
void BestBuy::buyPremadeCompRoom5(int n) {
    // declare variables
    int moneyTaken = n * 130;

    if (premadeComp == 0){    // only do it if they have 0 premade computers
        if (n == 1){    // only make it so they can buy 1 premade comp

            if (dogeCoins >= moneyTaken) { // make it so they have to have enough money to buy
                setPremadeComp(getPremadeComp() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }

            else {
                cout << "You do not have enough money to buy a Premade Computer." << endl;
            }
        }
        else if (n == 0) {  // they don't want to buy
            setPremadeComp(getPremadeComp() + n);
        }
        else if (n > 1) {   // if they try to buy more than 1
            cout << "You cannot buy more then 1 premade computer." << endl;
        }
        else if (n < 0) {   // if they input a negative num
            cout << "Invalid Input. Please enter a positive computer." << endl;
        }
    }
    else {
        cout << "You can only have 1 Premade Computer." << endl;
    }
}

// BUY antivirus software
void BestBuy::buyAVSRoom5(int n) {
    // declare variables
    int moneyTaken = n * 13;

    if (n > 0) {    // only do it when input is greater than 0
        if (moneyTaken <= dogeCoins){    // if they have enough money then buy
            setAVS(getAVS() + n);
            setDogeCoins(dogeCoins - moneyTaken);
        }
        else if (moneyTaken > dogeCoins) {   // they dont have enough money
            cout << "You do not have enough money to buy Antivirus Software." << endl;
        }
    }
    else {  
        cout << "Invalid input. Please enter a positive number." << endl;
    }
}

// BUY vpn
void BestBuy::buyVPNRoom5(int n) {
    // declare variable
    double moneyTaken = n * 26;

    if (VPN < 2){   // only buy if they have less than 2 vpns
        if (n == 1) {
            if (moneyTaken <= dogeCoins) {
                setVPN(getVPN() + n);
                setDogeCoins(dogeCoins - moneyTaken);
            }
            else if (moneyTaken > dogeCoins){
                cout << "You do not have enough money to buy a VPN." << endl;
            }
        }
        else if (n > 1) {
            cout << "You cannot buy more then 1 VPN." << endl;
        }
        else if (n == 0){
            cout << "" << endl;
        }
        else {
            cout << "Invalid Input. Please enter another number." << endl;
        }
    }
    else if (VPN >= 2) {
        cout << "You cannot buy any more VPN's." << endl;
    } 
}

// BUY internet level
void BestBuy::buyIntRoom5(int n) {
    // make a switch to see what option they choose 
    switch (n) 
    {
        case 2: // if they choose to buy level 2 internet
        if (dogeCoins >= 13) {  // make sure they have enough money
            setInternet(2);
            setDogeCoins(dogeCoins - 13);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;
        
        case 3: // if they choose to buy level 3 internet
        if (dogeCoins >= 32.50) {  // make sure they have enough money
            setInternet(3);
            setDogeCoins(dogeCoins - 32.50);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 4: // if they choose to buy level 4 internet
        if (dogeCoins >= 52) {  // make sure they have enough money
            setInternet(4);
            setDogeCoins(dogeCoins - 52);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        case 5: // if they choose to buy level 5 internet
        if (dogeCoins >= 65) {  // make sure they have enough money
            setInternet(5);
            setDogeCoins(dogeCoins - 65);
        }
        else {
            cout << "You do not have enough money!" << endl;
        }
        break;

        default:
        cout << "Invalid Input." << endl;
        cout << "Please enter a number (2-5)." << endl;
    }
}

// display players parts
void BestBuy::displayParts() {
    cout << "Inventory:" << endl;
    cout << "1. CPU: " << getCPU() << endl;
    cout << "2. GPU: " << getGPU() << endl;
    cout << "3. Power Supply Unit: " << getPSU() << endl;
    cout << "4. Computer Case: " << getCompCase() << endl;
    cout << "5. Internet Card: " << getIntCard() << endl;
    cout << "6. Keyboard and Mouse: " << getKeyMouse() << endl;
}

// function to repair a users computer
void BestBuy::repairComputer() {
    // declare variables
    int choice = 0;
    int repair = 0;
    int repairLev = 0;

    do 
        {
        // display players parts
        displayParts();
        cout << "7. Quit" << endl;
        cout << "Computer Maintence Level: " << getCompMaintenceLev() <<endl;
        cout << endl;

        // ask user what part they want to use and have them input
        cout << "Which part would you like to use?" << endl;
        cout << "Please select a number (1-7)" << endl;
        cin >> choice;

        if (repair < 5) {   // to make sure they cant get more use more than 5 parts to repair
            switch (choice)
            {
                case 1: // if they use a cpu to repair
                    if (getCPU() > 0){
                        setCPU(getCPU() - 1);   // take one part away
                        repair += 1;    
                    }
                    else if (getCPU() <= 0){
                        cout << "You don't have enough CPUs to repair." << endl;
                    }
                break;

                case 2: // if they use a gpu to repair
                    if (getGPU() > 0){
                        setGPU(getGPU() - 1);
                        repair += 1;
                    }
                    else if (getGPU() <= 0) {
                        cout << "You don't have enough GPUs to repair." << endl;
                    }
                break;

                case 3: // if they use a power supply unit to repair
                    if (getPSU() > 0) {
                        setPSU(getPSU() - 1);
                        repair += 1;
                    }
                    else if (getPSU() <= 0){
                        cout << "You don't have enough Power Supply Units to repair." << endl;
                    }
                break;

                case 4: // if they use a computer case
                    if (getCompCase() > 0) {
                        setCompCase(getCompCase() - 1);
                        repair += 1;
                    }
                    else if (getCompCase() <= 0) {
                        cout << "You don't have enough Computer Cases to repair." << endl;
                    }
                break;

                case 5: // if they use an internet card
                    if (getIntCard() > 0) {
                        setIntCard(getIntCard() - 1);
                        repair += 1;
                    }
                    else if (getIntCard() <= 0) {
                        cout << "You don't have enough Internet Cards to repair." << endl;
                    }
                break;

                case 6: // if they use a keyboard and mouse
                    if (getKeyMouse() > 0) {
                        setKeyMouse(getKeyMouse() - 1);
                        repair += 1;
                    }
                    else if (getKeyMouse() <= 0) {
                        cout << "You don't have enough Keyboard and Mouses to repair." << endl;
                    }
                break;

                case 7: // quit
                    cout << "Good Bye!" << endl;
                break;

                default:
                    cout << "Invalid Input. \nPlease select a number (1-7)" << endl;
                break;
            }
        }
        else if (repair >= 5){
            cout << "You cannot use any more parts." << endl;
            break;
        }
    }
    while (choice != 7);

    if (repair == 1) {
        repairLev = 20;
    }
    else if (repair == 2) {
        repairLev = 40;
    }
    else if (repair == 3) {
        repairLev = 60;
    }
    else if (repair == 4) {
        repairLev = 80;
    }
    else if (repair == 5) {
        repairLev = 100;
    }

    cout << "You have used " << repair << " parts." << endl;
    cout << "Your computer maintence level will now be increased by " << repairLev << endl;
    setCompMaintenceLev(getCompMaintenceLev() + repairLev); // set new computer maintence level
    cout << "Computer Maintence Level: " << getCompMaintenceLev() << endl;
}

// lose random part function
void BestBuy::loseRandPart(int n) {
    // make if statements to see what number n is and remove part
    if (getCPU() <= 0 && getGPU() <= 0 && getPSU() <= 0 && getCompCase() <= 0 && getIntCard() <= 0 && getKeyMouse() <= 0) { // if they have no computer part to take
        cout << "You have no computer parts to take." << endl;
    }

    else if (n == 1) {   // take away cpu
        if (getCPU() > 0) { // make sure they have a cpu to take
            setCPU(getCPU() - 1);
            cout << "You have lost 1 CPU!" << endl;
            cout << "You now have " << getCPU() << " CPU" << endl;
        }
        else if (getCPU() <= 0) {
            n = 2;
        }
    }

    else if (n == 2) {  // take away gpu
        if (getGPU() > 0) {     // make sure they have one to take
            setGPU(getGPU() - 1);
            cout << "You have lost 1 GPU!" << endl;
            cout << "You now have " << getGPU() << " GPU" << endl;
        }
        else if (getGPU() <= 0) {
            n = 3;
        }
    }

    else if (n == 3) {  // take away power supply unit
        if (getPSU() > 0) {     // make sure they have one to take
            setPSU(getPSU() - 1);
            cout << "You have lost 1 Power Supply Unit!" << endl;
            cout << "You now have " << getPSU() << " Power Supply Units" << endl;
        }
        else if (getPSU() <= 0) {
            n = 4;
        }
    }

    else if (n == 4) {  // take away computer case
        if (getCompCase() > 0) {     // make sure they have one to take
            setCompCase(getCompCase() - 1);
            cout << "You have lost 1 Computer Case!" << endl;
            cout << "You now have " << getCompCase() << " Computer Cases" << endl;
        }
        else if (getCompCase() <= 0) {
            n = 5;
        }
    }

    else if (n == 5) {  // take away internet card
        if (getIntCard() > 0) {     // make sure they have one to take
            setIntCard(getIntCard() - 1);
            cout << "You have lost 1 Internet Card!" << endl;
            cout << "You now have " << getIntCard() << " Internet Cards" << endl;
        }
        else if (getIntCard() <= 0) {
            n = 6;
        }
    }

    else if (n == 6) {  // take away keyboard and mouse
        if (getKeyMouse() > 0) {     // make sure they have one to take
            setKeyMouse(getKeyMouse() - 1);
            cout << "You have lost 1 Keyboard and Mouse!" << endl;
            cout << "You now have " << getKeyMouse() << " Keyboard and Mouses" << endl;
        }
        else if (getKeyMouse() <= 0) {
            n = 1;
        }
    }
}

// get random part function
void BestBuy::getRandPart(int n) {
    if (n == 1) {   // get cpu
        setCPU(getCPU() + 1);
        cout << "You have gained 1 CPU!" << endl;
        cout << "You now have " << getCPU() << " CPUs" << endl;
    }
    else if (n == 2) {   // get gpu
        setGPU(getGPU() + 1);
        cout << "You have gained 1 GPU!" << endl;
        cout << "You now have " << getGPU() << " CPUs" << endl;
    }
    else if (n == 3) {   // get power supply unit
        setPSU(getPSU() + 1);
        cout << "You have gained 1 Power Supply Unit!" << endl;
        cout << "You now have " << getPSU() << " Power Supply Units" << endl;
    }
    else if (n == 4) {   // get computer case
        setGPU(getGPU() + 1);
        cout << "You have gained 1 computer case!" << endl;
        cout << "You now have " << getGPU() << " Computer Cases" << endl;
    }
    else if (n == 5) {   // get internet card
        setGPU(getGPU() + 1);
        cout << "You have gained 1 Internet Card!" << endl;
        cout << "You now have " << getIntCard() << " Internet Cards" << endl;
    }
    else if (n == 6) {   // get Keyboard and mouse
        setKeyMouse(getKeyMouse() + 1);
        cout << "You have gained 1 Keyboard and Mouse!" << endl;
        cout << "You now have " << getKeyMouse() << " Keyboard and Mouses" << endl;
    }
}

// room 1 buy menu
void BestBuy::buyMenu1() {
    int choice = 0;
    int l = 0;
    int n = 0;

    do 
    {
        // ask user what they want to get and have them input
        cout << "WELCOME TO BEST BUY!" << endl;
        cout << "Select a numerical option:" << endl;
        cout << "1. Computer Parts" << endl;
        cout << "2. Antivirus Software" << endl;
        cout << "3. Virtual Private Network (VPN)" << endl;
        cout << "4. Internet Provider" << endl;
        cout << "5. Display Inventory" << endl;
        cout << "6. Quit" << endl;
        
        cin >> choice; // get user input

        // make a switch for user input
        switch (choice)
        {
            case 1: // for computer parts
                do {    // make another do-while for this case
                    // ask user what they want and have them input
                    cout << "Which computer part would you like to buy?" << endl;
                    cout << "YOU CAN ONLY HAVE MAX 3 OF EACH PART AND 1 PREMADE COMPUTER." << endl;
                    cout << "Select a numerical option:" << endl;
                    cout << "1. CPU, 10 DogeCoins" << endl;
                    cout << "2. GPU, 20 DogeCoins" << endl;
                    cout << "3. Power Supply Unit, 5 DogeCoins" << endl;
                    cout << "4. Computer Case, 15 DogeCoins" << endl;
                    cout << "5. Internet Card, 5 DogeCoins" << endl;
                    cout << "6. Keyboard and Mouse, 10 DogeCoins" << endl;
                    cout << "7. Premade Computer, 100 DogeCoins" << endl;
                    cout << "8. Quit" << endl;
                    cin >> n;

                    switch (n) // make another switch for this menu
                    {
                        case 1: // buy a cpu
                            cout << "How many CPUs would you like to buy?" << endl;
                            cin >> l;
                            buyCPU(l);
                        break;

                        case 2: // buy a GPU
                            cout << "How many GPUs would you like to buy?" << endl;
                            cin >> l;
                            buyGPU(l);
                        break;

                        case 3: // buy a Power supply unit
                            cout << "How many Power Supply Units would you like to buy?" << endl;
                            cin >> l;
                            buyPSU(l);
                        break;

                        case 4: // buy a computer case
                            cout << "How many Computer Cases would you like to buy?" << endl;
                            cin >> l;
                            buyCompCase(l);
                        break;

                        case 5: // buy an internet card
                            cout << "How many Internet Cards would you like to buy?" << endl;
                            cin >> l;
                            buyIntCard(l);
                        break;

                        case 6: // buy a keyboard and mouse
                            cout << "How many Keyboards and Mouses would you like to buy?" << endl;
                            cin >> l;
                            buyKeyMouse(l);
                        break;

                        case 7: // buy apremade computer
                            cout << "Are you sure you want to buy a premade computer for 100 DogeCoins?" << endl;
                            cout << "1. Yes" << endl;
                            cout << "0. No" << endl;
                            cin >> l;
                            buyPremadeComp(1);
                        break;

                        case 8:     // quit
                            cout << "Good Bye!" << endl;
                        break;

                        default:
                            cout << "Invalid Input. Please select a numerical number (1-8)" << endl;
                        break;
                    }
                }
                while (n != 8);
            break;

            case 2:     // buy antivirus software
                cout << "One USB of Antivirus Software costs 10 DogeCoins." << endl;
                cout << "It will give a one-time use to get rid of any viruses on the computer." << endl;
                cout << "How many antivirus USB sticks would you like to purchase?" << endl;
                cout << "Please enter a positive number." << endl;
                cin >> l;
                buyAVS(l);
            break;

            case 3:     // buy VPN
                cout << "A VPN costs 20 Dogecoins each." << endl;
                cout << "VPNs reduce your chances of getting hacked by preventing hackers from tracking down your main computer." << endl;
                cout << "The increase in security maxes out at 2 VPNs." << endl;
                cout << "Are you sure you want to purchase 1 VPN?" << endl;
                cout << "1. Yes" << endl;
                cout << "0. No" << endl;
                cin >> l;
                buyVPN(l);
            break;

            case 4:     // buy internet
                cout << "Costs:" << endl;
                cout << "Internet Provider Level 2: 10 DogeCoins" << endl;
                cout << "Internet Provider Level 3: 25 DogeCoins" << endl;
                cout << "Internet Provider Level 4: 40 DogeCoins" << endl;
                cout << "Internet Provider Level 5: 50 DogeCoins" << endl;
                cout << "Please enter a number (2-5)." << endl;
                cin >> l;
                buyInt(l);
            break;

            case 5: // display player inventory
                displayInfo();
            break;

            case 6: // quit
                cout << "Good Bye!" << endl;
            break;

            default:
                cout << "Invalid Input." << endl;
                cout << "Please enter a number (1-6)." << endl;
            break;
        }
    }
    while (choice != 6);
}

// ROOM 2 BUY MENU
void BestBuy::buyMenu2() {
    int choice = 0;
    int l = 0;
    int n = 0;

    do 
    {
        // ask user what they want to get and have them input
        cout << "WELCOME TO BEST BUY!" << endl;
        cout << "Select a numerical option:" << endl;
        cout << "1. Computer Parts" << endl;
        cout << "2. Antivirus Software" << endl;
        cout << "3. Virtual Private Network (VPN)" << endl;
        cout << "4. Internet Provider" << endl;
        cout << "5. Display Inventory" << endl;
        cout << "6. Quit" << endl;
        
        cin >> choice; // get user input

        // make a switch for user input
        switch (choice)
        {
            case 1: // for computer parts
                do {    // make another do-while for this case
                    // ask user what they want and have them input
                    cout << "Which computer part would you like to buy?" << endl;
                    cout << "YOU CAN ONLY HAVE MAX 3 OF EACH PART AND 1 PREMADE COMPUTER." << endl;
                    cout << "Select a numerical option:" << endl;
                    cout << "1. CPU, 11 DogeCoins" << endl;
                    cout << "2. GPU, 22 DogeCoins" << endl;
                    cout << "3. Power Supply Unit, 5.50 DogeCoins" << endl;
                    cout << "4. Computer Case, 16.50 DogeCoins" << endl;
                    cout << "5. Internet Card, 5.50 DogeCoins" << endl;
                    cout << "6. Keyboard and Mouse, 11 DogeCoins" << endl;
                    cout << "7. Premade Computer, 110 DogeCoins" << endl;
                    cout << "8. Quit" << endl;
                    cin >> n;

                    switch (n) // make another switch for this menu
                    {
                        case 1: // buy a cpu
                            cout << "How many CPUs would you like to buy?" << endl;
                            cin >> l;
                            buyCPURoom2(l);
                        break;

                        case 2: // buy a GPU
                            cout << "How many GPUs would you like to buy?" << endl;
                            cin >> l;
                            buyGPURoom2(l);
                        break;

                        case 3: // buy a Power supply unit
                            cout << "How many Power Supply Units would you like to buy?" << endl;
                            cin >> l;
                            buyPSURoom3(l);
                        break;

                        case 4: // buy a computer case
                            cout << "How many Computer Cases would you like to buy?" << endl;
                            cin >> l;
                            buyCompCaseRoom2(l);
                        break;

                        case 5: // buy an internet card
                            cout << "How many Internet Cards would you like to buy?" << endl;
                            cin >> l;
                            buyIntCardRoom2(l);
                        break;

                        case 6: // buy a keyboard and mouse
                            cout << "How many Keyboards and Mouses would you like to buy?" << endl;
                            cin >> l;
                            buyKeyMouseRoom2(l);
                        break;

                        case 7: // buy apremade computer
                            cout << "Are you sure you want to buy a premade computer for 100 DogeCoins?" << endl;
                            cout << "1. Yes" << endl;
                            cout << "0. No" << endl;
                            cin >> l;
                            buyPremadeCompRoom2(1);
                        break;

                        case 8:     // quit
                            cout << "Good Bye!" << endl;
                        break;

                        default:
                            cout << "Invalid Input. Please select a numerical number (1-8)" << endl;
                        break;
                    }
                }
                while (n != 8);
            break;

            case 2:     // buy antivirus software
                cout << "One USB of Antivirus Software costs 11 DogeCoins." << endl;
                cout << "It will give a one-time use to get rid of any viruses on the computer." << endl;
                cout << "How many antivirus USB sticks would you like to purchase?" << endl;
                cout << "Please enter a positive number." << endl;
                cin >> l;
                buyAVSRoom2(l);
            break;

            case 3:     // buy VPN
                cout << "A VPN costs 22 Dogecoins each." << endl;
                cout << "VPNs reduce your chances of getting hacked by preventing hackers from tracking down your main computer." << endl;
                cout << "The increase in security maxes out at 2 VPNs." << endl;
                cout << "Are you sure you want to purchase 1 VPN?" << endl;
                cout << "1. Yes" << endl;
                cout << "0. No" << endl;
                cin >> l;
                buyVPNRoom2(l);
            break;

            case 4:     // buy internet
                cout << "Costs:" << endl;
                cout << "Internet Provider Level 2: 11 DogeCoins" << endl;
                cout << "Internet Provider Level 3: 27.50 DogeCoins" << endl;
                cout << "Internet Provider Level 4: 44 DogeCoins" << endl;
                cout << "Internet Provider Level 5: 55 DogeCoins" << endl;
                cout << "Please enter a number (2-5)." << endl;
                cin >> l;
                buyIntRoom2(l);
            break;

            case 5: // display player inventory
                displayInfo();
            break;

            case 6: // quit
                cout << "Good Bye!" << endl;
            break;

            default:
                cout << "Invalid Input." << endl;
                cout << "Please enter a number (1-6)." << endl;
            break;
        }
    }
    while (choice != 6);
}

// BUY MENU ROOM 3
void BestBuy::buyMenu3() {
    int choice = 0;
    int l = 0;
    int n = 0;

    do 
    {
        // ask user what they want to get and have them input
        cout << "WELCOME TO BEST BUY!" << endl;
        cout << "Select a numerical option:" << endl;
        cout << "1. Computer Parts" << endl;
        cout << "2. Antivirus Software" << endl;
        cout << "3. Virtual Private Network (VPN)" << endl;
        cout << "4. Internet Provider" << endl;
        cout << "5. Display Inventory" << endl;
        cout << "6. Quit" << endl;
        
        cin >> choice; // get user input

        // make a switch for user input
        switch (choice)
        {
            case 1: // for computer parts
                do {    // make another do-while for this case
                    // ask user what they want and have them input
                    cout << "Which computer part would you like to buy?" << endl;
                    cout << "YOU CAN ONLY HAVE MAX 3 OF EACH PART AND 1 PREMADE COMPUTER." << endl;
                    cout << "Select a numerical option:" << endl;
                    cout << "1. CPU, 12 DogeCoins" << endl;
                    cout << "2. GPU, 24 DogeCoins" << endl;
                    cout << "3. Power Supply Unit, 6 DogeCoins" << endl;
                    cout << "4. Computer Case, 18 DogeCoins" << endl;
                    cout << "5. Internet Card, 6 DogeCoins" << endl;
                    cout << "6. Keyboard and Mouse, 12 DogeCoins" << endl;
                    cout << "7. Premade Computer, 120 DogeCoins" << endl;
                    cout << "8. Quit" << endl;
                    cin >> n;

                    switch (n) // make another switch for this menu
                    {
                        case 1: // buy a cpu
                            cout << "How many CPUs would you like to buy?" << endl;
                            cin >> l;
                            buyCPURoom3(l);
                        break;

                        case 2: // buy a GPU
                            cout << "How many GPUs would you like to buy?" << endl;
                            cin >> l;
                            buyGPURoom3(l);
                        break;

                        case 3: // buy a Power supply unit
                            cout << "How many Power Supply Units would you like to buy?" << endl;
                            cin >> l;
                            buyPSURoom3(l);
                        break;

                        case 4: // buy a computer case
                            cout << "How many Computer Cases would you like to buy?" << endl;
                            cin >> l;
                            buyCompCaseRoom3(l);
                        break;

                        case 5: // buy an internet card
                            cout << "How many Internet Cards would you like to buy?" << endl;
                            cin >> l;
                            buyIntCardRoom3(l);
                        break;

                        case 6: // buy a keyboard and mouse
                            cout << "How many Keyboards and Mouses would you like to buy?" << endl;
                            cin >> l;
                            buyKeyMouseRoom3(l);
                        break;

                        case 7: // buy apremade computer
                            cout << "Are you sure you want to buy a premade computer for 100 DogeCoins?" << endl;
                            cout << "1. Yes" << endl;
                            cout << "0. No" << endl;
                            cin >> l;
                            buyPremadeCompRoom3(1);
                        break;

                        case 8:     // quit
                            cout << "Good Bye!" << endl;
                        break;

                        default:
                            cout << "Invalid Input. Please select a numerical number (1-8)" << endl;
                        break;
                    }
                }
                while (n != 8);
            break;

            case 2:     // buy antivirus software
                cout << "One USB of Antivirus Software costs 12 DogeCoins." << endl;
                cout << "It will give a one-time use to get rid of any viruses on the computer." << endl;
                cout << "How many antivirus USB sticks would you like to purchase?" << endl;
                cout << "Please enter a positive number." << endl;
                cin >> l;
                buyAVSRoom3(l);
            break;

            case 3:     // buy VPN
                cout << "A VPN costs 24 Dogecoins each." << endl;
                cout << "VPNs reduce your chances of getting hacked by preventing hackers from tracking down your main computer." << endl;
                cout << "The increase in security maxes out at 2 VPNs." << endl;
                cout << "Are you sure you want to purchase 1 VPN?" << endl;
                cout << "1. Yes" << endl;
                cout << "0. No" << endl;
                cin >> l;
                buyVPNRoom3(l);
            break;

            case 4:     // buy internet
                cout << "Costs:" << endl;
                cout << "Internet Provider Level 2: 12 DogeCoins" << endl;
                cout << "Internet Provider Level 3: 30 DogeCoins" << endl;
                cout << "Internet Provider Level 4: 48 DogeCoins" << endl;
                cout << "Internet Provider Level 5: 60 DogeCoins" << endl;
                cout << "Please enter a number (2-5)." << endl;
                cin >> l;
                buyIntRoom3(l);
            break;

            case 5: // display player inventory
                displayInfo();
            break;

            case 6: // quit
                cout << "Good Bye!" << endl;
            break;

            default:
                cout << "Invalid Input." << endl;
                cout << "Please enter a number (1-6)." << endl;
            break;
        }
    }
    while (choice != 6);
}

// BUY MENU ROOM 4
void BestBuy::buyMenu4() {
    int choice = 0;
    int l = 0;
    int n = 0;

    do 
    {
        // ask user what they want to get and have them input
        cout << "WELCOME TO BEST BUY!" << endl;
        cout << "Select a numerical option:" << endl;
        cout << "1. Computer Parts" << endl;
        cout << "2. Antivirus Software" << endl;
        cout << "3. Virtual Private Network (VPN)" << endl;
        cout << "4. Internet Provider" << endl;
        cout << "5. Display Inventory" << endl;
        cout << "6. Quit" << endl;
        
        cin >> choice; // get user input

        // make a switch for user input
        switch (choice)
        {
            case 1: // for computer parts
                do {    // make another do-while for this case
                    // ask user what they want and have them input
                    cout << "Which computer part would you like to buy?" << endl;
                    cout << "YOU CAN ONLY HAVE MAX 3 OF EACH PART AND 1 PREMADE COMPUTER." << endl;
                    cout << "Select a numerical option:" << endl;
                    cout << "1. CPU, 12.50 DogeCoins" << endl;
                    cout << "2. GPU, 25 DogeCoins" << endl;
                    cout << "3. Power Supply Unit, 6.25 DogeCoins" << endl;
                    cout << "4. Computer Case, 18.75 DogeCoins" << endl;
                    cout << "5. Internet Card, 6.25 DogeCoins" << endl;
                    cout << "6. Keyboard and Mouse, 12.50 DogeCoins" << endl;
                    cout << "7. Premade Computer, 120 DogeCoins" << endl;
                    cout << "8. Quit" << endl;
                    cin >> n;

                    switch (n) // make another switch for this menu
                    {
                        case 1: // buy a cpu
                            cout << "How many CPUs would you like to buy?" << endl;
                            cin >> l;
                            buyCPURoom4(l);
                        break;

                        case 2: // buy a GPU
                            cout << "How many GPUs would you like to buy?" << endl;
                            cin >> l;
                            buyGPURoom4(l);
                        break;

                        case 3: // buy a Power supply unit
                            cout << "How many Power Supply Units would you like to buy?" << endl;
                            cin >> l;
                            buyPSURoom4(l);
                        break;

                        case 4: // buy a computer case
                            cout << "How many Computer Cases would you like to buy?" << endl;
                            cin >> l;
                            buyCompCaseRoom4(l);
                        break;

                        case 5: // buy an internet card
                            cout << "How many Internet Cards would you like to buy?" << endl;
                            cin >> l;
                            buyIntCardRoom4(l);
                        break;

                        case 6: // buy a keyboard and mouse
                            cout << "How many Keyboards and Mouses would you like to buy?" << endl;
                            cin >> l;
                            buyKeyMouseRoom4(l);
                        break;

                        case 7: // buy apremade computer
                            cout << "Are you sure you want to buy a premade computer for 100 DogeCoins?" << endl;
                            cout << "1. Yes" << endl;
                            cout << "0. No" << endl;
                            cin >> l;
                            buyPremadeCompRoom4(1);
                        break;

                        case 8:     // quit
                            cout << "Good Bye!" << endl;
                        break;

                        default:
                            cout << "Invalid Input. Please select a numerical number (1-8)" << endl;
                        break;
                    }
                }
                while (n != 8);
            break;

            case 2:     // buy antivirus software
                cout << "One USB of Antivirus Software costs 12.50 DogeCoins." << endl;
                cout << "It will give a one-time use to get rid of any viruses on the computer." << endl;
                cout << "How many antivirus USB sticks would you like to purchase?" << endl;
                cout << "Please enter a positive number." << endl;
                cin >> l;
                buyAVSRoom4(l);
            break;

            case 3:     // buy VPN
                cout << "A VPN costs 25 Dogecoins each." << endl;
                cout << "VPNs reduce your chances of getting hacked by preventing hackers from tracking down your main computer." << endl;
                cout << "The increase in security maxes out at 2 VPNs." << endl;
                cout << "Are you sure you want to purchase 1 VPN?" << endl;
                cout << "1. Yes" << endl;
                cout << "0. No" << endl;
                cin >> l;
                buyVPNRoom4(l);
            break;

            case 4:     // buy internet
                cout << "Costs:" << endl;
                cout << "Internet Provider Level 2: 12.50 DogeCoins" << endl;
                cout << "Internet Provider Level 3: 31.25 DogeCoins" << endl;
                cout << "Internet Provider Level 4: 50 DogeCoins" << endl;
                cout << "Internet Provider Level 5: 62.50 DogeCoins" << endl;
                cout << "Please enter a number (2-5)." << endl;
                cin >> l;
                buyIntRoom4(l);
            break;

            case 5: // display player inventory
                displayInfo();
            break;

            case 6: // quit
                cout << "Good Bye!" << endl;
            break;

            default:
                cout << "Invalid Input." << endl;
                cout << "Please enter a number (1-6)." << endl;
            break;
        }
    }
    while (choice != 6);
}

// BUY MENU ROOM 5
void BestBuy::buyMenu5() {
    int choice = 0;
    int l = 0;
    int n = 0;

    do 
    {
        // ask user what they want to get and have them input
        cout << "WELCOME TO BEST BUY!" << endl;
        cout << "Select a numerical option:" << endl;
        cout << "1. Computer Parts" << endl;
        cout << "2. Antivirus Software" << endl;
        cout << "3. Virtual Private Network (VPN)" << endl;
        cout << "4. Internet Provider" << endl;
        cout << "5. Display Inventory" << endl;
        cout << "6. Quit" << endl;
        
        cin >> choice; // get user input

        // make a switch for user input
        switch (choice)
        {
            case 1: // for computer parts
                do {    // make another do-while for this case
                    // ask user what they want and have them input
                    cout << "Which computer part would you like to buy?" << endl;
                    cout << "YOU CAN ONLY HAVE MAX 3 OF EACH PART AND 1 PREMADE COMPUTER." << endl;
                    cout << "Select a numerical option:" << endl;
                    cout << "1. CPU, 13 DogeCoins" << endl;
                    cout << "2. GPU, 26 DogeCoins" << endl;
                    cout << "3. Power Supply Unit, 6.50 DogeCoins" << endl;
                    cout << "4. Computer Case, 19.50 DogeCoins" << endl;
                    cout << "5. Internet Card, 6.50 DogeCoins" << endl;
                    cout << "6. Keyboard and Mouse, 13 DogeCoins" << endl;
                    cout << "7. Premade Computer, 130 DogeCoins" << endl;
                    cout << "8. Quit" << endl;
                    cin >> n;

                    switch (n) // make another switch for this menu
                    {
                        case 1: // buy a cpu
                            cout << "How many CPUs would you like to buy?" << endl;
                            cin >> l;
                            buyCPURoom5(l);
                        break;

                        case 2: // buy a GPU
                            cout << "How many GPUs would you like to buy?" << endl;
                            cin >> l;
                            buyGPURoom5(l);
                        break;

                        case 3: // buy a Power supply unit
                            cout << "How many Power Supply Units would you like to buy?" << endl;
                            cin >> l;
                            buyPSURoom5(l);
                        break;

                        case 4: // buy a computer case
                            cout << "How many Computer Cases would you like to buy?" << endl;
                            cin >> l;
                            buyCompCaseRoom5(l);
                        break;

                        case 5: // buy an internet card
                            cout << "How many Internet Cards would you like to buy?" << endl;
                            cin >> l;
                            buyIntCardRoom5(l);
                        break;

                        case 6: // buy a keyboard and mouse
                            cout << "How many Keyboards and Mouses would you like to buy?" << endl;
                            cin >> l;
                            buyKeyMouseRoom5(l);
                        break;

                        case 7: // buy apremade computer
                            cout << "Are you sure you want to buy a premade computer for 100 DogeCoins?" << endl;
                            cout << "1. Yes" << endl;
                            cout << "0. No" << endl;
                            cin >> l;
                            buyPremadeCompRoom5(1);
                        break;

                        case 8:     // quit
                            cout << "Good Bye!" << endl;
                        break;

                        default:
                            cout << "Invalid Input. Please select a numerical number (1-8)" << endl;
                        break;
                    }
                }
                while (n != 8);
            break;

            case 2:     // buy antivirus software
                cout << "One USB of Antivirus Software costs 13 DogeCoins." << endl;
                cout << "It will give a one-time use to get rid of any viruses on the computer." << endl;
                cout << "How many antivirus USB sticks would you like to purchase?" << endl;
                cout << "Please enter a positive number." << endl;
                cin >> l;
                buyAVSRoom5(l);
            break;

            case 3:     // buy VPN
                cout << "A VPN costs 26 Dogecoins each." << endl;
                cout << "VPNs reduce your chances of getting hacked by preventing hackers from tracking down your main computer." << endl;
                cout << "The increase in security maxes out at 2 VPNs." << endl;
                cout << "Are you sure you want to purchase 1 VPN?" << endl;
                cout << "1. Yes" << endl;
                cout << "0. No" << endl;
                cin >> l;
                buyVPNRoom5(l);
            break;

            case 4:     // buy internet
                cout << "Costs:" << endl;
                cout << "Internet Provider Level 2: 13 DogeCoins" << endl;
                cout << "Internet Provider Level 3: 32.50 DogeCoins" << endl;
                cout << "Internet Provider Level 4: 52 DogeCoins" << endl;
                cout << "Internet Provider Level 5: 65 DogeCoins" << endl;
                cout << "Please enter a number (2-5)." << endl;
                cin >> l;
                buyIntCardRoom5(l);
            break;

            case 5: // display player inventory
                displayInfo();
            break;

            case 6: // quit
                cout << "Good Bye!" << endl;
            break;

            default:
                cout << "Invalid Input." << endl;
                cout << "Please enter a number (1-6)." << endl;
            break;
        }
    }
    while (choice != 6);
}