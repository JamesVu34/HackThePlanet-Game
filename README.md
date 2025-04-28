# Hack The Planet
## Project Overview:
A C++ text-based adventure game with interactive decision-making and turn-based combat mechanics.
- Designed a fiver server room environment where players battle hackers, upgrade equipment, and navigate challenges.
- Implemented an inventory system allowing players to purchase computer supplies from Best Buy, including antivirus software and VPNs.
- Created a frustration mechanic where excessive rage-quitting on StackOverflow can end the game
- Balanced multiple win/lose conditions, such as defeating hackers, preventing data theft, or maintaining system integrity.
- Integrated virtual currency (Dogecoins) for strategic resource management and item upgrades.


## HOW TO COMPILE AND RUN

Compile: `g++ -std=c++11 GameDriver.cpp Start.cpp BestBuy.cpp Hacker.cpp Room.cpp Map.cpp -o game` \
Run: `./game`


## DEPENDENCIES
All .h files must be in the same directory as the cpp files in order to compile.
Also all text files included in the zip must be in the same directory as well.
