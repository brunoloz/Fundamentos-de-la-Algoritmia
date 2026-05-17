// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {

    int pos;
    int suma;


};

/*
      sumaVagones(pos, d) ≡ sum k : pos <= k < pos + d : datos[k]

    - Precondición: { datos.size() > 0 and 0 < d <= datos.size() }

    - Invariante: { -1 <= i <= datos.size() - 1 and
                    (cont == d => suma_acu == sumaVagones(i + 1, d)) and
                    sol.suma == (max j : i < j <= datos.size() - d : sumaVagones(j, d)) }

    - Función de cota: i + 1

    - Postcondición: {
        // 1. La suma es la máxima posible de cualquier ventana de tamaño d
        sol.suma == (max j : 0 <= j <= datos.size() - d : sumaVagones(j, d)) and
        // 2. La posición devuelta genera esa suma máxima
        sol.suma == sumaVagones(sol.pos, d) and
        // 3. Regla de desempate: sol.pos es el índice más grande (más cerca de la cola)
        (forAll j : 0 <= j <= datos.size() - d and sumaVagones(j, d) == sol.suma : sol.pos >= j)
      }

    - Coste: O(N) en tiempo, donde N es el número de vagones. Se recorre el vector una sola vez
             usando una ventana deslizante. Espacio O(1) adicional.
*/

// función que resuelve el problema
tSolucion resolver(vector<int> const& datos, int d) {


    int suma_acu = 0;
    int max = -1;
    int cont = 0;
    tSolucion sol;

    if (datos.size() == 0) return { 0, 0 };

    for (int i = datos.size() - 1; i >= 0; i--) {

        if (cont == d) {

            suma_acu = suma_acu - datos[i + d];
            cont--;

        }

        suma_acu += datos[i];
        cont++;

        if (suma_acu > max && cont == d) {

            max = suma_acu;
            sol.suma = suma_acu;
            sol.pos = i;

        }


    }

    return sol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, d;
    cin >> n >> d;

    vector<int> v;
    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }


    tSolucion sol = resolver(v, d);
    // escribir sol
    cout << sol.pos << " " << sol.suma << '\n';

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