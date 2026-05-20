// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cinta {

    char id;
    int longitud;

};

struct tSolucion {

    int ini;
    int fin;

};

bool operator<(Cinta const& c1, Cinta const& c2) {

    return c1.longitud < c2.longitud;

}

// función que resuelve el problema
tSolucion resolver(vector<Cinta>& v) {

    tSolucion sol = { -1, -1 };

    int i = 0; 
    int azul = 0;
    int rojo = v.size() - 1;

    while (i <= rojo) {

        if (v[i].id == 'a') {

            swap(v[azul], v[i]);
            azul++;
            i++;
        }
        else if (v[i].id == 'r') {

            swap(v[rojo], v[i]);
            rojo--;

        }
        else i++;

    }
    


    return { azul, rojo };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<Cinta> v;

    for (int i = 0; i < n; i++) {

        Cinta cinta;
        cin >> cinta.id >> cinta.longitud;
        v.push_back(cinta);

    }


    tSolucion sol = resolver(v);

    sort(v.begin(), v.begin() + sol.ini);
    sort(v.begin() + sol.ini, v.begin() + (sol.fin + 1));
    sort(v.begin() + (sol.fin + 1), v.end());

    cout << "Azules: ";
    for (int i = 0; i < sol.ini; i++) {

        cout << v[i].longitud << " ";

    }
    cout << '\n';
    cout << "Verdes: ";
    for (int i = sol.ini; i <= sol.fin; i++) {

        cout << v[i].longitud << " ";

    }
    cout << '\n';
    cout << "Rojas: ";
    for (int i = sol.fin + 1; i < v.size(); i++) {

        cout << v[i].longitud << " ";

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