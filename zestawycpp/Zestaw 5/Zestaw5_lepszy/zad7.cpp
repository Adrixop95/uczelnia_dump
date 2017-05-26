#include <iostream>

using namespace std;

class punkt3{
private:
    int x,y,z;
public:
    void ustaw(int, int, int);
    void wczytaj();
    punkt3(int, int, int);
};

punkt3::punkt3(int c, int d, int m){
    x = c;
    y = d;
    z = m;
}

void punkt3::ustaw(int a, int b, int n){
    x = a;
    y = b;
    z = n;
}

void punkt3::wczytaj(){
    cout << "x: " << x << "y: " << y << "z:"<< z << endl;
}

int main(){
    punkt3 p(1,2,3);
    p.wczytaj();
    p.ustaw(4,5,6);
    p.wczytaj();
    
    
    cin.get();
    return 0;
}