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

int main(){
    vector<osoba> x = ZrobWektor(10);
    
    cout << "Vektor zawiera:";
    for (int i = 0; i < x.size(); i++){
        cout << " " << &x.at(i);
    }
    
    
    cin.get();
    return 0;
}