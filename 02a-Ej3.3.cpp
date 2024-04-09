#include <iostream>
#include <bitset>
#include <conio.h>

using namespace std;

void configuracionInicial() {
    system("cls");
    cout << "Se puede cambiar la cantidad de bits "<<endl << endl;
}

int multiplicacion(int multiplicando, int multiplicador) {
    int resultado = 0;
    int multiplicandoAbs = abs(multiplicando);
    int multiplicadorAbs = abs(multiplicador);
    int producto = 0;
    int contador = 0;

    while (contador < 32) { //  <-- Aqui se cambia
        int lsbMultiplicador = multiplicadorAbs & 1;
        if (lsbMultiplicador == 1) {
            producto += multiplicandoAbs;
        }
        multiplicandoAbs <<= 1;
        multiplicadorAbs >>= 1;
        contador++;
    }

    if ((multiplicando < 0) ^ (multiplicador < 0)) {
        resultado = -producto;
    }
    else {
        resultado = producto;
    }

    return resultado;
}

string binario(int n) {
    return bitset<32>(n).to_string();
}

int main() {
    configuracionInicial(); 

    char opcion;
    do {
        int multiplicando, multiplicador;

        cout << "ingrese el multiplicando: ";
        cin >> multiplicando;

        cout << "ingrese el multiplicador: ";
        cin >> multiplicador;

        int producto = multiplicacion(multiplicando, multiplicador);

        cout << "resultado: " << producto << endl;
        cout << "resultado en binario: " << binario(producto) << endl;
        cout << "Q para salir, otra tecla para continuar--> ";
        opcion = getch();
        cout << endl;
    } while (toupper(opcion) != 'Q');

    return 0;
}
