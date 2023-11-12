#include <iostream>
#include <conio.h>
#include "LIBRERIA.h"
#include <vector>
#include <string>
using namespace std;

struct Cola{
    string NombreProceso;
    int MomemtoLlegada;
    int TiempoEjecucion;
    int ProcesoCompletado;
    int TiempoServicio;
    int TiempoEspra;
    int prioridadLlegada;
    int prioridadTiempoEjecucion;
    struct Cola *next;
};

typedef struct Cola COLA;
typedef COLA *apuntador_cola;
void enqueue(apuntador_cola *cabeza, apuntador_cola *fin, string Nombre, int MLL, int TE);
void imprimir (apuntador_cola *cabeza);
void prioridad (apuntador_cola *cabeza);
void dequeue2 (apuntador_cola *cabeza, apuntador_cola *fin);
void swapProcesos(apuntador_cola proceso1, apuntador_cola proceso2);

int main (){
    system("cls");
    


    apuntador_cola cabeza= NULL, fin =NULL;
    int NumProcesos;
    cout << "Ingrese la cantidad de procesos a introducir: "; cin >> NumProcesos;
    string Nombre;
    int MLL, TE;
    for (int i=0; i<NumProcesos; i++){
        cout << "Ingrese el Nombre del Proceso " << i+1 << " "; 
        cin.ignore(); getline(cin,Nombre);
        cout << endl << "Ingrese el Momento de LLegada del Proceso " << Nombre << " "; cin >> MLL;
        cout << endl << "Ingrese el Tiempo de Ejecucion del Proceso " << Nombre << " "; cin >> TE;
        enqueue(&cabeza,&fin,Nombre,MLL,TE);
    }
    prioridad(&cabeza);
    getch();
    system("cls");
    //imprimir(&cabeza);

    int auxPC=0;

    apuntador_cola actual=cabeza;

    for (int i=0; i<NumProcesos;i++){
        actual->ProcesoCompletado=actual->TiempoEjecucion+auxPC;
        actual->TiempoServicio=actual->ProcesoCompletado-actual->MomemtoLlegada;
        actual->TiempoEspra = actual->TiempoServicio-actual->TiempoEjecucion;
        auxPC+=actual->TiempoEjecucion;
        actual=actual->next;
    }

    posxy(1,1); cout << "Nombre del Proceso";
    posxy(22,1); cout << "Momento de Llegada";
    posxy(42,1); cout << "Tiempo de Ejecucion";
    posxy(64,1); cout << "Proceso completado";
    posxy(85,1); cout << "Tiempo de Servicio";
    posxy(106,1); cout << "Tiempo en espera";

    actual=cabeza; int auxContador=0, contadorTiempo;
    for (int i=0; i<NumProcesos;i++){
        posxy(1,2+i*2); cout << actual->NombreProceso;
        posxy(32,2+i*2); cout << actual->MomemtoLlegada;
        posxy(54,2+i*2); cout << actual->TiempoEjecucion;
        posxy(74,2+i*2); cout << actual->ProcesoCompletado;
        posxy(95,2+i*2); cout << actual->TiempoServicio;
        posxy(114,2+i*2); cout << actual->TiempoEspra;
        auxContador=(2+i*2);
        contadorTiempo=actual->ProcesoCompletado;
        actual=actual->next;
    }

    //IMPRIMIR SEGUNDA MATRIZ
    vector<vector<string>> matriz(contadorTiempo+1,vector<string>(4));
    actual=cabeza;

    posxy(1,auxContador+2); cout << "Tiempo";
    /*posxy(10,auxContador+2); cout << "Llegada";
    posxy(20,auxContador+2); cout << "Cola";
    posxy(40,auxContador+2); cout << "CPU";
    posxy(46,auxContador+2); cout << "Salida";*/
    posxy(85,auxContador+2); cout << "Tiempo";

    for (int i=0; i<contadorTiempo+1; i++){
        posxy(1,(auxContador+3)+i*2); cout << i;
        posxy(85,(auxContador+3)+i*2); cout << i;
    }

    //for (int i=0;i<4;i++){
        for (int tiempo=0; tiempo<contadorTiempo+1; tiempo++){
            actual = cabeza;
             while (actual != NULL) {
                 if (tiempo == actual->MomemtoLlegada) {
              // Concatenar el momento de llegada en la primera columna
                matriz[tiempo][0] = actual->NombreProceso;
                 } 
                 if (tiempo >= actual->MomemtoLlegada && tiempo < actual->MomemtoLlegada+actual->TiempoEspra) {
                 // Concatenar el tiempo de ejecución en la segunda columna
                 matriz[tiempo][1] += actual->NombreProceso + ",";
                 }  
                 if (tiempo>=actual->MomemtoLlegada+actual->TiempoEspra && tiempo<actual->ProcesoCompletado){
                    matriz[tiempo][2] = actual->NombreProceso;
                 }

                 if(tiempo==actual->ProcesoCompletado){
                    matriz[tiempo][3]=actual->NombreProceso;
                 }
              actual = actual->next;
              }
        }
    //}

    int columna_x = 10; // La posición inicial x para la primera columna

    // Etiquetas para cada columna
    string etiquetas[] = { "Llegada", "Cola", "CPU", "Salida" };

for (int col = 0; col < 4; col++) {
    posxy(columna_x, auxContador + 2); cout << etiquetas[col]; // Imprimir etiqueta
    for (int fila = 0; fila < contadorTiempo+1; fila++) {
        posxy(columna_x, (auxContador + 3) + fila * 2); // Posición para imprimir el valor
        cout << matriz[fila][col]; // Imprimir el valor de la matriz
    }
    columna_x += 20; // Ajusta la posición x para la siguiente columna
}
    



    //cin.get();
    getch();
    return 0;
}


void enqueue(apuntador_cola *cabeza, apuntador_cola *fin, string Nombre, int MLL, int TE) {
    apuntador_cola nuevoNodo = new COLA();
    nuevoNodo->NombreProceso = Nombre;
    nuevoNodo->MomemtoLlegada = MLL;
    nuevoNodo->TiempoEjecucion = TE;
    nuevoNodo->prioridadLlegada = MLL;
    nuevoNodo->prioridadTiempoEjecucion = TE;
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

void imprimir (apuntador_cola *cabeza){
    apuntador_cola actual;
    actual = *cabeza;
    if (actual == NULL){
        cout << "Cola vacia"<<endl;
    } else {
        cout << "Los elementos de la cola son: "<<endl<<endl;
        while (actual!=NULL){
            cout <<actual->NombreProceso << " " << "MLL: " << actual->MomemtoLlegada << " TE: " << actual->TiempoEjecucion << " PC: " << actual->ProcesoCompletado << " TS: " << actual->TiempoServicio << " TE: "<<actual->TiempoEspra<<endl;
            actual=actual->next;
        }
        cout << "NULL"<<endl;
    }
}

void prioridad (apuntador_cola *cabeza){
    apuntador_cola actual, siguiente, actual2,siguienteSiguiente, procesoElegido;
    string Nombre;
    int MLL, TE, PrioLLegada, PrioTE;

    actual=*cabeza;

    while (actual->next!=NULL){
        siguiente=actual->next;
        while(siguiente!=NULL){
            if(actual->prioridadLlegada > siguiente->prioridadLlegada){
                swapProcesos(actual,siguiente);
            } else if (siguiente->prioridadLlegada == actual->prioridadLlegada) {
                if (siguiente->prioridadTiempoEjecucion < actual->prioridadTiempoEjecucion) {
                    swapProcesos(actual, siguiente);
                }
            }
            siguiente=siguiente->next;
        }
        actual=actual->next;
    }
    
    actual=*cabeza;
    actual2=actual->next;
    int aux=0;
    while (actual != NULL) {
    siguiente = actual->next;
    aux += actual->MomemtoLlegada + actual->TiempoEjecucion; // Momento en que termina el proceso actual
    procesoElegido = NULL;

    // Encuentra el proceso con el tiempo de ejecución más corto dentro del intervalo
    while (siguiente != NULL) {
        if (siguiente->MomemtoLlegada <= aux) {
            if (procesoElegido == NULL || siguiente->TiempoEjecucion < procesoElegido->TiempoEjecucion) {
                procesoElegido = siguiente;
            }
        }
        siguiente = siguiente->next;
    }

    // Si se encontró un proceso elegido, intercámbialo con el proceso actual
    if (procesoElegido != NULL) {
        swapProcesos(actual->next, procesoElegido);
    }

    actual = actual->next;
}


}


void dequeue2 (apuntador_cola *cabeza, apuntador_cola *fin){
    apuntador_cola temporal;
    if((*cabeza)!=NULL){
        temporal=*cabeza;
        delete temporal;
        if((*cabeza)==NULL){
            *fin=NULL;
        }
    } 
}

void swapProcesos(apuntador_cola proceso1, apuntador_cola proceso2) {
    string Nombre = proceso1->NombreProceso;
    int MLL = proceso1->MomemtoLlegada;
    int TE = proceso1->TiempoEjecucion;
    int PrioLLegada = proceso1->prioridadLlegada;
    int PrioTE = proceso1->prioridadTiempoEjecucion;

    proceso1->NombreProceso = proceso2->NombreProceso;
    proceso1->MomemtoLlegada = proceso2->MomemtoLlegada;
    proceso1->TiempoEjecucion = proceso2->TiempoEjecucion;
    proceso1->prioridadLlegada = proceso2->prioridadLlegada;
    proceso1->prioridadTiempoEjecucion = proceso2->prioridadTiempoEjecucion;

    proceso2->NombreProceso = Nombre;
    proceso2->MomemtoLlegada = MLL;
    proceso2->TiempoEjecucion = TE;
    proceso2->prioridadLlegada = PrioLLegada;
    proceso2->prioridadTiempoEjecucion = PrioTE;
}