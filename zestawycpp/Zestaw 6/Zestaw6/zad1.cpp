#include <iostream>

using namespace std;

class osoba{
private:
    string imie, nazwisko;
    
public:
    osoba(string, string);
    void wczytaj();
    void wypisz();
};

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

int main(){
    
    osoba os("xxx","yyy");
    os.wypisz();

    
    os.wczytaj();
    os.wypisz();
    
    cin.get();
    return 0;
}