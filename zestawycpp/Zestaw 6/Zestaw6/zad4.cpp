#include <iostream>

using namespace std;

class semafor{
private:
	int max;
	int min = 0, obecny = 0;
public:
	semafor();
	semafor(unsigned int);
	bool wartosc();
	void obrot();
	void zmniejsz();
};

semafor::semafor(unsigned int m){
	max = m;
}

semafor::semafor(void){
	max = 1;
}

void semafor::obrot(){
	if(obecny < max){
		obecny++;
	}
}

void semafor::zmniejsz(){
	if(obecny > max){
		obecny--;
	}
}

bool semafor::wartosc(){
	return (obecny != max);
}

int main(){
	semafor sem;

	if (sem.wartosc()){
		cout << "Brak sygnalu" << endl;
	} else {
		cout << "Jest sygnal" << endl;
	}

	sem.obrot();
	
	if (sem.wartosc()){
		cout << "Brak sygnalu" << endl;
	} else {
		cout << "Jest sygnal" << endl;
	}	

	cin.get();
	return 0;
}