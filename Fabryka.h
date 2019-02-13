#ifndef FABRYKA_H_INCLUDED
#define FABRYKA_H_INCLUDED

#include <iostream>
#include <bitset>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include "Podstawa.h"
#include "Prostokat.h"
#include "Trojkat.h"
#include "Trapez.h"
#include "Kolo.h"
#include "Bryla.h"
#include "Graniastoslup.h"
#include "Ostroslup.h"
#include "Bryla_Obrotowa.h"
#include "Walec.h"
#include "Stozek.h"
#include "FileNotFoundException.h"
#include "VectorIsEmptyException.h"
#include "WrongDataException.h"

class Fabryka
{
public:
    Fabryka(void)=default;
    void zapisz_figury_do_pliku(std::string s,std::vector<std::shared_ptr<Podstawa>> figury);
    void zapisz_bryly_do_pliku(std::string s,std::vector<std::shared_ptr<Bryla>> bryly);
    void zapisz_pola_figur_do_pliku(std::string s,std::vector<std::shared_ptr<Podstawa>> figury);
    void zapisz_objetosci_bryl_do_pliku(std::string s,std::vector<std::shared_ptr<Bryla>> bryly);
    auto wczytaj_plik_z_figurami(std::string sciezka_pliku);
    auto wczytaj_plik_z_brylami(std::string sciezka_pliku);
    void wczytaj_bryly(std::string s);
    void wczytaj_figury(std::string s);
    std::shared_ptr<Podstawa> stworzProstokat(void);
    std::shared_ptr<Podstawa> stworzTrojkat(void);
    std::shared_ptr<Podstawa> stworzTrapez(void);
    std::shared_ptr<Podstawa> stworzKolo(void);
    std::shared_ptr<Kolo> stworzKolo2(void);
    double wysokosc(void);
    std::shared_ptr<Bryla> stworzGraniastoslup(std::shared_ptr<Podstawa> p, double h);
    std::shared_ptr<Bryla> stworzOstroslup(std::shared_ptr<Podstawa> p, double h);
    std::shared_ptr<Bryla> stworzWalec(std::shared_ptr<Kolo> p,double h);
    std::shared_ptr<Bryla> stworzStozek(std::shared_ptr<Kolo> p,double h);
    int obliczenia(void);
    void find_pole(std::string s);
    void find_objetosc(std::string s);
    void wczytaj_obliczenia_pola(std::string sciezka_pliku);
    void wczytaj_obliczenia_objetosci(std::string sciezka_pliku);

};


#endif // FABRYKA_H_INCLUDED
