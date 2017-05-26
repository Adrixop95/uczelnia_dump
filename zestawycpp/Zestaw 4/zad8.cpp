#include <iostream>
#include <vector>

using namespace std;

void a(unsigned int n, int a1[], int a2[], int a3[]){
    for(int i = 0; i != n; i++){
        a3[i] = a1[i] + a2[i];
    }
}

void b(unsigned int n, int a1[], int a2[], int a3[]){
    for(int i = 0; i != n; i++){
        a3[i] = (a1[i] > a2[i]) ? a3[i] = a1[i] : a3[i] = a2[i];
    }
    cout << a3[0] << endl;
}

void c(unsigned int n, int a1[], int a2[], int a3[]){
    int temp;
    int temp2;
    for(int i = 0; i != n; i++){
        temp = a3[i];
        a3[i] = a2[i];
        a2[i] = a1[i];
        a1[i] = temp; 
    }
}

int main(){
    int n;
    cout << "Give the length of the array: " << endl;
    cin >> n;
    int tab1[] = {22,4,7};
    int tab2[] = {1,2,3};
    int tab3[] = {};
    return 0;
}
