#include <iostream>

using namespace std;

void zamiana(int* n, int* m){
    int temp;
    if(*n > *m){
        temp = *n;
        *n = *m;
        *m = temp;
    }
}

int main(){
    int n, m;
    
    cout << "Podaj n: " << endl;
    cin >> n;
    cout << "Podaj m: " << endl;
    cin >> m;
    cin.get();
    
    cout << "Liczby przed zamiana:" << endl;
    cout << "N = " << n << " M = " << m << endl;
    zamiana(&n, &m);
    cout << "Liczby po zamianie:" << endl;
    cout << "N = " << n << " M = " << m << endl;
    
    cin.get();
    return 0;
}
