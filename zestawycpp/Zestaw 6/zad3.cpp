#include <iostream>
#include <vector>
#include <string>

using namespace std;

class osoba{
private:
    string imie, nazwisko;
    
public:
    osoba(string, string);
    void wczytaj();
    void wypisz();
};

class tab_osoba{
private:
    osoba ** tab;
    int rozmiar;
public:
    tab_osoba(int, string, string);
    osoba& at(int);
    ~tab_osoba();
};

tab_osoba::tab_osoba(int n, string imie, string nazwisko){
    tab = new osoba*[n];
    rozmiar = n;
    for(int i = 0; i < n; i++){
        tab[i] = new osoba(imie, nazwisko);
    }
}

osoba::osoba(string im, string nazw){
    imie=im;
    nazwisko=nazw;
}

void osoba::wczytaj(){
    cout <<"Podaj imie: ";
    cin >> imie;
    cout <<"Podaj nazwisko: ";
    cin >> nazwisko;
}

void osoba::wypisz(){
    cout << "Imie " << imie << endl;
    cout << "Nazwisko " << nazwisko << endl;
}

vector<osoba> ZrobWektor(int n){
    return vector<osoba>(n, osoba("Jan", "Kowalski"));
}

osoba& tab_osoba::at(int i){
    return *tab[i];
}

tab_osoba::~tab_osoba(){
    
    for(int i = 0; i < rozmiar; i++){
        delete tab[i];
    }
    tab = NULL;
    delete [] tab;
}

int main(){
    tab_osoba tabb(10, "Adrian", "Rupala");
    osoba osob = tabb.at(5);
    osob.wczytaj();
    
    cin.get();
    return 0;
}