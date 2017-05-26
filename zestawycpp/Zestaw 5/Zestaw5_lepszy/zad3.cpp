#include <iostream>

using namespace std;

struct trojkat{
    double a,h;
};

struct prostokat{
    double a,b;
};

struct trapez{
    double a,b,h;
};

union wymiary{
    struct trojkat troj, rown;
    struct prostokat prost;
    struct trapez trap;
};

struct figura{
    union wymiary wym;
    int fig;
};

double pole(struct figura f){
    switch (f.fig){
        case 0: return f.wym.troj.a*f.wym.troj.h/2;
        case 1: return f.wym.prost.a*f.wym.prost.b;
        case 2: return f.wym.rown.a*f.wym.rown.h;
        case 3: return f.wym.trap.h*(f.wym.trap.a+f.wym.trap.b)/2;
    }
}

int main(){

    figura f;
    int x;

    cout << "Jaka figure chcesz policzyc? (0 - trojkat, 1 - prostokat, 2 - rownoleglobok, 3 - trapez" << endl;
    cin >> x;

    if(x == 0){
        cout << "Podaj a: " << endl;
        cin >> f.wym.troj.a;

        cout << "Podaj wysokosc h: " << endl;
        cin >> f.wym.troj.h;

        cout << "Pole trojkata: " << pole(f) << endl;
    } else if(x == 1){
        cout << "Podaj a: " << endl;
        cin >> f.wym.prost.a;

        cout << "Podaj b: " << endl;
        cin >> f.wym.prost.b;

        cout << "Pole prostokota: " << pole(f) << endl;

    } else if(x == 2){
        cout << "Podaj a: " << endl;
        cin >> f.wym.rown.a;

        cout << "Podaj b: " << endl;
        cin >> f.wym.rown.h;

        cout << "Pole rownolegloboku: " << pole(f) << endl;

    } else if(x == 3){
        cout << "Podaj h: " << endl;
        cin >> f.wym.trap.h;

        cout << "Podaj a: " << endl;
        cin >> f.wym.trap.a;

        cout << "Podaj b: " << endl;
        cin >> f.wym.trap.b;

        cout << "Pole trapezu: " << pole(f) << endl;
    } else {
        return 0;
    }

    cin.get();
    return 0;
}
