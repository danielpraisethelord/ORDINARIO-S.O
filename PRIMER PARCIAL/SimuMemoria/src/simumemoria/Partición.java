/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simumemoria;


/**
 *
 * @author danie
 */
public class Partición {

        int id;
    int tamano;
    boolean ocupada;
    String nombreProceso;
    
    public Partición (int id, int tamano){
        this.id = id;
        this.tamano = tamano;
        this.ocupada = false;
        this.nombreProceso = "";
    }
}
