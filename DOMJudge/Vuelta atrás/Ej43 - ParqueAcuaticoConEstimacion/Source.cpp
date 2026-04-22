// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J-19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tAtraccion{

    string nombre;
    double tiempo;
    double satisfaccion;
    int acuatico;

};

struct tDatos{

    int n;
    int t;
    vector<tAtraccion> atracciones;

};

class Comparador {
public:
    bool operator ()(const tAtraccion& a, const tAtraccion& b) const {
        return a.satisfaccion / a.tiempo > b.satisfaccion / b.tiempo;
    }
};

/*

El vector solución tiene tamaño n y guarda las decisiones tomadas sobre las atracciones.
Cada posición i del vector guarda un 1 si decidimos montar en esa atracción o un 0 si la descartamos.

El árbol de exploración tiene altura n, siendo n el numero de atracciones.
Cada nodo representa un estado parcial y almacena el tiempo gastado, la satisfacción, los tipos de atracciones y el vector construido hasta ahí.

*/

double calcularEstimacion(int k, double tiempo_actual, double sat_actual, double tiempo_max, const vector<tAtraccion>& atracciones) {
    double estimacion = sat_actual;

    double tiempo_restante = tiempo_max - tiempo_actual;
    int i = k;

    while (i < atracciones.size() && tiempo_restante > 0) {
        if (atracciones[i].tiempo <= tiempo_restante) {
            estimacion += atracciones[i].satisfaccion;
            tiempo_restante -= atracciones[i].tiempo;
        }
        else {
            estimacion += (atracciones[i].satisfaccion * tiempo_restante) / atracciones[i].tiempo;
            tiempo_restante = 0;
        }
        i++;
    }

    return estimacion;
}

// función que resuelve el problema
void resolver(const vector<tAtraccion>& atracciones, const vector<int>& max_salpican, double tiempo_max, int k, double tiempo_actual, double sat_actual, int num_salpican, int num_mojan,
                vector<int>& sol, vector<int>& mejor_sol, double& max_sat) {

    if (k == atracciones.size()) {

        if (num_mojan <= num_salpican && sat_actual > max_sat) {
            max_sat = sat_actual;
            mejor_sol = sol;
        }
        return;
    }

    if (num_mojan > num_salpican + max_salpican[k]) {
        return;
    }

    double estimacion = calcularEstimacion(k, tiempo_actual, sat_actual, tiempo_max, atracciones);
    if (estimacion <= max_sat) {
        return;
    }

    if (tiempo_actual + atracciones[k].tiempo <= tiempo_max) {
        sol[k] = 1; // Marcamos en el vector solución parcial

        int sig_salpican = num_salpican;
        int sig_mojan = num_mojan;

        if (atracciones[k].acuatico == 0) {
            sig_salpican++; 
        }
        else {
            sig_mojan++;
        }

        resolver(atracciones, max_salpican, tiempo_max, k + 1, tiempo_actual + atracciones[k].tiempo, sat_actual + atracciones[k].satisfaccion, sig_salpican, sig_mojan, sol, mejor_sol, max_sat);
    }

    sol[k] = 0; // Marcamos en el vector solución parcial
    resolver(atracciones, max_salpican, tiempo_max, k + 1, tiempo_actual, sat_actual, num_salpican, num_mojan, sol, mejor_sol, max_sat);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;

    cin >> datos.n >> datos.t;

    if (datos.n == 0 && datos.t == 0)
        return false;

    datos.atracciones.resize(datos.n);

    for (int i = 0; i < datos.n; i++) {

        cin >> datos.atracciones[i].nombre >> datos.atracciones[i].tiempo 
            >> datos.atracciones[i].satisfaccion >> datos.atracciones[i].acuatico;

    }

    sort(datos.atracciones.begin(), datos.atracciones.end(), Comparador());

    vector<int> max_salpican(datos.n + 1, 0);
    int cont = 0;
    for (int i = datos.n - 1; i >= 0; i--) {
        if (datos.atracciones[i].acuatico == 0) cont++;
        max_salpican[i] = cont;
    }

    vector<int> sol(datos.n, 0);       
    vector<int> mejor_sol(datos.n, 0);
    double max_sat = 0;

    resolver(datos.atracciones, max_salpican, datos.t, 0, 0, 0, 0, 0, sol, mejor_sol, max_sat);

    // escribir sol
    if (max_sat == 0) {
        cout << "NINGUNA\n";
    }
    else {
        cout << max_sat << "\n";
    }

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
