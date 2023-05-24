#include <iostream>
#include <string>
using namespace std;

class Persona 
{
    private:
        string nombre;
        int edad;
        float salario;

    protected:
        string correo_electronico;

    public:
        Persona(string nombre, int edad, float salario, string correo_electronico) 
        {
            this->nombre = nombre;
            this->edad = edad;
            this->salario = salario;
            this->correo_electronico = correo_electronico;
        }

        string obtener_correo_electronico() 
        {
            return correo_electronico;
        }
};

class Empleado : public Persona 
{
    public:
        Empleado(string nombre, int edad, float salario, string correo_electronico)
            : Persona(nombre, edad, salario, correo_electronico) {}
};

class Cliente : public Persona 
{
    public:
        Cliente(string nombre, int edad, float salario, string correo_electronico)
            : Persona(nombre, edad, salario, correo_electronico) {}
};

int main() 
{
    Empleado empleado("Leonardo", 19, 2500.0, "abigiron911@gmail.com");
    Cliente cliente("Guchi", 20, 0.0, "guchizor123@gmail.com");
    
    cout<<"MOSTRANDO DATOS: "<< endl;
    cout<<"Correo electronico del empleado: "<<empleado.obtener_correo_electronico()<<endl;
    cout<<"Correo electronico del cliente: "<<cliente.obtener_correo_electronico()<<endl;

    return 0;
}
