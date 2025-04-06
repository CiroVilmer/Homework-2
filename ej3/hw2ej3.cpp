#include "hw2ej3.hpp"
#include <iostream>
#include <string>
using namespace std;

// Constructor de la clase Entero
// Inicializa el valor del entero
// Parametros:
// int v: valor del entero
Entero::Entero(int v) : valor(v) {};

// Metodo para sumar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Entero con la suma de los valores
// Si el objeto pasado no es de tipo Entero, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Entero con la suma de los valores
Numero* Entero::suma(Numero* n){
    Entero* res = dynamic_cast<Entero*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Entero(this->valor + res->valor);
};

// Metodo para restar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Entero con la resta de los valores
// Si el objeto pasado no es de tipo Entero, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Entero con la resta de los valores
Numero* Entero::resta(Numero* n){
    Entero* res = dynamic_cast<Entero*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Entero(this->valor - res->valor);
}

// Metodo para multiplicar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Entero con la multiplicación de los valores
// Si el objeto pasado no es de tipo Entero, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Entero con la multiplicación de los valores
Numero* Entero::multiplicacion(Numero* n){
    Entero* res = dynamic_cast<Entero*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Entero(this->valor * res->valor);
};

// Metodo para imprimir el valor del entero
void Entero::print(){
    cout << "El valor de su entero es: " << this->valor << endl;
};

// Metodo para convertir el entero a string
// Retorna:
// string: valor del entero como string
string Entero::toString(){
    return to_string(this->valor);
};

//Implementación de Decimal


// Constructor de la clase Decimal
// Inicializa el valor del decimal
// Parametros:
// double v: valor del decimal
// Retorna:
// Decimal: objeto Decimal inicializado con el valor pasado
Decimal::Decimal(double v) : valor(v) {};

// Metodo para sumar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Decimal con la suma de los valores
// Si el objeto pasado no es de tipo Decimal, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Decimal con la suma de los valores
Numero* Decimal::suma(Numero* n){
    Decimal* res = dynamic_cast<Decimal*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Decimal(this->valor + res->valor);
};

// Metodo para restar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Decimal con la resta de los valores
// Si el objeto pasado no es de tipo Decimal, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Decimal con la resta de los valores
Numero* Decimal::resta(Numero* n){
    Decimal* res = dynamic_cast<Decimal*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Decimal(this->valor - res->valor);
}

// Metodo para multiplicar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Decimal con la multiplicación de los valores
// Si el objeto pasado no es de tipo Decimal, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Decimal con la multiplicación de los valores
Numero* Decimal::multiplicacion(Numero* n){
    Decimal* res = dynamic_cast<Decimal*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Decimal(this->valor * res->valor);
};

// Metodo para imprimir el valor del decimal
void Decimal::print(){
    cout << "El valor de su decimal es: " << this->valor << endl;
};
// Metodo para convertir el decimal a string
// Retorna:
// string: valor del decimal como string
string Decimal::toString(){
    return to_string(this->valor);
};

//Implementación de Complejo

// Constructor de la clase Complejo
// Inicializa el valor real e imaginario del número complejo
// Parametros:
// double r: parte real del número complejo
// double i: parte imaginaria del número complejo
// Retorna:
// Complejo: objeto Complejo inicializado con los valores pasados
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {};

// Metodo para sumar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Complejo con la suma de los valores
// Si el objeto pasado no es de tipo Complejo, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Complejo con la suma de los valores
Numero* Complejo::suma(Numero* n){
    Complejo* res = dynamic_cast<Complejo*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Complejo(this->real + res->real, this->imaginario + res->imaginario);
};

// Metodo para restar dos números
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Complejo con la resta de los valores
// Si el objeto pasado no es de tipo Complejo, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Complejo con la resta de los valores
Numero* Complejo::resta(Numero* n){
    Complejo* res = dynamic_cast<Complejo*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Complejo(this->real - res->real, this->imaginario - res->imaginario);
}

// Metodo para multiplicar dos números complejos
// Recibe un puntero a un objeto Numero y devuelve un nuevo objeto Complejo con la multiplicación de los valores
// Si el objeto pasado no es de tipo Complejo, devuelve nullptr gracias a dynamic_cast
// Parametros:
// Numero* n: puntero a un objeto Numero
// Retorna:
// Numero*: puntero a un nuevo objeto Complejo con la multiplicación de los valores
Numero* Complejo::multiplicacion(Numero* n){
    Complejo* res = dynamic_cast<Complejo*>(n);
    if (res == nullptr) {
        return nullptr;
    }
    return new Complejo(this->real * res->real - this->imaginario * res->imaginario, this->real * res->imaginario + this->imaginario * res->real);
};

// Metodo para imprimir el valor del número complejo
void Complejo::print(){
    cout << "El valor de su complejo es: " << this->real << " + " << this->imaginario << "i" << endl;
};

// Metodo para convertir el número complejo a string
// Retorna:
// string: valor del número complejo como string
string Complejo::toString(){
    return to_string(this->real) + " + " + to_string(this->imaginario) + "i";
};