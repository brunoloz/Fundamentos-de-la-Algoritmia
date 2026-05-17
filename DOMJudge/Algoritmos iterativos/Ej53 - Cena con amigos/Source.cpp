// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {

    int suma;
    int pos;
    int longitud;

};

/*

    - Precondición: { datos.size > 0  and Exist k : 0 <= k < datos.size() : v[k] > 0 }

    - Invariante: { 
        0 <= i <= datos.size() and
        sol.suma == (max a, b : 0 <= a <= b < i : suma(a, b)) and
        suma_acu == (max a : 0 <= a <= i : suma(a, i - 1)) 
      }
        Donde suma(a, b) = sum k : a <= k <= b : datos[k]

    - Funcion de cota: n - i

    - Postcondición: { 
        // 1. La solución es un segmento válido que da la suma máxima posible
        sol.suma == (max a, b : 0 <= a <= b < datos.size() : suma(a, b)) and
        sol.suma == suma(sol.pos, sol.pos + sol.longitud - 1) and
        
        // 2. Primera regla de desempate: es el de MENOR longitud
        (forAll a, b : 0 <= a <= b < datos.size() and suma(a, b) == sol.suma : 
            b - a + 1 >= sol.longitud) and
            
        // 3. Segunda regla de desempate: a igual suma y longitud, es el PRIMERO (menor pos)
        (forAll a, b : 0 <= a <= b < datos.size() and suma(a, b) == sol.suma and b - a + 1 == sol.longitud : 
            sol.pos <= a)
      }

      - Coste O(N)

*/

// función que resuelve el problema
tSolucion resolver(vector<int> const& datos) {

    int suma_acu = 0;
    int max = 0;
    int longitud = 0;
    tSolucion sol;

    if (datos.size() == 0) return { 0, 0, 0 };

    for (int i = 0; i < datos.size(); i++) {

        suma_acu += datos[i];
        longitud++;

        if (suma_acu <= 0) {

            suma_acu = 0;
            longitud = 0;

        }

        if (suma_acu > max) {

            max = suma_acu;
            sol.longitud = longitud;
            int pos = i - longitud + 1;
            sol.pos = pos;
            sol.suma = suma_acu;

        }
        else if (suma_acu == max) {


            if (longitud < sol.longitud) {

                sol.longitud = longitud;
                sol.pos = i - longitud + 1;

            }

        }

    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v;
    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);


    }

    tSolucion sol = resolver(v);

    // escribir sol
    cout << sol.suma << " " << sol.pos << " " << sol.longitud << '\n';

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