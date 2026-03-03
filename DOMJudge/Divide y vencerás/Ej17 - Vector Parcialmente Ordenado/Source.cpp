// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {

    bool ordenado;
    int maximo;
    int minimo;

};

// función que resuelve el problema
Resultado resolver(vector<int> const& v, int ini, int fin) {

    if (ini == fin) {

        return { true, v[ini], v[ini] };

    }

    int m = (ini + fin) / 2;

    Resultado izq = resolver(v, ini, m);
    Resultado der = resolver(v, m + 1, fin);

    return { izq.ordenado && der.ordenado && izq.maximo <= der.maximo && izq.minimo <= der.minimo, der.maximo, izq.minimo};

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v;

    while (n != 0) {

        v.push_back(n);
        cin >> n;

    }

    Resultado sol = resolver(v, 0, v.size() - 1);

    // escribir sol
    if (sol.ordenado) cout << "SI";
    else cout << "NO";
    cout << '\n';

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
