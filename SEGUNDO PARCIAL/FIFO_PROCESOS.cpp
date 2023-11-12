#include <iostream>
#include <conio.h>
#include "LIBRERIA.h"
#include <vector>

using namespace std;

struct lista {
    string nombreProceso;
    int tiempoLlegada;
    int tiempoCPU;
    int prioridad;
    int numeroProceso;
    int inicio;
    int fin;
    int tiempoEspera;
    struct lista *next;
};

typedef struct lista LISTA;
typedef LISTA *apuntador_lista;

void imprimir(apuntador_lista actual);
void prioridad (apuntador_lista *cabeza);
void swapProcesos(apuntador_lista proceso1, apuntador_lista proceso2);
void enqueue(apuntador_lista *cabeza, apuntador_lista *fin, string Nombre, int llegada, int cpu);

int main (){
    system ("cls");
    apuntador_lista nuevoNodo = NULL, fin=NULL;

    float Numeroprocesos;

    cout << "Digite el numero de procesos a ingresar: "; cin >> Numeroprocesos;
    cout << endl;

    string NombreProceso;
    int llegada, cpu;
    for (int i=0; i< Numeroprocesos; i++){
        cout << "Digite el nombre del Proceso " << i << " ";
        cin.ignore();
        getline(cin, NombreProceso);
        cout << "Digite el tiempo de llegada de " << NombreProceso << " "; cin >> llegada;
        cout << "Digite el tiempo en CPU de " << NombreProceso << " "; cin >> cpu;
        enqueue(&nuevoNodo,&fin,NombreProceso,llegada,cpu);
    }
    system ("cls");
    prioridad(&nuevoNodo);
    apuntador_lista actual = nuevoNodo;
    apuntador_lista actual2=nuevoNodo;
    

    int contador=0;
    for (int i=0;i<Numeroprocesos;i++){
        contador+=actual2->tiempoCPU;
        actual2=actual2->next;
    }

    int aux2 = 0;
while (actual != NULL) {
    actual->inicio = aux2;
    aux2 += actual->tiempoCPU;
    actual->fin = (actual->tiempoCPU + actual->inicio) - 1;
    actual->tiempoEspera = actual->inicio - actual->tiempoLlegada;
    actual = actual->next; 
}


     apuntador_lista copiaActual = nuevoNodo;
    int aux3=0;
    posxy(1,1); cout << "NOMBRE DEL PROCESO";
    posxy(21,1); cout << "LLEGADA";
    posxy(30,1); cout << "TIMEPO EN CPU";
    posxy(45,1); cout << "INICIO";
    posxy(53,1); cout << "FIN";
    posxy(59,1); cout << "TIEMPO EN ESPERA";
    float sumEspera=0, sumRegresion=0;
    for (int i = 0; i < Numeroprocesos; i++) {
        posxy(1,(i+1)*2); cout << copiaActual->nombreProceso;
        posxy(21,(i+1)*2); cout << copiaActual->tiempoLlegada;
        posxy(30,(i+1)*2); cout << copiaActual->tiempoCPU;
        posxy(45,(i+1)*2); cout << copiaActual->inicio;
        posxy(53,(i+1)*2); cout << copiaActual->fin;
        posxy(59,(i+1)*2); cout << copiaActual->tiempoEspera;
        sumEspera+=copiaActual->tiempoEspera;
        sumRegresion+= copiaActual->fin;
        copiaActual = copiaActual->next;
        aux3=(i+1)*2;
    }

    // IMPRIMIR SEGUNDA MATRIZ
    cout << endl << endl << endl;
    apuntador_lista nuevo5 = nuevoNodo;

    posxy(1,aux3+2); cout << "PROCESOS";
    for (int i=0; i<contador;i++){
        posxy(11+i*4,aux3+2);cout << i;
    }

    for (int i=0; i<Numeroprocesos;i++){
        posxy(1,(aux3+4)+i*2); cout << nuevo5->nombreProceso;
        nuevo5=nuevo5->next;
    }



    vector<vector<char>> matrizProcesos(Numeroprocesos, vector<char>(contador, ' '));
   

apuntador_lista nuevo6 = nuevoNodo;
apuntador_lista auxNuevo6;

for (int tiempo = 0; tiempo < contador; tiempo++) {
    nuevo6 = nuevoNodo; // Reiniciar el puntero al principio de la lista
    auxNuevo6 = nuevoNodo;

    for (int i = 0; i < Numeroprocesos; i++) {
        if (tiempo >= nuevo6->inicio && tiempo <= nuevo6->fin) {
            matrizProcesos[i][tiempo] = 'E';
        } else if (tiempo >= nuevo6->tiempoLlegada && tiempo < nuevo6->inicio) {
            matrizProcesos[i][tiempo] = 'P';
        }
        nuevo6 = nuevo6->next;
    }
}


for (int i = 0; i < Numeroprocesos; i++) {
    for (int j = 0; j < contador; j++) {
        posxy(11+j*4,(aux3+3)+i*2+1);cout << matrizProcesos[i][j] << " ";
    }
    cout << endl;
} 
    
    cout <<endl<<endl<< " TIEMPO DE ESPERA: "<< sumEspera/Numeroprocesos<<endl;
    cout << "TIEMPO DE REGRESION:  " << sumRegresion/Numeroprocesos;
    getch();
    return 0;
}


void imprimir(apuntador_lista actual)
{
    if(actual==NULL){
        cout<<"La lista esta vacia"<<endl;
    }
    else{
        cout<<"La lista es:\t"<<endl;
        while(actual!=NULL){
            cout<<"-->"<<actual->nombreProceso << " ," << actual->tiempoLlegada<< ", " << actual->tiempoCPU << "NumProceso: "<<actual->numeroProceso;
            actual=actual->next;
            cout <<endl;
        }
        cout<<"NULL"<<endl;
    }
}

void swapProcesos(apuntador_lista proceso1, apuntador_lista proceso2) {
    string Nombre = proceso1->nombreProceso;
    int TiempoLlegada = proceso1->tiempoLlegada;
    int TiempoCPU = proceso1->tiempoCPU;
    int Prioridad = proceso1->prioridad;

    proceso1->nombreProceso = proceso2->nombreProceso;
    proceso1->tiempoLlegada = proceso2->tiempoLlegada;
    proceso1->tiempoCPU = proceso2->tiempoCPU;
    proceso1->prioridad = proceso2->prioridad;
    
    proceso2->nombreProceso = Nombre;
    proceso2->tiempoLlegada = TiempoLlegada;
    proceso2->tiempoCPU = TiempoCPU;
    proceso2->prioridad = Prioridad;
}


void prioridad(apuntador_lista* cabeza) {
    apuntador_lista actual, siguiente;
    
    actual = *cabeza;

    while (actual->next!=NULL){
        siguiente=actual->next;
        while(siguiente!=NULL){
            if(actual->prioridad > siguiente->prioridad){
                swapProcesos(actual,siguiente);
                
            }
            siguiente=siguiente->next;
        }
        actual=actual->next;
    }
}

void enqueue(apuntador_lista *cabeza, apuntador_lista *fin, string Nombre, int llegada, int cpu) {
    apuntador_lista nuevoNodo = new LISTA();
    nuevoNodo->nombreProceso = Nombre;
    nuevoNodo->tiempoLlegada = llegada;
    nuevoNodo->tiempoCPU = cpu;
    nuevoNodo->prioridad = llegada;
    nuevoNodo->next = NULL;

    if (*cabeza == NULL) {
        // Si la cola está vacía, establece el nuevo nodo como el primer y último elemento.
        *cabeza = nuevoNodo;
        *fin = nuevoNodo;
    } else {
        // Si la cola no está vacía, enlaza el último nodo al nuevo nodo y actualiza fin.
        (*fin)->next = nuevoNodo;
        *fin = nuevoNodo;
    }
}



