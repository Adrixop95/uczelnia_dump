#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <sstream>
#include <limits>
#include <cstring>
#include <cstddef>


using namespace std;

string user = "", name;
int cena, sum_cal, podatek_sum, promocja_sum;

void stworz_plik(){
    ofstream outfile ("przedmioty.txt");
}


void dodaj_do_pliku(){
    string przedmiot;
    size_t lines_count =1;
    ifstream aFile("przedmioty.txt");
    
    string num_line,s;
    
   	while (std::getline(aFile , num_line))
        ++lines_count;
    
    cout << "Podaj nazwe przedmiotu: " << endl;
    cin >> przedmiot;
    
    cout << "Podaj cene za sztuke: " << endl;
    cin >> cena;
    
    ofstream log("przedmioty.txt", std::ios_base::app | std::ios_base::out);
    
    log << "Numer katalogowy: " << lines_count << " "
    "Przedmiot: "<< przedmiot << " "
    "Cena za sztuke: "<< cena <<"\n";
}

void stworz_rachunek(){
    string kupujacy;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    
    cout << "Podaj swoje imie: " << endl;
    cin >> kupujacy;
    
    char buf[16];
    snprintf(buf, 16, "%lu", time(NULL));
    
    name = "paragon_" + kupujacy + buf+ ".txt";
    
    ofstream outfile (name);
    
    ofstream log(name, std::ios_base::app | std::ios_base::out);
    
    log << "Rachunek na dzien: " <<(now->tm_year + 1900) << '-'
    << (now->tm_mon + 1) << '-'
    <<  now->tm_mday <<"\n";
    
    log << "Przedmiot:" << " " << "Cena za sztuke:" <<"\n";
}

void dodaj_do_rachunku(){
   	ifstream aFile("przedmioty.txt");
    
   	size_t lines_count =0;
   	string num_line,s;
   	int numlin, ilosc;
    
   	while (std::getline(aFile , num_line))
        ++lines_count;
    
    cout << "Jaki produkt chcesz dodac do rachunku? (numer produktu)" << endl;
    cin >> numlin;
    
    cout << "Ile sztuk chcesz zamowic?" << endl;
    cin >> ilosc;
    
    std::ifstream f("przedmioty.txt");
    
    for (int i = 1; i <= numlin; i++)
        std::getline(f, s);
    
    std::cout << "Wybrales: " << s;
    
    ofstream outfile;
    outfile.open(name, std::ios_base::app);
    outfile << s << " Ilosc: "<< ilosc <<"\n";
}

void cena_wlasciwa(){
    ifstream is {name};
    int x,y,z;
    vector<string> v {istream_iterator<string>{is},istream_iterator<string>{}};
    
    for (int i=0; i<v.size();i++){
        for(int j = 0; j < v.size();j++){
            if(v[i] == "sztuke:" && v[j] == "Ilosc:"){
                x = atoi(v[i+1].c_str());
                y = atoi(v[j+1].c_str());
                z=x*y;
                sum_cal = sum_cal+z;
                cout << "Suma bez podatku: " << sum_cal << endl;
            }
        }
    }
}

void podatek(){
    podatek_sum = sum_cal + sum_cal * 23 / 100;
    cout << "Do zaplaty z podatkiem: " << podatek_sum << endl;
}

void promocja_z_podatkiem(){
    int promocja;
    
    cout << "Ile procent ma wynosic promocja?" << endl;
    cin >> promocja;
    
    promocja_sum = podatek_sum - podatek_sum * promocja / 100;
    cout <<  "Do zaplaty z promocja i podatkiem: " << promocja_sum << endl;
}


void wyswietl_plik(){
    ifstream f("przedmioty.txt");
    if (f.is_open()){
        cout << f.rdbuf();
    }
}

void wyswietl_rachunek(){
    ifstream f(name);
    if (f.is_open()){
        cout << f.rdbuf();
    }
}

void logowanie(){
    string pass = "";
    bool loginsucc = false;
    
    cout << "Zaloguj sie do systemu!" << endl;
    
    do {
        cout << "Podaj nazwe uzytkownika: ";
        cin >> user;
        cout << "Podaj haslo: ";
        cin >> pass;
        
        if (user == "user" && pass == "zxczxc"){
            cout << "Witaj " << user << "\n";
            loginsucc = true;
        } else if (user == "admin" && pass == "zxczxc"){
            cout << "Witaj " << user << "\n";
            loginsucc = true;
        } else{
            cout << "Sprobuj ponownie!" << endl;
        }
        
    }while(!loginsucc);
}

int main(){
    cout << "Witaj w sklepie!" << endl;
    int wybor;
    bool checkloop = false;
    logowanie();
    
    do {
        if (user == "admin"){
            cout << "\nCo chcesz zrobić? \n(0 - utworz plik przedmiotow (usuwa wczesniejszy), 1 - dodaj przedmiot, 2 - wyswietl przedmioty w pliku/napraw plik, 99999 - wyjscie)" << endl;;
            cin >> wybor;
            
            if(wybor == 0){
                stworz_plik();
            } else if (wybor == 1){
                dodaj_do_pliku();
            } else if (wybor == 2){
                wyswietl_plik();
            } else if (wybor == 99999) {
                checkloop = true;
            } else {
                cout << "Sprobuj ponownie!" << endl;
            }
        } else if (user == "user"){
            cout << "\nCo chcesz zrobić? \n(0 - pokaz przedmioty, 1 - stworz swoj rachunek, 2 - pokaz rachunek, 3 - dodaj do rachunku, 4 - suma 99999 - wyjscie)" << endl;;
            cin >> wybor;
            
            if(wybor == 0){
                wyswietl_plik();
            } else if (wybor == 1){
                stworz_rachunek();
            } else if (wybor == 2){
                wyswietl_rachunek();
            } else if (wybor == 99999) {
                checkloop = true;
            } else if (wybor == 3){
                dodaj_do_rachunku();
            } else if (wybor == 4) {
                cena_wlasciwa();
                podatek();
                promocja_z_podatkiem();
            } else {
                cout << "Sprobuj ponownie!" << endl;
            }
            
        }
    } while (!checkloop);
    
    cin.get();
    return 0;
}