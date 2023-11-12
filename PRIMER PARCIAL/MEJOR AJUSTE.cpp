#include <iostream>
#include <vector>

using namespace std;

class Particion {
public:
    int id;
    int tamano;
    bool ocupado;
    string nombreProceso;

    Particion (int id, int tamano){
        this->id = id;
        this->tamano = tamano;
        this->ocupado = false;
        this->nombreProceso = "";
    }
};

class Proceso {
public:
    string nombre;
    int tamano;
    bool asignado;

    Proceso (string nombre, int tamano){
        this->nombre = nombre;
        this->tamano = tamano;
        this->asignado = false;
    }
};

vector<int> ordenamientoBurbuja(vector<int> arr);

int main(){
    system("cls");

    int memoriaTotal, cantidad, aux, memoriaDisponible;
    vector <Particion> particiones;
    vector <Proceso> procesos;

    cout << "Ingresa el tamanio total de tu memoria (EL S.O OCUPA 300MB POR DEFAULT): ";
    cin >> memoriaTotal;
    cout << endl << "Ingresa la cantidad de particiones a realizar: ";
    cin >> cantidad;
    cout << endl;
    memoriaDisponible = memoriaTotal - 300;
    particiones.push_back(Particion(1, 300));

    

        for (int i = 2; i <= cantidad + 1; i++) {
            cout << "Ingresa el tamanio de tu particion " << i << ": ";
            cin >> aux;

                if (aux <= memoriaDisponible) {
                    particiones.push_back(Particion(i, aux));
                    cout << "Se asigno correctamente la particion a la memoria" << endl<<endl;
                    memoriaDisponible -= aux;
                }   else {
                        cout << "No hay espacio disponible en la memoria para asignar la particion" << endl;
                        cout << "Intentalo de nuevo." << endl<<endl;
                        i--; // Reintentar con la misma 'i'
                        }
        }

    string programaD, programaY, programaS, programaG;
    int procesoD, procesoY, procesoS, procesoG;
    cout << "Ingrese un programa con la letra 'D' para asignarle un proceso: "<<endl;
    cin >> programaD; 
    cout << "Ingrese el tamaio de memoria que ocupara el proceso: "<<endl;
    cin >> procesoD; cout <<endl;
    cout << "Ingrese un programa con la letra 'Y' para asignarle un proceso: "<<endl;
    cin >> programaY; 
    cout << "Ingrese el tamanio de memoria que ocupara el proceso: "<<endl;
    cin >> procesoY;  cout <<endl;  
    cout << "Ingrese un programa con la letra 'S' para asignarle un proceso: "<<endl;
    cin >> programaS; 
    cout << "Ingrese el tamanio de memoria que ocupara el proceso: "<<endl;
    cin >> procesoS; cout <<endl;
    cout << "Ingrese un programa con la letra 'G' para asignarle un proceso: "<<endl;
    cin >> programaG;
    cout << "Ingrese el tamanio de memoria que ocupara el proceso: "<<endl;
    cin >> procesoG; cout <<endl;

    procesos.push_back(Proceso("S.O (DEFAULT)", 300));
    procesos.push_back(Proceso(programaD, procesoD));
    procesos.push_back(Proceso(programaY, procesoY));
    procesos.push_back(Proceso(programaS, procesoS));
    procesos.push_back(Proceso(programaG, procesoG)); 
    

    cout << " " <<endl<<endl;   
        int memoriaUtilizada = 0;

 for (Proceso& proceso : procesos) {
        bool asignado = false;
        int bestFitIndex = -1;
        int bestFitDiff = INT_MAX;

        for (size_t j = 0; j < particiones.size(); j++) {
            Particion& particion = particiones[j];

            if (!particion.ocupado && particion.tamano >= proceso.tamano) {
                int diff = particion.tamano - proceso.tamano;
                if (diff < bestFitDiff) {
                    bestFitIndex = j;
                    bestFitDiff = diff;
                }
            }
        }

        if (bestFitIndex != -1) {
            particiones[bestFitIndex].ocupado = true;
            particiones[bestFitIndex].nombreProceso = proceso.nombre;
            std::cout << proceso.nombre << " Asignado a la particion " << particiones[bestFitIndex].id << std::endl;
            memoriaUtilizada += proceso.tamano;
            asignado = true;
        }

        if (!asignado) {
            std::cout << proceso.nombre << " No fue asignado a memoria" << std::endl;
        }
    }

    return 0;
}


vector<int> ordenamientoBurbuja(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar elementos si están en el orden incorrecto
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}