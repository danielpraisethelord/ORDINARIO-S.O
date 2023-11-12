#include <iostream>
#include <vector>

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

int main() {
    int memoriaTotal = 1000;

    std::vector<Particion> particiones;
    std::vector<Proceso> procesos;

    particiones.push_back(Particion(1, 200));
    particiones.push_back(Particion(2, 300));
    particiones.push_back(Particion(3, 500));

    procesos.push_back(Proceso("1", 310));
    procesos.push_back(Proceso("2", 250));
    procesos.push_back(Proceso("3", 501));

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
                break;
            }
        }

        if (!asignado) {
            std::cout << proceso.nombre << " No fue asignado a memoria" << std::endl;
        }
    }

    return 0;
}


//Realizar un programa que pida al usuario la cantidad de particiones 
//Pedir 3 procesos
