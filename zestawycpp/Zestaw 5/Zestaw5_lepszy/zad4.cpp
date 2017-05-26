#include <iostream>
#include <string>

using namespace std;

struct dane_osobowe{
    string imie, nazwisko, plec, stan_cywilny;
};

void wczytaj(struct dane_osobowe tab[], int n){
    int i, d;
    
    for (i = 0; i < n; i++){
        cout << "Podajesz dane osobowe kobiety czy mezczyzny? (Kobieta - 1, Mezczyzna - 2)" << endl;
        cin >> d;
        
        cout << "Podaj imie: " << endl;
        cin >> tab[i].imie;
        
        cout << "Podaj nazwisko: " << endl;
        cin >> tab[i].nazwisko;
        
        if (d == 1){
            tab[i].plec = "Kobieta";
            cout << "Czy wyszlas za maz? (tak (1), nie (0)" << endl;
            cin >> i;
            if (i == 1){
                tab[i].stan_cywilny = "Mezatka";
            } else if (i == 0){
                tab[i].stan_cywilny = "Wolna";
            }
        } else if (d == 2){
            tab[i].plec = "Mezczyzna";
            cout << "Czy ozeniles sie? (tak (1), nie (0)" << endl;
            cin >> i;
            if (i == 1){
                tab[i].stan_cywilny = "Zonaty";
            } else if (i == 0){
                tab[i].stan_cywilny = "Wolny";
            }
            
        }
    }
}

int main(){
    dane_osobowe informacje[2];
    wczytaj(informacje, 2);
    
    cin.get();
    return 0;
}