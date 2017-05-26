#include <iostream>

using namespace std;

class kolejka{
private:
    struct element{
        int liczba;
        element * nastepny;
    };
    element *pierw, *ostatni;
public:
    kolejka();
    kolejka(const kolejka &);
    ~kolejka();
    int pierwszy ();
    void usun_pierwszy();
    void dodaj_na_koniec(int);
    bool pusta();
};

kolejka::kolejka(){
    pierw=ostatni=NULL;
}

kolejka::kolejka(const kolejka & kol){
    if(kol.pierw == kol.ostatni){
        pierw = ostatni = NULL;
    } else {
        element *pom;
        pom = kol.pierw;
        pierw = new element;
        pierw -> liczba=pom -> liczba;
        ostatni=pierw;
        
        while(pom!=kol.ostatni){
            pom=pom->nastepny;
            ostatni -> nastepny = new element;
            ostatni = ostatni -> nastepny;
            ostatni -> liczba = pom -> liczba;
        }
    }
}

kolejka::~kolejka(){
    if (pierw!=NULL){
        element *pom;
        
        while (pierw != ostatni){
            pom=pierw;
            pierw=pierw -> nastepny;
            delete pom;
        }
        delete pierw;
    }
}

int kolejka::pierwszy(){
    return pierw -> liczba;
}

void kolejka::usun_pierwszy(){
    element* pom=pierw;
    
    if (pierw == ostatni){
        pierw = ostatni = NULL;
    } else{
        pierw = pierw -> nastepny;
    }
    delete pom;
}

void kolejka::dodaj_na_koniec(int liczba){
    if(ostatni != NULL){
        ostatni -> nastepny = new element;
        ostatni = ostatni -> nastepny;
    } else {
        ostatni = pierw = new element;
    }
    ostatni -> liczba = liczba;
}

bool kolejka::pusta(){
    return (pierw == NULL);
}


int main(){
    
    kolejka kol;
    int x;
    
    cout << "podaj liczbe: " << endl;
    cin >> x;
    
    
    kol.dodaj_na_koniec(x);
    kol.pierwszy();
    kol.pusta();
    kol.usun_pierwszy();
    
    cin.get();
    return 0;
}