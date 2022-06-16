/*
 * EVIDENCIA PROYECTO TC1030.301
 * Castillo Sánchez Alan Rodrigo
 * A01708668
 * 14/06/22
 * Esta clase define el objeto tipo Cuenta con todos los métodos
 * para agregar lo que el cliente consuma para tener una lista final
 * con su comidas y bebidas e imprimirle el precio total dependiendo del 
 * consumo.
*/

#ifndef CUENTA_H_
#define CUENTA_H_

#include <string>

#include <sstream>
#include "Consumibles.h" //biblioteca con mis objetos a usar
using namespace std;

const int MAX = 100; //constante de tamaño de arreglos

class Cuenta{

    //Declaro las variables privadas de instancia
    private:
    int cantidadtotal;
    Consumibles* comida[MAX]; //se define como apuntador para usar polimorfismo
    
    //Declaro constructor por default y metodos públicos.
    public:
    Cuenta(){cantidadtotal=0;}; //constructor por defualt
    Cuenta(int, Consumibles*[]);
    
    int get_cantidadt(){return cantidadtotal;}

    void consumibles();
    int precio_total();
    void agrega_tacos(string, string, int);
    void agrega_bebidas(string, string, int);
};

Cuenta::Cuenta(int c, Consumibles *co[]){
    cantidadtotal = c;
    for(int i=0; i<cantidadtotal;i++){
        comida[i] = co[i];
    }
}


    /**
     * consumibles imprime todos los atributos que se deben ver
     * reflejados en una cuenta total de algún restaurante para 
     * el conteo de comida total consumida y sus atributos específicos
     * de cada consumible 
     *
     * @param
     */

void Cuenta::consumibles(){
    string taco, bebida;
    for(int i = 0; i < cantidadtotal; i++){
        if(comida[i]->get_tipo()=="taco"){
            taco = comida[i]->to_string();
            cout << taco << " "; comida[i]->print_precio();
            cout << "\n";
        }
        else if(comida[i]->get_tipo()=="bebida"){
            bebida = comida[i]->to_string();
            cout << bebida << " "; comida[i]->print_precio();
            cout << "\n";
        }
        else{
            cout << "No se especifica el tipo de consumible";
        }
    } 
}

/**
 * precio_total calcula el precio total de los consumibles (comida[])
 * 
 * Mediante un ciclo for, toma uno a uno los consumibles dentro del arreglo
 * y obtiene su precio, luego lo suma y lo almacena en la variable pt
 * que es la variable que regresa en el retun
 * 
 * @return int 
 */

int Cuenta::precio_total(){int pt=0;
    for(int i = 0; i < cantidadtotal; i++){
        if(comida[i]->get_tipo() == "taco"){
            pt = pt + comida[i]->get_precio();
        }
        else if(comida[i]->get_tipo() == "bebida"){
            pt = pt + comida[i]->get_precio();
        }
    }
    return pt;
}

/**
 * agraga_tacos es una función que se encarga de añadir al arreglo de 
 * consumibles (comida[]) un objeto de tipo taco
 * Por un ciclo for, crea un nuevo objeto de tipo Taco en el heap mediante
 * el uso de la palabra reservada 'new'
 * para usar el polimorfismo y lo añade al siguiente número del arreglo 
 * dinámico ya guardado para poder modificarlo 
 * @param  
 */

void Cuenta::agrega_tacos(string carne, string tortilla, int cantidad){
    for(int i = cantidadtotal; i < (cantidadtotal+cantidad); i++){
        comida[i] = new Tacos(carne,tortilla, cantidad);
        comida[i]->set_precio();
    }
    cantidadtotal=cantidadtotal+cantidad;
}

/**
 * agraga_bebidas es una función que se encarga de añadir al arreglo de 
 * consumibles (comida[]) un objeto de tipo bebida
 * 
 * Por un ciclo for, crea un nuevo objeto de tipo Bebidas en el heap mediante
 * el uso de la palabra reservada 'new' para usar el polimorfismo y lo añade al
 * siguiente número del arreglo dinámico ya guardado para poder modificarlo 
 * @param  
 */

void Cuenta::agrega_bebidas(string refresco, string agua, int cantidad){
    for(int i = cantidadtotal; i < cantidadtotal+cantidad; i++){
        comida[i] = new Bebidas(refresco, agua, cantidad);
        comida[i]->set_precio();
    }
    cantidadtotal=cantidadtotal+cantidad;
}




#endif 
