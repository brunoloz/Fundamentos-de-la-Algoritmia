// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tObjeto {

    int indice;
    int coste;
    int superficie;
    bool tomado;

};

struct tDatos {

    int n;
    int presupuesto;
    vector<tObjeto> objetos;

};

class Comparador {
public:
    bool operator ()(const tObjeto& a, const tObjeto& b) const {
        return (double)a.superficie/ a.coste > (double)b.superficie / b.coste;
    }
};

/*
    El arbol de exploración tiene una altura n, siendo n el numero de objetos a elegir para adorna la casa.
    Cada nodo representa el objeto y las ramas del arbol las distintas opciones a elegir.

    El vector solucion sera del tamaño de los objetos obtenidos (0 a n-1)

*/

// función que resuelve el problema
void resolver(tDatos const& datos, int k, int coste_actual, int& coste_mejor, int presupuesto_actual, vector<tObjeto>& sol_actual, vector<tObjeto>&sol_mejor, vector<int> const& estimacion) {


    if (k == datos.n) {

        if (coste_actual > coste_mejor) {
            coste_mejor = coste_actual;
            sol_mejor = sol_actual;
        }

        return;

    }

    int valor = datos.presupuesto - presupuesto_actual;
    double max_superficie = coste_actual + valor * (double)datos.objetos[k].superficie / datos.objetos[k].coste;

    if (max_superficie <= coste_mejor) return; 



    if (presupuesto_actual + datos.objetos[k].coste <= datos.presupuesto) {


        sol_actual[k] = datos.objetos[k];
        sol_actual[k].tomado = true;

        resolver(datos, k + 1, coste_actual + datos.objetos[k].superficie, coste_mejor, presupuesto_actual + datos.objetos[k].coste, sol_actual, sol_mejor, estimacion);

    }
    
    sol_actual[k] = datos.objetos[k];
    sol_actual[k].tomado = false;

    resolver(datos, k + 1, coste_actual, coste_mejor, presupuesto_actual, sol_actual, sol_mejor, estimacion);



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    tDatos datos;
    cin >> datos.n >> datos.presupuesto;

    if (!std::cin)
        return false;

    for (int i = 0; i < datos.n; i++) {

        tObjeto objeto;
        objeto.indice = i;
        cin >> objeto.coste >> objeto.superficie;
        datos.objetos.push_back(objeto);

    }

    int coste_mejor = 0;
    vector<tObjeto> sol_actual(datos.n);
    vector<tObjeto> sol_mejor;
    sort(datos.objetos.begin(), datos.objetos.end(), Comparador());

    vector<int> estimacion(datos.n + 1, 0);

    for (int i = datos.n - 1; i >= 0; i--) {

        estimacion[i] = datos.objetos[i].superficie + estimacion[i + 1];

    }

    resolver(datos, 0, 0, coste_mejor, 0, sol_actual, sol_mejor, estimacion);

    // escribir sol
    cout << coste_mejor << '\n';

    for (int i = 0; i < sol_mejor.size(); i++) {

        if (sol_mejor[i].tomado) {

            cout << sol_mejor[i].indice << ' ';

        }

    }

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