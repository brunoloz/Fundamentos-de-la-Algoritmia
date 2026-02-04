// Esquema de la entrada: número de casos
#include <iostream>
#include <string>
using namespace std;

int esOperador(char c) {

    if (c == '+') return true;
    else if (c == '-') return true;
    else if (c == '/') return true;
    else if (c == '*') return true;
    else return false;

}

int resultado(char c, int i , string operacion) {


    if (!esOperador(c)) return (int)c;

    if (operacion[i+ 1] == ' ') i++;

    int op1 = resultado(operacion[i+ 1], i, operacion);
    int op2 = resultado(operacion[i + 1], i, operacion);

    if (c == '+') return op1 + op2;
    if (c == '-') return op1 - op2;
    if (c == '/') return op1 / op2;
    if (c == '*') return op1 * op2;

    
}

void casoDePrueba() {

    string operacion;
    cin.ignore();
    getline(cin, operacion);
    cout << resultado(operacion[0], 0, operacion) << '\n';


} // casoDePrueba

int main() {

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }

    return 0;

} // main
