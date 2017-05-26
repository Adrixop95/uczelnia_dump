#include <iostream>

using namespace std;

class stos{
private:
	int rozmiar, gora;
	int *a;
public:
	stos(int);
	~stos();
	bool isempty(void);
	void push(int);
	void pop(void);
	int top(void);
};

stos::stos(int m){
	rozmiar = m;
	gora = 0;
	a = new int[m];
}

stos::~stos(){
	delete [] a;
}

bool stos::isempty(){
	return(gora == 0);
}

void stos::push(int x){
	a[gora] = x;
	gora++;
}

void stos::pop(){
	if(isempty()){
		cout << "Stos jest pusty" << endl;
	} else {
		gora--;
	}
}

int stos::top(){
	if(isempty()){
		cout << "Stos jest pusty" << endl;
	} else {
		return a[gora-1];
	}
}

int main(){
	stos st(10);

	st.push(10);

	if (st.isempty()){
		cout << "Stos jest pusty" << endl;
	} else {
		cout << "Stos nie jest pusty" << endl;
	}

	st.pop();

	if (st.isempty()){
		cout << "Stos jest pusty" << endl;
	} else {
		cout << "Stos nie jest pusty" << endl;
	}

	cin.get();
	return 0;
}