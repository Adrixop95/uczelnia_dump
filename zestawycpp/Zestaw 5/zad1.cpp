#include <iostream>

using namespace std;

struct trojkat{
    double a,b,c;
};

double obwod(trojkat t){
    return t.a+t.b+t.c;
}

int main(){
    
    trojkat triangle;
    cout << "Podaj a: " << endl;
    cin >> triangle.a;
    
    cout << "Podaj b: " << endl;
    cin >> triangle.b;
    
    cout << "Podaj c: " << endl;
    cin >> triangle.c;
    
    cout << obwod(triangle) << endl;
    
    cin.get();
    return 0;
}