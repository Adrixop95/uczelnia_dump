#include <iostream>

using namespace std;

int pierw(unsigned int x){
    int pocz=0, kon=x, sr;
    
    while(kon - pocz >1){
        sr = (pocz + kon) /2;
        if (sr*sr <= x){
            pocz = sr;
        } else{
            kon = sr;
        }
    }
    
    if (x<=1){
        return kon;
    } else {
        return pocz;
    }
    
}

void wypisz(unsigned int n){
    int i,p;
    for (i=1; i <= pierw(n); i++){
        p=pierw(n-i*i);
        if ((i*i+p*p==n) && (i <p)){
            printf("%d*%d+%d*%d=%d\n",i,i,p,p,n);
        }
    }
}

int main(){
    
    int n;
    
    cout << "Podaj n: " << endl;
    cin >> n;
    
    wypisz(n);
    
    cin.get();
    return 0;
}