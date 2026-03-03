// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J19

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Solucion {
    bool hablan;
    int val1;    
    int val2;   
};

Solucion resolver(const vector<int>& novita, const vector<int>& gigante, int ini, int fin) {


    
    if (ini + 1 == fin) {

        //si coinciden al inicio o al final
        if (novita[ini] == gigante[ini]) return { true, novita[ini], 0 };
        if (novita[fin] == gigante[fin]) return { true, novita[fin], 0 };

        return { false, novita[ini], novita[fin] };
    }

    int m = (ini + fin) / 2;

    if (novita[m] == gigante[m]) {

        return { true, novita[m], 0 };

    }
    else if (novita[m] < gigante[m]) {

        return resolver(novita, gigante, m, fin);
    }
    else {

        return resolver(novita, gigante, ini, m);
    }
}


bool resuelveCaso() {
    int n;
    cin >> n;

    if (n == 0) 
        return false;

    vector<int> novita;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        novita.push_back(val);
    }

    vector<int> gigante;
    for (int j = 0; j < n; j++) {
        int val;
        cin >> val;
        gigante.push_back(val);
    }

    Solucion sol = resolver(novita, gigante, 0, novita.size() - 1);

    if (sol.hablan) {
        cout << "HABLAN " << sol.val1 << endl;
    }
    else {
        cout << "SE CRUZAN " << sol.val1 << " " << sol.val2 << endl;
    }

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}