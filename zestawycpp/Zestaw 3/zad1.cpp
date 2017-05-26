#include <iostream>

using namespace std;

float x1, y1, z1, x2, y2, z2;
float x, y;

void obliczenia()
{
    float W0, W1, W2;
    
    W0 = x1 * x2 - z1 * y1;
    W1 = x2 * y2 - y1 * z2;
    W2 = x1 * z2 - z1 * y2;
    
    cout << "W0 = " << W0 << "\n" << "W1 = " << W1 << "\n" << "W2 = " << W2 << "\n" << endl;
    
    if( W0 != 0 ){
        x = W1 / W0;
        y = W2 / W0;
        cout << "Uklad oznaczony o rozwiazaniu: \n" << x << "\n" << y << endl;
    } else if(( W0 == 0 ) &&( W1 == 0 ) &&( W2 == 0 ) ) {
        cout << "Uklad nieoznaczony" << endl;
    } else if( W0 == 0 &&( W1 != 0 || W2 != 0 ) ) {
        cout << "Uklad sprzeczny" << endl;
    }
    
}

void wspolczynniki()
{
    
    cout << "Podaj wspolczynniki:" << endl;
    cout << "x1 = " << endl;
    cin >> x1;
    cin.get();
    
    cout << "y1 = " << endl;
    cin >> y1;
    cin.get();
    
    cout << "z1 = "<< endl;;
    cin >> z1;
    cin.get();
    
    cout << "x2 = "<< endl;;
    cin >> x2;
    cin.get();
    
    cout << "y2 = "<< endl;;
    cin >> y2;
    cin.get();
    
    cout << "z2 = "<< endl;;
    cin >> z2;
    cin.get();
    
    cout << "Twój uklad rownan ma postac: "<< endl;
    cout << x1 <<"x + "<< y1 << "y = "<< z1 << endl;
    cout << x2 <<"x + "<< y2 << "y = "<< z2 << endl;
    cout << "\n" << endl;
    
    obliczenia();
}

int main()
{
    cout << "Program uzywa metody Cramera" << endl;
    cout << "Podaj wspolczynniki rownania \n" << endl;
    wspolczynniki();
}
