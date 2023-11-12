/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simumemoria;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author danie
 */
public class SimuMemoria {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int memoriaTotal = 1000;
        
        List<Partición> particiones = new ArrayList<>();
        List<Proceso> procesos = new ArrayList <>();
        
        particiones.add(new Partición(1,200));
        particiones.add(new Partición(2,300));
        particiones.add(new Partición(3,500));
        
        procesos.add(new Proceso("1",310));
        procesos.add(new Proceso("2",250));
        procesos.add(new Proceso("3",501));
        
        for (int i=0; i<procesos.size();i++){
            Proceso proceso = procesos.get(i);
            boolean asignado = false;
            
            for (int j=0; j<particiones.size(); j++){
                Partición particion = particiones.get(j);
                if (!particion.ocupada  && particion.tamano >= proceso.tamano) {
                    particion.ocupada = true;
                    asignado = true;
                    System.out.println(proceso.nombre + " Asignado a la particion " + particion.id);
                    break;
                    
                }
                
            }
            if (!asignado) {
                System.out.println(proceso.nombre+ " No fuiste asignado a memoria");
            }
            
        }
        
    }
    
}
