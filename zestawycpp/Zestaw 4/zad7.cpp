#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

double geom(unsigned int n, std::vector <unsigned int> array){
    
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 100);
    int m;
    double result=1, true_result;
    
    while(array.size() != n){
        m = uni(rng);
        result *= m;
        array.push_back(m);
    }
    true_result = pow(result, 1.0/n);
    return true_result;
}

int main(){
    int n;
    vector<unsigned int> array;
    
    cout << "Podaj dlugosc tablicy: " << endl;
    cin >> n;
    cin.get();
    
    cout << "Wynik: " << geom(n, array) << endl;
    
    cin.get();
    return 0;
}
