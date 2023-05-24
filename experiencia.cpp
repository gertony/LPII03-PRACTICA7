#include <iostream>
#include <string>

using namespace std;

class Cliente {
protected:
    int dni;
    string nombre;
    int nroCuenta;
    double saldo;
    string clave;

    string encriptar(const string& clave, char key) {
        string claveE = clave;
        for (char& c : claveE) {
            c ^= key;
        }
        return claveE;
    }

public:
    Cliente(int dni, string nombre, int nroCuenta, double saldo, string clave)
        : dni(dni), nombre(nombre), nroCuenta(nroCuenta), saldo(saldo), clave(clave) {
        this->clave = encriptar(this->clave, 'K');
    }


    void mostrarDatos() {
        cout << "-----------------------------------"<<endl;
        cout << "DNI: " << dni << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Número de cuenta: " << nroCuenta << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "-----------------------------------"<<endl;

    }

    ~Cliente() {
        cout <<"Ejecutando destructor Cliente......"<<endl;
        cout << "-----------------------------------"<<endl;
    }

};

class ClienteSeguro : private Cliente {
private:
    string desencriptar(const string& claveE, char key) {
        string claveD = claveE;
        for (char& c : claveD) {
            c ^= key;
        }
        return claveD;
    }

public:
    ClienteSeguro(int dni, string nombre, int nroCuenta, double saldo, string clave)
        : Cliente(dni, nombre, nroCuenta, saldo, clave) {
        this->clave = desencriptar(this->clave, 'K');
    }

    void mostrarDatos() {
        string inputClave;
        cout << "Ingrese la clave: ";
        cin >> inputClave;

        if (clave == inputClave) {
            Cliente::mostrarDatos();
        } else {
            cerr << "La clave es incorrecta. No se pueden mostrar los datos." << endl;

        }
    }
    
    ~ClienteSeguro() {
        cout << "-----------------------------------"<<endl;
        cout <<"Ejecutando destructor ClienteSeguro......"<<endl;
        cout << "-----------------------------------"<<endl;

    }
};

int main() {
    ClienteSeguro cliente(72137941, "Tony Jimenez", 8274721, 5000, "contra123");
    cliente.mostrarDatos();
    return 0;
}
