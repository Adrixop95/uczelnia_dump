#include <iostream>

using namespace std;

unsigned int pot(unsigned int n, unsigned int m = 2){
    int p = 1;
    
    if (n == 0)
        return 0;
    
    for (int i = 1; i <= m; i++){
        p*=n;
        cout << p << endl;
    }
    return p;
}

int main(){
    int n,m;
    
    cout << "Podaj n: " << endl;
    cin >> n;
    
    cout << "podaj m: " << endl;
    cin >> m;
    
    pot(n, m);
    pot(n);
    
    cin.get();
    return 0;
}