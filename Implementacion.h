#include <iostream>
#include <sstream>
using namespace std;

class Fecha{
    private:
    int mes;
    int ano;

    public:
    Fecha();
    Fecha(int, int);
    int getMes();
    int getAno();
    void setMes(int);
    void setAno(int);
    int reporte();
};

class Tarjeta{
    private:
    string numero;
    string Titular;
    Fecha Vencimiento;
    int CVV;

    public:
    Tarjeta();
    Tarjeta(string, string, int, int, int);
    string getNumero();
    string getTitular();
    Fecha getVencimiento();
    int getCVV();
    void setNumero(string);
    void setTitular(string);
    void setVencimiento(int, int);
    void setCVV(int);
    int reporte();
};

class Articulo{
    private:
    string objeto;
    int precio;

    public:
    Articulo();
    Articulo(string, int);
    string getObjeto();
    int getPrecio();
    void setObjeto(string);
    void setPrecio(int);
    string reporte();
};

class Comprador{
    private:
    string usuario;
    string contrasena;
    string correo;
    string direccion;
    int CP;
    string cel;
    Tarjeta tarjeta; 

    public:
    Comprador();
    Comprador(string, string, string, string, int, string, string, string, int, int, int);
    string getUsuario();
    string getContrasena();
    string getCorreo();
    string getDireccion();
    int getCP();
    string getCel();
    Tarjeta getTarjeta();
    void setUsuario(string);
    void setContra(string);
    void setCorreo(string);
    void setDireccion(string);
    void setCP(int);
    void setCel(string);
    void setTarjeta(string, string, int, int, int);
    int comprar(Articulo);
};