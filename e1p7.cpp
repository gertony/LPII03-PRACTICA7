#include <iostream>
#include <string>
using namespace std;
class Vehiculo{
        string modelo;
        int AdeFabricacion;
        float precio;
    public:
        Vehiculo(string modelo, int AdeFabricacion, float precio){
            this->modelo=modelo;
            this->AdeFabricacion=AdeFabricacion;
            this->precio=precio;
            cout<<"1. Se ejecuto el constructor de (Vehiculo)"<<endl;
        }
        string getModelo(){return modelo;}
        int getAFabricacion(){return AdeFabricacion;}
        float getPrecio(){return precio;}
        ~Vehiculo(){
            cout<<"2. Ejecutando Destructor de la clase (Vehiculo)"<<endl;
        }
};
class Automovil : public Vehiculo{
    int NumPuertas;
    string TipoCombustible;
    public:
        Automovil(string modelo, int AdeFabricacion, float precio, int NumPuertas, string TipoCombustible) : Vehiculo(modelo, AdeFabricacion, precio){
            this->NumPuertas=NumPuertas;
            this->TipoCombustible=TipoCombustible;
            cout<<"2. Se ejecuto el constructor de (Automovil)"<<endl;
        }
        int getNumPuertas(){return NumPuertas;}
        string getTipoCombustible(){return TipoCombustible;}
        ~Automovil(){
            cout<<"1. Ejecutando destructor de la clase (Automovil)"<<endl;
        }
};
class Motocicleta : public Vehiculo{
        int cilindrada;
    public:
        Motocicleta(string modelo, int AdeFabricacion, float precio, int cilindrada) : Vehiculo(modelo, AdeFabricacion, precio){
            this->cilindrada=cilindrada;
            cout<<"2. Se ejecuto el constructor de (Motocicleta)"<<endl;
        }
        int getCilindrada(){return cilindrada;}
        ~Motocicleta(){
            cout<<"1. Ejecutando destructor de la clase (Motocicleta)"<<endl;
        }
};
using namespace std;
int main(){
    cout<<"Creando un objeto de la clase (Automovil)."<<endl;
    Automovil auto1("Tesla Model S", 2021, 10000, 4, "electrico");
    cout<<"Creando un objeto de la clase (Motocicleta)."<<endl;
    Motocicleta moto1("Kawasaki Ninja ZX-6R", 2022, 50000, 636);
    cout<<"El auto es el: "<<auto1.getModelo()<<", salio en el: "<<auto1.getAFabricacion()<<", su valer es de: "<<auto1.getPrecio()<<" dolares, tiene "<<auto1.getNumPuertas()<<" puertas y su combustible es de tipo: "<<auto1.getTipoCombustible()<<endl;
    cout<<"La moto es: "<<moto1.getModelo()<<", salio en el: "<<moto1.getAFabricacion()<<", vale: "<<moto1.getPrecio()<<" dolares y su capcacidad de cilindrada es: "<<moto1.getCilindrada()<<endl;
    cout<<"Destructores:"<<endl;
    return 0;
}