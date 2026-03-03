// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


bool esPosible(int capacidad, const std::vector<int>& pesos, int maxViajes) {

    int viajesActuales = 1;
    int cargaActual = 0;
    
    for (int peso : pesos) {
        if (cargaActual + peso > capacidad) {
            viajesActuales++;
            cargaActual = peso;
        } else {
            cargaActual += peso;
        }
    }
    
    return viajesActuales <= maxViajes;
}


int busquedaBinariaRecursiva(int ini, int fin, const std::vector<int>& pesos, int maxViajes) {

    if (ini >= fin) {
        return ini;
    }
    
    int mitad = (ini + fin) / 2;
    
    if (esPosible(mitad, pesos, maxViajes)) {

        return busquedaBinariaRecursiva(ini, mitad, pesos, maxViajes);
    } 
    else {
        return busquedaBinariaRecursiva(mitad + 1, fin, pesos, maxViajes);
    }
}


bool resuelveCaso() {
    int numObras, maxViajes;
    

    std::cin >> numObras >> maxViajes;
    
    if (numObras == 0 && maxViajes == 0)
        return false;
    
    std::vector<int> pesos(numObras);
    int maxPeso = 0;
    int sumaPesos = 0;
    
    for (int i = 0; i < numObras; ++i) {
        std::cin >> pesos[i];
        if (pesos[i] > maxPeso) {
            maxPeso = pesos[i];
        }
        sumaPesos += pesos[i];
    }
    

    int sol = busquedaBinariaRecursiva(maxPeso, sumaPesos, pesos, maxViajes);
    
    std::cout << sol << "\n";
    
    return true;
}

int main() {

    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
    #endif 
    
    while (resuelveCaso())
        ;
    
    #ifndef DOMJUDGE 
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
    #endif
    
    return 0;
}