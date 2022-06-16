/*
 * EVIDENCIA PROYECTO TC1030.301
 * Castillo Sánchez Alan Rodrigo
 * A01708668
 * 14/06/22
 * Esta clase define el objeto tipo Consumibles que contiene las clases 
 * heredadas Tacos y Bebidas
*/

#ifndef CONSUMIBLES_H_
#define CONSUMIBLES_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//Declaración de clase Consumibles que es abstracta
class Consumibles{

    //Declaro variables de instacia 
    protected:
    string tipo;
    int cantidad;
    int precio;

    //Declaro los métodos que va a tener el objeto
    public:
    Consumibles(): tipo(""), cantidad(0){}; //Constructor por default
    Consumibles(int p, string t, int c): tipo(t), cantidad(c){}; 

    int get_precio() {
        return precio;
        }
    int get_cantidad() {
        return cantidad;
        }
    string get_tipo() {
        return tipo;
    }

    virtual void set_precio()=0;    //Método abstracto será sobreescrito
    virtual void print_precio()=0;  
    virtual string to_string()=0;   
};


//Declaro objeto Tacos que hereda de Consumibles 
class Tacos:public Consumibles{

    //Variables de instacia del objeto
    private:
    string carne;
    string tortilla;

    //Métodos del objeto
    public:
    Tacos():carne(""), tortilla(""){};
    Tacos(string ca, string t, int c){ 
        tipo="taco";cantidad = c; carne = ca; tortilla = t;
        } 

    void set_carne(string c) {
        carne = c;
        }
    void set_tortilla(string t) {
        tortilla = t;
        }
    
    string to_string();
    void print_precio();
    void set_precio();
};

/**
 * to_string convierte los atributos a string.
 * Concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */

string Tacos::to_string(){
    stringstream aux;
    aux << "1 taco de " << carne << " con tortilla de " << tortilla;
    return aux.str();
}

/**
 * print_precio imprime el precio del objeto tipo Taco al que se le llame
 */

void Tacos::print_precio(){
    cout << "$" << get_precio() << "MXN";
}

/**
 * set_precio establece el precio de tipo taco
 * 
 * Depende del tipo de carne (o quesadilla), el precio que se establecerá
 * al objeto 
 */

void Tacos::set_precio(){
    if(carne=="Queso"){
        precio = 15;
    }
    else if(carne=="Pastor"){
        precio = 25;
    }
    else{
        precio = 20;
    }
}


//Declaro objeto Bebidas que hereda de Consumibles 
class Bebidas:public Consumibles{

    //Declaro las variables de instancia del objeto
    private:
    string refresco;
    string agua;

    // Declaro métodos públicos del objeto
    public:
    Bebidas(): refresco(""), agua(""){};
    Bebidas(string r, string a, int c){
        tipo = "bebida"; refresco = r; agua = a; cantidad = c;
        }

    void set_refresco(string r) {
        refresco = r;
        }
    void set_agua(string a) {
        agua = a;
    }

    
    string to_string();
    void print_precio();
    void set_precio();
};

/**
 * to_string convierte los atributos a string.
 * Concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */

string Bebidas::to_string(){
    stringstream aux;
    aux << "1 " << refresco << agua;
    return aux.str();
}

void Bebidas::print_precio(){
    cout << "$" << get_precio() << "MXN";
}

void Bebidas::set_precio(){
    if(refresco!=""){
        precio = 25;
    }
    else if(agua!=""){
        precio = 15;
    }
}

#endif