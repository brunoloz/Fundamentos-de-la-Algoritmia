// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Resultado {

    int numero;
    bool mayoritario;

};

int contar(vector<int> const& v, int ini, int fin, int x) {
    int cont = 0;
    for (int i = ini; i <= fin; ++i) {
        if (v[i] == x) cont++;
    }
    return cont;
}

// función que resuelve el problema
Resultado resolver(vector<int> const& v, int ini, int fin) {

    if (ini == fin) return { v[ini], true};

    int m = (ini + fin) / 2;

    Resultado izq = resolver(v, ini, m);
    Resultado der = resolver(v, m + 1, fin);

    int n = fin - ini + 1;
    
    if (izq.mayoritario) {

        if (contar(v, ini, fin, izq.numero) > (n / 2)) return { izq.numero, true };

    }

    if (der.mayoritario) {

        if (contar(v, ini, fin, der.numero) > (n / 2)) return { der.numero, true };

    }

    if (!izq.mayoritario && !der.mayoritario) return { 0, false };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    vector<int> v;

    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }

    Resultado sol = { 0, false };

    if(!v.empty())
        sol = resolver(v, 0, v.size() - 1);
    // escribir sol
    if (!sol.mayoritario || sol.numero == 0) cout << "NO";
    else cout << sol.numero;

    cout << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}