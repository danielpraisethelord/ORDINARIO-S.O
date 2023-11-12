#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

string binario (int numero);

int main() {
    int numero;
    cout << "Ingresa un numero entero positivo: "; cin >> numero;
    string numero2 = binario(numero);
    cout << "El numero en binario es: " << numero2;
    getch();
    return 0;
}

string binario (int numero){

    if (numero == 0){
        return  "0";
    } else if (numero < 0 ){
        return "No  se pudo realizar la conversion, ingresa solo numeros positivos";
    }


    string binario = "";
    if (numero>0){
        while (numero>0){
            if(numero%2 == 0){
                binario= "0"+binario;
            }
            else {
                binario = "1"+binario;
            }
            numero = numero / 2;
        }
    } 
    return binario;
}
