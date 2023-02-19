//object.cpp (POD)
    /*cout << "MIN = "<< min<<endl;
    cout << "List [0] = "<< list[0]<< endl;
    cout << "List [1] = "<< list[1]<< endl;
    cout << "List [2] = "<< list[2]<< endl;
    cout << "List [3] = "<< list[3]<< endl;
    cout << "List [4] = "<< list[4]<< endl;

    cout << "Testing, zombie1 one y and x = " << Z1rows << " " << Z1columns<< endl;
    cout << "Testing, zombie2 one y and x = " << Z2rows << " " << Z2columns<< endl;
    cout << "Testing, zombie3 one y and x = " << Z3rows << " " << Z3columns<< endl;
    cout << "Testing, zombie4 one y and x = " << Z4rows << " " << Z4columns<< endl;
    cout << "Testing, zombie5 one y and x = " << Z5rows << " " << Z5columns<< endl << endl << endl;
    
    cout << "Testing, zombie 1 distance: " << object.PandZ1Distance << endl;
    cout << "Testing, zombie 2 distance: " << object.PandZ2Distance << endl;
    cout << "Testing, zombie 3 distance: " << object.PandZ3Distance << endl;
    cout << "Testing, zombie 4 distance: " << object.PandZ4Distance << endl;
    cout << "Testing, zombie 5 distance: " << object.PandZ5Distance << endl;
    cout << "listsize is = " << list.size()<< endl;

    cout << "Random [0] = "<< random[0]<< endl;
    cout << "Random [1] = "<< random[1]<< endl;
    cout << "Random [2] = "<< random[2]<< endl;
    cout << "Random [3] = "<< random[3]<< endl;
    cout << "Random [4] = "<< random[4]<< endl;
    cout << "RANDOM SIZE = "<< random.size() <<endl;*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//gameplay1.cpp (movement)
    /*switch (movementAns) //This gameplay1.movementAns is the user enter the command like Up down left right 
    {
    case 'U':
        alienLoop = 1;
        while (alienLoop > 0)
        {
            AlienSearch(gameplay1); //search alien position
            borderCheck(gameplay1);  //if pass means can move
            cout << "Alien move up"<< endl << endl;
            RowElement = ARP - 1; ColumnElement = ACP; //the "RowElement" and "ColumnElement" are the index of the next element
            elementCheck(gameplay1); //call function to check element by using the index created above this line
            moving(gameplay1); //call function to change the index of A to the entered direction
            stopCheck(gameplay1); //refresh board and check whether have hit border or not|| if hit, zombie turn.
        }

    case 'D':
        alienLoop = 1;
        while (alienLoop > 0)
        {
            AlienSearch(gameplay1);
            borderCheck(gameplay1);
            cout << "Alien move down" << endl << endl;
            RowElement = ARP + 1; ColumnElement = ACP;
            elementCheck(gameplay1);
            moving(gameplay1);
            stopCheck(gameplay1);
        }

    case 'L':
        alienLoop = 1;
        while (alienLoop > 0)
        {
            AlienSearch(gameplay1);
            borderCheck(gameplay1);
            cout << "Alien move left"<< endl << endl;
            RowElement = ARP ; ColumnElement = ACP - 1;
            elementCheck(gameplay1);
            moving(gameplay1);
            stopCheck(gameplay1);
        }

    case 'R':
        alienLoop = 1;
        while (alienLoop > 0)
        {
            AlienSearch(gameplay1);
            borderCheck(gameplay1);
            cout << "Alien move right"<< endl << endl;
            RowElement = ARP; ColumnElement = ACP + 1;
            elementCheck(gameplay1);
            moving(gameplay1);
            stopCheck(gameplay1);
        } 
    }*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//gameplay1.cpp (stopcheck)
    /*switch (movementAns) 
    {
    case 'U':
       if (ARP - 1 == 0 )
        {
            cout << "Alien hits the border."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            alienLoop = 0;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;

    case 'D':
        if (ARP + 1 == (totalrows - 1) )
        {
            cout << "Alien hits the border."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            alienLoop = 0;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;
        
    case 'L':
        if (ACP - 1 == 0 )
        {
            cout << "Alien hits the border."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            alienLoop = 0;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;
        
    case 'R':
       if (ACP + 1 == (totalcolumns - 1) )
        {
            cout << "Alien hits the border."<<endl;
            cout << "Alien turn's end. The trail is reset." << endl << endl;
            alienLoop = 0;
            trailReset(gameplay1);
            ZombieCheck(gameplay1);
        }
        break;
    }*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//zombie check
/*for (int i = 1; i <= totalZombies; ++i)
    {
        switch (i)
        {
        case 1:
            gameplay2.Zombie1Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 2:
            gameplay2.Zombie2Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 3:
            gameplay2.Zombie3Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 4:
            gameplay2.Zombie4Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        case 5:
            gameplay2.Zombie5Start(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies,
                                alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range,
                                zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
            break;
        }
    }*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AlienatkZombie
/*char zombieded = 'N';
    switch (nextElement)
    {
    case '1':
        cout << "Alien attack zombie 1." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 1 "<<endl;
            cout << "Zombie 1 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 1 receives a damage of "<< alienAtk <<endl;
            if (zombie1Life > 20)
            {
                zombie1Life = zombie1Life - alienAtk;
                cout << "Zombie 1 is still alive" <<endl;
            }
            if (zombie1Life <= 20)
            {
                cout << "Zombie 1 died" <<endl;
                zombie1Life = 0;
                Z1status = 'd';
                zombieded = 'Y';
            }
        }
        break;

    case '2':
        cout << "Alien attack zombie 2." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 2 "<<endl;
            cout << "Zombie 2 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 2 receives a damage of "<< alienAtk <<endl;
            if (zombie2Life > 20)
            {
                zombie2Life = zombie2Life - alienAtk;
                cout << "Zombie 2 is still alive" <<endl;
            }
            if (zombie1Life <= 20)
            {
                cout << "Zombie 2 died" <<endl;
                zombie2Life = 0;
                Z2status = 'd';
                zombieded = 'Y';
            }
        }
        break;

    case '3':
        cout << "Alien attack zombie 3." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 3 "<<endl;
            cout << "Zombie 3 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 3 receives a damage of "<< alienAtk <<endl;
            if (zombie3Life > 20)
            {
                zombie3Life = zombie3Life - alienAtk;
                cout << "Zombie 3 is still alive" <<endl;
            }
            if (zombie3Life <= 20)
            {
                cout << "Zombie 3 died" <<endl;
                zombie3Life = 0;
                Z3status = 'd';
                zombieded = 'Y';
            }
        }
        break;

    case '4':
        cout << "Alien attack zombie 4." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 4 "<<endl;
            cout << "Zombie 4 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 4 receives a damage of "<< alienAtk <<endl;
            if (zombie4Life > 20)
            {
                zombie4Life = zombie4Life - alienAtk;
                cout << "Zombie 4 is still alive" <<endl;
            }
            if (zombie4Life <= 20)
            {
                cout << "Zombie 4 died" <<endl;
                zombie4Life = 0;
                Z4status = 'd';
                zombieded = 'Y';
            }
        }
        break;
        
    case '5':
        cout << "Alien attack zombie 5." << endl;
        if (alienAtk == 0)
        {
            cout << "Alien has 0 attack. No damage inflicts to the zombie 5 "<<endl;
            cout << "Zombie 5 is still alive" <<endl;
        }
        if (alienAtk >= 20)
        {
            cout << "Zombie 5 receives a damage of "<< alienAtk <<endl;
            if (zombie5Life > 20)
            {
                zombie5Life = zombie5Life - alienAtk;
                cout << "Zombie 5 is still alive" <<endl;
            }
            if (zombie5Life <= 20)
            {
                cout << "Zombie 5 died" <<endl;
                zombie5Life = 0;
                Z5status = 'd';
                zombieded = 'Y';
            }
        }
        break;
    }

    if (zombieded == 'N')
    {
        displayOnly(gameplay1);
        cout<< "Alien turns end, the trail has reset." << endl;
        trailReset(gameplay1);
        ZombieCheck(gameplay1);
    }*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Repeating zombie movement
/*void Gameplay2::Zombie1Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    A1 = 0, Z1 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie1movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie2Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z1 = 0, Z2 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie2movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);    
}

void Gameplay2::Zombie3Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z2 = 0, Z3 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie3movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie4Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z3 = 0, Z4 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie4movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie5Start(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    Z4 = 0, Z5 = 1;
    displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
    Zombie5movement(game_, A1, Z1, Z2, Z3, Z4, Z5, ARP, ACP, Z1Row, Z1Column, totalrows, totalcolumns, totalZombies, alienLife, alienAtk, zombie1Life, zombie1Atk, zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range);
}

void Gameplay2::Zombie1movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
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
            case '1':
                Z1Row = y; Z1Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z1Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z1Row - 1][Z1Column] == 'A'||
                game_[Z1Row - 1][Z1Column] == '2'||
                game_[Z1Row - 1][Z1Column] == '3'||
                game_[Z1Row - 1][Z1Column] == '4'||
                game_[Z1Row - 1][Z1Column] == '5')
            {
                continue;
            }
            game_[Z1Row - 1][Z1Column] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Row = Z1Row - 1;
            cout << "Zombie 1 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z1Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z1Row + 1][Z1Column] == 'A'||
                game_[Z1Row + 1][Z1Column] == '2'||
                game_[Z1Row + 1][Z1Column] == '3'||
                game_[Z1Row + 1][Z1Column] == '4'||
                game_[Z1Row + 1][Z1Column] == '5')
            {
                continue;
            }
            game_[Z1Row + 1][Z1Column] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Row = Z1Row + 1;
            cout << "Zombie 1 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z1Column -1 == -1)
            {
                continue;
            }
            if (game_[Z1Row][Z1Column - 1] == 'A'||
                game_[Z1Row][Z1Column - 1] == '2'||
                game_[Z1Row][Z1Column - 1] == '3'||
                game_[Z1Row][Z1Column - 1] == '4'||
                game_[Z1Row][Z1Column - 1] == '5')
            {
                continue;
            }
            game_[Z1Row][Z1Column - 1] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Column = Z1Column - 1;
            cout << "Zombie 1 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z1Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z1Row][Z1Column + 1] == 'A'||
                game_[Z1Row][Z1Column + 1] == '2'||
                game_[Z1Row][Z1Column + 1] == '3'||
                game_[Z1Row][Z1Column + 1] == '4'||
                game_[Z1Row][Z1Column + 1] == '5')
            {
                continue;
            }
            game_[Z1Row][Z1Column + 1] = '1';
            game_[Z1Row][Z1Column] = ' ';
            Z1Column = Z1Column + 1;
            cout << "Zombie 1 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z1andADistance = abs(Z1Row - ARP) + abs(Z1Column - ACP);
        cout << "for checking distance and range : " <<Z1andADistance << " "<< zombie1Range<<endl;

        if (zombie1Range >= Z1andADistance)
        {
            cout << "Zombie 1 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie1Range < Z1andADistance)
        {
            cout << "Zombie 1 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie2movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z2Row, Z2Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '2':
                Z2Row = y; Z2Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z2Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z2Row - 1][Z2Column] == 'A'||
                game_[Z2Row - 1][Z2Column] == '1'||
                game_[Z2Row - 1][Z2Column] == '3'||
                game_[Z2Row - 1][Z2Column] == '4'||
                game_[Z2Row - 1][Z2Column] == '5')
            {
                continue;
            }
            game_[Z2Row - 1][Z2Column] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Row = Z2Row - 1;
            cout << "Zombie 2 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z2Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z2Row + 1][Z2Column] == 'A'||
                game_[Z2Row + 1][Z2Column] == '1'||
                game_[Z2Row + 1][Z2Column] == '3'||
                game_[Z2Row + 1][Z2Column] == '4'||
                game_[Z2Row + 1][Z2Column] == '5')
            {
                continue;
            }
            game_[Z2Row + 1][Z2Column] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Row = Z2Row + 1;
            cout << "Zombie 2 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z2Column -1 == -1)
            {
                continue;
            }
            if (game_[Z2Row][Z2Column - 1] == 'A'||
                game_[Z2Row][Z2Column - 1] == '1'||
                game_[Z2Row][Z2Column - 1] == '3'||
                game_[Z2Row][Z2Column - 1] == '4'||
                game_[Z2Row][Z2Column - 1] == '5')
            {
                continue;
            }
            game_[Z2Row][Z2Column - 1] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Column = Z2Column - 1;
            cout << "Zombie 2 moves left" << endl << endl ;
            i = 0;
            break;

        case 'R':
            if (Z2Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z2Row][Z2Column + 1] == 'A'||
                game_[Z2Row][Z2Column + 1] == '1'||
                game_[Z2Row][Z2Column + 1] == '3'||
                game_[Z2Row][Z2Column + 1] == '4'||
                game_[Z2Row][Z2Column + 1] == '5')
            {
                continue;
            }
            game_[Z2Row][Z2Column + 1] = '2';
            game_[Z2Row][Z2Column] = ' ';
            Z2Column = Z2Column + 1;
            cout << "Zombie 2 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z2andADistance = abs(Z2Row - ARP) + abs(Z2Column - ACP);
        cout << "for checking distance and range : " <<Z2andADistance << " "<< zombie2Range<<endl;
        if (zombie2Range >= Z2andADistance)
        {
            cout << "Zombie 2 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie2Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie2Atk;
        }
        
        if (zombie2Range < Z2andADistance)
        {
            cout << "Zombie 2 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie3movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z3Row, Z3Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '3':
                Z3Row = y; Z3Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z3Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z3Row - 1][Z3Column] == 'A'||
                game_[Z3Row - 1][Z3Column] == '2'||
                game_[Z3Row - 1][Z3Column] == '1'||
                game_[Z3Row - 1][Z3Column] == '4'||
                game_[Z3Row - 1][Z3Column] == '5')
            {
                continue;
            }
            game_[Z3Row - 1][Z3Column] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Row = Z3Row - 1;
            cout << "Zombie 3 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z3Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z3Row + 1][Z3Column] == 'A'||
                game_[Z3Row + 1][Z3Column] == '2'||
                game_[Z3Row + 1][Z3Column] == '1'||
                game_[Z3Row + 1][Z3Column] == '4'||
                game_[Z3Row + 1][Z3Column] == '5')
            {
                continue;
            }
            game_[Z3Row + 1][Z3Column] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Row = Z3Row + 1;
            cout << "Zombie 3 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z3Column -1 == -1)
            {
                continue;
            }
            if (game_[Z3Row][Z3Column - 1] == 'A'||
                game_[Z3Row][Z3Column - 1] == '2'||
                game_[Z3Row][Z3Column - 1] == '1'||
                game_[Z3Row][Z3Column - 1] == '4'||
                game_[Z3Row][Z3Column - 1] == '5')
            {
                continue;
            }
            game_[Z3Row][Z3Column - 1] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Column = Z3Column - 1;
            cout << "Zombie 3 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z3Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z3Row][Z3Column + 1] == 'A'||
                game_[Z3Row][Z3Column + 1] == '2'||
                game_[Z3Row][Z3Column + 1] == '1'||
                game_[Z3Row][Z3Column + 1] == '4'||
                game_[Z3Row][Z3Column + 1] == '5')
            {
                continue;
            }
            game_[Z3Row][Z3Column + 1] = '3';
            game_[Z3Row][Z3Column] = ' ';
            Z3Column = Z3Column + 1;
            cout << "Zombie 3 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z3andADistance = abs(Z3Row - ARP) + abs(Z3Column - ACP);
        cout << "for checking distance and range : " <<Z3andADistance << " "<< zombie3Range<<endl;
        if (zombie3Range >= Z3andADistance)
        {
            cout << "Zombie 3 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie3Range < Z3andADistance)
        {
            cout << "Zombie 3 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie4movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z4Row, Z4Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '4':
                Z4Row = y; Z4Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z4Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z4Row - 1][Z4Column] == 'A'||
                game_[Z4Row - 1][Z4Column] == '2'||
                game_[Z4Row - 1][Z4Column] == '3'||
                game_[Z4Row - 1][Z4Column] == '1'||
                game_[Z4Row - 1][Z4Column] == '5')
            {
                continue;
            }
            game_[Z4Row - 1][Z4Column] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Row = Z4Row - 1;
            cout << "Zombie 4 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z4Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z4Row + 1][Z4Column] == 'A'||
                game_[Z4Row + 1][Z4Column] == '2'||
                game_[Z4Row + 1][Z4Column] == '3'||
                game_[Z4Row + 1][Z4Column] == '1'||
                game_[Z4Row + 1][Z4Column] == '5')
            {
                continue;
            }
            game_[Z4Row + 1][Z4Column] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Row = Z4Row + 1;
            cout << "Zombie 4 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z4Column -1 == -1)
            {
                continue;
            }
            if (game_[Z4Row][Z4Column - 1] == 'A'||
                game_[Z4Row][Z4Column - 1] == '2'||
                game_[Z4Row][Z4Column - 1] == '3'||
                game_[Z4Row][Z4Column - 1] == '1'||
                game_[Z4Row][Z4Column - 1] == '5')
            {
                continue;
            }
            game_[Z4Row][Z4Column - 1] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Column = Z4Column - 1;
            cout << "Zombie 4 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z4Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z4Row][Z4Column + 1] == 'A'||
                game_[Z4Row][Z4Column + 1] == '2'||
                game_[Z4Row][Z4Column + 1] == '3'||
                game_[Z4Row][Z4Column + 1] == '1'||
                game_[Z4Row][Z4Column + 1] == '5')
            {
                continue;
            }
            game_[Z4Row][Z4Column + 1] = '4';
            game_[Z4Row][Z4Column] = ' ';
            Z4Column = Z4Column + 1;
            cout << "Zombie 4 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z4andADistance = abs(Z4Row - ARP) + abs(Z4Column - ACP);
        cout << "for checking distance and range : " <<Z4andADistance << " "<< zombie4Range<<endl;
        if (zombie4Range >= Z4andADistance)
        {
            cout << "Zombie 4 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie4Range < Z4andADistance)
        {
            cout << "Zombie 4 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}

void Gameplay2::Zombie5movement(vector<vector<char>>& game_, int& A1, int& Z1, int& Z2, int& Z3, int& Z4, int& Z5, int& ARP, int& ACP, int& Z1Row, int& Z1Column, int& totalrows, int& totalcolumns, int& totalZombies, int& alienLife, int& alienAtk, int& zombie1Life, int& zombie1Atk, int& zombie1Range, int&zombie2Life, int&zombie2Atk, int&zombie2Range, int&zombie3Life, int&zombie3Atk, int&zombie3Range, int&zombie4Life, int&zombie4Atk, int&zombie4Range, int&zombie5Life, int&zombie5Atk, int&zombie5Range)
{
    int Z5Row, Z5Column;
    for (int y = 0; y < totalrows; ++y)
    {
        for (int x = 0; x < totalcolumns; ++x)
        {
            switch (game_[y][x])
            {
            case 'A':
                ARP = y; ACP = x;
                break;           
            case '5':
                Z5Row = y; Z5Column = x;
                break;
            }
        } 
    }

    int i = 1;
    while (i > 0)
    {
        char choice[]={'U','D','L','R'};
        int numofchoice = 4;
        char result = choice[rand() % numofchoice];
        switch (result)
        {
        case 'U':
            if (Z5Row - 1 == -1)
            {
                continue;
            }
            if (game_[Z5Row - 1][Z5Column] == 'A'||
                game_[Z5Row - 1][Z5Column] == '2'||
                game_[Z5Row - 1][Z5Column] == '3'||
                game_[Z5Row - 1][Z5Column] == '4'||
                game_[Z5Row - 1][Z5Column] == '1')
            {
                continue;
            }
            game_[Z5Row - 1][Z5Column] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Row = Z5Row - 1;
            cout << "Zombie 5 moves up" << endl << endl;
            i = 0;
            break;
           
        case 'D':
            if (Z5Row + 1 == totalrows) 
            {
                continue;
            }
            if (game_[Z5Row + 1][Z5Column] == 'A'||
                game_[Z5Row + 1][Z5Column] == '2'||
                game_[Z5Row + 1][Z5Column] == '3'||
                game_[Z5Row + 1][Z5Column] == '4'||
                game_[Z5Row + 1][Z5Column] == '1')
            {
                continue;
            }
            game_[Z5Row + 1][Z5Column] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Row = Z5Row + 1;
            cout << "Zombie 5 moves down" << endl << endl;
            i = 0;
            break;

        case 'L':
            if (Z5Column -1 == -1)
            {
                continue;
            }
            if (game_[Z5Row][Z5Column - 1] == 'A'||
                game_[Z5Row][Z5Column - 1] == '2'||
                game_[Z5Row][Z5Column - 1] == '3'||
                game_[Z5Row][Z5Column - 1] == '4'||
                game_[Z5Row][Z5Column - 1] == '1')
            {
                continue;
            }
            game_[Z5Row][Z5Column - 1] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Column = Z5Column - 1;
            cout << "Zombie 5 moves left" << endl << endl;
            i = 0;
            break;

        case 'R':
            if (Z5Column + 1 == totalcolumns)
            {
                continue;
            }
            if (game_[Z5Row][Z5Column + 1] == 'A'||
                game_[Z5Row][Z5Column + 1] == '2'||
                game_[Z5Row][Z5Column + 1] == '3'||
                game_[Z5Row][Z5Column + 1] == '4'||
                game_[Z5Row][Z5Column + 1] == '1')
            {
                continue;
            }
            game_[Z5Row][Z5Column + 1] = '5';
            game_[Z5Row][Z5Column] = ' ';
            Z5Column = Z5Column + 1;
            cout << "Zombie 5 moves right" << endl << endl;
            i = 0;
            break;
        }

        displayOnly(game_, A1,  Z1,  Z2,  Z3,  Z4,  Z5,  ARP,  ACP,  Z1Row,  Z1Column,  totalrows,  totalcolumns, totalZombies,  alienLife,  alienAtk,  zombie1Life,  zombie1Atk,  zombie1Range, zombie2Life, zombie2Atk, zombie2Range, zombie3Life, zombie3Atk, zombie3Range, zombie4Life, zombie4Atk, zombie4Range, zombie5Life, zombie5Atk, zombie5Range); 
        int Z5andADistance = abs(Z5Row - ARP) + abs(Z5Column - ACP);
        cout << "for checking distance and range : " <<Z5andADistance << " "<< zombie5Range<<endl;
        if (zombie5Range >= Z5andADistance)
        {
            cout << "Zombie 5 attacks Alien."<<endl;
            cout << "Alien receives a damage of " << zombie1Atk <<"."<< endl << endl;
            alienLife = alienLife - zombie1Atk;
        }
        
        if (zombie5Range < Z5andADistance)
        {
            cout << "Zombie 5 is unable to attack Alien."<<endl;
            cout << "Alien is too far"<< endl << endl;
        }
    }
}*/