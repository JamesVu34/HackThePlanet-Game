// CSCI 1300 Fall 2021
// Author: James Vu
// Project 3

#include <iostream>
#include "Start.h"
using namespace std;

// Default Constructor
Start::Start() {
    name = "";
    frustrationLevel = 0;
    virus = 0;
}

// Parameterized Constructor
Start::Start(string playerName, int theFrustLevel, int theVirus) {
    name = playerName;
    frustrationLevel = theFrustLevel;
    virus = theVirus;
}

// GETTER to get the player name
string Start::getName() {
    return name;
}

// GETTER to get players frustration level
int Start::getFrustLevel() {
    return frustrationLevel;
}

// GETTER to get virus
int Start::getVirus() {
    return virus;
}

// SETTER to set the players name
void Start::setName(string playerName) {
    name = playerName;
}

// SETTER to set the frustration level of the player
void Start::setFrustLevel(int theFrustLevel) {
    frustrationLevel = theFrustLevel;
}

// SETTER to set virus
void Start::setVirus(int v) {
    virus = v;
}

// display player info
void Start::display() {
    cout << "Player Name: " << name << endl;
    cout << "Frustration Level: " << frustrationLevel << endl;
}

// the first puzzle
int Start::puzzle1() {
    int n = 0;

    cout << "****FIND THE ERROR****" << endl;
    cout << "This code works perfectly except for one pesky bug. Enter the number of the line on which the error appears to win this puzzle." << endl;
    cout << endl;
    cout << "1. #include <iostream>" << endl;
    cout << "2. using namespace std;" << endl;
    cout << "3." << endl; 
    cout << "4. double frobenius(double arr1[][3], double arr2[][3]);" << endl;
    cout << "5." << endl;
    cout << "6. int main() {" << endl;
    cout << "7.     double arr1[3][3];" << endl;
    cout << "8.     double arr2[3][3];" << endl;
    cout << "9." << endl;
    cout << "10.   for(int i = 0; i < 3; i++){" << endl;
    cout << "11.       for(int j = 0; j < 3; j++) {" << endl;
    cout <<  "12.           arr1[i][j] = i + j;" << endl;
    cout << "13.           arr2[i][j] = i * j;" << endl;
    cout << "14.       }" << endl;
    cout << "15.   }" << endl;
    cout << "16." << endl;
    cout << "17.   cout << frobenius(arr1, arr2) << endl;" << endl;
    cout << "18.   return 0;" << endl;
    cout << "19. }" << endl;
    cout << "20." << endl;
    cout << "21. double frobenius(arr1[][3], arr2[][3]){" << endl;
    cout <<"22.   double innerProduct = 0;" << endl;
    cout << "23.   for(int i = 0; i < 3; i++){"<< endl;
    cout <<"24.       for(int j = 0; j < 3; j++){  "<<endl;
    cout<< "25.           innerProduct += arr1[i][j] * arr2[i][j];"<<endl;
    cout<<"26.       }"<<endl;
    cout<<"27.    }"<<endl;
    cout<<"28.   return innerProduct;"<<endl;
    cout<<"29. }"<<endl;
    cin >> n;

    if (n == 21) {
        return 1;
    }
    else {
        return -1;
    }
    
    return 0;
}

// the second puzzle
int Start::puzzle2() {
    // declare variable
    int ans = 0;

    cout << "****FIND THE ERROR****" << endl;
    cout<<"This code works perfectly except for one pesky bug. Enter the number of the line on which the error appears to win this puzzle."<< endl;
    cout << endl;
    cout<<"1. #include <iostream>"<<endl;
    cout<<"2. #include <fstream>"<< endl;
    cout<< "3. " << endl;
    cout<< "4. using namespace std;"<<endl;
    cout<<"5."<<endl;
    cout<<"6. int main() {"<<endl;
    cout<<"7.     string fileName = 'fake_file.txt';"<<endl;
    cout<<"8.     fstream infile(fileName);"<<endl;
    cout<<"9.  "<<endl;
    cout<<"10.   if(infile.is_open()){"<<endl;
    cout<<"11.       string line;"<<endl;
    cout<<"12.       int lineNum = 0;"<<endl;
    cout<<"13.       while(getline(line, infile)){"<<endl;
    cout<<"14.          lineNum++;"<<endl;
    cout<< "15.          cout << 'Line ' << lineNum << ': ' << line << endl;" <<endl;
    cout<<"16.       }"<<endl;
    cout<<"17.   }else{"<<endl;
    cout<<"18.          cout << �Failed to open file.� << endl;"<<endl;
    cout<<"19.   }"<<endl;
    cout<<"20.   return 0; "<<endl;
    cout<<"21. }"<<endl;

    cin >> ans;

    if (ans == 13) {
        return 1;
    }
    else {
       return -1;
    }

    return 0;
}

// puzzle 3
int Start::puzzle3() {
    // declare variable
    char ans;

    cout<<"****MULTIPLE CHOICE****"<<endl;
    cout<<"Consider the following snippet of code. How many times will the sentence inside of the for loop be printed?"<<endl;
    cout << endl;
    cout<<"#include <iostream>"<< endl;
    cout<< endl;
    cout << "using namespace std;"<< endl;
    cout << endl;
    cout<<"int main(){"<<endl;
    cout<<"    int begin = 5;"<<endl;
    cout<<"    int end = 20;"<<endl;
    cout<<"    for (int i = begin; i <= end; i+=2){"<<endl;
    cout<<"    cout << 'This code does nothing important' << endl;"<<endl;
    cout<<"    }"<<endl;
    cout<<"    return 0;"<<endl;
    cout<<"}"<<endl;
    cout << endl;
    cout<<"A) 15"<<endl;
    cout<<"B) 8"<<endl;
    cout<<"C) 7"<<endl;
    cout<<"D) 10"<<endl;

    cin >> ans;

    if (ans == 'B' || ans == 'b'){
        // setFrustLevel(getFrustLevel() - 5);
        // cout << "Correct!" << endl;
        // cout << "Your frustration level will now be lowered by 5" << endl;
        // cout << "Frusration Level: " << getFrustLevel() << endl;
        return 1;
    }
    else {
        return -1;
    }

    return 0;
}

// puzzle 4
int Start::puzzle4() {
    // declare variable
    char ans;

    cout<<"****MULTIPLE CHOICE****"<<endl;
    cout<<"In the function below, word double before multiply represents what about the function?"  <<endl;
    cout<<endl;
    cout<<"double multiply(double x, double y)"<<endl;
    cout<<"{"<<endl;
    cout<<"    return x*y;" <<endl;
    cout<<"}"<<endl;
    cout<<endl;
    cout<<"A) The type of return value"<<endl;
    cout<<"B) The name of the function"<<endl;
    cout<<"C) The type of parameter variable"<<endl;
    cout<<"D) The algorithm within the function"<<endl;

    cin >> ans;

    if (ans == 'A' || ans == 'a') {
        return 1;
    }
    else {
        return -1;
    }

    return 0;
}

// puzzle 5
int Start::puzzle5() {
    // declare variables
    char ans;

    cout<<"****MULTIPLE CHOICE****"<<endl;
    cout<<"To defeat a hacker you need to use a brute force attack on his account. To do this, you are using a text file that holds words, numbers and other potential password combinations. Sometimes you come up with new word combinations you would like to add to the list. Which of the following streams should you use to both read and write from this file?"<<endl;
    cout<<endl;
    cout<<"A) iofstream"<<endl;
    cout<<"B) ofstream"<<endl;
    cout<<"C) ifstream"<<endl;
    cout<<"D) fstream"<<endl;

    cin >> ans;

    if (ans == 'D' || ans == 'd') {
        return 1;
    }
    else {
        return -1;
    }

    return 0;
}

// misfortune generator
int Start::misfortuneGen() {
    srand(time(NULL));
    if ((rand() % 30 + 1) % 3 == 0) {
        return 1;
    }
    return 0;
}