// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {

    bool pastoso;
    int pos;

};

// función que resuelve el problema

/*
   - Precondición: { v.size() > 0 }
        resolver(vector<int> const& v) dev boolean and integer
    
   - Invariante: {-1 <= i <= v.size() - 2 && suma == suma(i + 1, v.size()) && 
                    !sol.pastoso ==  (forAll k : i < k <= v.size() - 1 : v[k] != suma(k, v.size())}
           Donde suma(i, v.size) = sum k1 : i < k1 < v.size() : v[k1]

   - Funcion de cota: i + 1

   - Postcondición: { sol.pastoso == Exist k: 0 <= k <= v.size() - 1 : v[k] == suma(k, v.size()) and 
                        sol.pos == max {k : 0 <= k <= v.size() - 1 and v[k] == suma(k, v.size()) }
           Donde suma(i, v.size) = sum k1 : i < k1 < v.size() : v[k1]

   - Coste: O(n)


*/
tSolucion resolver(vector<int> const& v) { 

    int suma = 0;
    int n = v.size();
    tSolucion sol = { false, n - 1 };

    if (n == 0) return { false, -1 };

    if (v[n - 1] == 0) {

        int n = v.size() - 1;
        return { true, n};

    }
    int i = n - 2;

    while ( i >= 0 && !sol.pastoso) {

         suma += v[i + 1];

        if (suma == v[i]) {

            sol.pastoso = true;
            sol.pos = i;
        }

        i--;
    }

    return sol;

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    tSolucion sol = resolver(v);
    // escribir sol

    if (sol.pastoso) {

        cout << "Si " << sol.pos;

    }
    else cout << "No";

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