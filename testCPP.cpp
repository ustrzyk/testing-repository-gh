/******************************************************************************

C++ programowanie  obiektowe Wyklad Funkcje Wirtualne 1

*******************************************************************************/
#include <iostream>
using namespace std;

class Osoba 
{
    private:
        string imie;
        string nazwisko;
    public:
        Osoba(string imie,string nazwisko)
        :imie(imie),nazwisko(nazwisko)
        {
        }
        // Funkcja Drukuj() jest virtualna poniewarz w klacie Ksiegowosc funkcja DrukujPIT() wywwołuje te Funkcje
        // i ma byc wywoływana z tej klasy która reprezentuje obiekt
        virtual void Drukuj() const
        {
            cout<<endl<<"Imie i nazwisko: "<<imie<<" "<<nazwisko;
        }
};

class Pracownik: public Osoba 
{
    private:
        string stanowisko;
    public:
        Pracownik(string _imie,string _nazwisko,string _stanowisko)
        :Osoba(_imie,_nazwisko),stanowisko(_stanowisko)
        {
        }
        void Drukuj() const
        {
            Osoba::Drukuj();
            cout<<endl<<"Stanowisko: "<<stanowisko;
        }
        virtual double DochodyRoczne()
        {
            return 0;
        }
    
};
class PracownikEtatowy:public Pracownik
{
    private:
        double placaBrutto;
    public:
        PracownikEtatowy(string imie,string nazwisko,string stanowisko,double placaBrutto)
        :Pracownik(imie,nazwisko,stanowisko),placaBrutto(placaBrutto)
        {
        }
        // Funkcja Drukuj() jest virtualna poniewarz w klacie Ksiegowosc funkcja DrukujPIT() wywwołuje te Funkcje
        // i ma byc wywoływana z tej klasy która reprezentuje obiekt PracownikEtatowy
        void Drukuj() const
            {
                Pracownik::Drukuj();
                cout<<endl<<"Placa Brutto: "<<placaBrutto;
            }
        // funkcja dochody DochodyRoczne() jest funkcja virtualną
        double DochodyRoczne()
        {
            return placaBrutto*12;
        }    
};
class PracownikGodzinowy :public Pracownik
{
    private:
        double liczbaGodzin;
        double stawkaGodzinowa;
    public:
        PracownikGodzinowy(string imie,string nazwisko,string stanowisko,double liczbaGodzin,double stawkaGodzinowa)
        :Pracownik(imie,nazwisko,stanowisko),liczbaGodzin(liczbaGodzin),stawkaGodzinowa(stawkaGodzinowa)
        {
        }
        // Funkcja Drukuj() jest virtualna poniewarz w klacie Ksiegowosc funkcja DrukujPIT() wywwołuje te Funkcje
        // i ma byc wywoływana z tej klasy która reprezentuje obiekt PracownikGodzinowy
        void Drukuj() const
        {
            Pracownik::Drukuj();// wywolanie metody Drukuj() z klasy Pracownik, wyswietlenie nazwiska i stanowiska
            cout<<endl<<"Liczba godzin: "<<liczbaGodzin;
            cout<<endl<<"Stawka Godzinowa: "<<stawkaGodzinowa;
        }
                double DochodyRoczne()
        {
            return liczbaGodzin*stawkaGodzinowa;
        }
        
};
class Ksiegowosc
{
    public:
    void DrukujPIT(Pracownik &p) 
    {
        cout<<endl;
        cout<<endl<<"PIT-11";
        cout<<endl<<"Dane podatnika: ";
        p.Drukuj();
        cout<<endl<<"Dochody roczne podatnika: "<<p.DochodyRoczne();
        cout<<endl;
    }
};
int main()
{
    Ksiegowosc ksiegowosc;
    
    Pracownik p1("Tomek","Pracownik","Kierownik");
    ksiegowosc.DrukujPIT(p1);
    
    
    PracownikEtatowy pe1("Tomek","Etatowy","Kierownik",6000);
    ksiegowosc.DrukujPIT(pe1);
    
    
    PracownikGodzinowy pg1("Tomek","Godzinowy","Kierownik",400,200);
    ksiegowosc.DrukujPIT(pg1);
    
    
    return 0;
}
// dodano zmiany