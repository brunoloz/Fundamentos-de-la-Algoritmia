// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tCancion {

    int duracion;
    int sat;

};

struct tDatos {

    int n;
    int t1;
    int t2;
    vector<tCancion> canciones;

};

// función que resuelve el problema
void resolver(tDatos const& datos, int k, int acu_ida, int acu_vuelta, int& sat_mejor,  int sat_actual, bool& posible, vector<int>const& acum, vector<int>const& acum_tiempo) {

    if (k == datos.n) {

        if (acu_ida == datos.t1 && acu_vuelta == datos.t2) {

            posible = true;
            if (sat_actual > sat_mejor) {
                sat_mejor = sat_actual;
            }

        }

        return;

    }

    int tiempo = (datos.t1 - acu_ida) + (datos.t2 - acu_vuelta);
    if (acum_tiempo[k] < tiempo) {
        return; 
    }

    if (acu_ida + datos.canciones[k].duracion <= datos.t1) {

        if (sat_actual + datos.canciones[k].sat + acum[k + 1] > sat_mejor) {

            resolver(datos, k + 1, acu_ida + datos.canciones[k].duracion, acu_vuelta, sat_mejor, sat_actual + datos.canciones[k].sat, posible, acum, acum_tiempo);

        }


    }

    if (acu_vuelta + datos.canciones[k].duracion <= datos.t2) {

        if (sat_actual+ datos.canciones[k].sat + acum[k + 1] > sat_mejor) {

            resolver(datos, k + 1, acu_ida, acu_vuelta + datos.canciones[k].duracion, sat_mejor, sat_actual + datos.canciones[k].sat, posible, acum,acum_tiempo);

        }
    }

    if (sat_actual + acum[k + 1] > sat_mejor) {

        resolver(datos, k + 1, acu_ida, acu_vuelta, sat_mejor, sat_actual, posible, acum, acum_tiempo);

    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    tDatos datos;

    cin >> datos.n >> datos.t1 >> datos.t2;

    if (datos.n == 0 && datos.t1 == 0 && datos.t2 == 0)
        return false;

    for (int i = 0; i < datos.n; i++) {

        tCancion cancion;
        cin >> cancion.duracion >> cancion.sat;

        datos.canciones.push_back(cancion);
    }
    vector<int> acum_tiempo(datos.n + 1, 0);
    vector<int> acum(datos.n + 1, 0);
    for (int i = datos.n - 1; i >= 0; i--) {

        acum[i] = acum[i + 1] + datos.canciones[i].sat;
        acum_tiempo[i] = acum_tiempo[i + 1] + datos.canciones[i].duracion;

    }

    int sat_actual = 0;
    bool posible = false;
    int sat_mejor = 0;
    resolver(datos, 0, 0,0, sat_mejor, 0, posible, acum, acum_tiempo);

    // escribir sol
    if (posible)
        cout << sat_mejor << '\n';
    else cout << "Imposible" << '\n';

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
