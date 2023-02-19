#include "helper.h"
#include "setting.h"
#include "gboard.h"
#include "object.h"
#include "gameplay1.h"
#include "gameplay2.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <filesystem>
using namespace std;

Gameplay::Gameplay()
{
    alienLife = alienLife_; alienAtk = alienAtk_;
    AlienResult = AlienResult_; ZombieResult = ZombieResult_;
    arrowLoop = arrowLoop_;
    A1 = A1_; Z1 = Z1_; Z2 = Z2_; Z3 = Z3_; Z4 = Z4_; Z5 = Z5_;
    Astatus = Astatus_;  Z1status = Z1status_; Z2status = Z2status_; Z3status = Z3status_; Z4status = Z4status_; Z5status = Z5status_ ;
}

void Gameplay::AlienStart(Gameplay& gameplay1)
{
    pf::ClearScreen();
    A1 = 1, Z1 = 0, Z2 = 0, Z3 = 0, Z4 = 0, Z5 = 0;
    displayBoard(gameplay1);
    displayAttributes(gameplay1);
    command(gameplay1);
}

void Gameplay::displayOnly(Gameplay& gameplay1)
{
    pf::Pause();
    pf::ClearScreen();
    displayBoard(gameplay1);
    displayAttributes(gameplay1);
}

void Gameplay::displayBoard(Gameplay& gameplay1)
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

void Gameplay::displayAttributes(Gameplay& gameplay1)
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

void Gameplay::command(Gameplay& gameplay1)
{
    char ans[5];
    cout <<endl <<"command >";
    cin >> ans;
    for (int i = 0; i < strlen(ans); ++i) //change ans to upper
    {
        ans[i] = toupper(ans[i]);
    }

    char help[] = "HELP";
    char up[] = "UP"; char down[] = "DOWN"; char left[] = "LEFT"; char right[] = "RIGHT";
    char arrow[] = "ARROW"; char save[] = "SAVE"; char load[]= "LOAD" ; char quit[]= "QUIT";
    
    switch (ans[0]) 
    {
    case 'H':
        for (int i = 0; i < strlen(help); ++i)
        {
            if (strlen(ans) != strlen(help) || ans[i] != help[i]) //check whether the character user's enter met the condition or not(length and character same /not)
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0]; 
        helpCommand(gameplay1);
        break;
        
    case 'U':
        for (int i = 0; i < strlen(up); ++i)
        {
            if (strlen(ans) != strlen(up) || ans[i] != up[i] )
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0];
        movement(gameplay1);
        if (AlienResult == 'W' || ZombieResult == 'W')
        {
            return;
        }
        
        break;

    case 'D':
        for (int i = 0; i < strlen(down); ++i)
        {
            if (strlen(ans) != strlen(down) || ans[i] != down[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0];
        movement(gameplay1);
        if (AlienResult == 'W' || ZombieResult == 'W')
        {
            return;
        }
        break;

    case 'L':
        char IsLeft, IsLoad; // this abit diff since we have Left and Load where two characters begin with letter 'L'
        for (int i = 0; i < strlen(left); ++i)
        {
            if (strlen(ans) != strlen(left) || ans[i] != left[i])
            {
                IsLeft = 'N';
                break;
            }
            else
            {
                IsLeft = 'Y';
            }
        }
        for (int i = 0; i < strlen(load); ++i)
        {
            if (strlen(ans) != strlen(load) || ans[i] != load[i])
            {
                IsLoad = 'N';
                break;
            }
            else
            {
                IsLoad = 'Y';
            }
        }
        if (IsLeft == 'N' && IsLoad == 'N')
        {
            cout << "Please enter correct characters"<< endl << endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        if (IsLeft == 'Y')
        {
            movementAns = ans[0];
            movement(gameplay1);
        }
        if (IsLoad == 'Y')
        {
            loadFile(gameplay1);
        }
        break;

    case 'R':
        for (int i = 0; i < strlen(right); ++i)
        {
            if (strlen(ans) != strlen(right) || ans[i] != right[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        movementAns = ans[0];
        movement(gameplay1);
        if (AlienResult == 'W' || ZombieResult == 'W')
        {
            return;
        }
        break;

    case 'A':
        if (strlen(ans) != strlen(arrow))
        {
            cout << "Please enter correct characters"<< endl << endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        for (int i = 0; i < strlen(arrow); ++i)
        {
            if (ans[i] != arrow[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        arrowChange(gameplay1);
        break;

    case 'S':
        for (int i = 0; i < strlen(save); ++i)
        {
            if (strlen(ans) != strlen(save) || ans[i] != save[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        saveFile(gameplay1);
        cout << "Data saved to file." << endl;
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'Q':
        for (int i = 0; i < strlen(quit); ++i)
        {
            if (strlen(ans) != strlen(quit) || ans[i] != quit[i])
            {
                cout << "Please enter correct characters"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        quitGame(gameplay1);
        return;
        break;
        
    default:
        cout << "Please enter correct characters"<< endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
}

void Gameplay::helpCommand(Gameplay& gameplay1)
{
    cout                << endl;
    cout << "Commands"  << endl;
    cout << "1. up      - Move up"                              << endl;
    cout << "2. down    - Move down"                            << endl;
    cout << "3. left    - Move left"                            << endl;
    cout << "4. right   - Move Right"                           << endl;
    cout << "5. arrow   - Change the directions of the arrow"   << endl;
    cout << "6. help    - Display the user commands"            << endl;
    cout << "7. save    - Save the game"                        << endl;
    cout << "8. load    - Load a game"                          << endl;
    cout << "9. quit    - Quit the game"                        << endl;
    
    pf::Pause();
    AlienStart(gameplay1);
}

void Gameplay::AlienSearch(Gameplay& gameplay1)
{
    for (int y = 0; y < totalrows; ++y)  //search 'A' index
    {
        for (int x = 0; x < totalcolumns; ++x) 
        {
            if (game_[y][x] == 'A')
            {   
                ARP = y; ACP = x;
                break;
            }
        }
    }
}

void Gameplay::movement(Gameplay& gameplay1)
{
    string up = "up"; string down = "down"; string left = "left"; string right = "right";
    string movementText[]={up, down, left, right};
    int printText;

    alienLoop = 1;
    while (alienLoop > 0)
    {
        alienLoopStatus = 'Y'; arrowLoopStatus = 'N';// this indicate that the alien moving by user enterted direction, not the arrow.
        AlienSearch(gameplay1); // search alien position
        borderCheck(gameplay1); // if pass means can move
        
        switch (movementAns)
        {
        case 'U':
            RowElement = ARP - 1; ColumnElement = ACP;
            printText = 0;
            break;
        case 'D':
            RowElement = ARP + 1; ColumnElement = ACP;
            printText = 1;
            break;
        case 'L':
            RowElement = ARP ; ColumnElement = ACP - 1;
            printText = 2;
            break;
        case 'R':
            RowElement = ARP; ColumnElement = ACP + 1;
            printText = 3;
            break;
        }
        cout << "Alien move " << movementText[printText] <<endl << endl;
        elementCheck(gameplay1); // call function to check element by using the index created above this line
        if (AlienResult == 'W' || ZombieResult == 'W')
        {
            return;
        }
        moving(gameplay1);       // call function to change the index of A to the entered direction
        stopCheck(gameplay1);    // refresh board and check whether have hit border or not|| if hit, zombie turn.
    }
}

void Gameplay::borderCheck(Gameplay& gameplay1)
{
    //cout <<endl<< "For Testing Alien y and x " << gameplay1.ARP << " "<< gameplay1.ACP<<endl<<endl;
    switch (movementAns) 
    {
    case 'U':
        if (ARP - 1 == -1)
        {
            cout << "You can't move up, u have reach the border."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }     
        break;

    case 'D':
        if (ARP + 1 == totalrows)
        {
            cout << "You can't move down, u have reach the border."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        break;

    case 'L':
        if (ACP - 1 == -1)
        {
            cout << "You can't move left, u have reach the border."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        break;

    case 'R':
       if (ACP + 1 == totalcolumns)
        {
            cout << "You can't move right, u have reach the border."<< endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        break;
    }
}
 
void Gameplay::elementCheck(Gameplay& gameplay1)
{
    Object object;
    nextElement = game_[RowElement][ColumnElement];
    switch (nextElement)  //check the element 
    {
    case 'h':
        object.healthpack(game_, movementAns, alienLife, ARP, ACP);
        break;

    case 'p':
        object.pod(game_ , Z1status, Z2status, Z3status, Z4status, Z5status, totalrows, totalcolumns, totalZombies, zombie1Life, zombie2Life, zombie3Life, zombie4Life, zombie5Life, movementAns);
        break;

    case 'r':
        arrowLoop = 0;
        object.rock(game_, RowElement, ColumnElement);
        displayOnly(gameplay1);
        cout << "Alien's turn ends, The trails has reset"<< endl<< endl;
        trailReset(gameplay1);
        ZombieCheck(gameplay1);
        break;

    case '^':
        arrowType = '^';
        arrowLoopStatus = 'Y'; alienLoopStatus = 'N';
        arrowLoop = 1; // arrowloop 1 means start the loop for arrow
        object.ArrowUp(alienLife, alienAtk, totalrows, totalcolumns, RowElement, ColumnElement, arrowLoop); // check whether arrow '^' have hit border /not
        if (arrowLoop == 0) //if hit
        {
            moving(gameplay1);
            trailReset(gameplay1);
            displayOnly(gameplay1);
            ZombieCheck(gameplay1);
        }
        else
        {
            movingArrow(gameplay1);           
        }
        break;

    case 'v':
        arrowType = 'v';
        arrowLoopStatus = 'Y'; alienLoopStatus = 'N';
        arrowLoop = 1;
        object.ArrowDown(alienLife, alienAtk, totalrows, totalcolumns, RowElement, ColumnElement, arrowLoop); 
        if (arrowLoop == 0)
        {
            moving(gameplay1);
            trailReset(gameplay1);
            displayOnly(gameplay1);
            ZombieCheck(gameplay1);
        }
        else
        {
            movingArrow(gameplay1);           
        }
        break;

    case '<':
        arrowType = '<';
        arrowLoopStatus = 'Y'; alienLoopStatus = 'N';
        arrowLoop = 1;
        object.ArrowLeft(alienLife, alienAtk, totalrows, totalcolumns, RowElement, ColumnElement, arrowLoop); 
        if (arrowLoop == 0)
        {
            moving(gameplay1);
            trailReset(gameplay1);
            displayOnly(gameplay1);
            ZombieCheck(gameplay1);
        }
        else
        {
            movingArrow(gameplay1);           
        }
        break;

    case '>':
        arrowType = '>';
        arrowLoopStatus = 'Y'; alienLoopStatus = 'N';
        arrowLoop = 1;
        object.ArrowRight(alienLife, alienAtk, totalrows, totalcolumns, RowElement, ColumnElement, arrowLoop); 
        if (arrowLoop == 0)
        {
            moving(gameplay1);
            trailReset(gameplay1);
            displayOnly(gameplay1);
            ZombieCheck(gameplay1);
        }
        else
        {
            movingArrow(gameplay1);           
        }
        break;

    case ' ': case '.':
        cout << "Alien finds an empty space"<<endl;
        break;

    case '1': case '2': case '3': case '4': case '5':
        alienATKzombie(gameplay1);
        break;
    }
}

void Gameplay::moving(Gameplay& gameplay1)
{
    game_[RowElement][ColumnElement] = 'A';
    game_[ARP][ACP] = '.';
}

void Gameplay::stopCheck(Gameplay& gameplay1)
{
    displayOnly(gameplay1);
    AlienSearch(gameplay1);
    char checkingAns, hitsborder;
    //cout << "alien y and x "<< ARP << " "<< ACP <<endl;
    //cout << "Alien and Arrow Loop status:  "<< alienLoopStatus << " "<< arrowLoopStatus <<endl;
    if (alienLoopStatus == 'Y')
    {
        char typeofMovementAns[]= {'U','D','L','R'};
        char typeofArrow[] = {'^','v','<','>'};
        for (int i = 0; i < 4; ++i)
        {
            if (movementAns == typeofMovementAns[i])
            {
                checkingAns = typeofArrow[i];
            }
        }
    }
    if (arrowLoopStatus == 'Y')
    {
        checkingAns = arrowType;
    }
    
    switch (checkingAns)
    {
    case '^':
        if (ARP - 1 == -1)
        {
            hitsborder = 'Y';
        }
        break;

    case 'v':
        if (ARP + 1 == totalrows)
        {
            hitsborder = 'Y';
        }
        break;

    case '<':
        if (ACP - 1 == -1)
        {
            hitsborder = 'Y';
        }
        break;

    case '>':
        if (ACP + 1 == totalcolumns)
        {
            hitsborder = 'Y';
        }
        break;
    }

    if (hitsborder == 'Y')
    {
        cout << "Alien hits the border."<<endl;
        cout << "Alien turn's end. The trail is reset." << endl << endl;
        alienLoop = 0;
        trailReset(gameplay1);
        ZombieCheck(gameplay1);
    }
}

void Gameplay::trailReset(Gameplay& gameplay1)
{
    for (int y = 0; y < totalrows; ++y)
    {
        alienAtk = 0;
        for (int x = 0; x < totalcolumns; ++x) 
        {
            char elements[] = {' ',' ',' ','<','>','^','v','h','p','r'};
            int numeoflements = 10;
            if (game_[y][x] == '.')
            {   
                int random = rand() % numeoflements;
                game_[y][x] = elements[random];
            }
        }
    }
}

void Gameplay::arrowChange(Gameplay& gameplay1)
{
    int newRow, newColumn; char newDirection[6] ;
    cout << "Enter Row, Column and Direction: ";
    cin >> newRow >> newColumn >> newDirection;

    for (int i = 0; i < strlen(newDirection); ++i) //chg upper case
    {
        newDirection[i] = toupper(newDirection[i]);
    }
    
    if(newRow < 0 || newRow > totalrows || newColumn < 0 || newColumn > totalcolumns) //check range
    {
        cout << "Please enter correct range"<< endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
    
    newRow = newRow - 1; newColumn = newColumn - 1; //to get vector base index
    char up[] = "UP"; char down[] = "DOWN"; char left[] = "LEFT"; char right[] = "RIGHT";

    switch (newDirection[0])
    {
    case 'U':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(up) || newDirection[i] != up[i]) //check character correct/not
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>') 
        {
            cout << "There's no arrow in this place" <<endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to ^" << endl;
        game_[newRow][newColumn] = '^';
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'D':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(down) || newDirection[i] != down[i])
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>')
        {
            cout << "There's no arrow in this place" << endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to v" << endl;
        game_[newRow][newColumn] = 'v';
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'L':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(left) || newDirection[i] != left[i])
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>')
        {
            cout << "There's no arrow in this place" << endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to <" << endl;
        game_[newRow][newColumn] = '<';
        pf::Pause();
        AlienStart(gameplay1);
        break;

    case 'R':
        for(int i = 0 ; i < strlen(newDirection); ++i)
        {   
            if (strlen(newDirection) != strlen(right) || newDirection[i] != right[i])
            {
                cout << "Please enter correct direction"<< endl << endl;
                pf::Pause();
                AlienStart(gameplay1);
            }
        }
        if (game_[newRow][newColumn] != '^' && game_[newRow][newColumn] != 'v' && game_[newRow][newColumn] != '<' && game_[newRow][newColumn] != '>')
        {
            cout << "There's no arrow in this place" << endl <<endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
        cout << "Arrow " << game_[newRow][newColumn] << " has switch to >" << endl;
        game_[newRow][newColumn] = '>';
        pf::Pause();
        AlienStart(gameplay1);
        break; 

    default:
        cout << "Please enter correct value and direction"<< endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
        break;
    }
    
}

void Gameplay::alienATKzombie(Gameplay& gameplay1)
{
    char okZombie;
    char allZombieGG;
    char zombieded = 'N';
    int zLife[]={zombie1Life, zombie2Life, zombie3Life, zombie4Life, zombie5Life}; //These arrays are the copy value for each zombie as we'll be using under this code.
    char zStatus[]={Z1status, Z2status, Z3status, Z4status, Z5status};
    char zombieNum[]={'1', '2', '3', '4', '5'};

    for (int i = 0; i < totalZombies; ++i) //search whether the nextElement is 1/2/3/4/5, then assign it to okZombie, where will be use below this code.
    {
        char find = '1' + i;
        if (nextElement == find)
        {
            okZombie = i;
            break;
        }
    }

    cout << "Alien attack zombie "<< zombieNum[okZombie] << endl; 
    if (alienAtk == 0)
    {
        cout << "Alien has 0 attack. No damage inflicts to the zombie "<< zombieNum[okZombie] << endl;
        cout << "Zombie " << zombieNum[okZombie] <<" is still alive" << endl;
    }
    if (alienAtk >= 20)
    {
        cout << "Zombie " << zombieNum[okZombie] << " receives a damage of " << alienAtk << endl;
        zLife[okZombie] = zLife[okZombie] - alienAtk;
        if (zLife[okZombie] > 0)
        {
            cout << "Zombie " << zombieNum[okZombie] <<" is still alive" << endl << endl;
        }
        if (zLife[okZombie] <= 0)
        {
            cout << "Zombie " << zombieNum[okZombie]  << " died" << endl << endl;
            zLife[okZombie] = 0;
            zStatus[okZombie] = 'd';
            zombieded = 'Y';

            for (int m = 0; m < totalZombies; ++m)
            {
                if (zStatus[m] == 'd')
                {
                    allZombieGG = 'Y';
                }
                else
                {
                    allZombieGG = 'N';
                    break;
                }
            }
            if (allZombieGG = 'Y')
            {
                AlienResult == 'W';
                cout << "Alien win the game" << endl << endl;
                pf::Pause();
                return;
            }

            int zombieY, zombieX;
            for (int y = 0; y < totalrows; ++y)  //search the particular zombie index then assign '.' (Alien trail) since the alien killed zombie, and can continue to move.
            {
                for (int x = 0; x < totalcolumns; ++x) 
                {
                    if (game_[y][x] == nextElement)
                    {   
                        game_[y][x] = '.';
                        break;
                    }
                }
            }
        }
    }

    switch (nextElement) //assigning back the value change above to the particular zombieLife and zombieStatus
    {
    case '1':
        zombie1Life = zLife[0];
        Z1status = zStatus[0];
        break;
    case '2':
        zombie2Life = zLife[1];
        Z1status = zStatus[1];
        break;
    case '3':
        zombie3Life = zLife[2];
        Z1status = zStatus[2];
        break;
    case '4':
        zombie4Life = zLife[3];
        Z1status = zStatus[3];
        break;
    case '5':
        zombie5Life = zLife[4];
        Z1status = zStatus[4];
        break;    
    }
    
    if (zombieded == 'N') // check whether alien have killed zombie or not.
    {
        displayOnly(gameplay1);
        cout<< "Alien turns end, the trail has reset." << endl;
        trailReset(gameplay1);
        ZombieCheck(gameplay1);
        if (AlienResult == 'W' || ZombieResult == 'W')
        {
            return;
        }
    }
}

void Gameplay::movingArrow(Gameplay& gameplay1)
{
    int i = 1;
    while (i > 0)
    {
        if (arrowLoop == 1) 
        {
            bool ans = false;
            moving(gameplay1);
            displayOnly(gameplay1); 
            AlienSearch(gameplay1);

            //Let's say if the next move will hit the border, then this is to check whether there are any arrow in the next element
            //because, if thr exist arrow. the alien will not hit the border, instead he will continue loop base on the direction of the arrow.
            //cout << " arrow type  = "<< arrowType <<endl;
            switch (arrowType)
            {   
            case '^':
                RowElement = ARP - 1; ColumnElement = ACP;
                if (ARP - 1 == 0 && game_[ARP - 1][ACP] != '^' && game_[ARP - 1][ACP] != 'v' && game_[ARP - 1][ACP] != '<' &&  game_[ARP - 1][ACP] != '>') 
                {
                    ans = true;
                }
                break;

            case 'v':
                RowElement = ARP + 1; ColumnElement = ACP;
                if (ARP + 1 == totalrows - 1 && game_[ARP + 1][ACP] != '^' && game_[ARP + 1][ACP] != 'v' && game_[ARP + 1][ACP] != '<' && game_[ARP + 1][ACP] != '>')
                {
                    ans = true;
                }
                break;

            case '<':
                RowElement = ARP; ColumnElement = ACP - 1;
                if (ACP - 1 == 0 && game_[ARP][ACP - 1] != '^' && game_[ARP][ACP - 1] != 'v' && game_[ARP][ACP - 1] != '<' && game_[ARP][ACP - 1] != '>')
                {
                    ans = true;
                }
                break;

            case '>':
                RowElement = ARP; ColumnElement = ACP + 1;
                if (ACP + 1 == totalcolumns - 1 && game_[ARP][ACP + 1] != '^' && game_[ARP][ACP + 1] != 'v' && game_[ARP][ACP + 1] != '<' && game_[ARP][ACP + 1] != '>')
                {
                    ans = true;
                }
                break;        
            }
            
            //cout << "ans true or false = " << ans <<endl;
            if (ans == true)
            {
                arrowLoop = 0;
                moving(gameplay1);
                stopCheck(gameplay1);
            }
    
            nextElement = game_[RowElement][ColumnElement];
            elementCheck(gameplay1);
        }
    }
}

void Gameplay::ZombieCheck(Gameplay& gameplay1)
{
    Gameplay2 gameplay2;
    gameplay2.zombieMovement(game_, A1, Z1, Z2, Z3, Z4, Z5, ZombieResult, Z1status, Z2status, Z3status, Z4status, Z5status, ARP, ACP, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    if (ZombieResult == 'W')
    {
        return;
    }
    else
    {
        displayOnly(gameplay1);
        cout << "Zombie's turn ends. Alien's turn now." << endl << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
}

void Gameplay::saveFile(Gameplay& gameplay1)
{
    string fileName;
    cout << "Enter the file name to save the current game: ";
    cin >> fileName;
    
    if (filesystem::exists(fileName)) 
    {
        cout << "File " << fileName << " already exists. Do you want to replace it? (Y/N): ";
        char response;
        cin >> response;
        if (response == 'n' || response == 'N') 
        {
            cout << "Alright "<< endl << endl;
            pf::Pause();
            AlienStart(gameplay1);
        }
    }

    int zLife[]={zombie1Life, zombie2Life, zombie3Life, zombie4Life, zombie5Life};
    int zAtk[]={zombie1Atk, zombie2Atk, zombie3Atk, zombie4Atk, zombie5Atk};
    int zRange[]={zombie1Range, zombie2Range, zombie3Range, zombie4Range, zombie5Range};

    ofstream file(fileName);
    file << alienLife << " " << alienAtk <<endl;
    file << totalrows << " " << totalcolumns << " " << totalZombies <<endl;
    for (int i = 0; i < totalZombies; ++i)
    {
        file << zLife[i] << " " << zAtk[i] << " " << zRange[i] <<endl;
    }
    file << Astatus << " " << Z1status << " " << Z2status << " " << Z3status << " " << Z4status << " " << Z5status <<endl;
    
    for (int y = 0; y < totalrows; ++y) 
    {
        for (int x = 0; x < totalcolumns; ++x) 
        {
            file << game_[y][x];
        }
        file << endl;
    }
    file.close();
}

void Gameplay::loadFile(Gameplay& gameplay1)
{
    string fileName;
    cout << "Enter the filename to load: ";
    cin >> fileName;

    ifstream file(fileName);
    if (file)
    {
        int zLife[]={zombie1Life, zombie2Life, zombie3Life, zombie4Life, zombie5Life};
        int zAtk[]={zombie1Atk, zombie2Atk, zombie3Atk, zombie4Atk, zombie5Atk};
        int zRange[]={zombie1Range, zombie2Range, zombie3Range, zombie4Range, zombie5Range};

        file >> alienLife; file >> alienAtk;
        file >> totalrows; file >> totalcolumns; file >> totalZombies; 
        for (int i = 0; i < totalZombies; ++i)
        {
            file >> zLife[i]; file >> zAtk[i]; file >> zRange[i];
            file.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        file >> Astatus; file >> Z1status; file >> Z2status; file >> Z3status; file >> Z4status; file >> Z5status;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int k = 0; k < totalZombies; ++k) 
        {
            switch (k)
            {
            case 0:
                zombie1Life = zLife[0]; zombie1Atk = zAtk[0]; zombie1Range = zRange[0];
                break;
            
            case 1:
                zombie2Life = zLife[1]; zombie2Atk = zAtk[1]; zombie2Range = zRange[1];
                break;

            case 2:
                zombie3Life = zLife[2]; zombie3Atk = zAtk[2]; zombie3Range = zRange[2];
                break;

            case 3:
                zombie4Life = zLife[3]; zombie4Atk = zAtk[3]; zombie4Range = zRange[3];
                break;

            case 4:
                zombie5Life = zLife[4]; zombie5Atk = zAtk[4]; zombie5Range = zRange[4];
                break;
            }
        }

        game_.resize(totalrows); 
        for (int i = 0; i < totalrows; ++i)
        {
            game_[i].resize(totalcolumns);
            string line;
            getline(file, line); 
            for (int x = 0; x < totalcolumns; ++x)
            {
                game_[i][x] = line[x]; 
            }
        }

        cout << "Game data loaded successfully from file " << fileName << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
    else
    {
        cout << "Failed to load game data from file " << fileName << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
}

void Gameplay::quitGame(Gameplay& gameplay1)
{
    char ans;
    cout << "Do you want to save before quit? (Y/N)";
    cin >> ans;
    ans = toupper(ans);
    switch (ans)
    {
    case 'Y':
        saveFile(gameplay1);
        cout << "GoodBye :D" <<endl;
        return;
        break;
    case 'N':
        cout << "GoodBye :D" <<endl;
        return;
        break;
    default:
        cout << "Please enter correct character" << endl;
        pf::Pause();
        AlienStart(gameplay1);
    }
}

