#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "gameNameBotul.h"
#include "upgradey.h"
#include "upgrade1.h"
#include "kupilesjuz.h"
#include <io.h>
#include <stdlib.h>
#include <stdio.h>

#define space 32
#define b 66
#define Be 98
#ifdef WIN32
#endif

int points() //tworzenie funkcji points
{
    int score = 0; //tworzenie zmiennej całkowitej int score                                            
    std::fstream points; //tworzenie zmiennej do plików
    std::fstream upgrade; //tworzenie zmiennej do plików 
    std::stringstream ss; //tworzenie stringstream o nazwie ss - to się przyda w zamianie string na int 
    points.open("punkty.txt", std::ios::in); //otworzenie pliku "punkty.txt" tylko do odczytu               |
    std::string str; //tworzenie string str                                                                 |
    std::getline(points, str); //pobieranie z zmiennej points, czyli z pliku tekstowego                     | WSZYSTKO ODPOWIADA ZA WCZYTANIE
    ss << str;      // | ZAMIANA STRING                                                                     | PUNKTOW PO ZAMKNIECU PROGRAMU
    ss >> score;    // |     W INT                                                                          |
    points.close(); //zamyka punkty.txt                                                                     |
    int click = 1; //tworzy zmienna click, którą ustawia na 1
    char x; //tworzy znak x
    for (;;) //nieskonczona petla
    {
        system("cls"); //czysci console
        nameGame(); //pobiera nazwę gry z pliku "gameNameBotul.h"
        std::cout << std::endl; //wypisuje pusta linie
        std::cout << "Ilosc klikniec: " << score << std::endl; //wypisuje ilosc klikniec
        std::cout << std::endl; //wypisuje pusta linie
        upgradey(); //pobiera każdy tekst z pliku "upgradey.h"
        x = _getch(); // do x przypisuje _getch() ?

        switch (x) // pętla swtich do x
        {
        case (32): //ASCII - 32 to spacja w ASCII, więc jeżeli spacja naciśnięta 
        {
            points.open("punkty.txt", std::ios::out); //otwiera plik "punkty.txt" do tworzenia w nim
            Sleep(101); //usypia program na 1.01 sekundy
            score += click; // do punktów przypisuje clickniecia
            points << score; //pobiera punkty do pliku "punkty.txt"
            points.close(); //zamyka plik
            break;
        }
        
        case 'b': //dla b nacisniętego
        case 'B': //dla B nacisniętego
        {
            if (score >= 169) //jeżeli punky są większe lub równe 169
            {
                points.open("punkty.txt", std::ios::out); //otwórz "punkty.txt" do wpisywania
                upgrade.open("up1.txt", std::ios::out); //utwórz "up1.txt"
                score = score - 169; //od score odejmij 169
                points << score; //wczytaj do pliku wynik z score-169
                points.close(); //zamknij 
                upgrade.close(); //zamknij
                HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //dziwna linijka, ale potrzebna do kolorów
                SetConsoleTextAttribute(hConsole, 12); //kolor czerwony - liczby odpowiadają za kolorek
                std::cout << "Zakupiono!" << std::endl; //napis zakupiono
                Sleep(200); //usypia na 2 sekundy
                SetConsoleTextAttribute(hConsole, 15); //zmienia na biały 
                Sleep(250); //usypia na 2.5 sekundny
                upgrade1(); //wczytuje "upgrade1.h"
            }
            else if (score < 169) //w przecwinym wypadku 
            {
                std::cout << "Masz za malo punktow!" << std::endl; //wpisuje, że za mało pkt
                Sleep(200); //usypia na 2 sec.
            }
        }
        break;                  
        case 'A'://                                                                         | TO SAMO CO DLA B 
        case 'a'://                                                                         | DO break; to samo co po naciśnięciu b lub B, tlyko tutaj A lub a   |
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
        }break;
        
        }
        return 0;
    }
}

int fileExists(const char* up1)
{
    /* Sprawdzenie dostępu do pliku (jeżeli takowy istnieje, musi istnieć plik) */
#ifdef WIN32
    return !_access(up1, 0);    /* w przypadku Win32 */
#endif
}

int main()
{

    std::fstream upgrade; 
    //NAZWA GRY
    nameGame(); //wywołanie "gameNameBotul.h"

    //LICZENIE PUNTKÓW
    if (fileExists("up1.txt")) //jeżel plik "up1.txt" istnieje wywołaj funkcję upgrade1()
        upgrade1();
    else //w przeciwnym wypadku wywołaj funkcję points()
        points();
        


    return 0;
}
