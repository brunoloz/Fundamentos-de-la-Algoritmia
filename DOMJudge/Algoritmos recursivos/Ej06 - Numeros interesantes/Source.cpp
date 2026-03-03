// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema

struct tSol {

    int suma_izq;
    bool interesante;

};

//P:{ n > 0 }
tSol interesante(int n, int suma_der) {

    if (n < 10) {

        if (n != 0 && suma_der % n == 0) return { n, true };
        else return  { 0, false };

    }
    else {

        if (n % 10 == 0 || suma_der % (n % 10) != 0) return { 0, false };
        else {

            tSol s = interesante(n / 10, suma_der + n % 10);

            if (s.suma_izq % (n % 10) == 0 && s.interesante) return { s.suma_izq + n % 10, true };
            else return{ 0,false };

        }

    }

}

/*

bool interesante(long long int n, int suma_total, int suma_der) {

    if (n == 0) return true;

    int digit = n % 10;

    if (digit == 0) return false;

    int suma_izq = suma_total - suma_der - digit;

    if (!(suma_izq % digit == 0) || !(suma_der % digit == 0)) return false;

    return interesante(n / 10, suma_total, suma_der + digit);

}

int valorSuma(long long int n) {

    if (n == 0) return 0;

    return valorSuma(n / 10) + n % 10;

}

*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int n;
    cin >> n;


    tSol sol = interesante(n, 0);

    // escribir sol
    if (sol.interesante) cout << "SI";
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