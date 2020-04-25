#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "upgrade2.h"

//to samo w points tylko, że click jest ustawione na 2, żeby dodawało 2 

int upgrade1()
{
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int score = 0;
    std::fstream points;
    std::fstream upgrade; std::stringstream ss;
    points.open("punkty.txt", std::ios::in);
    std::string str;
    std::getline(points, str);
    ss << str;
    ss >> score;
    points.close();
    int click = 2;
    char x;
    for (;;)
    {
        system("cls");
        nameGame();
        std::cout << std::endl;
        std::cout << "Ilosc klikniec: " << score << std::endl;
        std::cout << std::endl;
        upgradey();
        x = _getch();

        switch (x)
        {
        case (32):
        {
            points.open("punkty.txt", std::ios::out);
            Sleep(101);
            score += click;
            points << score;
            points.close();
        }
        break;
        case 'b':
        case 'B':
        {

            HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "JUZ TO KUPILES!!" << std::endl;
            Sleep(200);
            SetConsoleTextAttribute(hConsole, 15);

        }
        break;
        case 'A':
        case 'a':
        {
            if (score >= 569)
            {
                points.open("punkty.txt", std::ios::out);
                upgrade.open("up2.txt", std::ios::out);
                score = score - 169;
                points << score;
                points.close();
                upgrade.close();
                HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
                std::cout << "Zakupiono!" << std::endl;
                Sleep(200);
                SetConsoleTextAttribute(hConsole, 15);
                Sleep(250);
                upgrade2();
            }
            else if (score < 569)
            {
                std::cout << "Masz za malo punktow!" << std::endl;
                Sleep(200);
            }
        }
        break;
        }
    }
    return 0;
}
