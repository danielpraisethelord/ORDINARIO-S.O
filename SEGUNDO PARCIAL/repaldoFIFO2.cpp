#include <iostream>
#include <conio.h>
#include "LIBRERIA.h"

using namespace std;

struct lista {
    int dato;
    struct lista *next;
};

typedef struct lista LISTA;
typedef LISTA *apuntador_lista;

int main () {
    int RefP;
    cout << "Ingrese la cantidad de paginas a ingresar: ";
    cin>>RefP;
    int Vector[RefP];
    cout << "Ingresa la secuencia: "<<endl;
    for (int i=0; i<RefP; i++){
        cin>>Vector[i];
    }

    int Matriz[4][RefP] = {0},PD=0, HIT=0;

    for (int i = 0; i < RefP; i++) {
        bool encontrado = false;
        for (int j = 0; j < 4; j++) {

            
            if (Matriz[j][i] == Vector[i]) {
                encontrado = true;
                HIT++;
                break;
            }
        }
        if (!encontrado) {
            for (int j = 0; j < 4; j++) {
                if (Matriz[j][i] == 0) {
                    Matriz[j][i] = Vector[i];
                    PD++;
                    break;
                }
            }
        }
    }


cout << "Hubo un total de " << PD << " Fallos de pagina"<<endl;
cout << "Hubo un total de " << HIT << " Aciertos de pagina";

    getch();
    system ("cls");
    color(14);cuadriculaM(4,RefP,1,1);
    for (int i=0;i<4;i++){
        for (int j=0;j<RefP;j++){
            posxy(1 + 8*j+3, 1 + i*2+1); color(12);cout << Matriz[i][j];
        }
        }
    getch();
    return 0;
}