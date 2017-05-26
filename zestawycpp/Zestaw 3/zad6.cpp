#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<double> random(int n){
    vector<double> results;
    double xn, xn1;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    
    xn1 = dis(gen);
    results.push_back(xn1);
    for(int x=0; x < n; x++){
        xn = 1 - (xn1 * xn1);
        results.push_back(xn);
        xn1 = xn;
    }
    return results;
}

int main(){
    int n, i=0;
    cout << "Podaj ile liczb chcesz wygenerowac: ";
    cin >> n;
    
    vector<double> results = random(n);
    
    for(vector<double>::iterator it = results.begin(); it != results.end(); ++it){
        cout << "N" << i << " = " << *it << endl;
        i++;
    }
    return 0;
}
