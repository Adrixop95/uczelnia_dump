#include <iostream>

using namespace std;

void zamien(unsigned int n, int *** tab){
    int i, j, k, pom;
    
    for (i=0; i < n; i++){
        for(j=i; j<n; j++){
            if(i==j){
                k=i;
            }else{
                k=i+1;
            }
            
            for(;k<n;k++){
                pom=tab[i][j][k];
                tab[i][j][k]=tab[j][k][i];
                tab[i][j][k]=tab[j][k][i];
                tab[k][i][j]=pom;
            }
        }
    }
    
}

int main(){
    
    cin.get();
    return 0;
}