// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {

    int m;
    int n;
    vector<int> operandos;

};

/*
    El árbol de exploración de este problema tiene una altura n, siendo n el número de operandos del vector de entrada.
    Cada nodo representa un operando. Las ramas del árbol representan las dos opciones posibles (suma o resta)

*/


// función que resuelve el problema
void resolver(tDatos const& datos, int k, int valor_actual, bool& posible, vector<int> const& acum_suma) {

    int n = datos.operandos.size();

    if (k == n) return;

    if (posible) return;

        //Realizo una suma
        valor_actual += datos.operandos[k];

        if (k == n - 1) {

            if (valor_actual == datos.m) posible = true;

        }
        else {
            if( acum_suma[k] + valor_actual >= datos.m)
                resolver(datos, k + 1, valor_actual, posible, acum_suma);

        }

        valor_actual -= datos.operandos[k];

        //Realizo una resta
        valor_actual -= datos.operandos[k];

        if (k == n - 1) {

            if (valor_actual == datos.m) posible = true;

        }
        else {

            if (valor_actual  - acum_suma[k] <= datos.m)
                resolver(datos, k + 1, valor_actual, posible, acum_suma);

        }

        valor_actual += datos.operandos[k];


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;
    cin >> datos.m >> datos.n;

    for (int i = 0; i < datos.n; i++) {

        int a;
        cin >> a;
        datos.operandos.push_back(a);

    }

    bool posible = false;

    if (datos.n > 0) {

        int valor_actual = datos.operandos[0];

        vector<int> acum_suma(datos.operandos.size() + 1, 0);

        for (int i = datos.operandos.size() - 1; i >= 0; i--) {

            acum_suma[i] = acum_suma[i + 1] + datos.operandos[i];
        }


        resolver(datos, 1, valor_actual, posible, acum_suma);

    }
    else posible = true;

    // escribir sol
    if (posible) cout << "SI";
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