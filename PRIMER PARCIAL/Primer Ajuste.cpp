#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class Particion {
public:
    int id;
    int tamano;
    bool ocupada;
    std::string nombreProceso;

    Particion(int id, int tamano) {
        this->id = id;
        this->tamano = tamano;
        this->ocupada = false;
        this->nombreProceso = "";
    }
};

class Proceso {
public:
    std::string nombre;
    int tamano;

    Proceso(std::string nombre, int tamano) {
        this->nombre = nombre;
        this->tamano = tamano;
    }
};

int main () {
    system ("cls");
    int memoriaTotal, cantidad, aux;

    vector <Particion> particiones;
    vector <Proceso> procesos;

    cout << "Ingresa el tamanio total de tu memoria (EL S.O OCUPA 100MB POR DEFAULT): ";
    cin >> memoriaTotal;
    cout << endl << "Ingresa la cantidad de particiones a realizar: ";
    cin >> cantidad;
    cout << endl;
    particiones.push_back(Particion(1, 100));
    
int memoriaDisponible = memoriaTotal - 100;

        for (int i = 2; i <= cantidad + 1; i++) {
    cout << "Ingresa el tamanio de tu particion " << i << ": ";
    cin >> aux;

    if (aux <= memoriaDisponible) {
        particiones.push_back(Particion(i, aux));
        cout << "Se asigno correctamente la particion a la memoria" << endl<<endl;
        memoriaDisponible -= aux;
    } else {
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
   // cout << "Ingrese un programa con la letra 'G' para asignarle un proceso: "<<endl;
   // cin >> programaG;
    //cout << "Ingrese el tamanio de memoria que ocupara el proceso: "<<endl;
   // cin >> procesoG; cout <<endl;

    procesos.push_back(Proceso("S.O (DEFAULT)", 100));
    procesos.push_back(Proceso(programaD, procesoD));
    procesos.push_back(Proceso(programaY, procesoY));
    procesos.push_back(Proceso(programaS, procesoS));
    //procesos.push_back(Proceso(programaG, procesoG)); 

    cout << " " <<endl<<endl;
    

  int aux2=0;
for (size_t i = 0; i < procesos.size(); i++) {
    Proceso proceso = procesos[i];
    bool asignado = false;
    

    for (size_t j = 0; j < particiones.size(); j++) {
        
        Particion& particion = particiones[j];
        if (!particion.ocupada && particion.tamano >= proceso.tamano) {
            
            particion.ocupada = true;
            particion.nombreProceso = proceso.nombre;
            asignado = true;
            std::cout << proceso.nombre << " Asignado a la particion " << particion.id << std::endl;
            //aux2 = aux2 + (particiones[j].tamano - procesos[i].tamano);
            aux2+=proceso.tamano;
            break;
        
        }
            //if (!particion.ocupada && proceso.tamano > particion.tamano) {
                //aux2 = aux2 + particiones[j].tamano;
            //} 
    }


            if (!asignado) {
            std::cout << proceso.nombre << " No fue asignado a memoria" << std::endl;
        }
    } 

    cout<<endl<<"Sobraron "<<memoriaTotal - aux2<<"mb de memoria"<<endl;

	getch();
    return 0;
} 
