// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {

    int num_partidos;
    bool presentado;
    int ronda;

};

//El coste de este algoritmo es del orden de O(n) siendo n el numero de elementos del vector

// función que resuelve el problema
Resultado resolver(vector<string> const& v, int ini, int fin, int r) {

    if(ini + 1 >= fin) {
    
        if (v[ini] == "NP") {

            if (v[fin] == "NP") return { 0, false, 1 };
            else return { 0, true, 1 };

        }
        else {

            if (v[fin] == "NP") return { 0, true, 1 };
            else return { 1, true, 1 };

        }
    
    }

    int m = (ini + fin) / 2;

    Resultado izq = resolver(v, ini, m, r);
    Resultado der = resolver(v, m + 1, fin, r);

    int ronda = izq.ronda + 1;

    if (izq.presentado && der.presentado) {
        if(ronda <= r)
            return { izq.num_partidos + der.num_partidos + 1, true, ronda };
        else 
            return { izq.num_partidos + der.num_partidos, true, ronda };
    }
    else if (!izq.presentado && !der.presentado) return { izq.num_partidos + der.num_partidos, false, ronda };
    else return { izq.num_partidos + der.num_partidos, true, ronda };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, r;
    cin >> n >> r;
    if (!std::cin)
        return false;

    vector<string> v(n);

    for(int i = 0; i < n; i++){
    
        cin >> v[i];

    }

    Resultado sol = resolver(v, 0, n-1, r);

    // escribir sol
    cout << sol.num_partidos << '\n';

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