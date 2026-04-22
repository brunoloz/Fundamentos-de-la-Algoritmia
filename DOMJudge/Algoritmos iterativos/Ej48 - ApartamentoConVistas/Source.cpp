// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tEdificio {

    string id;
    int altura;
    int piso;

};

// función que resuelve el problema
vector<string> resolver(vector<tEdificio> const& edificios) {

    vector<string> vistas;

    int n = edificios.size() - 1;

    if (edificios[n].piso != -1)
        vistas.push_back(edificios[n].id);

    int maximo = edificios[n].altura;

    for (int i = n - 1 ; i >= 0; i--) {

        if (edificios[i].piso > maximo)
            vistas.push_back(edificios[i].id);

        if (edificios[i].altura > maximo)
            maximo = edificios[i].altura;

    }

    return vistas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<tEdificio> edificios(n);


    for (int i = 0; i < n; i++) {

        cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;

    }

    vector<string> sol = resolver(edificios);

    // escribir sol
    if (sol.size() == 0) cout << "Ninguno";
    else {

        cout << sol.size() << '\n';
        for (int i = 0; i < sol.size(); i++) {

            cout << sol[i] << ' ';

        }

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
