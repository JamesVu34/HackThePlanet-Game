// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
using namespace std;

class BestBuy {
    public:
    BestBuy();                  // default constructor
    BestBuy(double coins, int comp, int vpnLevel, int internetLevel, int numCPU, int numGPU, int numPSU, int numCompCase, int numIntCard, int numKeyMouse, int numPremadeComp, int numAVS, int cMaintenceLev);
    
    // getters  
    double getDogeCoins();        // returns the players dogecoins
    int getComp();             // returns the computer
    int getVPN();              // returns the VPN level
    int getInternet();         // returns the internet level
    int getCPU();              // returns how many CPU's they have
    int getGPU();              // returns how many GPU's they have
    int getPSU();              // returns how many Power Supply Units they have
    int getCompCase();         // returns how many Computer Cases they have
    int getIntCard();          // returns the number of internet cards they have
    int getKeyMouse();         // returns the number of keyboards and mouses they have
    int getPremadeComp();      // returns the number of premade computers they have
    int getAVS();              // returns the number of Antivirus software they have
    int getCompMaintenceLev(); // returns the computer maintence level

    // setters
    void setDogeCoins(double);      // sets the players dogecoins
    void setComp(int);              // sets the player computer
    void setVPN(int);               // sets the player VPN level
    void setInternet(int);          // sets the players internet level
    void setCPU(int);               // sets the player CPU
    void setGPU(int);               // sets the player GPU
    void setPSU(int);               // sets the player Power Supply Unit
    void setCompCase(int);          // sets the computer case number
    void setIntCard(int);           // sets the number of internet cards
    void setKeyMouse(int);          // sets the number of keyboards and mouses
    void setPremadeComp(int);       // sets the number of premade computers
    void setAVS(int);               // sets the number of antivirus softwares they have
    void setCompMaintenceLev(int);  // sets the computer maintence level

    // display
    void displayInfo();             // displays players info

    // lost random part function
    void loseRandPart(int);

    // get random part function
    void getRandPart(int);

    // menu
    void buyMenu1();                // room 1 buy menu
    void buyMenu2();                // room 2 buy menu
    void buyMenu3();                // room 3 buy menu
    void buyMenu4();                // room 4 buy menu 
    void buyMenu5();                // room 5 buy menu

    // BUYING COMPUTER STUFF
    void buyCPU(int);
    void buyGPU(int);
    void buyPSU(int);    
    void buyCompCase(int);
    void buyIntCard(int);
    void buyKeyMouse(int);
    void buyPremadeComp(int);
    void buyVPN(int);
    void buyInt(int);

    // room 2 = increase prices by 10%
    void buyCPURoom2(int);
    void buyGPURoom2(int);
    void buyPSURoom2(int);    
    void buyCompCaseRoom2(int);
    void buyIntCardRoom2(int);
    void buyKeyMouseRoom2(int);
    void buyPremadeCompRoom2(int);
    void buyVPNRoom2(int);
    void buyIntRoom2(int);

    // room 3 = increase prices by 20%
    void buyCPURoom3(int);
    void buyGPURoom3(int);
    void buyPSURoom3(int);    
    void buyCompCaseRoom3(int);
    void buyIntCardRoom3(int);
    void buyKeyMouseRoom3(int);
    void buyPremadeCompRoom3(int);
    void buyVPNRoom3(int);
    void buyIntRoom3(int);

    // room 4 = increase prices by 25%
    void buyCPURoom4(int);
    void buyGPURoom4(int);
    void buyPSURoom4(int);    
    void buyCompCaseRoom4(int);
    void buyIntCardRoom4(int);
    void buyKeyMouseRoom4(int);
    void buyPremadeCompRoom4(int);
    void buyVPNRoom4(int);
    void buyIntRoom4(int);

    // room 5 = increase prices by 30%
    void buyCPURoom5(int);
    void buyGPURoom5(int);
    void buyPSURoom5(int);    
    void buyCompCaseRoom5(int);
    void buyIntCardRoom5(int);
    void buyKeyMouseRoom5(int);
    void buyPremadeCompRoom5(int);
    void buyVPNRoom5(int);
    void buyIntRoom5(int);


    // ANTI VIRUS SOFTWARE
    void buyAVS(int);
    void buyAVSRoom2(int);
    void buyAVSRoom3(int);
    void buyAVSRoom4(int);
    void buyAVSRoom5(int);

    // display text
    void displayTxt();

    // display all the players parts
    void displayParts();    

    // repair computer
    void repairComputer();

    private:
    double dogeCoins;
    int computer;
    int VPN;
    int internet;
    int CPU;
    int GPU;
    int PSU;
    int compCase;
    int internetCard;
    int keyMouse;
    int premadeComp;
    int AVS;
    int compMaintenceLev;
};