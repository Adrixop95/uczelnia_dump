#include <iostream>
#include <cmath>

using namespace std;

bool trojkapitagorejska(int a, int b, int c) {
    return (a * a + b * b == c * c);
}

bool czyistnieje(int a, int b, int c) {
    if (c > b && c > a){
        return trojkapitagorejska(a, b, c);
    }
    return czyistnieje(b, c, a);
}

int znajdz(int a1, int a2) {
    double c = sqrt( a1 * a1 + a2 * a2 );
    if (c == int(c)){
        return c;
    }
    double b = sqrt(abs(a1 * a1 - a2 * a2));
    if (b == int(b)){
        return b;
    }
    return 0;
}

int NWD(int a, int b) {
    if (a == 0){
        return b;
    }
    return NWD(b%a, a);
}

bool pierwotna(int a, int b, int c) {
    return NWD(NWD(a, b), c) == 1;
}

int main () {
    int ilosc;
    
    cout << "Podaj liczbe: " << endl;
    cin >> ilosc;
    
    for (int i = 3; i < ilosc; i++) {
        for (int j = i; j < 1000; j++) {
            int c = znajdz(i, j);
            if (i <= j && j <= c && c != 0) {
                cout << i << ", " << j << ", " << c << endl;
                continue;
            }
        }
    }
    
    cin.get();
    return 0;
}