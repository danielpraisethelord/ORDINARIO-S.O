#include <iostream>
#include <vector>
#include <conio.h>


using namespace std;

class Particion {
public: 
    int id;
    int tamano;
    bool ocupado;
    std::string nombreProceso;

    Particion (int id, int tamano){
        this->id = id;
        this->tamano = tamano;
        this->ocupado = false;
        this->nombreProceso= "";
    }
};

class Proceso {
public:
    std::string nombre;
    int tamano;
    bool asignado;

    Proceso (std::string nombre, int tamano){
        this->nombre = nombre;
        this->tamano = tamano;
        this->asignado = false;
    }

};


int main () {
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

    int aux2=0;
    int auxP=0;

    //    particiones.push_back(Particion(cantidad+2, tamanoparticionN));
    
    int memoriaUtilizada = 0;
    int lastPartitionIndex = 0; // Índice de la última partición utilizada
    int tamanoParticionN = 0;
    particiones.push_back(Particion(cantidad+2, tamanoParticionN));

    int espacioNoUtilizado =0;
    
        for (Proceso& proceso : procesos) {
            bool asignado = false;

            for (size_t j = lastPartitionIndex; j < particiones.size()-2; j++) {
                Particion& particion = particiones[j];
                if (!particion.ocupado && particion.tamano >= proceso.tamano) {
                    particion.ocupado = true;
                    proceso.asignado=true;
                    particion.nombreProceso = proceso.nombre;

                    espacioNoUtilizado += (particion.tamano - proceso.tamano);

                    if (espacioNoUtilizado > 0) {
                        particion.tamano = proceso.tamano;
                        particiones.push_back(Particion(cantidad+2, espacioNoUtilizado));
                        //cout << "Se creó una nueva particion y se actulizo con: " << espacioNoUtilizado << "MB" << endl;
                    }

                    asignado = true;
                    cout << proceso.nombre << " Asignado a la particion " << particion.id << endl;
                    memoriaUtilizada += proceso.tamano;
                    lastPartitionIndex = j;
                    break;
                }
            }

            if (!asignado) {
                cout << proceso.nombre << " No fue asignado a memoria" << endl;
            }
        }

        for (Proceso& proceso : procesos) {
            if(!proceso.asignado){
                for (size_t j = lastPartitionIndex; j < particiones.size(); j++) {
                Particion& particion = particiones[j];
                if (!particion.ocupado && particion.tamano >= proceso.tamano) {
                    particion.ocupado = true;
                    particion.nombreProceso = proceso.nombre;

                    espacioNoUtilizado += (particion.tamano - proceso.tamano);

                    if (espacioNoUtilizado > 0) {
                        particion.tamano = proceso.tamano;
                        particiones.push_back(Particion(cantidad+2, espacioNoUtilizado));
                        cout << "Se creo una nueva particion de " << espacioNoUtilizado << "MB" << endl;
                    }

                    cout << proceso.nombre << " Asignado a la particion " << particion.id << endl;
                    memoriaUtilizada += proceso.tamano;
                    lastPartitionIndex = j;
                    break;
                }
            }

            }
        }






    cout <<endl<< "Sobraron " << memoriaTotal - memoriaUtilizada <<"mb de memoria"<<endl;
    getch();
    return 0;
}
