#include <iostream>

using namespace std;

class wskaznik{
private:
    int *wsk;
    
public:
    wskaznik();
    void utworz(int);
    int* zwroc();
    void zwolnij();
    void kopiuj(wskaznik&);
    ~wskaznik();
};

wskaznik::wskaznik(){
    wsk=NULL;
}

void wskaznik::utworz(int n){
    wsk = new int[n];
}

int* wskaznik::zwroc(){
    return wsk;
}

void wskaznik::zwolnij(){
    delete [] wsk;
    wsk = NULL;
}

void wskaznik::kopiuj(wskaznik & ref){
    ref.wsk=wsk;
}

wskaznik::~wskaznik(){
    if (wsk!=NULL){
        delete [] wsk;
    }
}


int main(){

    wskaznik wsk;
    cout << "Wartosc przed deklaracja: " << wsk.zwroc()<< endl;

    wsk.utworz(10);
    cout << "Warosc po stworzeniu 10 elementow: " << wsk.zwroc() << endl;

    wsk.zwolnij();
    cout << "Wartosc po zwolnieniu: " << wsk.zwroc() << endl;
    
    cin.get();
    return 0;
}