// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Persona {

    string nombre;
    int altura;

};

bool operator<(Persona const& p1, Persona const& p2) {

    return p1.nombre < p2.nombre;

}

/*

    - Precondición: { 0 <= v.size < 150000 and altos.size == 0 and bajos.size == 0 and limite > 0 }

    - Invariante: { 0 <= i <= v.size() and altos = (k: 0 <= k < i : v[k].altura > limite : v[k] ) and bajos = (k : 0 <= k < i : v[k].altura <= limite : v[k]) }

    - Funcion de cota: n - i

    - Postcondición: { altos = (k: 0 <= k < v.size() : v[k].altura > limite : v[k]) and bajos = (k : 0 <= k < v.size() : v[k].altura <= limite : v[k]) }

    - Coste: O(n)
        
*/

// función que resuelve el problema
void resolver(vector<Persona> const& v, vector<Persona>& altos, vector<Persona>& bajos, int limite) {


    for (int i = 0; i < v.size(); i++) {

        if (v[i].altura > limite) altos.push_back(v[i]);
        else bajos.push_back(v[i]);

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, limite;
    cin >> n >> limite;
    if (!std::cin)
        return false;

    vector<Persona> v;

    for (int i = 0; i < n; i++) {

        Persona persona;
        cin >> persona.nombre >> persona.altura;
        v.push_back(persona);

    }

    vector<Persona> altos;
    vector<Persona> bajos;

    sort(v.begin(), v.end());

    resolver(v, altos, bajos, limite);


    // escribir sol

    cout << "Bajos: ";
    for (int i = 0; i < bajos.size(); i++) {

        cout << bajos[i].nombre << " ";

    }
    cout << '\n';

    cout << "Altos: ";
    for (int i = 0; i < altos.size(); i++) {

        cout << altos[i].nombre << " ";

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