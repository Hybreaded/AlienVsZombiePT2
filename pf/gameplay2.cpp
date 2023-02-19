#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay1.h"
#include "gameplay2.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Gameplay2::displayOnly(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    pf::Pause();
    pf::ClearScreen();
    displayBoard(game_,  totalrows,  totalcolumns);
    displayAttributes(A1,  Z1,  Z2,  Z3,  Z4,  Z5,  totalZombies, alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::displayBoard(vector<vector<char>>& game_, int& totalrows, int& totalcolumns)
{
    int numofcharacter = 19;
    int width = (((totalcolumns * 2)+1)-numofcharacter)/2; 

    string space = " ";
    cout << "  ";
    for (int i = 0; i < width ; ++i)
    {
        cout << space;
    }
    cout << ".:Alien Vs Zombie:." <<endl;

    for (int y = totalrows; y > 0; --y) 
    {
        int tempY = totalrows - y;
        cout << setw(4);

        for (int x = 0; x < totalcolumns; ++x) 
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << setw(2) << (totalrows - y + 1); 

        for (int x = 0; x < totalcolumns; ++x)
        {
            cout << "|" << game_[tempY][x];
        }
        cout << "|" << endl;
    }    

    cout << setw(4);  
    for (int x = 0; x < totalcolumns; ++x) 
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << setw(3);

    for (int x = 0; x < totalcolumns; ++x) 
    {
        int num = ((x+1) / 10);
        cout << " ";
        if (num == 0)
        {
            cout << " ";
        }
        else
        {
            cout << num;
        }
    }
    cout << endl;
    cout << setw(3); 
    
    for (int x = 0; x < totalcolumns; ++x) 
    {
        cout << " " << ((x + 1)) % 10;
    }
    cout << endl;
    cout << endl;
}

void Gameplay2::displayAttributes(int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& totalZombies,int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    for (int i = 0; i <= totalZombies; ++i)
    {
        char symbol[]= {' ','>'};
        switch (i)
        {
        case 0:
            cout << " "<< symbol[A1] << "Alien" << "     :   " <<  "Life  "  << alienLife << ",  Attack   " <<  alienAtk << endl;
            break;
        
        case 1:
            cout << " "<< symbol[Z1] << "Zombie 1" << "  :   " <<  "Life  "  << zombie1Life << ",  Attack   " <<  zombie1Atk << ",  Range   "<< zombie1Range << endl;
            break;
        
        case 2:
            cout << " "<< symbol[Z2] << "Zombie 2" << "  :   " <<  "Life  "  << zombie2Life << ",  Attack   " <<  zombie2Atk << ",  Range   "<< zombie2Range << endl;
            break;

        case 3:
            cout << " "<< symbol[Z3] << "Zombie 3" << "  :   " <<  "Life  "  << zombie3Life << ",  Attack   " <<  zombie3Atk << ",  Range   "<< zombie3Range << endl;
            break;

        case 4:
            cout << " "<< symbol[Z4] << "Zombie 4" << "  :   " <<  "Life  "  << zombie4Life << ",  Attack   " <<  zombie4Atk << ",  Range   "<< zombie4Range << endl;
            break;

        case 5: 
            cout << " "<< symbol[Z5] << "Zombie 5" << "  :   " <<  "Life  "  << zombie5Life << ",  Attack   " <<  zombie5Atk << ",  Range   "<< zombie5Range << endl;
            break;    
        }
    }
    cout << endl << endl;
}

void Gameplay2::zombieMovement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, char& ZombieResult, char& Z1status, char& Z2status, char& Z3status, char& Z4status, char& Z5status, int& ARP, int& ACP, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    for (int j = 0; j < totalZombies; ++j)
    {   
        char status[]={Z1status, Z2status, Z3status, Z4status, Z5status};
        if (status[j] == 'd')
        {
            continue;
        }

        A1 = 0; Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; 
        switch (j)
        {
        case 0:
            Z1 = 1;
            break;
        case 1:
            Z2 = 1;
            break;
        case 2:
            Z3 = 1;
            break;
        case 3:
            Z4 = 1;
            break;
        case 4:
            Z5 = 1;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP, totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);

        int Z1Row, Z2Row, Z3Row, Z4Row, Z5Row;
        int Z1Column, Z2Column, Z3Column, Z4Column, Z5Column;

        char zombieNum[] = {'1', '2', '3', '4', '5'};
        int zombieRow[] = {Z1Row, Z2Row, Z3Row, Z4Row, Z5Row};
        int zombieColumn[] = {Z1Column, Z2Column, Z3Column, Z4Column, Z5Column};

        for (int i = 0; i < totalZombies; ++i) 
        {
            for (int y = 0; y < totalrows; ++y)
            {
                for (int x = 0; x < totalcolumns; ++x)
                {
                    switch (game_[y][x])
                    {
                    case 'A':
                        ARP = y; ACP = x;
                        break;
                    default:
                        break;
                    }

                    if (game_[y][x] == zombieNum[i])
                    {
                        zombieRow[i] = y; zombieColumn[i] = x;
                    }
                }
            }
        }
        
        bool ans = false;
        while (ans == false)
        {
            char choice[] = {'U', 'D', 'L', 'R'};
            int numofchoice = 4;
            char result = choice[rand() % numofchoice];
            switch (result)
            {
            case 'U':
                if (zombieRow[j] - 1 != -1 &&
                    game_[zombieRow[j] - 1][zombieColumn[j]] != 'A' &&
                    game_[zombieRow[j] - 1][zombieColumn[j]] != '1' &&
                    game_[zombieRow[j] - 1][zombieColumn[j]] != '2' &&
                    game_[zombieRow[j] - 1][zombieColumn[j]] != '3' &&
                    game_[zombieRow[j] - 1][zombieColumn[j]] != '4' &&
                    game_[zombieRow[j] - 1][zombieColumn[j]] != '5')
                {
                    ans = true;
                }
                if (ans == true)
                {
                    game_[zombieRow[j] - 1][zombieColumn[j]] = zombieNum[j];
                    game_[zombieRow[j]][zombieColumn[j]] = ' ';
                    zombieRow[j] = zombieRow[j] - 1;
                    cout << "Zombie " << zombieNum[j] <<  " moves up" << endl << endl;
                }
                break;
                
            case 'D':
                if (zombieRow[j] + 1 != totalrows &&
                    game_[zombieRow[j] + 1][zombieColumn[j]] != 'A' &&
                    game_[zombieRow[j] + 1][zombieColumn[j]] != '1' &&
                    game_[zombieRow[j] + 1][zombieColumn[j]] != '2' &&
                    game_[zombieRow[j] + 1][zombieColumn[j]] != '3' &&
                    game_[zombieRow[j] + 1][zombieColumn[j]] != '4' &&
                    game_[zombieRow[j] + 1][zombieColumn[j]] != '5')
                {
                    ans = true;
                }
                if (ans == true)
                {
                    game_[zombieRow[j] + 1][zombieColumn[j]] = zombieNum[j];
                    game_[zombieRow[j]][zombieColumn[j]] = ' ';
                    zombieRow[j] = zombieRow[j] + 1;
                    cout << "Zombie " << zombieNum[j] <<  " moves down" << endl << endl;
                } 
                break;

            case 'L':
                if (zombieColumn[j] - 1 != -1 &&
                    game_[zombieRow[j]][zombieColumn[j] - 1] != 'A' &&
                    game_[zombieRow[j]][zombieColumn[j] - 1] != '1' &&
                    game_[zombieRow[j]][zombieColumn[j] - 1] != '2' &&
                    game_[zombieRow[j]][zombieColumn[j] - 1] != '3' &&
                    game_[zombieRow[j]][zombieColumn[j] - 1] != '4' &&
                    game_[zombieRow[j]][zombieColumn[j] - 1] != '5')
                {
                    ans = true;
                }
                if (ans == true)
                {
                    game_[zombieRow[j]][zombieColumn[j] - 1] = zombieNum[j];
                    game_[zombieRow[j]][zombieColumn[j]] = ' ';
                    zombieColumn[j] = zombieColumn[j] - 1;
                    cout << "Zombie " << zombieNum[j] <<  " moves left" << endl << endl;
                }
                break;

            case 'R':
                if (zombieColumn[j] + 1 != totalcolumns &&
                    game_[zombieRow[j]][zombieColumn[j] + 1] != 'A' &&
                    game_[zombieRow[j]][zombieColumn[j] + 1] != '1' &&
                    game_[zombieRow[j]][zombieColumn[j] + 1] != '2' &&
                    game_[zombieRow[j]][zombieColumn[j] + 1] != '3' &&
                    game_[zombieRow[j]][zombieColumn[j] + 1] != '4' &&
                    game_[zombieRow[j]][zombieColumn[j] + 1] != '5')
                {
                    ans = true;
                }
                if (ans == true)
                {
                    game_[zombieRow[j]][zombieColumn[j] + 1] = zombieNum[j];
                    game_[zombieRow[j]][zombieColumn[j]] = ' ';
                    zombieColumn[j] = zombieColumn[j] + 1;
                    cout << "Zombie " << zombieNum[j] <<  " moves right" << endl << endl;
                }
                break;
            }
        }

        displayOnly(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);

        int Z1andADistance, Z2andADistance, Z3andADistance, Z4andADistance, Z5andADistance;
        int Distance[]={Z1andADistance, Z2andADistance, Z3andADistance, Z4andADistance, Z5andADistance};
        int Range[]={zombie1Range, zombie2Range, zombie3Range, zombie4Range, zombie5Range};
        int Attck[]={zombie1Atk, zombie2Atk, zombie3Atk, zombie4Atk, zombie5Atk};

        Distance[j] = abs(zombieRow[j] - ARP) + abs(zombieColumn[j] - ACP);

        if (Range[j] >= Distance[j])
        {
            cout << "Zombie " << zombieNum[j] << "attacks Alien." << endl;
            cout << "Alien receives a damage of " << Attck[j] << "." << endl << endl;
            if (Attck[j] >= alienLife)
            {
                j = 10;
                alienLife = 0;
                ZombieResult = 'W';
                cout << " Alien died, you lost "<< endl << endl;
            }
            else
            {
                alienLife = alienLife - Attck[j];
            }
        }

        if (Range[j] < Distance[j])
        {
            cout << "Zombie " << zombieNum[j] << " unable to attack the Alien." << endl;
            cout << "Alien is too far" << endl << endl;
        }
    }
}