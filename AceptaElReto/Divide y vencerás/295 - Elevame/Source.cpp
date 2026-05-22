#include <iostream>
#include <cmath>

using namespace std;

int const k = 31543;

int eleva(int x, int n) {
	if (n == 0) return 1;
	else {

		long long int ret = eleva(x, n / 2);
		if (n % 2 == 1) {
			return ((x % k) * ret * ret) % k;
		}
		else {
			return (ret * ret) % k;
		}
	}

}

bool resuelveCaso() {
	int x, n;
	cin >> x >> n;
	if (x == 0 && n == 0) return false;
	else {
		long long int resultado = eleva(x, n);
		cout << resultado << endl;
		return true;
	}
}

int main() {

	while (resuelveCaso());

	return 0;
}