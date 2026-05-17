// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

/*
    - Precondición: { datos.size > 0 and d >= 0 }

    - Invariante: { 0 <= i <= datos.size - 1 and apta == (forAll j, k: 0 <= j <= k < i : creciente(j, k) and (d >= (datos[k] - datos[j]))}
        Donde creciente(j, k) = forAll x : j <= x < k : datos[x + 1] > datos[x]

    - Funcion de cota: (n - 1) - i

    - Postcondición: { apta == (forAll j, k: 0 <= j <= k <= datos.size : creciente(j, k) and (d >= (datos[k] - datos[j])) }
        Donde creciente(j, k) = forAll x : j <= x < k : datos[x + 1] > datos[x]

    - Coste. O(n)

*/
bool resolver(vector<int> const& datos, int d) {

    int n = datos.size();

    int cota_baja = datos[0];
    int cota_alta = datos[0];
    bool apta = true;

    int i = 0;

    while (i < n - 1 && apta) {

        if (datos[i + 1] > datos[i]) {
            cota_alta = datos[i + 1];

            if (d < (cota_alta - cota_baja)) apta = false;

        }
        else cota_baja = datos[i + 1];



        i++;
    }

    return apta;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int d, n;
    cin >> d >> n;

    if (!std::cin)
        return false;

    vector<int> v;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    bool sol = resolver(v, d);

    // escribir sol
    if (sol) cout << "APTA";
    else cout << "NO APTA";

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