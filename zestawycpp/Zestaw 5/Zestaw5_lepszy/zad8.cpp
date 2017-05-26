#include <iostream>

using namespace std;

class punkt{
	friend punkt rzut(punkt3);
private:
    int x,y;
public:
    void ustaw(int, int);
    void wczytaj();
    punkt(int, int);
};

class punkt3{
private:
    int x,y,z;
public:
    void ustaw(int, int, int);
    void wczytaj();
    punkt3(int, int, int);
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

punkt rzut(punkt3 p3){
	punkt p(1,2);
	p.x = p3.x;
	p.y = p3.y;
	return p;
}

int main(){

	return 0;
}