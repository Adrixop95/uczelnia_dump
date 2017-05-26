#include <iostream>

using namespace std;

class punkt{
private:
    int x,y;
public:
    void ustaw(int, int);
    void wczytaj();
    punkt(int, int);
};

punkt::punkt(int c, int d){
    x = c;
    y = d;
}

void punkt::ustaw(int a, int b){
    x = a;
    y = b;
}

void punkt::wczytaj(){
    cout << "x: " << x << "y: " << y << endl;
}

int main(){
    punkt p(1,2);
    p.wczytaj();
    p.ustaw(3,4);
    p.wczytaj();
    
    
    cin.get();
    return 0;
}