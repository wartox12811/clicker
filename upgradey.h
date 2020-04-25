#include <conio.h>
#include <windows.h>
#include <iostream>

void upgradey()
{
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "-------- UPGRADE'Y --------" << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "1. Botulek - Cena 169 klikniec - dodaje 1 - kliknij B aby zakupic" << std::endl;
    std::cout << "2. Afro z Ameryki - Cena 569 klikniec - dodaje 2 - kliknij A aby zakupic" << std::endl;
    std::cout << "3. Gruchacz na ramie - Cena 969 klikniec - dodaje 4 i SHOP - kliknij G aby miec" << std::endl;
    std::cout << "4. Bycie rakiem - Cena 1369 klikniec - dodaje 6 - kliknij R aby zakupic" << std::endl;
    std::cout << "5. Poglaskanie Bidoffa - Cena 1669 klikniec - dodaje 8 - kliknij D aby zakupic" << std::endl;

}
