#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(b != 0){
        return GCD(b, a % b);
    }
    return a;
}

int main(){
    int a, b;
    
    cout << "Podaj A: " << endl;
    cin >> a;
    cin.get();
    
    cout << "Podaj b: " << endl;
    cin >> b;
    cin.get();
    
    cout << "GCD wynosi: " << GCD(a, b) << endl;
    
    cin.get();
    return 0;
}
