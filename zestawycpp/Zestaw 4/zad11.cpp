#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Calculator{
    double temp=0, result=0;
public:
    void addition(void);
    void substraction(void);
    void multiplication(void);
    void division(void);
    double results(void);
};

void Calculator::addition(void){
    cout << "Jakie liczby chcesz dodac. Napisz 99999 aby przerwac." << endl;
    bool run = true;
    while(run){
        cin >> temp;
        if(temp == 99999){
            run = false;
        }else{
            result += temp;
        }
    }
}

void Calculator::substraction(void){
    cout << "Jakie liczby chcesz odjac. Napisz 99999 aby przerwac." << endl;
    bool run = true;
    while(run){
        cin >> temp;
        if(temp == 99999){
            run = false;
        }else{
            result -= temp;
        }
    }
}

void Calculator::multiplication(void){
    cout << "Jakie liczby chcesz pomnozyc. Napisz 99999 aby przerwac." << endl;
    bool run = true;
    while(run){
        std::cin >> temp;
        if(temp == 99999){
            run = false;
        }else{
            if(result == 0){
                result = temp;
            }else{
                result *= temp;
            }
        }
    }
}

void Calculator::division(void){
    cout << "Jakie liczby chcesz podzielic. Napisz 99999 aby przerwac." << endl;
    bool run = true;
    while(run){
        std::cin >> temp;
        if(temp == 99999){
            run = false;
        }else{
            if(result == 0){
                result = temp;
            }else{
                result /= temp;
            }
        }
    }
}

double Calculator::results(void){
    return result;
}
int main(){
    string function;
    Calculator calc;
    
    while(function != "="){
        cout << "Jakie dzialanie chcesz wykonac? (+,-,*,/,=): ";
        cin >> function;
        if(function == "+"){
            calc.addition();
        }else if(function == "-"){
            calc.substraction();
        }else if(function == "*"){
            calc.multiplication();
        }else if(function == "/"){
            calc.division();
        }else if(function == "="){
            cout << "Wynik: " << calc.results() << endl;
            break;
        }else{
            cout << "Popelniles blad!" << endl;
            break;
        }
    }
    return 0;
}
