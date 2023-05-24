#include <iostream>

using namespace std;

class Movil
{
    string marca;
    string modelo;
    string so;

    public:
        Movil(string marca, string modelo, string so)
        {
            this->marca = marca;
            this->modelo = modelo;
            this->so = so;
        }

        virtual ~Movil() { cout << "Destructor Clase Movil" << endl; }

};

class Telefono : public Movil
{
    int numero;
    
    public:
        Telefono(string marca, string modelo, string so, int numero) : Movil(marca, modelo, so)
        {
            this->numero = numero;
        } 

        virtual ~Telefono() { cout << "Destructor Clase Telefono" << endl; }
};

class Tablet : public Movil 
{
    float pulgadas;

    public:
        Tablet(string marca, string modelo, string so, float pulgadas) : Movil(marca, modelo, so)
        {
            this->pulgadas=pulgadas ;
        }

        virtual ~Tablet() { cout << "Destructor Clase Tablet" << endl; }
};


int main()
{
    Telefono telefono("Huawei", "P20", "Android 15", 934145110);
    Tablet tablet("Xiaomi", "T15", "Android 12", 7.5);
    
    return 0;
}