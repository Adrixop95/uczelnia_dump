#include <iostream>

using namespace std;

double pot1(double n, unsigned int m){
    double p = 1;
    if (n == 0)
        return 0;
    for (int i = 1; i <= m; i++)
        p+=n;
    return p;
}

int pot2(int n, unsigned int m){
    int p = 1;
    if (n==0)
        return 0;
    for (int i = 1; i <=m; i++)
        p+=n;
    return p;
}

unsigned int pot3(unsigned int n, unsigned int m){
    unsigned int p = 1;
    if (n == 0)
        return 0;
    for (int i = 1; i <=m; i++)
        p*=n;
    return p;
}

int main(){
    
    int n, m;
    
    cout << "Podaj n: " << endl;
    cin >> n;
    cin.get();
    
    cout << "Podaj m: " << endl;
    cin >> m;
    cin.get();
    
    cout << pot1(n, m) << endl;
    cout << pot2(n, m) << endl;
    cout << pot3(n, m) << endl;
    
    cin.get();
    return 0;
}