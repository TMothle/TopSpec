/*
Thando Mothle
34496580
*/

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

//Function to display array containing cars
void displayCars(string arrCars[])
{
    cout << "Cars" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". " << arrCars[i] << endl;
    }
}

//Function to display specifications
void specs()
{
    cout << "Categories" << endl;
    cout << "1. Engine" << endl;
    cout << "2. Horsepower" << endl;
    cout << "3. Torque" << endl;
    cout << "4. Power" << endl;
    cout << "5. Top Speed" << endl;
}

//Function to load the game rules from a textfile
void loadGameRules()
{
    fstream inFile;
    string line;

    inFile.open("GameRules.txt", ios::in);

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
    inFile.close();
}

//Gameplay function
void gamePlay(string arrCars[], double arrEngine[], double arrHP[], double arrTorque[], double arrPower[], double arrTopSpeed[])
{
    //Declaration and initilization of variables
    int diffLevel = 0;
    int playOrExit = 0;
    int carOption = 0;
    int specOption = 0;
    int comp = 0;
    int playerScore = 0;
    int compScore = 0;
    int gameCnt = 0;

    cout << "========" << endl;
    cout << "Top Spec" << endl;
    cout << "========" << endl;
    loadGameRules();

    cout << "========" << endl;
    cout << "1. Play\n2. Exit\nChoose an option: ";
    cin >> playOrExit;

    while (playOrExit != 2)
    {
        if (playOrExit == 1)
        {
            do
            {
                while(gameCnt < 5)
                {
                    gameCnt++;
                    cout << "========" << endl;
                    cout << "Choose Difficulty Level\n1. Easy\n2. Medium\n3. Hard\nChoose an option: ";
                    cin >> diffLevel;

                    cout << "========" << endl;
                    displayCars(arrCars);

                    switch (diffLevel)
                    {
                        case 1: //Easy
                        {
                            cout << "Choose an option: ";
                            cin >> carOption;

                            cout << "========" << endl;
                            specs();

                            cout << "Choose an option: ";
                            cin >> specOption;

                            srand(time(0));
                            comp = rand() % 10;

                            switch (specOption)
                            {
                                case 1:
                                {
                                    cout << "========" << endl;
                                    cout << "Category: Engine" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrEngine[carOption - 1] << "L" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrEngine[comp] << "L" << endl;
                                    if (arrEngine[carOption - 1] > arrEngine[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    cout << "========" << endl;
                                    cout << "Category: Horsepower" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrHP[carOption - 1] << "HP" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrHP[comp] << "HP" << endl;
                                    if (arrHP[carOption - 1] > arrHP[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    cout << "========" << endl;
                                    cout << "Category: Torque" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrTorque[carOption - 1] << "Nm" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrTorque[comp] << "Nm" << endl;
                                    if (arrTorque[carOption - 1] > arrTorque[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    cout << "========" << endl;
                                    cout << "Category: Power" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrPower[carOption - 1] << "kW" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrPower[comp] << "kW" << endl;
                                    if (arrPower[carOption - 1] > arrPower[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 5:
                                {
                                    cout << "========" << endl;
                                    cout << "Category: Top Speed" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrTopSpeed[carOption - 1] << "km/h" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrTopSpeed[comp] << "km/h" << endl;
                                    if (arrTopSpeed[carOption - 1] > arrTopSpeed[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                            }

                            break;
                        }
                        case 2: //Medium
                        {
                            cout << "Choose an option: ";
                            cin >> carOption;

                            cout << "========" << endl;
                            specs();

                            cout << "Choose an option: ";
                            cin >> specOption;

                            double highest;
                            int comp = 0;

                            switch (specOption)
                            {
                                case 1:
                                {
                                    if ((gameCnt % 2) == 0)
                                    {
                                        highest = arrEngine[0];

                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (arrEngine[i] > highest)
                                            {
                                                comp = i;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        srand(time(0));
                                        comp = rand() % 10;
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Engine" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrEngine[carOption - 1] << "L" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrEngine[comp] << "L" << endl;
                                    if (arrEngine[carOption - 1] > arrEngine[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }

                                    break;
                                }
                                case 2:
                                {
                                    if ((gameCnt % 2) == 0)
                                    {
                                        highest = arrHP[0];

                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (arrHP[i] > highest)
                                            {
                                                comp = i;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        srand(time(0));
                                        comp = rand() % 10;
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Horsepower" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrHP[carOption - 1] << "HP" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrHP[comp] << "HP" << endl;
                                    if (arrHP[carOption - 1] > arrHP[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    if ((gameCnt % 2) == 0)
                                    {
                                        highest = arrTorque[0];

                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (arrTorque[i] > highest)
                                            {
                                                comp = i;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        srand(time(0));
                                        comp = rand() % 10;
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Torque" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrTorque[carOption - 1] << "Nm" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrTorque[comp] << "Nm" << endl;
                                    if (arrTorque[carOption - 1] > arrTorque[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    if ((gameCnt % 2) == 0)
                                    {
                                        highest = arrPower[0];

                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (arrPower[i] > highest)
                                            {
                                                comp = i;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        srand(time(0));
                                        comp = rand() % 10;
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Power" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrPower[carOption - 1] << "kW" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrPower[comp] << "kW" << endl;
                                    if (arrPower[carOption - 1] > arrPower[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 5:
                                {
                                    if ((gameCnt % 2) == 0)
                                    {
                                        highest = arrTopSpeed[0];

                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (arrTopSpeed[i] > highest)
                                            {
                                                comp = i;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        srand(time(0));
                                        comp = rand() % 10;
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Top Speed" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrTopSpeed[carOption - 1] << "km/h" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrTopSpeed[comp] << "km/h" << endl;
                                    if (arrTopSpeed[carOption - 1] > arrTopSpeed[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                            }

                            break;
                        }
                        case 3: //Hard
                        {
                            cout << "Choose an option: ";
                            cin >> carOption;

                            cout << "========" << endl;
                            specs();

                            cout << "Choose an option: ";
                            cin >> specOption;

                            double highest;

                            switch (specOption)
                            {
                                case 1:
                                {
                                    highest = arrEngine[0];

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (arrEngine[i] > highest)
                                        {
                                            comp = i;
                                        }
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Engine" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrEngine[carOption - 1] << "L" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrEngine[comp] << "L" << endl;
                                    if (arrEngine[carOption - 1] > arrEngine[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    highest = arrHP[0];

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (arrHP[i] > highest)
                                        {
                                            comp = i;
                                        }
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Horsepower" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrHP[carOption - 1] << "HP" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrHP[comp] << "HP" << endl;
                                    if (arrHP[carOption - 1] > arrHP[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    highest = arrTorque[0];

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (arrTorque[i] > highest)
                                        {
                                            comp = i;
                                        }
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Torque" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrTorque[carOption - 1] << "Nm" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrTorque[comp] << "Nm" << endl;
                                    if (arrTorque[carOption - 1] > arrTorque[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    highest = arrPower[0];

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (arrPower[i] > highest)
                                        {
                                            comp = i;
                                        }
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Power" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrPower[carOption - 1] << "kW" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrPower[comp] << "kW" << endl;
                                    if (arrPower[carOption - 1] > arrPower[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                                case 5:
                                {
                                    highest = arrTopSpeed[0];

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (arrTopSpeed[i] > highest)
                                        {
                                            comp = i;
                                        }
                                    }

                                    cout << "========" << endl;
                                    cout << "Category: Top Speed" << endl;
                                    cout << "Player: " << arrCars[carOption - 1] << " - " << arrTopSpeed[carOption - 1] << "km/h" << endl;
                                    cout << "Computer: " << arrCars[comp] << " - " << arrTopSpeed[comp] << "km/h" << endl;
                                    if (arrTopSpeed[carOption - 1] > arrTopSpeed[comp])
                                    {
                                        playerScore++;
                                    }
                                    else
                                    {
                                        compScore++;
                                    }
                                    break;
                                }
                            }

                            break;
                        }
                        default:
                        {
                            cout << "Invalid input. Try again." << endl;
                        }
                    }

                    cout << "========" << endl;
                    cout << "Current Score" << endl;
                    cout << "Player: " << playerScore << endl;
                    cout << "Computer: " << compScore << endl;
                }

                cout << "========" << endl;
                cout << "Final Score" << endl;
                cout << "Player: " << playerScore << endl;
                cout << "Computer: " << compScore << endl;

                if (playerScore > compScore)
                {
                    cout << "Congratulations! You Win!" << endl;
                }
                else
                {
                    cout << "Computer Wins!" << endl;
                }

                cout << "========" << endl;
                cout << "1. Play Again\n2. Exit\nChoose an option: ";
                cin >> playOrExit;

                if (playOrExit == 1)
                {
                    gameCnt = 0;
                    playerScore = 0;
                    compScore = 0;
                }

            } while (playOrExit != 2);
        }
        else if (playOrExit == 2)
        {
            exit(0);
        }
        else
        {
            cout << "Invalid input. Try again." << endl;
        }
    }
}


int main()
{
    string arrCars[10] = {"McLaren P1", "Ferrari LaFerrari", "Porsche 918 Spyder", "Lamborghini Huracan", "Volkswagen W12 Nardo", "Porsche 911 GT3RS", "Audi R8 GT", "Mercedes-Benz AMG GT63", "Lamborghini Sian", "McLaren 720s"};
    double arrEngine[10] = {3.8, 6.3, 4.6, 5.2, 6.0, 4.0, 5.2, 4.0, 6.5, 4.0};
    double arrHP[10] = {903, 950, 875, 572, 600, 502, 552, 630, 808, 710};
    double arrTorque[10] = {900, 970, 1280, 430, 620, 465, 540, 900, 760, 770};
    double arrPower[10] = {674, 708, 652, 470, 441, 386, 412, 470, 602, 530};
    double arrTopSpeed[10] = {350, 350, 345, 320, 350, 296, 320, 315, 335, 341};

    gamePlay(arrCars, arrEngine, arrHP, arrTorque, arrPower, arrTopSpeed);

    return 0;
}
