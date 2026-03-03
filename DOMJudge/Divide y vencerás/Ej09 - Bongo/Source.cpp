// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL - J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Jugada {

    int posicion;
    int numero;
    int objetivo;
    bool tachado;

};

//El coste del algoritmo es del orden de O(log n) siendo n el numero de elementos del vector

// función que resuelve el problema
Jugada resolver(vector<Jugada> const& carton, int ini, int fin, int numero) {

    if (ini + 1 >= fin) {

        if (carton[ini].numero == (numero + ini)) return {ini, numero, numero + ini, true };
        if (carton[fin].numero == (numero + fin)) return {ini, numero, numero + fin, true };


        return {ini, numero, numero + ini, false };

    }

    int m = (ini + fin) / 2;

    if (carton[m].numero == carton[m].objetivo) return {m, carton[m].numero, carton[m].objetivo, true};
    else if (carton[m].objetivo < carton[m].numero) return resolver(carton, ini, m, numero);
    else return resolver(carton, m, fin, numero);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, num;
    cin >> n >> num;

    vector<Jugada> carton(n);

    for (int i = 0; i < n; i++) {

        int numero;
        cin >> numero;

        carton[i] = { i, numero, i+num, false };

    }

    Jugada sol = resolver(carton, 0, n - 1, num);

    // escribir sol
    if (sol.tachado) cout << sol.objetivo;
    else cout << "NO";
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