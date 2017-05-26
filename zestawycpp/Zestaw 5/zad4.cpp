#include <iostream>
#include <string>

using namespace std;

struct dane_osobowe{
    string imie, nazwisko, plec, stan_cywilny;
};

void wczytaj(struct dane_osobowe tab[], int n){
    int i, d;
    
    for (i = 0; i < n; i++){
        cout <<"Czy teraz wpisujesz dane osobne kobiety (1) czy mężczyny (2)?" << endl;
        cin >> d;
        
        if (d == 1){
            tab[i].plec= "kobieta";
        } else {
            tab[i].plec= "mezczyzna";
        }
        
        cout << "Podaj imie" << endl;
        cin >> tab[i].imie;
        
        cout << "Podaj nazwysko" << endl;
        cin >> tab[i].nazwisko;
        
        cout << "Podaj stan cywilny" << endl;
        
        if (tab[i].plec=="kobieta"){
            cout << "Wolna (0), mezatka (1)" << endl;
            cin >> d;
            
            if (d == 0){
                tab[i].stan_cywilny="wolna";
            } else {
                tab[i].stan_cywilny="mezatka";
            }
        } else {
            cout << "Wolny (=), zonaty (1)" << endl;
            cin >> d;
            
            if (d == 0){
                tab[i].stan_cywilny="wolny";
            } else {
                tab[i].stan_cywilny="zonaty";
            }
        }
    }
}

int main(){
    
    dane_osobowe informacje[3];
    wczytaj(informacje, 3);
    
    cin.get();
    return 0;
}