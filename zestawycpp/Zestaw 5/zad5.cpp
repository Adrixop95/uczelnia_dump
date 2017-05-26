#include <iostream>
#include <cmath>

using namespace std;

class liczba{
    int wart_licz;

public:
    void wczytaj();
    void wypisz();
    void nadaj_w(int);
    int wartosc();
    unsigned int abs();
};

void liczba::wczytaj(){
    cin >> wart_licz;
}

void liczba::wypisz(){
    cout << wart_licz;
}

void liczba::nadaj_w(int n){
    wart_licz = n;
}

int liczba::wartosc(){
    return wart_licz;
}

unsigned int liczba::abs(){
    if (wart_licz >= 0){
        return wart_licz;
    } else {
        return -wart_licz;
    }
}

int main(){
    
    liczba licz;
    int n = 0;
    
    cout << "Podaj liczbe: " << endl;
    licz.wczytaj();
    cout << "Wypisz liczbe: " << endl;
    licz.wypisz();
    cout << "Nadaj wartosc liczby (-20)" << endl;
    licz.nadaj_w(-20);
    cout << "Wartosc liczby: " << endl;
    licz.wartosc();
    cout << "abs: " << endl;
    licz.abs();
    
    cin.get();
    return 0;
}