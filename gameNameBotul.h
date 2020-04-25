#include <conio.h>
#include <windows.h>
#include <iostream>

void nameGame()
{
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //do fajnych kolorków
    std::cout << ">>>>>>>>>>>>" << std::endl; //tworzenie napisu botul kliker
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "B";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "O";
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "T";
    SetConsoleTextAttribute(hConsole, 3);
    std::cout << "U";
    SetConsoleTextAttribute(hConsole, 5);
    std::cout << "L";
    std::cout << " ";
    SetConsoleTextAttribute(hConsole, 5);
    std::cout << "K";
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "L";
    SetConsoleTextAttribute(hConsole, 3);
    std::cout << "I";
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "K";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "E";
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "R" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "<<<<<<<<<<<<" << std::endl;
}
