#include <iostream>

using namespace std;

class punkt{
    int x,y;
    friend punkt rzutuj(punkt3);
public:
    void rzutuj(punkt3);
    void wczytaj();
    void wypisz();
};

class punkt3{
    int x,y,z;
    friend punkt rzutuj(punkt3);
    friend void punkt::rzutuj(punkt3);
public:
    void wczytaj();
    void wypisz();
};

void punkt::wczytaj(){
    cout << "Podaj wspolrzedne punktu: " << endl;
    cin >> x >> y;
}

void punkt::wypisz(){
    cout << "Wspolrzedne punktu to: " << x << " " << y << endl;
}

void punkt3::wczytaj(){
    cout << "Podaj wspolrzedne punktu: " << endl;
    cin >> x >> y >> z;
}

void punkt3::wypisz(){
    cout << "Wspolrzedne punktu to: " << x << " " << y << " " << z << endl;
}

punkt rzutuj (punkt3 p3){
    punkt p2;
    p2.x=p3.x;
    p2.y=p3.y;
    return p2;
}

void punkt::rzutuj(punkt3 p3){
    x=p3.x;
    y=p3.y;
}

int main(){
    
    cin.get();
    return 0;
}