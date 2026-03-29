// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


struct Resultado {

    int peso;
    bool equilibrado;

};

// función que resuelve el problema
Resultado resolver() {

    int pi, di, pd, dd;
    cin >> pi >> di >> pd >> dd;

    bool equilibrado_izq = true;
    bool equilibrado_der = true;


    if (pi == 0) {

        Resultado izquierda = resolver();
        pi = izquierda.peso;
        equilibrado_izq = izquierda.equilibrado;

    }

    if (pd == 0) {

        Resultado derecho = resolver();
        pd = derecho.peso;
        equilibrado_der = derecho.equilibrado;

    }

    bool equilibrado = equilibrado_izq && equilibrado_der && (pi * di == pd * dd);

    return { pi + pd, equilibrado };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    Resultado sol = resolver();

    // escribir sol
    if (sol.equilibrado) cout << "SI";
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