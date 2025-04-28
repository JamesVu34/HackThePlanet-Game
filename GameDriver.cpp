// CSCI 1300 FALL 2021
// Author: James Vu
// Project 3: Game Compile File

#include <iostream>
#include <fstream>
#include "BestBuy.h"
#include "Start.h"
#include "Map.h"
#include "Hacker.h"
#include "Room.h"
using namespace std;

// implement split function
int split(string beSplit, char sep, string stored[], int sizeArray){
    //declare any variables
    int count = 0;

    if (beSplit.length() == 0)
        return 0;

    else if (count < sizeArray){
        beSplit += sep;
        int j = 0;
        int length = 0;
        // make a for loop to go through the string
        for (int i = 0; i < beSplit.length(); i++){
            if (beSplit[i] == sep){
                
                string substring = beSplit.substr(j, length);
                stored[count] = substring;
                j = i+1; 
                count++;
                length = 0;
            
                if (count > sizeArray)
                    return -1;
            }
            else{
                length = length + 1;
            }
        }
    }
    return count;
}

int main(){
    //declare variables
    Start s = Start();
    BestBuy b = BestBuy();
    Hacker h = Hacker();
    Map m;
    Map m2;
    Map m3;
    Map m4;
    Map m5;
    string name;
    char move;
    int choice = 0; 
    int n = 0;
    int l = 0;
    srand(time(NULL));
    string line;
    int numLines = 0;
    string splitHack[2];
    vector<string> room1;
    vector<string> room2;
    vector<string> room3;
    vector<string> room4;
    vector<string> room5;
    int t = 3;
    int room1Rand = rand() % t + 0; // random number for hacker in room 1
    int f = 3;
    int room2Rand = rand() % f + 0; // random number for hacker in room 2
    int a = 3;
    int room3Rand = rand() % a + 0; // random number for hacker in room 3
    int r4Rand = 3;
    int room4Rand = rand() % r4Rand + 0; // random number for hacker in room 4
    int r5Rand = 3;
    int room5Rand = rand() % r5Rand + 0; // random number for hacker in room 5
    int c = 3;
    int r = 0;
    int numGPU = b.getGPU();
    int winCount1 = 0;  // keeps track of how many hackers they've beet in room 1 
    int winCount2 = 0;  // keeps track of how many hackers they've beet in room 2
    int winCount3 = 0;  // keeps track of how many hackers they've beet in room 3
    int winCount4 = 0;  // keeps track of how many hackers they've beet in room 4
    int winCount5 = 0;  // keeps track of how many hackers they've beet in room 5
    char ans1;      // for room 1 when they beat a hacker and want to move on
    char ans2;      // for room 2 when they beat a hacker and want to move on
    char ans3;      // for room 3 when they beat a hacker and want to move on
    char ans4;      // for room 4 when they beat a hacker and want to move on
    char ans5;      // for room 5 when they beat a hacker and want to move on
    int puzz1 = 0;
    int puzz2 = 0;
    int puzz3 = 0;
    int puzz4 = 0;
    int puzz5 = 0;
    int moveOn1 = 0;
    int moveOn2 = 0;
    int moveOn3 = 0;
    int moveOn4 = 0;
    int moveOn5 = 0;
    int randMisfortune = rand() % 3 + 1;
 
    // START OF GAME
    cout << "Hello! Please enter your name." << endl;
    getline(cin, name);
    s.setName(name);
    cout << "Welcome, " << s.getName() << "!" << endl;
    cout << endl;
    
    // display bestbuytxt
    b.displayTxt();
    cout << endl;

    // GOING INTO
    // make a do-while statement until they quit
    b.buyMenu1();
    cout << endl;

    // READ HACKERS AND SET THEM TO CORRECT ROOMS
    // open file
    ifstream theFile("hackers.txt");
    if (theFile.is_open()){     // only do stuff when file is open
        while (getline(theFile, line)) {    // get each line of the file
            if (line.length() > 0) {    // only get non empty lines
                // split up lines
                split(line, ',', splitHack, 2);

                if (stoi(splitHack[1]) == 1){   // storing room 1 into room 1 vector
                    h.setHackerName(splitHack[0]);
                    h.setHackerLevel(stoi(splitHack[1]));
                    room1.push_back(h.getHackerName());
                }

                else if (stoi(splitHack[1]) == 2){   // storing room 2 names into room 2 vec
                    h.setHackerName(splitHack[0]);
                    h.setHackerLevel(stoi(splitHack[1]));
                    room2.push_back(h.getHackerName());
                }
                
                else if (stoi(splitHack[1]) == 3) {     // storing room 3 names into room3 vec
                    h.setHackerName(splitHack[0]);
                    h.setHackerLevel(stoi(splitHack[1]));
                    room3.push_back(h.getHackerName());
                }

                else if (stoi(splitHack[1]) == 4) {     // storing room 4 names into room4 vec
                    h.setHackerName(splitHack[0]);
                    h.setHackerLevel(stoi(splitHack[1]));
                    room4.push_back(h.getHackerName());
                }

                else if (stoi(splitHack[1]) == 5) {     // storing room 5 names into 5 vec
                    h.setHackerName(splitHack[0]);
                    h.setHackerLevel(stoi(splitHack[1]));
                    room5.push_back(h.getHackerName());
                }
                
                numLines++;
            }
        }
        // close file when done
        theFile.close();
    }
    else if (theFile.fail()) {
        return -1;
    }


    
    // make a menu for activites you can do in each room.
    if (s.getFrustLevel() < 100 || b.getCompMaintenceLev() > 0) {   // if statement to see if the game ends or not
        // FIRST ROOM
        // 1 BESTBUY, 2 NPC, 4 HACKER
        Room r1 = Room("Turing Room", 1); 
        cout << "You will now be entered into the 1st Room:" << endl;
        cout << r1.getRoomName() << endl;
        cout << endl;

        do {
            cout << "Here are the activities you can do: " << endl;
            cout << "Please select a numerical option. (1-5)" << endl; 
            cout << "1. Start Traveling in Server Room \n2. Repair Your Computer \n3. Use your antivirus software \n4. Browse Stackoverflow \n5. Move on to next server room\n6. Quit" << endl;
            cin >> l;   // get user input

            if (s.getVirus() > 0) { // if the player has a virus 
                int virusNum = s.getVirus() * 10;
                
                if (l == 1 || l == 2 || l == 3 || l == 4 || l == 5){ // whenever they do something on the menu 
                    b.setCompMaintenceLev(b.getCompMaintenceLev() - virusNum);
                }
            }

            // create a switch and do whatever user wants
            switch(l)
            {
                case 1: // case for traveling in the server room
                    cout << "Traveling To Server Room" << endl;
                    m.spawnBestBuy(rand() % 4 + 1, rand() % 8 + 1);   // spawns bestbuy at random location on map
                    m.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);     // spawn 2 npcs at random location on map
                    m.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);
                    m.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);  // spawn 4 hacker at random location on map
                    m.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                    m.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                    m.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);

                    // quit after player makes 10 moves
                    for (int i = 0; i < 10; i++) {
                        m.displayMap(); // display map

                        cout << "Valid Moves Are: " << endl;
                        m.displayMoves();   // displays the valid moves the player can pick from
                        cin >> move;
                        m.executeMove(move);
                        

                        // adds 5 bitcoin everytime a move is executed
                        b.setDogeCoins(b.getDogeCoins() + 5);
                        if (b.getGPU() > 0) {   // adds more if they player has gpus
                            b.setDogeCoins(b.getDogeCoins() + (numGPU * 5));
                        }

                        if (m.isBestBuyLocation()) {    // if they are in a bestbuy 
                            cout << "Entering Best Buy..." << endl;
                            cout << endl;
                            b.buyMenu1();
                        }
                                    
                        if (m.isHackerLocation()) {     // if they run into a hacker
                            cout << "You just ran into " << room1[room1Rand] << "! Think you can beat this hacker's skills?" << endl;
                            cout << "1. Attack \n2. Forfeit" << endl;   // give the user an option to forfeit or attack
                            cin >> l;

                            // misfortune
                            if (s.misfortuneGen() == 1) {
                                if (randMisfortune == 1) {  // steal a random part
                                    b.loseRandPart(rand() % 6 + 1);
                                    cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                                }

                                else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                    b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                    cout << "OH NO! Your computer was damaged!" << endl;
                                }

                                else if (randMisfortune == 3) {     // increase frustration level by 10
                                    s.setFrustLevel(s.getFrustLevel() + 10);
                                    cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                                }
                            }

                            if (l == 1) {   // if they choose to attack
                                int result = h.fightHacker(b.getInternet(), b.getVPN(), 1);
                                cout << "You have chosen to attack!" << endl;

                                if (result > 0) {   // if player wins battle
                                    cout << "You have won the battle against " << room1[room1Rand] << "!" << endl;
                                    cout << "You have gained 50 Doge Coins!" << endl;
                                    b.setDogeCoins(b.getDogeCoins() + 50);  // add 50 dogecoins if they win
                                    cout << "DogeCoins: " << b.getDogeCoins() << endl;
                                    winCount1 += 1;

                                    b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker

                                    if (t >= 0) {   // for the room1Rand 
                                        room1.erase(room1.begin() + room1Rand); // THIS IS HOW TO ERASE ONCE THEY DEFEAT THE HACKER
                                        t -= 1;
                                    }
                                }
                                
                                else if (result <= 0) { // if player loses battle
                                    b.setCompMaintenceLev(b.getCompMaintenceLev() - 20);    // computermaintencelevel goes down 20
                                    b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker
                                    cout << "You have lost the battle against " << room1[room1Rand] << "!" << endl;
                                    cout << "Your computer maintence level is now down 20." << endl;
                                    cout << "Computer Maintenece Level: " << b.getCompMaintenceLev() << endl;

                                    if ((rand() % 10 + 1) % 10 == 0) {  // add a virus 
                                        s.setVirus(s.getVirus() + 1);
                                        cout << "Your computer now has a virus." << endl;
                                        cout << "Viruses: " << s.getVirus() << endl;
                                    }
                                }
                            }

                            else if (l == 2) {  // if they choose to forfeit
                                cout << "Forfeit." << endl;
                            }
                            else {
                                cout << "Invalid Input. Please select a number (1-2)." << endl;
                            }
                        }

                        if (m.isNPCLocation()) {        // if they run into an NPC 
                            cout << "Do you want to complete their puzzle?" << endl;
                            cout << "1. Yes\n2. No" << endl;
                            cin >> l;

                            if (l == 1) {   // when they do want to complete a puzzle
                                if (s.getFrustLevel() >= 5) {
                                        r = rand() % 5 + 1;

                                        // to pick which puzzle to use
                                        if (r == 1) {
                                            puzz1 = s.puzzle1();

                                            if (puzz1 == 1) {
                                                s.setFrustLevel(s.getFrustLevel() - 5);
                                                cout << "Correct!" << endl;
                                                cout << "Your frustration level will now be lowered by 5" << endl;
                                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                            }
                                            else if (puzz1 == -1) {
                                                cout << "Incorrect!" << endl;
                                            }
                                        }
                                        else if (r == 2){
                                            puzz2 = s.puzzle2();

                                            if (puzz2 == 1) {
                                                s.setFrustLevel(s.getFrustLevel() - 5);
                                                cout << "Correct!" << endl;
                                                cout << "Your frustration level will now be lowered by 5" << endl;
                                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                            }
                                            else if (puzz2 == -1) {
                                                cout << "Incorrect!" << endl;
                                            }
                                        }
                                        else if (r == 3){
                                            puzz3 = s.puzzle3();

                                            if (puzz3 == 1) {
                                                s.setFrustLevel(s.getFrustLevel() - 5);
                                                cout << "Correct!" << endl;
                                                cout << "Your frustration level will now be lowered by 5" << endl;
                                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                            }
                                            else if (s.puzzle3() == -1) {
                                                cout << "Incorrect!" << endl;
                                            }
                                        }
                                        else if (r == 4){
                                            puzz4 = s.puzzle4();

                                            if (puzz4 == 1) {
                                                s.setFrustLevel(s.getFrustLevel() - 5);
                                                cout << "Correct!" << endl;
                                                cout << "Your frustration level will now be lowered by 5" << endl;
                                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                            }
                                            else if (puzz4 == -1) {
                                                cout << "Incorrect!" << endl;
                                            }
                                        }
                                        else if (r == 5){
                                            puzz5 = s.puzzle5();

                                            if (puzz5 == 1) {
                                                s.setFrustLevel(s.getFrustLevel() - 5);
                                                cout << "Correct!" << endl;
                                                cout << "Your frustration level will now be lowered by 5" << endl;
                                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                            }
                                            else if (puzz5 == -1) {
                                                cout << "Incorrect!" << endl;
                                            }
                                        }
                                    }
                            }

                            else if (l == 2) {  // if they dont want to complete a puzzle
                                cout << "Do you want to take your chances with the NPC?" << endl;

                                if ((rand() % 100 + 1) % 33) {  // good npc
                                    b.getRandPart(rand() % 6 + 1);  // get a random part
                                }
                                
                                if ((rand() % 100 + 1) % 33) {  // bad npc
                                    b.loseRandPart(rand() % 6 + 1); // lose a random part
                                }
                            }

                            else {  // invalid
                                cout << "Invalid Input. Please select a number (1-2)" << endl;
                            }

                        }
                    }
                break;

                case 2:     // case for repair a computer
                    if (s.getVirus() == 0) {    // make sure they dont have a virus 

                        if (b.getCompMaintenceLev() < 100){ // if their maintence level is less than 100 let them repair
                            b.repairComputer();
                        }
                        else {  // if their computer maintence level is at 100 or higher
                            cout << "Computer Maintence Level: " << b.getCompMaintenceLev() << endl;
                            cout << "You cannot repair your computer. You're maintence level is already high." << endl;
                        }
                    }

                    else if (s.getVirus() > 0) {    // if they have a virus tell them they cant repair
                        cout << "Your computer has a virus. \nYou cannot repair your computer until you get rid of your virus." << endl;
                    }
                        
                break;

                case 3:     // case for using antivirus software
                    cout << "Your computer has " << s.getVirus() << " would you like to use Antivirus Software?" << endl;
                    cout << "1. Yes\n2. No" << endl;
                    cin >> l;

                    if (l == 1){    // if they choose to use antivirus software
                        if (b.getAVS() > 0) {    // make sure they have antivirus software to use
                            b.setAVS(b.getAVS() - 1);   // get rid of one antivirus software once they use it
                            s.setVirus(0);  // set virus to 0 
                            cout << "You used Antivirus Software succesfully." << endl;

                        }

                        else if (b.getAVS() <= 0){   // if they dont have antivirus software
                        cout << "You don't have an antivirus software to use." << endl;
                        }
                    }
                    if (l == 2){    // if they choose not to use antivirus software
                        cout << "Okay." << endl;
                    }   
                        
                break;

                case 4:     // case for browsing stackoverflow
                    r = rand() % 5 + 1; // rand num generator to select a random puzzle each time

                    // misfortune
                    if (s.misfortuneGen() == 1) {
                        if (randMisfortune == 1) {  // steal a random part
                            b.loseRandPart(rand() % 6 + 1);
                            cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                        }
                    }
                    
                    else if (randMisfortune == 2) {     // lower computer maintence level by 10
                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                        cout << "OH NO! Your computer was damaged!" << endl;
                    }
                                                
                    else if (randMisfortune == 3) {     // increase frustration level by 10
                        s.setFrustLevel(s.getFrustLevel() + 10);
                        cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                    }
                    
                    // make sure they can lower it 
                    if (s.getFrustLevel() >= 5) {
                        // to pick which puzzle to use
                        if (r == 1) {
                            puzz1 = s.puzzle1();

                            if (puzz1 == 1) {
                                s.setFrustLevel(s.getFrustLevel() - 5);
                                cout << "Correct!" << endl;
                                cout << "Your frustration level will now be lowered by 5" << endl;
                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                            }
                            else if (puzz1 == -1) {
                                cout << "Incorrect!" << endl;
                            }
                        }
                        else if (r == 2){
                            puzz2 = s.puzzle2();

                            if (puzz2 == 1) {
                                s.setFrustLevel(s.getFrustLevel() - 5);
                                cout << "Correct!" << endl;
                                cout << "Your frustration level will now be lowered by 5" << endl;
                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                            }
                            else if (puzz2 == -1) {
                                cout << "Incorrect!" << endl;
                            }
                        }
                        else if (r == 3){
                            puzz3 = s.puzzle3();

                            if (puzz3 == 1) {
                                s.setFrustLevel(s.getFrustLevel() - 5);
                                cout << "Correct!" << endl;
                                cout << "Your frustration level will now be lowered by 5" << endl;
                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                            }
                            else if (s.puzzle3() == -1) {
                                cout << "Incorrect!" << endl;
                            }
                        }
                        else if (r == 4){
                            puzz4 = s.puzzle4();

                            if (puzz4 == 1) {
                                s.setFrustLevel(s.getFrustLevel() - 5);
                                cout << "Correct!" << endl;
                                cout << "Your frustration level will now be lowered by 5" << endl;
                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                            }
                            else if (puzz4 == -1) {
                                cout << "Incorrect!" << endl;
                            }
                        }
                        else if (r == 5){
                            puzz5 = s.puzzle5();

                            if (puzz5 == 1) {
                                s.setFrustLevel(s.getFrustLevel() - 5);
                                cout << "Correct!" << endl;
                                cout << "Your frustration level will now be lowered by 5" << endl;
                                cout << "Frusration Level: " << s.getFrustLevel() << endl;
                            }
                            else if (puzz5 == -1) {
                                cout << "Incorrect!" << endl;
                            }
                        }
                    }
                    else {
                        cout << "You cannot lower your frustration level anymore!" << endl;
                        cout << "Frustration Level: " << s.getFrustLevel() << endl;
                    }

                break;

                case 5: // case for moving on to next server room
                    if (winCount1 > 0) {
                        if (winCount1 == 1){
                            cout << "You have defeated " << winCount1 << " hacker!" << endl;
                            cout << "Would you like to move on to the next room?" << endl;
                            cout << "Y = Yes\nN = No" << endl;
                            cin >> ans1;

                            if (ans1 == 'y' || ans1 == 'Y') {
                                cout << "Press Quit on next menu to move on." << endl;
                                cout << endl;
                                moveOn1 += 1;
                                break;
                            }
                            else if (ans1 == 'n' || ans1 == 'N') {
                                cout << "Okay." << endl;
                            }
                            else {
                                cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                            }
                        }
                        else {
                            cout << "You have defeated " << winCount1 << " hackers!" << endl;
                            cout << "Would you like to move on to the next room?" << endl;
                            cin >> ans1;

                            if (ans1 == 'y' || ans1 == 'Y') {
                                cout << "Press Quit on next menu to move on." << endl;
                                cout << endl;
                                moveOn1 += 1;
                                break;
                            }
                            else if (ans1 == 'n' || ans1 == 'N') {
                                cout << "Okay." << endl;
                            }
                            else {
                                cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                            }
                        }
                    }

                    else if (winCount1 <= 0) {
                        cout << "You have not defeated a hacker yet!\nYou have to defeat at least 1 hacker in order to move on!" << endl;
                    }
                    
                break;

                case 6:     // case for quitting
                    if (moveOn1 <= 0) {
                        cout << "Sorry you couldn't defeat all the hackers!" << endl;
                        cout << "Maybe you can defeat them next time!" << endl;
                        cout << "Good Bye!" << endl;
                    }
                break;

                default:    // invalid input
                    cout << "Invalid Input. \nPlease select a number (1-5)" << endl;
                break;
                }
        }
        while (l != 6);

        // MOVING TO NEXT SERVER ROOM
        if (moveOn1 > 0) {  
            Room r2 = Room();
            r2.setRoomName("Ellis Room");
            r2.setRoomLevel(2);

            cout << "Now entering the 2nd Room: " << r2.getRoomName() << endl;
            cout << endl;
            do 
            {
                cout << "Here are the activities you can do: " << endl;
                cout << "Please select a numerical option. (1-5)" << endl; 
                cout << "1. Start Traveling in Server Room \n2. Repair Your Computer \n3. Use your antivirus software \n4. Browse Stackoverflow \n5. Move on to next server room\n6. Quit" << endl;
                cin >> l;   // get user input

                if (s.getVirus() > 0) { // if the player has a virus 
                    int virusNum = s.getVirus() * 10;
                    
                    if (l == 1 || l == 2 || l == 3 || l == 4 || l == 5){ // whenever they do something on the menu 
                        b.setCompMaintenceLev(b.getCompMaintenceLev() - virusNum);
                    }
                }

                // create a switch and do whatever user wants
                switch(l)
                {
                    case 1: // case for traveling in the server room
                        cout << "Traveling To Server Room" << endl;
                        m2.spawnBestBuy(rand() % 4 + 1, rand() % 8 + 1);   // spawns bestbuy at random location on map
                        m2.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);     // spawn 2 npcs at random location on map
                        m2.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);
                        m2.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);  // spawn 4 hacker at random location on map
                        m2.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m2.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m2.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);

                        // quit after player makes 10 moves
                        for (int i = 0; i < 10; i++) {
                            m2.displayMap(); // display map

                            cout << "Valid Moves Are: " << endl;
                            m2.displayMoves();   // displays the valid moves the player can pick from
                            cin >> move;
                            m2.executeMove(move);
                            

                            // adds 5 bitcoin everytime a move is executed
                            b.setDogeCoins(b.getDogeCoins() + 5);
                            if (b.getGPU() > 0) {   // adds more if they player has gpus
                                b.setDogeCoins(b.getDogeCoins() + (numGPU * 5));
                            }

                            if (m2.isBestBuyLocation()) {    // if they are in a bestbuy 
                                cout << "Entering Best Buy..." << endl;
                                cout << endl;
                                b.buyMenu2();
                            }
                                        
                            if (m2.isHackerLocation()) {     // if they run into a hacker
                                cout << "You just ran into " << room2[room2Rand] << "! Think you can beat this hacker's skills?" << endl;
                                cout << "1. Attack \n2. Forfeit" << endl;   // give the user an option to forfeit or attack
                                cin >> l;

                                // misfortune
                                if (s.misfortuneGen() == 1) {
                                    if (randMisfortune == 1) {  // steal a random part
                                        b.loseRandPart(rand() % 6 + 1);
                                        cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                                    }

                                    else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                        cout << "OH NO! Your computer was damaged!" << endl;
                                    }

                                    else if (randMisfortune == 3) {     // increase frustration level by 10
                                        s.setFrustLevel(s.getFrustLevel() + 10);
                                        cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                                    }
                                }

                                if (l == 1) {   // if they choose to attack
                                    int result = h.fightHacker(b.getInternet(), b.getVPN(), 2);
                                    cout << "You have chosen to attack!" << endl;

                                    if (result > 0) {   // if player wins battle
                                        cout << "You have won the battle against " << room2[room2Rand] << "!" << endl;
                                        cout << "You have gained 50 Doge Coins!" << endl;
                                        b.setDogeCoins(b.getDogeCoins() + 50);  // add 50 dogecoins if they win
                                        cout << "DogeCoins: " << b.getDogeCoins() << endl;
                                        winCount2 += 1;

                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker

                                        if (f >= 0) {   // for the room1Rand 
                                            room2.erase(room2.begin() + room2Rand); // THIS IS HOW TO ERASE ONCE THEY DEFEAT THE HACKER
                                            f -= 1;
                                        }
                                    }
                                    
                                    else if (result <= 0) { // if player loses battle
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 20);    // computermaintencelevel goes down 20
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker
                                        cout << "You have lost the battle against " << room2[room2Rand] << "!" << endl;
                                        cout << "Your computer maintence level is now down 20." << endl;
                                        cout << "Computer Maintenece Level: " << b.getCompMaintenceLev() << endl;

                                        if ((rand() % 10 + 1) % 10 == 0) {  // add a virus 
                                            s.setVirus(s.getVirus() + 1);
                                            cout << "Your computer now has a virus." << endl;
                                            cout << "Viruses: " << s.getVirus() << endl;
                                        }
                                    }
                                }

                                else if (l == 2) {  // if they choose to forfeit
                                    cout << "Forfeit." << endl;
                                }
                                else {
                                    cout << "Invalid Input. Please select a number (1-2)." << endl;
                                }
                            }

                            if (m2.isNPCLocation()) {        // if they run into an NPC 
                                cout << "Do you want to complete their puzzle?" << endl;
                                cout << "1. Yes\n2. No" << endl;
                                cin >> l;

                                if (l == 1) {   // when they do want to complete a puzzle
                                    if (s.getFrustLevel() >= 5) {
                                            r = rand() % 5 + 1;

                                            // to pick which puzzle to use
                                            if (r == 1) {
                                                puzz1 = s.puzzle1();

                                                if (puzz1 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz1 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 2){
                                                puzz2 = s.puzzle2();

                                                if (puzz2 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz2 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 3){
                                                puzz3 = s.puzzle3();

                                                if (puzz3 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (s.puzzle3() == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 4){
                                                puzz4 = s.puzzle4();

                                                if (puzz4 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz4 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 5){
                                                puzz5 = s.puzzle5();

                                                if (puzz5 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz5 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                        }
                                }

                                else if (l == 2) {  // if they dont want to complete a puzzle
                                    cout << "Do you want to take your chances with the NPC?" << endl;

                                    if ((rand() % 100 + 1) % 33) {  // good npc
                                        b.getRandPart(rand() % 6 + 1);  // get a random part
                                    }
                                    
                                    if ((rand() % 100 + 1) % 33) {  // bad npc
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part
                                    }
                                }

                                else {  // invalid
                                    cout << "Invalid Input. Please select a number (1-2)" << endl;
                                }

                            }
                        }
                    break;

                    case 2:     // case for repair a computer
                        if (s.getVirus() == 0) {    // make sure they dont have a virus 

                            if (b.getCompMaintenceLev() < 100){ // if their maintence level is less than 100 let them repair
                                b.repairComputer();
                            }
                            else {  // if their computer maintence level is at 100 or higher
                                cout << "Computer Maintence Level: " << b.getCompMaintenceLev() << endl;
                                cout << "You cannot repair your computer. You're maintence level is already high." << endl;
                            }
                        }

                        else if (s.getVirus() > 0) {    // if they have a virus tell them they cant repair
                            cout << "Your computer has a virus. \nYou cannot repair your computer until you get rid of your virus." << endl;
                        }
                            
                    break;

                    case 3:     // case for using antivirus software
                        cout << "Your computer has " << s.getVirus() << " would you like to use Antivirus Software?" << endl;
                        cout << "1. Yes\n2. No" << endl;
                        cin >> l;

                        if (l == 1){    // if they choose to use antivirus software
                            if (b.getAVS() > 0) {    // make sure they have antivirus software to use
                                b.setAVS(b.getAVS() - 1);   // get rid of one antivirus software once they use it
                                s.setVirus(0);  // set virus to 0 
                                cout << "You used Antivirus Software succesfully." << endl;

                            }

                            else if (b.getAVS() <= 0){   // if they dont have antivirus software
                            cout << "You don't have an antivirus software to use." << endl;
                            }
                        }
                        if (l == 2){    // if they choose not to use antivirus software
                            cout << "Okay." << endl;
                        }   
                            
                    break;

                    case 4:     // case for browsing stackoverflow
                        r = rand() % 5 + 1; // rand num generator to select a random puzzle each time

                        // misfortune
                        if (s.misfortuneGen() == 1) {
                            if (randMisfortune == 1) {  // steal a random part
                                b.loseRandPart(rand() % 6 + 1);
                                cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                            }
                        }
                        
                        else if (randMisfortune == 2) {     // lower computer maintence level by 10
                            b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                            cout << "OH NO! Your computer was damaged!" << endl;
                        }
                                                    
                        else if (randMisfortune == 3) {     // increase frustration level by 10
                            s.setFrustLevel(s.getFrustLevel() + 10);
                            cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                        }
                        
                        // make sure they can lower it 
                        if (s.getFrustLevel() >= 5) {
                            // to pick which puzzle to use
                            if (r == 1) {
                                puzz1 = s.puzzle1();

                                if (puzz1 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz1 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 2){
                                puzz2 = s.puzzle2();

                                if (puzz2 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz2 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 3){
                                puzz3 = s.puzzle3();

                                if (puzz3 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (s.puzzle3() == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 4){
                                puzz4 = s.puzzle4();

                                if (puzz4 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz4 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 5){
                                puzz5 = s.puzzle5();

                                if (puzz5 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz5 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                        }
                        else {
                            cout << "You cannot lower your frustration level anymore!" << endl;
                            cout << "Frustration Level: " << s.getFrustLevel() << endl;
                        }

                    break;

                    case 5: // case for moving on to next server room
                        if (winCount2 > 0) {
                            if (winCount2 == 1){
                                cout << "You have defeated " << winCount2 << " hacker!" << endl;
                                cout << "Would you like to move on to the next room?" << endl;
                                cout << "Y = Yes\nN = No" << endl;
                                cin >> ans2;

                                if (ans2 == 'y' || ans2 == 'Y') {
                                    cout << "Press Quit on next menu to move on." << endl;
                                    cout << endl;
                                    moveOn2 += 1;
                                    break;
                                }
                                else if (ans2 == 'n' || ans2 == 'N') {
                                    cout << "Okay." << endl;
                                }
                                else {
                                    cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                                }
                            }
                            else {
                                cout << "You have defeated " << winCount2 << " hackers!" << endl;
                                cout << "Would you like to move on to the next room?" << endl;
                                cin >> ans2;

                                if (ans2 == 'y' || ans2 == 'Y') {
                                    cout << "Press Quit on next menu to move on." << endl;
                                    cout << endl;
                                    moveOn2 += 1;
                                    break;
                                }
                                else if (ans2 == 'n' || ans2 == 'N') {
                                    cout << "Okay." << endl;
                                }
                                else {
                                    cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                                }
                            }
                        }

                        else if (winCount2 <= 0) {
                            cout << "You have not defeated a hacker yet!\nYou have to defeat at least 1 hacker in order to move on!" << endl;
                        }
                        
                    break;

                    case 6:     // case for quitting
                        if (moveOn2 <= 0) {
                            cout << "Sorry you couldn't defeat all the hackers!" << endl;
                            cout << "Maybe you can defeat them next time!" << endl;
                            cout << "Good Bye!" << endl;
                        }
                    break;

                    default:    // invalid input
                        cout << "Invalid Input. \nPlease select a number (1-5)" << endl;
                    break;
                    }
            }
            while (l != 6);
        }

        // ROOM 3
        if (moveOn2 > 0) {  
            Room r3 = Room();
            r3.setRoomName("Johnson Room");
            r3.setRoomLevel(3);

            cout << "Now entering the 3rd Room: " << r3.getRoomName() << endl;
            cout << endl;
            do 
            {
                cout << "Here are the activities you can do: " << endl;
                cout << "Please select a numerical option. (1-5)" << endl; 
                cout << "1. Start Traveling in Server Room \n2. Repair Your Computer \n3. Use your antivirus software \n4. Browse Stackoverflow \n5. Move on to next server room\n6. Quit" << endl;
                cin >> l;   // get user input

                if (s.getVirus() > 0) { // if the player has a virus 
                    int virusNum = s.getVirus() * 10;
                    
                    if (l == 1 || l == 2 || l == 3 || l == 4 || l == 5){ // whenever they do something on the menu 
                        b.setCompMaintenceLev(b.getCompMaintenceLev() - virusNum);
                    }
                }

                // create a switch and do whatever user wants
                switch(l)
                {
                    case 1: // case for traveling in the server room
                        cout << "Traveling To Server Room" << endl;
                        m3.spawnBestBuy(rand() % 4 + 1, rand() % 8 + 1);   // spawns bestbuy at random location on map
                        m3.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);     // spawn 2 npcs at random location on map
                        m3.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);
                        m3.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);  // spawn 4 hacker at random location on map
                        m3.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m3.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m3.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);

                        // quit after player makes 10 moves
                        for (int i = 0; i < 10; i++) {
                            m3.displayMap(); // display map

                            cout << "Valid Moves Are: " << endl;
                            m3.displayMoves();   // displays the valid moves the player can pick from
                            cin >> move;
                            m3.executeMove(move);
                            

                            // adds 5 bitcoin everytime a move is executed
                            b.setDogeCoins(b.getDogeCoins() + 5);
                            if (b.getGPU() > 0) {   // adds more if they player has gpus
                                b.setDogeCoins(b.getDogeCoins() + (numGPU * 5));
                            }

                            if (m3.isBestBuyLocation()) {    // if they are in a bestbuy 
                                cout << "Entering Best Buy..." << endl;
                                cout << endl;
                                b.buyMenu3();
                            }
                                        
                            if (m3.isHackerLocation()) {     // if they run into a hacker
                                cout << "You just ran into " << room3[room3Rand] << "! Think you can beat this hacker's skills?" << endl;
                                cout << "1. Attack \n2. Forfeit" << endl;   // give the user an option to forfeit or attack
                                cin >> l;

                                // misfortune
                                if (s.misfortuneGen() == 1) {
                                    if (randMisfortune == 1) {  // steal a random part
                                        b.loseRandPart(rand() % 6 + 1);
                                        cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                                    }

                                    else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                        cout << "OH NO! Your computer was damaged!" << endl;
                                    }

                                    else if (randMisfortune == 3) {     // increase frustration level by 10
                                        s.setFrustLevel(s.getFrustLevel() + 10);
                                        cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                                    }
                                }

                                if (l == 1) {   // if they choose to attack
                                    int result = h.fightHacker(b.getInternet(), b.getVPN(), r3.getRoomLevel());
                                    cout << "You have chosen to attack!" << endl;

                                    if (result > 0) {   // if player wins battle
                                        cout << "You have won the battle against " << room3[room3Rand] << "!" << endl;
                                        cout << "You have gained 50 Doge Coins!" << endl;
                                        b.setDogeCoins(b.getDogeCoins() + 50);  // add 50 dogecoins if they win
                                        cout << "DogeCoins: " << b.getDogeCoins() << endl;
                                        winCount3 += 1;

                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker

                                        if (a >= 0) {   // for the room1Rand 
                                            room3.erase(room3.begin() + room3Rand); // THIS IS HOW TO ERASE ONCE THEY DEFEAT THE HACKER
                                            a -= 1;
                                        }
                                    }
                                    
                                    else if (result <= 0) { // if player loses battle
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 20);    // computermaintencelevel goes down 20
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker
                                        cout << "You have lost the battle against " << room3[room3Rand] << "!" << endl;
                                        cout << "Your computer maintence level is now down 20." << endl;
                                        cout << "Computer Maintenece Level: " << b.getCompMaintenceLev() << endl;

                                        if ((rand() % 10 + 1) % 10 == 0) {  // add a virus 
                                            s.setVirus(s.getVirus() + 1);
                                            cout << "Your computer now has a virus." << endl;
                                            cout << "Viruses: " << s.getVirus() << endl;
                                        }
                                    }
                                }

                                else if (l == 2) {  // if they choose to forfeit
                                    cout << "Forfeit." << endl;
                                }
                                else {
                                    cout << "Invalid Input. Please select a number (1-2)." << endl;
                                }
                            }

                            if (m3.isNPCLocation()) {        // if they run into an NPC 
                                cout << "Do you want to complete their puzzle?" << endl;
                                cout << "1. Yes\n2. No" << endl;
                                cin >> l;

                                if (l == 1) {   // when they do want to complete a puzzle
                                    if (s.getFrustLevel() >= 5) {
                                            r = rand() % 5 + 1;

                                            // to pick which puzzle to use
                                            if (r == 1) {
                                                puzz1 = s.puzzle1();

                                                if (puzz1 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz1 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 2){
                                                puzz2 = s.puzzle2();

                                                if (puzz2 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz2 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 3){
                                                puzz3 = s.puzzle3();

                                                if (puzz3 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (s.puzzle3() == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 4){
                                                puzz4 = s.puzzle4();

                                                if (puzz4 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz4 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 5){
                                                puzz5 = s.puzzle5();

                                                if (puzz5 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz5 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                        }
                                }

                                else if (l == 2) {  // if they dont want to complete a puzzle
                                    cout << "Do you want to take your chances with the NPC?" << endl;

                                    if ((rand() % 100 + 1) % 33) {  // good npc
                                        b.getRandPart(rand() % 6 + 1);  // get a random part
                                    }
                                    
                                    if ((rand() % 100 + 1) % 33) {  // bad npc
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part
                                    }
                                }

                                else {  // invalid
                                    cout << "Invalid Input. Please select a number (1-2)" << endl;
                                }

                            }
                        }
                    break;

                    case 2:     // case for repair a computer
                        if (s.getVirus() == 0) {    // make sure they dont have a virus 

                            if (b.getCompMaintenceLev() < 100){ // if their maintence level is less than 100 let them repair
                                b.repairComputer();
                            }
                            else {  // if their computer maintence level is at 100 or higher
                                cout << "Computer Maintence Level: " << b.getCompMaintenceLev() << endl;
                                cout << "You cannot repair your computer. You're maintence level is already high." << endl;
                            }
                        }

                        else if (s.getVirus() > 0) {    // if they have a virus tell them they cant repair
                            cout << "Your computer has a virus. \nYou cannot repair your computer until you get rid of your virus." << endl;
                        }
                            
                    break;

                    case 3:     // case for using antivirus software
                        cout << "Your computer has " << s.getVirus() << " would you like to use Antivirus Software?" << endl;
                        cout << "1. Yes\n2. No" << endl;
                        cin >> l;

                        if (l == 1){    // if they choose to use antivirus software
                            if (b.getAVS() > 0) {    // make sure they have antivirus software to use
                                b.setAVS(b.getAVS() - 1);   // get rid of one antivirus software once they use it
                                s.setVirus(0);  // set virus to 0 
                                cout << "You used Antivirus Software succesfully." << endl;

                            }

                            else if (b.getAVS() <= 0){   // if they dont have antivirus software
                            cout << "You don't have an antivirus software to use." << endl;
                            }
                        }
                        if (l == 2){    // if they choose not to use antivirus software
                            cout << "Okay." << endl;
                        }   
                            
                    break;

                    case 4:     // case for browsing stackoverflow
                        r = rand() % 5 + 1; // rand num generator to select a random puzzle each time

                        // misfortune
                        if (s.misfortuneGen() == 1) {
                            if (randMisfortune == 1) {  // steal a random part
                                b.loseRandPart(rand() % 6 + 1);
                                cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                            }
                        
                            else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                cout << "OH NO! Your computer was damaged!" << endl;
                            }
                                                        
                            else if (randMisfortune == 3) {     // increase frustration level by 10
                                s.setFrustLevel(s.getFrustLevel() + 10);
                                cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                            }
                        }
                        
                        // make sure they can lower it 
                        if (s.getFrustLevel() >= 5) {
                            // to pick which puzzle to use
                            if (r == 1) {
                                puzz1 = s.puzzle1();

                                if (puzz1 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz1 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 2){
                                puzz2 = s.puzzle2();

                                if (puzz2 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz2 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 3){
                                puzz3 = s.puzzle3();

                                if (puzz3 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (s.puzzle3() == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 4){
                                puzz4 = s.puzzle4();

                                if (puzz4 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz4 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 5){
                                puzz5 = s.puzzle5();

                                if (puzz5 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz5 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                        }
                        else {
                            cout << "You cannot lower your frustration level anymore!" << endl;
                            cout << "Frustration Level: " << s.getFrustLevel() << endl;
                        }

                    break;

                    case 5: // case for moving on to next server room
                        if (winCount3 > 0) {
                            if (winCount3 == 1){
                                cout << "You have defeated " << winCount3 << " hacker!" << endl;
                                cout << "Would you like to move on to the next room?" << endl;
                                cout << "Y = Yes\nN = No" << endl;
                                cin >> ans3;

                                if (ans3 == 'y' || ans3 == 'Y') {
                                    cout << "Press Quit on next menu to move on." << endl;
                                    cout << endl;
                                    moveOn3 += 1;
                                    break;
                                }
                                else if (ans3 == 'n' || ans3 == 'N') {
                                    cout << "Okay." << endl;
                                }
                                else {
                                    cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                                }
                            }
                            else {
                                cout << "You have defeated " << winCount3 << " hackers!" << endl;
                                cout << "Would you like to move on to the next room?" << endl;
                                cin >> ans3;

                                if (ans3 == 'y' || ans3 == 'Y') {
                                    cout << "Press Quit on next menu to move on." << endl;
                                    cout << endl;
                                    moveOn3 += 1;
                                    break;
                                }
                                else if (ans3 == 'n' || ans3 == 'N') {
                                    cout << "Okay." << endl;
                                }
                                else {
                                    cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                                }
                            }
                        }

                        else if (winCount3 <= 0) {
                            cout << "You have not defeated a hacker yet!\nYou have to defeat at least 1 hacker in order to move on!" << endl;
                        }
                        
                    break;

                    case 6:     // case for quitting
                        if (moveOn3 <= 0) {
                            cout << "Sorry you couldn't defeat all the hackers!" << endl;
                            cout << "Maybe you can defeat them next time!" << endl;
                            cout << "Good Bye!" << endl;
                        }
                    break;

                    default:    // invalid input
                        cout << "Invalid Input. \nPlease select a number (1-5)" << endl;
                    break;
                    }
            }
            while (l != 6);
        }

        // ROOM 4
        if (moveOn3 > 0) {  
            Room r4 = Room();
            r4.setRoomName("Hopper Room");
            r4.setRoomLevel(4);

            cout << "Now entering the 2nd Room: " << r4.getRoomName() << endl;
            cout << endl;
            do 
            {
                cout << "Here are the activities you can do: " << endl;
                cout << "Please select a numerical option. (1-5)" << endl; 
                cout << "1. Start Traveling in Server Room \n2. Repair Your Computer \n3. Use your antivirus software \n4. Browse Stackoverflow \n5. Move on to next server room\n6. Quit" << endl;
                cin >> l;   // get user input

                if (s.getVirus() > 0) { // if the player has a virus 
                    int virusNum = s.getVirus() * 10;
                    
                    if (l == 1 || l == 2 || l == 3 || l == 4 || l == 5){ // whenever they do something on the menu 
                        b.setCompMaintenceLev(b.getCompMaintenceLev() - virusNum);
                    }
                }

                // create a switch and do whatever user wants
                switch(l)
                {
                    case 1: // case for traveling in the server room
                        cout << "Traveling To Server Room" << endl;
                        m4.spawnBestBuy(rand() % 4 + 1, rand() % 8 + 1);   // spawns bestbuy at random location on map
                        m4.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);     // spawn 2 npcs at random location on map
                        m4.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);
                        m4.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);  // spawn 4 hacker at random location on map
                        m4.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m4.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m4.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);

                        // quit after player makes 10 moves
                        for (int i = 0; i < 10; i++) {
                            m4.displayMap(); // display map

                            cout << "Valid Moves Are: " << endl;
                            m4.displayMoves();   // displays the valid moves the player can pick from
                            cin >> move;
                            m4.executeMove(move);
                            

                            // adds 5 bitcoin everytime a move is executed
                            b.setDogeCoins(b.getDogeCoins() + 5);
                            if (b.getGPU() > 0) {   // adds more if they player has gpus
                                b.setDogeCoins(b.getDogeCoins() + (numGPU * 5));
                            }

                            if (m4.isBestBuyLocation()) {    // if they are in a bestbuy 
                                cout << "Entering Best Buy..." << endl;
                                cout << endl;
                                b.buyMenu4();
                            }
                                        
                            if (m4.isHackerLocation()) {     // if they run into a hacker
                                cout << "You just ran into " << room4[room4Rand] << "! Think you can beat this hacker's skills?" << endl;
                                cout << "1. Attack \n2. Forfeit" << endl;   // give the user an option to forfeit or attack
                                cin >> l;

                                // misfortune generator
                                if (s.misfortuneGen() == 1) {
                                    if (randMisfortune == 1) {  // steal a random part
                                        b.loseRandPart(rand() % 6 + 1);
                                        cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                                    }

                                    else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                        cout << "OH NO! Your computer was damaged!" << endl;
                                    }

                                    else if (randMisfortune == 3) {     // increase frustration level by 10
                                        s.setFrustLevel(s.getFrustLevel() + 10);
                                        cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                                    }
                                }

                                if (l == 1) {   // if they choose to attack
                                    int result = h.fightHacker(b.getInternet(), b.getVPN(), r4.getRoomLevel());
                                    cout << "You have chosen to attack!" << endl;

                                    if (result > 0) {   // if player wins battle
                                        cout << "You have won the battle against " << room4[room4Rand] << "!" << endl;
                                        cout << "You have gained 50 Doge Coins!" << endl;
                                        b.setDogeCoins(b.getDogeCoins() + 50);  // add 50 dogecoins if they win
                                        cout << "DogeCoins: " << b.getDogeCoins() << endl;
                                        winCount4 += 1;

                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker

                                        if (r4Rand >= 0) {   // for the room1Rand 
                                            room4.erase(room4.begin() + room4Rand); // THIS IS HOW TO ERASE ONCE THEY DEFEAT THE HACKER
                                            r4Rand -= 1;
                                        }
                                    }
                                    
                                    else if (result <= 0) { // if player loses battle
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 20);    // computermaintencelevel goes down 20
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker
                                        cout << "You have lost the battle against " << room4[room4Rand] << "!" << endl;
                                        cout << "Your computer maintence level is now down 20." << endl;
                                        cout << "Computer Maintenece Level: " << b.getCompMaintenceLev() << endl;

                                        if ((rand() % 10 + 1) % 10 == 0) {  // add a virus 
                                            s.setVirus(s.getVirus() + 1);
                                            cout << "Your computer now has a virus." << endl;
                                            cout << "Viruses: " << s.getVirus() << endl;
                                        }
                                    }
                                }

                                else if (l == 2) {  // if they choose to forfeit
                                    cout << "Forfeit." << endl;
                                }
                                else {
                                    cout << "Invalid Input. Please select a number (1-2)." << endl;
                                }
                            }

                            if (m4.isNPCLocation()) {        // if they run into an NPC 
                                cout << "Do you want to complete their puzzle?" << endl;
                                cout << "1. Yes\n2. No" << endl;
                                cin >> l;

                                if (l == 1) {   // when they do want to complete a puzzle
                                    if (s.getFrustLevel() >= 5) {
                                            r = rand() % 5 + 1;

                                            // to pick which puzzle to use
                                            if (r == 1) {
                                                puzz1 = s.puzzle1();

                                                if (puzz1 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz1 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 2){
                                                puzz2 = s.puzzle2();

                                                if (puzz2 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz2 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 3){
                                                puzz3 = s.puzzle3();

                                                if (puzz3 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (s.puzzle3() == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 4){
                                                puzz4 = s.puzzle4();

                                                if (puzz4 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz4 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 5){
                                                puzz5 = s.puzzle5();

                                                if (puzz5 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz5 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                        }
                                }

                                else if (l == 2) {  // if they dont want to complete a puzzle
                                    cout << "Do you want to take your chances with the NPC?" << endl;

                                    if ((rand() % 100 + 1) % 33) {  // good npc
                                        b.getRandPart(rand() % 6 + 1);  // get a random part
                                    }
                                    
                                    if ((rand() % 100 + 1) % 33) {  // bad npc
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part
                                    }
                                }

                                else {  // invalid
                                    cout << "Invalid Input. Please select a number (1-2)" << endl;
                                }

                            }
                        }
                    break;

                    case 2:     // case for repair a computer
                        if (s.getVirus() == 0) {    // make sure they dont have a virus 

                            if (b.getCompMaintenceLev() < 100){ // if their maintence level is less than 100 let them repair
                                b.repairComputer();
                            }
                            else {  // if their computer maintence level is at 100 or higher
                                cout << "Computer Maintence Level: " << b.getCompMaintenceLev() << endl;
                                cout << "You cannot repair your computer. You're maintence level is already high." << endl;
                            }
                        }

                        else if (s.getVirus() > 0) {    // if they have a virus tell them they cant repair
                            cout << "Your computer has a virus. \nYou cannot repair your computer until you get rid of your virus." << endl;
                        }
                            
                    break;

                    case 3:     // case for using antivirus software
                        cout << "Your computer has " << s.getVirus() << " would you like to use Antivirus Software?" << endl;
                        cout << "1. Yes\n2. No" << endl;
                        cin >> l;

                        if (l == 1){    // if they choose to use antivirus software
                            if (b.getAVS() > 0) {    // make sure they have antivirus software to use
                                b.setAVS(b.getAVS() - 1);   // get rid of one antivirus software once they use it
                                s.setVirus(0);  // set virus to 0 
                                cout << "You used Antivirus Software succesfully." << endl;

                            }

                            else if (b.getAVS() <= 0){   // if they dont have antivirus software
                            cout << "You don't have an antivirus software to use." << endl;
                            }
                        }
                        if (l == 2){    // if they choose not to use antivirus software
                            cout << "Okay." << endl;
                        }   
                            
                    break;

                    case 4:     // case for browsing stackoverflow
                        r = rand() % 5 + 1; // rand num generator to select a random puzzle each time

                        // misfortune
                        if (s.misfortuneGen() == 1) {
                            if (randMisfortune == 1) {  // steal a random part
                                b.loseRandPart(rand() % 6 + 1);
                                cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                            }
                    
                            else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                cout << "OH NO! Your computer was damaged!" << endl;
                            }
                                                        
                            else if (randMisfortune == 3) {     // increase frustration level by 10
                                s.setFrustLevel(s.getFrustLevel() + 10);
                                cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                            }
                        }
                        
                        // make sure they can lower it 
                        if (s.getFrustLevel() >= 5) {
                            // to pick which puzzle to use
                            if (r == 1) {
                                puzz1 = s.puzzle1();

                                if (puzz1 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz1 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 2){
                                puzz2 = s.puzzle2();

                                if (puzz2 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz2 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 3){
                                puzz3 = s.puzzle3();

                                if (puzz3 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (s.puzzle3() == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 4){
                                puzz4 = s.puzzle4();

                                if (puzz4 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz4 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 5){
                                puzz5 = s.puzzle5();

                                if (puzz5 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz5 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                        }
                        else {
                            cout << "You cannot lower your frustration level anymore!" << endl;
                            cout << "Frustration Level: " << s.getFrustLevel() << endl;
                        }

                    break;

                    case 5: // case for moving on to next server room
                        if (winCount4 > 0) {
                            if (winCount4 == 1){
                                cout << "You have defeated " << winCount4 << " hacker!" << endl;
                                cout << "Would you like to move on to the next room?" << endl;
                                cout << "Y = Yes\nN = No" << endl;
                                cin >> ans4;

                                if (ans4 == 'y' || ans4 == 'Y') {
                                    cout << "Press Quit on next menu to move on." << endl;
                                    cout << endl;
                                    moveOn4 += 1;
                                    break;
                                }
                                else if (ans4 == 'n' || ans4 == 'N') {
                                    cout << "Okay." << endl;
                                }
                                else {
                                    cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                                }
                            }
                            else {
                                cout << "You have defeated " << winCount4 << " hackers!" << endl;
                                cout << "Would you like to move on to the next room?" << endl;
                                cin >> ans4;

                                if (ans4 == 'y' || ans4 == 'Y') {
                                    cout << "Press Quit on next menu to move on." << endl;
                                    cout << endl;
                                    moveOn4 += 1;
                                    break;
                                }
                                else if (ans4 == 'n' || ans4 == 'N') {
                                    cout << "Okay." << endl;
                                }
                                else {
                                    cout << "Invalid Input.\nPlease enter 'Y' or 'N'" << endl;
                                }
                            }
                        }

                        else if (winCount4 <= 0) {
                            cout << "You have not defeated a hacker yet!\nYou have to defeat at least 1 hacker in order to move on!" << endl;
                        }
                        
                    break;

                    case 6:     // case for quitting
                        if (moveOn4 <= 0) {
                            cout << "Sorry you couldn't defeat all the hackers!" << endl;
                            cout << "Maybe you can defeat them next time!" << endl;
                            cout << "Good Bye!" << endl;
                        }
                    break;

                    default:    // invalid input
                        cout << "Invalid Input. \nPlease select a number (1-5)" << endl;
                    break;
                    }
            }
            while (l != 6);
        }

        // ROOM 5
        if (moveOn4 > 0) {  
            Room r5 = Room();
            r5.setRoomName("Moore Room");
            r5.setRoomLevel(5);

            cout << "Now entering the 2nd Room: " << r5.getRoomName() << endl;
            cout << endl;
            do 
            {
                cout << "Here are the activities you can do: " << endl;
                cout << "Please select a numerical option. (1-5)" << endl; 
                cout << "1. Start Traveling in Server Room \n2. Repair Your Computer \n3. Use your antivirus software \n4. Browse Stackoverflow \n5. Quit" << endl;
                cin >> l;   // get user input

                if (s.getVirus() > 0) { // if the player has a virus 
                    int virusNum = s.getVirus() * 10;
                    
                    if (l == 1 || l == 2 || l == 3 || l == 4 || l == 5){ // whenever they do something on the menu 
                        b.setCompMaintenceLev(b.getCompMaintenceLev() - virusNum);
                    }
                }

                // create a switch and do whatever user wants
                switch(l)
                {
                    case 1: // case for traveling in the server room
                        cout << "Traveling To Server Room" << endl;
                        m5.spawnBestBuy(rand() % 4 + 1, rand() % 8 + 1);   // spawns bestbuy at random location on map
                        m5.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);     // spawn 2 npcs at random location on map
                        m5.spawnNPC(rand() % 4 + 1, rand() % 8 + 1);
                        m5.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);  // spawn 4 hacker at random location on map
                        m5.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m5.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);
                        m5.spawnHacker(rand() % 4 + 1, rand() % 8 + 1);

                        // quit after player makes 10 moves
                        for (int i = 0; i < 10; i++) {
                            m5.displayMap(); // display map

                            cout << "Valid Moves Are: " << endl;
                            m5.displayMoves();   // displays the valid moves the player can pick from
                            cin >> move;
                            m5.executeMove(move);
                            

                            // adds 5 bitcoin everytime a move is executed
                            b.setDogeCoins(b.getDogeCoins() + 5);
                            if (b.getGPU() > 0) {   // adds more if they player has gpus
                                b.setDogeCoins(b.getDogeCoins() + (numGPU * 5));
                            }

                            if (m5.isBestBuyLocation()) {    // if they are in a bestbuy 
                                cout << "Entering Best Buy..." << endl;
                                cout << endl;
                                b.buyMenu5();
                            }
                                        
                            if (m5.isHackerLocation()) {     // if they run into a hacker
                                cout << "You just ran into " << room5[room5Rand] << "! Think you can beat this hacker's skills?" << endl;
                                cout << "1. Attack \n2. Forfeit" << endl;   // give the user an option to forfeit or attack
                                cin >> l;

                                // misfortune
                                if (s.misfortuneGen() == 1) {
                                    if (randMisfortune == 1) {  // steal a random part
                                        b.loseRandPart(rand() % 6 + 1);
                                        cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                                    }

                                    else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                        cout << "OH NO! Your computer was damaged!" << endl;
                                    }

                                    else if (randMisfortune == 3) {     // increase frustration level by 10
                                        s.setFrustLevel(s.getFrustLevel() + 10);
                                        cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                                    }
                                }

                                if (l == 1) {   // if they choose to attack
                                    int result = h.fightHacker(b.getInternet(), b.getVPN(), r5.getRoomLevel());
                                    cout << "You have chosen to attack!" << endl;

                                    if (result > 0) {   // if player wins battle
                                        cout << "You have won the battle against " << room5[room5Rand] << "!" << endl;
                                        cout << "You have gained 50 Doge Coins!" << endl;
                                        b.setDogeCoins(b.getDogeCoins() + 50);  // add 50 dogecoins if they win
                                        cout << "DogeCoins: " << b.getDogeCoins() << endl;
                                        winCount5 += 1;

                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker

                                        if (r5Rand >= 0) {   // for the room1Rand 
                                            room5.erase(room5.begin() + room5Rand); // THIS IS HOW TO ERASE ONCE THEY DEFEAT THE HACKER
                                            r5Rand -= 1;
                                        }
                                    }
                                    
                                    else if (result <= 0) { // if player loses battle
                                        b.setCompMaintenceLev(b.getCompMaintenceLev() - 20);    // computermaintencelevel goes down 20
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part each time they fight a hacker
                                        cout << "You have lost the battle against " << room5[room5Rand] << "!" << endl;
                                        cout << "Your computer maintence level is now down 20." << endl;
                                        cout << "Computer Maintenece Level: " << b.getCompMaintenceLev() << endl;

                                        if ((rand() % 10 + 1) % 10 == 0) {  // add a virus 
                                            s.setVirus(s.getVirus() + 1);
                                            cout << "Your computer now has a virus." << endl;
                                            cout << "Viruses: " << s.getVirus() << endl;
                                        }
                                    }
                                }

                                else if (l == 2) {  // if they choose to forfeit
                                    cout << "Forfeit." << endl;
                                }
                                else {
                                    cout << "Invalid Input. Please select a number (1-2)." << endl;
                                }
                            }

                            if (m5.isNPCLocation()) {        // if they run into an NPC 
                                cout << "Do you want to complete their puzzle?" << endl;
                                cout << "1. Yes\n2. No" << endl;
                                cin >> l;

                                if (l == 1) {   // when they do want to complete a puzzle
                                    if (s.getFrustLevel() >= 5) {
                                            r = rand() % 5 + 1;

                                            // to pick which puzzle to use
                                            if (r == 1) {
                                                puzz1 = s.puzzle1();

                                                if (puzz1 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz1 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 2){
                                                puzz2 = s.puzzle2();

                                                if (puzz2 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz2 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 3){
                                                puzz3 = s.puzzle3();

                                                if (puzz3 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (s.puzzle3() == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 4){
                                                puzz4 = s.puzzle4();

                                                if (puzz4 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz4 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                            else if (r == 5){
                                                puzz5 = s.puzzle5();

                                                if (puzz5 == 1) {
                                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                                    cout << "Correct!" << endl;
                                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                                }
                                                else if (puzz5 == -1) {
                                                    cout << "Incorrect!" << endl;
                                                }
                                            }
                                        }
                                }

                                else if (l == 2) {  // if they dont want to complete a puzzle
                                    cout << "Do you want to take your chances with the NPC?" << endl;

                                    if ((rand() % 100 + 1) % 33) {  // good npc
                                        b.getRandPart(rand() % 6 + 1);  // get a random part
                                    }
                                    
                                    if ((rand() % 100 + 1) % 33) {  // bad npc
                                        b.loseRandPart(rand() % 6 + 1); // lose a random part
                                    }
                                }

                                else {  // invalid
                                    cout << "Invalid Input. Please select a number (1-2)" << endl;
                                }

                            }
                        }
                    break;

                    case 2:     // case for repair a computer
                        if (s.getVirus() == 0) {    // make sure they dont have a virus 

                            if (b.getCompMaintenceLev() < 100){ // if their maintence level is less than 100 let them repair
                                b.repairComputer();
                            }
                            else {  // if their computer maintence level is at 100 or higher
                                cout << "Computer Maintence Level: " << b.getCompMaintenceLev() << endl;
                                cout << "You cannot repair your computer. You're maintence level is already high." << endl;
                            }
                        }

                        else if (s.getVirus() > 0) {    // if they have a virus tell them they cant repair
                            cout << "Your computer has a virus. \nYou cannot repair your computer until you get rid of your virus." << endl;
                        }
                            
                    break;

                    case 3:     // case for using antivirus software
                        cout << "Your computer has " << s.getVirus() << " would you like to use Antivirus Software?" << endl;
                        cout << "1. Yes\n2. No" << endl;
                        cin >> l;

                        if (l == 1){    // if they choose to use antivirus software
                            if (b.getAVS() > 0) {    // make sure they have antivirus software to use
                                b.setAVS(b.getAVS() - 1);   // get rid of one antivirus software once they use it
                                s.setVirus(0);  // set virus to 0 
                                cout << "You used Antivirus Software succesfully." << endl;

                            }

                            else if (b.getAVS() <= 0){   // if they dont have antivirus software
                            cout << "You don't have an antivirus software to use." << endl;
                            }
                        }
                        if (l == 2){    // if they choose not to use antivirus software
                            cout << "Okay." << endl;
                        }   
                            
                    break;

                    case 4:     // case for browsing stackoverflow
                        r = rand() % 5 + 1; // rand num generator to select a random puzzle each time

                        // misfortune
                        if (s.misfortuneGen() == 1) {
                            if (randMisfortune == 1) {  // steal a random part
                                b.loseRandPart(rand() % 6 + 1);
                                cout << "OH NO! Your team was robbed by Carmen's dastardly hackers!" << endl;
                            }
                        
                            else if (randMisfortune == 2) {     // lower computer maintence level by 10
                                b.setCompMaintenceLev(b.getCompMaintenceLev() - 10);
                                cout << "OH NO! Your computer was damaged!" << endl;
                            }
                                                        
                            else if (randMisfortune == 3) {     // increase frustration level by 10
                                s.setFrustLevel(s.getFrustLevel() + 10);
                                cout << "OH NO! Why won’t my code work!!!!\nYour frustration level was increased." << endl;
                            }
                        }
                        
                        // make sure they can lower it 
                        if (s.getFrustLevel() >= 5) {
                            // to pick which puzzle to use
                            if (r == 1) {
                                puzz1 = s.puzzle1();

                                if (puzz1 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz1 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 2){
                                puzz2 = s.puzzle2();

                                if (puzz2 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz2 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 3){
                                puzz3 = s.puzzle3();

                                if (puzz3 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (s.puzzle3() == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 4){
                                puzz4 = s.puzzle4();

                                if (puzz4 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz4 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                            else if (r == 5){
                                puzz5 = s.puzzle5();

                                if (puzz5 == 1) {
                                    s.setFrustLevel(s.getFrustLevel() - 5);
                                    cout << "Correct!" << endl;
                                    cout << "Your frustration level will now be lowered by 5" << endl;
                                    cout << "Frusration Level: " << s.getFrustLevel() << endl;
                                }
                                else if (puzz5 == -1) {
                                    cout << "Incorrect!" << endl;
                                }
                            }
                        }
                        else {
                            cout << "You cannot lower your frustration level anymore!" << endl;
                            cout << "Frustration Level: " << s.getFrustLevel() << endl;
                        }

                    break;

                    case 5:     // case for quitting
                        if (moveOn2 <= 0) {
                            cout << "You made it to the end!" << endl;
                            cout << "Carmen's hackers couldn't handle you!" << endl;
                            cout << "Good Job!" << endl;
                        }
                    break;

                    default:    // invalid input
                        cout << "Invalid Input. \nPlease select a number (1-5)" << endl;
                    break;
                    }
            }
            while (l != 5);
        }
    }
    else if (s.getFrustLevel() >= 100 || b.getCompMaintenceLev() <= 0) {    // Game ends if either of these happen
        if (s.getFrustLevel() >= 100) {
            cout << "OH NO! You have rage quit!" << endl;
            cout << "Looks like you couldn't handle Carmen's Hackers!" << endl;
        }
        if (b.getCompMaintenceLev() <= 0) {
            cout << "Game Ends!" << endl;
            cout << "Your Computer Maintence Level is under 0!" << endl;
            cout << "Computer Maintence Level: " << b.getCompMaintenceLev() << endl;
            cout << "Better Luck Next Time!" << endl;
        }
    }

    return 0;
}