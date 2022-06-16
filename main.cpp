/*
 * EVIDENCIA PROYECTO TC1030.301
 * Castillo Sánchez Alan Rodrigo
 * A01708668
 * 14/06/22
 * Este proyecto realiza la cuenta total similar a lo que sería en un restaurante común
 * para poder añadir los consumibles específicos que el usuario desee, para darle una cuenta
 * total de todos estos consumibles desglosados con sus respectivos precios, y el total de la cuenta.
*/

#include <iostream> // para imprimir.

#include "Consumibles.h" // bibliotecas con objetos de mi proyecto.

#include"Cuenta.h"

using namespace std;

int main(){
Cuenta cuenta;
bool seguir = true;
while(seguir==true){
cout << "Bienvenido a la taqueria Los Primos\n" << "1. Ordenar\n2. La cuenta" << endl; int d;
cin >> d;
if(d==1){ bool ordenar = true;
while(ordenar==true){
cout << "Que desea ordenar?\n1. Tacos\n2. Bebidas" << endl; int r;
    cin >> r;
    if(r==1){
        cout << "Tacos disponibles:" << "\nSuadero\nPastor\nTripa\nCostilla\nQueso" << endl; string carne, tortilla; int cantidad;
        cin >> carne;
        cout << "Cantidad? " << endl;
        cin >> cantidad;
        cout << "Tortilla de maiz o harina? " << endl;
        cin >> tortilla;
        cuenta.agrega_tacos(carne, tortilla, cantidad);
        cout << "Desea ordenar mas? s/n\n";string m;
        cin >> m;
        if (m=="s"){
            ordenar=true;
        }
        else if(m=="n"){
            ordenar=false; 
            break;
        }
    }
    else if(r==2){
        cout << "1. Refrescos\n2. Aguas" << endl;
        cin >> r;
        if(r==1){
            cout << "Refrescos: \nCoca-Cola\nSprite\nFanta\nManzanita\nFresca" << endl; string refresco;
            cin >> refresco; string a;
            cout << "Cantidad? " << endl; int cantidadr;
            cin >> cantidadr;
            cuenta.agrega_bebidas(refresco, a, cantidadr);
            }
        else if(r==2){
            cout << "Aguas: \nNaranjada\nLimonada\nHorchata\nJamaica" << endl; string agua;
            cin >> agua; string r;
            cout << "Cantidad? " << endl; int cantidada;
            cin >> cantidada;
            cuenta.agrega_bebidas(r, agua, cantidada);
        }        
        cout << "Desea ordenar mas? s/n\n";string m;
        cin >> m;
        if (m=="s"){
            ordenar=true;
        }
        else if(m=="n"){
            ordenar=false;
            break;
        }
}}}
else if(d==2){
    cout << "Cuenta\n";
    cuenta.consumibles();
    cout << "\nTotal: " << cuenta.precio_total() <<"\n";
    seguir = false;
}}
system("pause");
return 0;
}