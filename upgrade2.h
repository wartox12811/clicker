#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

//to samo w points tylko, że click jest ustawione na 3, żeby dodawało 3

int upgrade2()
{
    std::fstream upgrade;
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int score = 0;
    std::fstream points;
    std::stringstream ss;
    points.open("punkty.txt", std::ios::in);
    std::string str;
    std::getline(points, str);
    ss << str;
    ss >> score;
    points.close();
    int click = 3;
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
        case 'A':
        case 'a':
        {

            HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "JUZ TO KUPILES!!" << std::endl;
            Sleep(200);
            SetConsoleTextAttribute(hConsole, 15);
        }
        break;
        }

    }

}
