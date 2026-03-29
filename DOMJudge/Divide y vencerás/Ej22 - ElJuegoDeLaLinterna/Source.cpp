// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Resultado {

    int menor;
    bool premio;

};

// función que resuelve el problema
Resultado resolver(vector<int> const& v, int ini, int fin) {

    if (ini + 2 >= fin) {

        if (v[ini] < v[ini + 1] && v[fin] < v[ini + 1] && v[ini] < v[fin]) return { v[ini], false };

        int minimo = min({ v[ini], v[ini + 1], v[fin] });

        return { minimo, true };


    }

    int m = (ini + fin) / 2;

    Resultado izq = resolver(v, ini, m);
    Resultado der = resolver(v, m + 1, fin);

    int menor = min(izq.menor, der.menor);



    return { menor, izq.premio && der.premio };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    Resultado sol = resolver(v, 0, n-1);

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}