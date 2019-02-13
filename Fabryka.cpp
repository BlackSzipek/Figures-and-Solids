#include "Fabryka.h"

void Fabryka::zapisz_figury_do_pliku(std::string s,std::vector<std::shared_ptr<Podstawa>> figury)
{
    std::ofstream plik(s);
    if(!plik.is_open())
    {
        throw FileNotFoundException(s);
    }
    else
    {
        if (figury.empty())
        {
            throw VectorIsEmptyException();
        }
        else
        {
            for (auto ptr : figury)
            {
                plik <<(*ptr)<<std::endl;
            }
        }
    }
}

void Fabryka::zapisz_bryly_do_pliku(std::string s,std::vector<std::shared_ptr<Bryla>> bryly)
{
    std::ofstream plik(s);
    if(!plik.is_open())
    {
        throw FileNotFoundException(s);
    }
    else
    {
        if (bryly.empty())
        {
            throw VectorIsEmptyException();
        }
        else
        {
            for (auto ptr : bryly)
            {
                plik << (*ptr)<<std::endl;
            }
        }
    }
}

void Fabryka::zapisz_pola_figur_do_pliku(std::string s,std::vector<std::shared_ptr<Podstawa>> figury)
{
    std::ofstream plik(s);
    if(!plik.is_open())
    {
        throw FileNotFoundException(s);
    }
    else
    {
        if (figury.empty())
        {
            throw VectorIsEmptyException();
        }
        else
        {
            for (auto ptr : figury)
            {
                plik <<"<pole="<<ptr->Pole()<<">\n"<<(*ptr)<<"</pole>"<<std::endl;
            }
        }
    }
}

void Fabryka::zapisz_objetosci_bryl_do_pliku(std::string s,std::vector<std::shared_ptr<Bryla>> bryly)
{
    std::ofstream plik(s);
    if(!plik.is_open())
    {
        throw FileNotFoundException(s);
    }
    else
    {
        if (bryly.empty())
        {
            throw VectorIsEmptyException();
        }
        else
        {
            for (auto ptr : bryly)
            {
                plik <<"<objetosc="<<ptr->Objetosc()<<">\n"<<(*ptr)<<"</objetosc>"<<std::endl;
            }
        }
    }
}

auto Fabryka::wczytaj_plik_z_figurami(std::string sciezka_pliku)
{
    std::vector<std::shared_ptr<Podstawa>> figury_wczytane;
    std::string nazwa_figury;
    std::ifstream plik_we(sciezka_pliku);
    if(!plik_we.is_open())
    {
        throw FileNotFoundException(sciezka_pliku);
    }
    else
    {
        while (!plik_we.eof())
        {
            nazwa_figury.clear();
            plik_we >> nazwa_figury;

            if (Prostokat::identyfikator_typu_ == nazwa_figury)
            {
                figury_wczytane.push_back(std::make_shared<Prostokat>());
                plik_we >> *(figury_wczytane.back());
                continue;
            }
            if (Trojkat::identyfikator_typu_ == nazwa_figury)
            {
                figury_wczytane.push_back(std::make_shared<Trojkat>());
                plik_we >> *(figury_wczytane.back());
                continue;
            }
            if (Trapez::identyfikator_typu_ == nazwa_figury)
            {
                figury_wczytane.push_back(std::make_shared<Trapez>());
                plik_we >> *(figury_wczytane.back());
                continue;
            }
            if (Kolo::identyfikator_typu_ == nazwa_figury)
            {
                figury_wczytane.push_back(std::make_shared<Kolo>());
                plik_we >> *(figury_wczytane.back());
                continue;
            }
            else if(Prostokat::identyfikator_typu_!=nazwa_figury && Prostokat::identyfikator_typu_end_!=nazwa_figury &&
                    Trojkat::identyfikator_typu_ !=nazwa_figury && Trojkat::identyfikator_typu_end_ !=nazwa_figury &&
                    Trapez::identyfikator_typu_ !=nazwa_figury && Trapez::identyfikator_typu_end_!= nazwa_figury &&
                    Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury && nazwa_figury!="")
            {
                throw WrongDataException(nazwa_figury);
            }
        }
        if (figury_wczytane.empty())
        {
            throw VectorIsEmptyException();
        }
        else
        {
            return figury_wczytane;
        }
    }
}

auto Fabryka::wczytaj_plik_z_brylami(std::string sciezka_pliku)
{
    std::ifstream plik_we(sciezka_pliku);
    std::vector<std::shared_ptr<Bryla>> bryly_wczytane;
    std::vector<std::shared_ptr<Podstawa>> figury;
    std::string nazwa_bryly;
    std::string nazwa_figury;
    double h;

    if(!plik_we.is_open())
    {
        throw FileNotFoundException(sciezka_pliku);
    }

    else
    {
        while (!plik_we.eof())
        {
            nazwa_bryly.clear();
            nazwa_figury.clear();
            plik_we >> nazwa_bryly;

            if (Ostroslup::identyfikator_typu_ == nazwa_bryly)
            {
                plik_we>>nazwa_figury;
                if (Prostokat::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Prostokat>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                    continue;
                }
                if (Trojkat::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Trojkat>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                }
                if (Trapez::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Trapez>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                    continue;
                }
                if (Kolo::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Kolo>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                    continue;
                }
                else if(Prostokat::identyfikator_typu_!=nazwa_figury && Prostokat::identyfikator_typu_end_!=nazwa_figury &&
                        Trojkat::identyfikator_typu_ !=nazwa_figury && Trojkat::identyfikator_typu_end_ !=nazwa_figury &&
                        Trapez::identyfikator_typu_ !=nazwa_figury && Trapez::identyfikator_typu_end_!= nazwa_figury &&
                        Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury && nazwa_figury!="")
                {
                    throw WrongDataException(nazwa_figury);
                }

            }
            if (Graniastoslup::identyfikator_typu_ == nazwa_bryly)
            {
                plik_we>>nazwa_figury;
                if (Prostokat::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Prostokat>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                        bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                        continue;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                }
                if (Trojkat::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Trojkat>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                }
                if (Trapez::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Trapez>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                    continue;
                }
                if (Kolo::identyfikator_typu_ == nazwa_figury)
                {
                    figury.push_back(std::make_shared<Kolo>());
                    plik_we >>*figury.back();
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                    continue;
                }
                else if(Prostokat::identyfikator_typu_!=nazwa_figury && Prostokat::identyfikator_typu_end_!=nazwa_figury &&
                        Trojkat::identyfikator_typu_ !=nazwa_figury && Trojkat::identyfikator_typu_end_ !=nazwa_figury &&
                        Trapez::identyfikator_typu_ !=nazwa_figury && Trapez::identyfikator_typu_end_!= nazwa_figury &&
                        Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury && nazwa_figury!="")
                {
                    throw WrongDataException(nazwa_figury);
                }
            }
            if (Walec::identyfikator_typu_ == nazwa_bryly)
            {
                plik_we>>nazwa_figury;
                if (Kolo::identyfikator_typu_ == nazwa_figury)
                {
                    auto k=std::make_shared<Kolo>();
                    plik_we >>*k;
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Walec>(k,h));
                    continue;
                }
                else if(Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury
                        && nazwa_figury!="")
                {
                    throw WrongDataException(nazwa_figury);
                }
            }
            if (Stozek::identyfikator_typu_ == nazwa_bryly)
            {
                plik_we>>nazwa_figury;
                if (Kolo::identyfikator_typu_ == nazwa_figury)
                {
                    auto k=std::make_shared<Kolo>();
                    plik_we >>*k;
                    plik_we >>nazwa_figury;
                    plik_we>>nazwa_figury;
                    if(nazwa_figury=="<wysokosc>")
                    {
                        plik_we>>h;
                    }
                    else
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                    bryly_wczytane.push_back(std::make_shared<Stozek>(k,h));
                    continue;
                }
                else if(Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury
                        && nazwa_figury!="")
                {
                    throw WrongDataException(nazwa_figury);
                }
            }
            else if(Ostroslup::identyfikator_typu_ != nazwa_bryly && Ostroslup::identyfikator_typu_end_ != nazwa_bryly &&
                    Graniastoslup::identyfikator_typu_ != nazwa_bryly && Graniastoslup::identyfikator_typu_end_ != nazwa_bryly &&
                    Walec::identyfikator_typu_ != nazwa_bryly && Walec::identyfikator_typu_end_ != nazwa_bryly &&
                    Stozek::identyfikator_typu_ != nazwa_bryly && Stozek::identyfikator_typu_end_ != nazwa_bryly && nazwa_bryly!=""
                    && nazwa_bryly!="</wysokosc>")
            {
                throw WrongDataException(nazwa_bryly);
            }
        }
        if (bryly_wczytane.empty())
        {
            throw VectorIsEmptyException();
        }
        else
        {
            return bryly_wczytane;
        }
    }
}

void Fabryka::wczytaj_obliczenia_objetosci(std::string sciezka_pliku)
{
    std::ifstream plik_we(sciezka_pliku);
    std::vector<std::shared_ptr<Bryla>> bryly_wczytane;
    std::vector<std::shared_ptr<Podstawa>> figury;
    std::string nazwa_bryly;
    std::string nazwa_figury;
    double h;

    if(!plik_we.is_open())
    {
        throw FileNotFoundException(sciezka_pliku);
    }

    else
    {
        plik_we>>nazwa_figury;
        if(nazwa_figury=="<Oblicz_Objetosci>")
        {
            while (!plik_we.eof())
            {
                nazwa_bryly.clear();
                nazwa_figury.clear();
                plik_we >> nazwa_bryly;

                if (Ostroslup::identyfikator_typu_ == nazwa_bryly)
                {
                    plik_we>>nazwa_figury;
                    if (Prostokat::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Prostokat>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                        continue;
                    }
                    if (Trojkat::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Trojkat>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                    }
                    if (Trapez::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Trapez>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                        continue;
                    }
                    if (Kolo::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Kolo>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Ostroslup>(figury.back(),h));
                        continue;
                    }
                    else if(Prostokat::identyfikator_typu_!=nazwa_figury && Prostokat::identyfikator_typu_end_!=nazwa_figury &&
                            Trojkat::identyfikator_typu_ !=nazwa_figury && Trojkat::identyfikator_typu_end_ !=nazwa_figury &&
                            Trapez::identyfikator_typu_ !=nazwa_figury && Trapez::identyfikator_typu_end_!= nazwa_figury &&
                            Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury && nazwa_figury!="")
                    {
                        throw WrongDataException(nazwa_figury);
                    }

                }
                if (Graniastoslup::identyfikator_typu_ == nazwa_bryly)
                {
                    plik_we>>nazwa_figury;
                    if (Prostokat::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Prostokat>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                            bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                            continue;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                    }
                    if (Trojkat::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Trojkat>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                    }
                    if (Trapez::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Trapez>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                        continue;
                    }
                    if (Kolo::identyfikator_typu_ == nazwa_figury)
                    {
                        figury.push_back(std::make_shared<Kolo>());
                        plik_we >>*figury.back();
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Graniastoslup>(figury.back(),h));
                        continue;
                    }
                    else if(Prostokat::identyfikator_typu_!=nazwa_figury && Prostokat::identyfikator_typu_end_!=nazwa_figury &&
                            Trojkat::identyfikator_typu_ !=nazwa_figury && Trojkat::identyfikator_typu_end_ !=nazwa_figury &&
                            Trapez::identyfikator_typu_ !=nazwa_figury && Trapez::identyfikator_typu_end_!= nazwa_figury &&
                            Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury && nazwa_figury!="")
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                }
                if (Walec::identyfikator_typu_ == nazwa_bryly)
                {
                    plik_we>>nazwa_figury;
                    if (Kolo::identyfikator_typu_ == nazwa_figury)
                    {
                        auto k=std::make_shared<Kolo>();
                        plik_we >>*k;
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Walec>(k,h));
                        continue;
                    }
                    else if(Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury
                            && nazwa_figury!="")
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                }
                if (Stozek::identyfikator_typu_ == nazwa_bryly)
                {
                    plik_we>>nazwa_figury;
                    if (Kolo::identyfikator_typu_ == nazwa_figury)
                    {
                        auto k=std::make_shared<Kolo>();
                        plik_we >>*k;
                        plik_we >>nazwa_figury;
                        plik_we>>nazwa_figury;
                        if(nazwa_figury=="<wysokosc>")
                        {
                            plik_we>>h;
                        }
                        else
                        {
                            throw WrongDataException(nazwa_figury);
                        }
                        bryly_wczytane.push_back(std::make_shared<Stozek>(k,h));
                        continue;
                    }
                    else if(Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury
                            && nazwa_figury!="")
                    {
                        throw WrongDataException(nazwa_figury);
                    }
                }
                else if(Ostroslup::identyfikator_typu_ != nazwa_bryly && Ostroslup::identyfikator_typu_end_ != nazwa_bryly &&
                        Graniastoslup::identyfikator_typu_ != nazwa_bryly && Graniastoslup::identyfikator_typu_end_ != nazwa_bryly &&
                        Walec::identyfikator_typu_ != nazwa_bryly && Walec::identyfikator_typu_end_ != nazwa_bryly &&
                        Stozek::identyfikator_typu_ != nazwa_bryly && Stozek::identyfikator_typu_end_ != nazwa_bryly && nazwa_bryly!=""
                        && nazwa_bryly!="</wysokosc>")
                {
                    throw WrongDataException(nazwa_bryly);
                }
            }
            if (bryly_wczytane.empty())
            {
                throw VectorIsEmptyException();
            }
            else
            {
                zapisz_objetosci_bryl_do_pliku(sciezka_pliku,bryly_wczytane);
            }
        }
        else
        {
            throw WrongDataException();
        }
    }
}

std::shared_ptr<Podstawa> Fabryka::stworzProstokat(void)
{
    double a,b;
    std::cout<<"Wybrales prostokat. Podaj wymiary jego bokow\na:";
    std::cin>>a;
    std::cout<<"b:";
    std::cin>>b;
    std::cout<<"Wymiary prostokata:"<<a<<","<<b<<std::endl;
    return std::make_shared<Prostokat>(a,b);
}

std::shared_ptr<Podstawa> Fabryka::stworzTrojkat(void)
{
    double a,h;
    std::cout<<"Wybrales trojkat. Podaj wymiary boku podstawy i wysokosci, ktora jest do niej prostopadla\na:";
    std::cin>>a;
    std::cout<<"h:";
    std::cin>>h;
    std::cout<<"Wymiary trojkata:"<<a<<","<<h<<std::endl;
    return std::make_shared<Trojkat>(a,h);
}

std::shared_ptr<Podstawa> Fabryka::stworzTrapez(void)
{
    double a,b,h;
    std::cout<<"Wybrales trapez. Podaj wymiary jego bokow i wysokosc\na:";
    std::cin>>a;
    std::cout<<"b:";
    std::cin>>b;
    std::cout<<"h:";
    std::cin>>h;
    std::cout<<"Wymiary trapeza:"<<a<<","<<b<<" i wysokosc: "<<h<<std::endl;
    return std::make_shared<Trapez>(a,b,h);
}

std::shared_ptr<Podstawa> Fabryka::stworzKolo(void)
{
    double r;
    std::cout<<"Wybrales kolo. Podaj promien r\nr:";
    std::cin>>r;
    std::cout<<"Promien r kola :"<<r<<std::endl;
    return std::make_shared<Kolo>(r);
}

std::shared_ptr<Kolo> Fabryka::stworzKolo2(void)
{
    double r;
    std::cout<<"Podaj promien r\nr:";
    std::cin>>r;
    std::cout<<"Promien r kola :"<<r<<std::endl;
    return std::make_shared<Kolo>(r);
}
double Fabryka::wysokosc(void)
{
    double h_;
    std::cout<<"Podaj wartosc wysokosci h\nh:";
    std::cin>> h_;
    return h_;
}

std::shared_ptr<Bryla> Fabryka::stworzGraniastoslup(std::shared_ptr<Podstawa> p, double h)
{
    return std::make_shared<Graniastoslup>(p,h);
}
std::shared_ptr<Bryla> Fabryka::stworzOstroslup(std::shared_ptr<Podstawa> p, double h)
{
    return std::make_shared<Ostroslup>(p,h);
}
std::shared_ptr<Bryla> Fabryka::stworzWalec(std::shared_ptr<Kolo> p,double h)
{
    return std::make_shared<Walec>(p,h);
}
std::shared_ptr<Bryla> Fabryka::stworzStozek(std::shared_ptr<Kolo> p,double h)
{
    return std::make_shared<Stozek>(p,h);
}

void Fabryka::wczytaj_bryly(std::string s)
{
    Fabryka f;
    auto bryly_wczytane=wczytaj_plik_z_brylami(s);
    for (auto it = bryly_wczytane.begin(); it != bryly_wczytane.end(); ++it)
    {
        std::cout<< **it<<std::endl;
    }
}

void Fabryka::wczytaj_figury(std::string s)
{
    Fabryka f;
    auto figury_wczytane=wczytaj_plik_z_figurami(s);
    for (auto it = figury_wczytane.begin(); it != figury_wczytane.end(); ++it)
    {
        std::cout<< **it<<std::endl;
    }
}

int Fabryka::obliczenia(void)
{
    std::vector<std::shared_ptr<Bryla>> bryly;
    std::vector<std::shared_ptr<Podstawa>> figury;
    std::string sciezka_pliku_1;
    std::string sciezka_pliku_2;
    std::string dane;
    int dane_;
    std::string str2 (".txt");

    std::cout<<"Program wykonuje rozne operacje na figurach p³askich oraz bry³ach."<<std::endl;
    std::cout<<"Wpisz nazwe pliku .txt, do ktorego chcesz zapisac obliczenia zwiazane z figurami"<<std::endl;
    std::cin>>sciezka_pliku_1;
    if (sciezka_pliku_1.find(str2)==std::string::npos)
    {
        std::cout<<"Nie podano nazwy pliku z odpowiednim rozszerzeniem .txt"<<std::endl;
        throw WrongDataException(sciezka_pliku_1);
    }
    else
        std::cout<<"Wpisz nazwe pliku .txt, do ktorego chcesz zapisac obliczenia zwiazane z brylami"<<std::endl;
    std::cin>>sciezka_pliku_2;
    if (sciezka_pliku_2.find(str2)==std::string::npos)
    {
        std::cout<<"Nie podano nazwy pliku z odpowiednim rozszerzeniem .txt"<<std::endl;
        throw WrongDataException(sciezka_pliku_2);
    }
    else
        while(dane_!=5)
        {
            std::cout<<"Wybierz pozadana akcje, jaka chcesz wykonac:\n1.Obliczenie pola powierzchni figury plaskiej\n2.Obliczanie objetosci bryly\n3.Koniec programu-wcisnij 5"<<std::endl;
            std::cin>>dane_;
            if(dane_==1)
            {
                std::cout<<"Wybrales obliczanie pola powierzchni figury plaskiej"<<std::endl;
                std::cout<<"Wybierz rodzaj figury plaskiej"<<std::endl;
                std::cout<<"1.Prostokat\n2.Trojkat\n3.Trapez\n4.Kolo"<<std::endl;
                std::cin>>dane_;
                if(dane_==1)
                {
                    auto p = stworzProstokat();
                    std::cout<<"Pole prostokata: "<<p->Pole()<<std::endl;
                    figury.push_back(p);
                }
                else if(dane_==2)
                {
                    auto t = stworzTrojkat();
                    std::cout<<"Pole trojkata: "<<t->Pole()<<std::endl;
                    figury.push_back(t);
                }
                else if(dane_==3)
                {
                    auto k = stworzTrapez();
                    std::cout<<"Pole trapeza: "<<k->Pole()<<std::endl;
                    figury.push_back(k);
                }
                else if(dane_==4)
                {
                    auto o = stworzKolo();
                    std::cout<<"Pole kola: "<<o->Pole()<<std::endl;
                    figury.push_back(o);

                }
                else
                {
                }
            }
            else if(dane_==2)
            {
                std::cout<<"Wybrales obliczanie objetosci bryly"<<std::endl;
                std::cout<<"Wybierz rodzaj bryly"<<std::endl;
                std::cout<<"1.Graniastoslup\n2.Ostroslup\n3.Walec\n4.Stozek"<<std::endl;
                std::cin>>dane_;
                if(dane_==1)
                {
                    std::cout<<"Wybrales graniastoslup.Teraz wybierz jego podstawe :";
                    std::cout<<"\n1.Prostokat\n2.Trojkat\n3.Trapez";
                    std::cin>>dane_;
                    if(dane_==1)
                    {
                        auto p  =stworzProstokat();
                        double h = wysokosc();
                        auto g = stworzGraniastoslup(p,h);
                        std::cout<<"Objetosc graniastoslupa: "<<g->Objetosc()<<std::endl;
                        bryly.push_back(g);
                    }
                    else if(dane_==2)
                    {
                        auto p = stworzTrojkat();
                        double h = wysokosc();
                        auto g = stworzGraniastoslup(p,h);
                        std::cout<<"Objetosc graniastoslupa: "<<g->Objetosc()<<std::endl;
                        bryly.push_back(g);
                    }
                    else if(dane_==3)
                    {
                        auto p = stworzTrapez();
                        double h = wysokosc();
                        auto g = stworzGraniastoslup(p,h);
                        std::cout<<"Objetosc graniastoslupa: "<<g->Objetosc()<<std::endl;
                        bryly.push_back(g);
                    }
                    else
                    {
                    }
                }
                else if(dane_==2)
                {
                    std::cout<<"Wybrales ostroslup.Teraz wybierz jego podstawe :";
                    std::cout<<"\n1.Prostokat\n2.Trojkat\n3.Trapez";
                    std::cin>>dane_;
                    if(dane_==1)
                    {
                        auto p  =stworzProstokat();
                        double h = wysokosc();
                        auto g = stworzOstroslup(p,h);
                        std::cout<<"Objetosc ostroslupa: "<<g->Objetosc()<<std::endl;
                        bryly.push_back(g);
                    }
                    else if(dane_==2)
                    {
                        auto p = stworzTrojkat();
                        double h = wysokosc();
                        auto g = stworzOstroslup(p,h);
                        std::cout<<"Objetosc ostroslupa: "<<g->Objetosc()<<std::endl;
                        bryly.push_back(g);
                    }
                    else if(dane_==3)
                    {
                        auto p = stworzTrapez();
                        double h = wysokosc();
                        auto g = stworzOstroslup(p,h);
                        std::cout<<"Objetosc ostroslupa: "<<g->Objetosc()<<std::endl;
                        bryly.push_back(g);
                    }
                    else
                    {
                    }
                }
                else if(dane_==3)
                {
                    std::cout<<"Wybrales walec.";
                    auto p = stworzKolo2();
                    double h = wysokosc();
                    auto g = stworzWalec(p,h);
                    std::cout<<"Objetosc walca: "<<g->Objetosc()<<std::endl;
                    bryly.push_back(g);
                }
                else if(dane_==4)
                {
                    std::cout<<"Wybrales stozek.";
                    auto p = stworzKolo2();
                    double h = wysokosc();
                    auto g = stworzStozek(p,h);
                    std::cout<<"Objetosc stozka: "<<g->Objetosc()<<std::endl;
                    bryly.push_back(g);
                }
                else
                {
                }

            }
            else if(dane_==5)
            {
                std::cout<<"Wcisnales 5";
                Fabryka f;
                f.zapisz_pola_figur_do_pliku(sciezka_pliku_1,figury);
                std::cout<<"Zapisano pola figur do pliku: "<<sciezka_pliku_1<<std::endl;
                f.zapisz_objetosci_bryl_do_pliku(sciezka_pliku_2,bryly);
                std::cout<<"Zapisano objetosci bryl do pliku: "<<sciezka_pliku_2<<std::endl;
                std::cout<<"Koniec programu!";
                return 0;
            }
            else
            {
                throw WrongDataException();
            }

        }
    return 0;
}


void Fabryka::find_pole(std::string s)
{
    std::cout<<"Funkcja znajdujaca najwieksze i najmniejsze pole figur w pliku"<<std::endl;
    Fabryka f;
    unsigned int minpos,maxpos;
    auto figury_wczytane=f.wczytaj_plik_z_figurami(s);
    double smallest_element = figury_wczytane[0]->Pole();
    double largest_element = figury_wczytane[0]->Pole();
    for(unsigned int i = 1; i < figury_wczytane.size(); i++)
    {
        if(figury_wczytane[i]->Pole() < smallest_element)
        {
            smallest_element = figury_wczytane[i]->Pole();
            minpos=i;
        }
        if(figury_wczytane[i]->Pole() > largest_element)
        {
            largest_element = figury_wczytane[i]->Pole();
            maxpos=i;
        }
    }
    std::cout<<"Najmniejsze pole : "<<smallest_element<<" dla : "<<figury_wczytane[minpos]->identyfikatorTypu()<<std::endl;
    std::cout<<"Najwieksze pole : "<<largest_element<<" dla : "<<figury_wczytane[maxpos]->identyfikatorTypu()<<std::endl;
}

void Fabryka::find_objetosc(std::string s)
{
    std::cout<<"Funkcja znajdujaca najwieksza i najmniejsza objetosc bryl w pliku"<<std::endl;
    Fabryka f;
    unsigned int minpos,maxpos;
    auto bryly_wczytane=f.wczytaj_plik_z_brylami(s);
    double smallest_element = bryly_wczytane[0]->Objetosc();
    double largest_element = bryly_wczytane[0]->Objetosc();
    for(unsigned int i = 1; i < bryly_wczytane.size(); i++)
    {
        if(bryly_wczytane[i]->Objetosc()< smallest_element)
        {
            smallest_element = bryly_wczytane[i]->Objetosc();
            minpos=i;
        }
        if(bryly_wczytane[i]->Objetosc() > largest_element)
        {
            largest_element = bryly_wczytane[i]->Objetosc();
            maxpos=i;
        }
    }
    std::cout<<"Najmniejsza objetosc : "<<smallest_element<<" dla : "<<bryly_wczytane[minpos]->identyfikatorTypu()<<std::endl;
    std::cout<<"Najwieksza objetosc : "<<largest_element<<" dla : "<<bryly_wczytane[maxpos]->identyfikatorTypu()<<std::endl;
}

void Fabryka::wczytaj_obliczenia_pola(std::string sciezka_pliku)
{
    std::vector<std::shared_ptr<Podstawa>> figury_wczytane;
    std::string nazwa_figury;
    std::ifstream plik_we(sciezka_pliku);
    if(!plik_we.is_open())
    {
        throw FileNotFoundException(sciezka_pliku);
    }
    else
    {
        plik_we>>nazwa_figury;
        if(nazwa_figury=="<Oblicz_Pola>")
        {
            while (!plik_we.eof())
            {
                nazwa_figury.clear();
                plik_we >> nazwa_figury;

                if (Prostokat::identyfikator_typu_ == nazwa_figury)
                {
                    figury_wczytane.push_back(std::make_shared<Prostokat>());
                    plik_we >> *(figury_wczytane.back());
                    continue;
                }
                if (Trojkat::identyfikator_typu_ == nazwa_figury)
                {
                    figury_wczytane.push_back(std::make_shared<Trojkat>());
                    plik_we >> *(figury_wczytane.back());
                    continue;
                }
                if (Trapez::identyfikator_typu_ == nazwa_figury)
                {
                    figury_wczytane.push_back(std::make_shared<Trapez>());
                    plik_we >> *(figury_wczytane.back());
                    continue;
                }
                if (Kolo::identyfikator_typu_ == nazwa_figury)
                {
                    figury_wczytane.push_back(std::make_shared<Kolo>());
                    plik_we >> *(figury_wczytane.back());
                    continue;
                }
                else if(Prostokat::identyfikator_typu_!=nazwa_figury && Prostokat::identyfikator_typu_end_!=nazwa_figury &&
                        Trojkat::identyfikator_typu_ !=nazwa_figury && Trojkat::identyfikator_typu_end_ !=nazwa_figury &&
                        Trapez::identyfikator_typu_ !=nazwa_figury && Trapez::identyfikator_typu_end_!= nazwa_figury &&
                        Kolo::identyfikator_typu_ != nazwa_figury && Kolo::identyfikator_typu_end_ != nazwa_figury && nazwa_figury!="")
                {
                    throw WrongDataException(nazwa_figury);
                }
            }
            if (figury_wczytane.empty())
            {
                throw VectorIsEmptyException();
            }
            else
            {
                zapisz_pola_figur_do_pliku(sciezka_pliku,figury_wczytane);
            }
        }
        else
        {
            throw WrongDataException();
        }
    }
}


