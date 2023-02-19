#ifndef PF_GAMEPLAY2_H
#define PF_GAMEPLAY2_H
#include <vector>
using namespace std;

class Gameplay2
{   
    public:
    void displayOnly(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP,int& totalrows, int& totalcolumns, 
                    int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, 
                    int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range);

    void displayBoard(vector<vector<char>>& game_, int& totalrows, int& totalcolumns);

    void displayAttributes(int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& totalZombies, int& alienLife, int& alienAtk, 
                        int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range,
                        int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range);

    void zombieMovement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, char& ZombieResult, char& Z1status, char& Z2status, char& Z3status, 
                char& Z4status, char& Z5status, int& ARP, int& ACP, int& totalrows, int& totalcolumns,int& totalZombies, int& alienLife, int& alienAtk, 
                int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range,int&zombie3Life, int&zombie3Atk, int&zombie3Range, 
                int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range);

};
#endif