#include <iostream>

using namespace std;

int escribeDigitos(int n) {

	//Caso base
	if (n < 10) {

		cout << n;
		return n;

	}
	//Caso recursivo
	int s = escribeDigitos(n / 10);
	cout << " + " << n % 10;
	return s + n % 10;
}

int escribeDigitos2(int n) {
	int suma = escribeDigitos(n);
	cout << " = ";
	return suma;
}


bool resuelveCaso() {
	int num;
	cin >> num;
	while (num >= 0) {
		int suma = escribeDigitos2(num);
		cout << suma << endl;
		cin >> num;
	}
	return false;
}

int main() {

	while (resuelveCaso());

	return 0;
}