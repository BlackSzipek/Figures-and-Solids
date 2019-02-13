#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
//Klasa Podstawa i dziedziczace po niej klasy
#include "Podstawa.h"
#include "Prostokat.h"
#include "Trojkat.h"
#include "Trapez.h"
#include "Kolo.h"
//Klasa Bryla i dziedziczace po niej klasy
#include "Bryla.h"
#include "Graniastoslup.h"
#include "Ostroslup.h"
//Klasa Bryla_Obrotowa i dziedziczace po niej klasy
#include "Bryla_Obrotowa.h"
#include "Walec.h"
#include "Stozek.h"
#include "Fabryka.h"
//Wyjatki
#include <exception>
#include "FileNotFoundException.h"
#include "VectorIsEmptyException.h"
#include "WrongDataException.h"
#include "WrongInputException.h"

using namespace std;

#define pi 3.14

int main()
{
    std::vector<std::shared_ptr<Podstawa>> figury;
    std::vector<std::shared_ptr<Bryla>> bryly;

    auto prostokat1 = std::make_shared<Prostokat>(2, 3);
    auto trojkat1 = std::make_shared<Trojkat>(1, 4);
    auto trapez1 = std::make_shared<Trapez>(2, 3, 4);
    auto kolo1 = std::make_shared<Kolo>(2);

    auto g1=std::make_shared<Graniastoslup>(prostokat1, 4);
    auto o1=std::make_shared<Ostroslup>(trapez1, 9);
    auto w1=std::make_shared<Walec>(kolo1,4);
    auto s1=std::make_shared<Stozek> (kolo1,3);

    figury.push_back(prostokat1);
    figury.push_back(trojkat1);
    figury.push_back(trapez1);
    figury.push_back(kolo1);

    bryly.push_back(g1);
    bryly.push_back(o1);
    bryly.push_back(w1);
    bryly.push_back(s1);

    try
    {
        Fabryka f;

        //Zapis wektora figury do pliku, znalezienie najwiekszego i najmniejszego pola figur
        //oraz wczytanie danych z pliku i wyswietlenie ich w konsoli

        f.zapisz_figury_do_pliku("figury.txt",figury);
        f.find_pole("figury.txt");
        f.wczytaj_figury("figury.txt");


        //Zapis wektora bryly do pliku,znalezienie najwiekszej i najmniejszej objetosci
        //oraz wczytanie danych z pliku i wyswietlenie ich w konsoli

        f.zapisz_bryly_do_pliku("bryly.txt",bryly);
        f.find_objetosc("bryly.txt");
        f.wczytaj_bryly("bryly.txt");


        //Obliczenia w konsoli w czasie rzeczywistym i ich zapis do podanych przez uzytkownika plikow

        f.obliczenia();


        //Wczytanie pliku z zapisanymi w nim figurami z tagiem "<Oblicz_Pola>" na poczatku pliku.Nastepnie obliczane sa pola figur
        // i zapisywane do pliku w ktorym wczesniej znajdowaly sie figury z tagiem.

        f.wczytaj_obliczenia_pola("figury_2.txt");


        //Wczytanie pliku z zapisanymi w nim brylami z tagiem "<Oblicz_Objetosci>" na poczatku pliku.Nastpenie obliczane sa objetosci
        //bryl i zapisywane w pliku w ktorym wczesniej byly bryly z tagiem.

        f.wczytaj_obliczenia_objetosci("bryly_2.txt");



    }
    catch(const FileNotFoundException& e)
    {
        std::cout<<"Wyjatek : "<<e.what()<<std::endl;
    }
    catch(const WrongDataException& e)
    {
        std::cout<<"Wyjatek : "<<e.what()<<std::endl;
    }
    catch(const VectorIsEmptyException& e)
    {
        std::cout<<"Wyjatek : "<<e.what()<<std::endl;
    }
    catch(const WrongInputException& e)
    {
        std::cout<<"Wyjatek : "<<e.what()<<std::endl;
    }
    catch(...)
    {
        std::cout<<"Nieznany wyjatek"<<std::endl;
    }

    return 0;
}



