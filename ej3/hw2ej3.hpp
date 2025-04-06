#include <string>
using namespace std;
#pragma once    

// interfaz Numero
class Numero{
public:
    virtual Numero* suma(Numero* n) = 0;
    virtual Numero* resta(Numero* n) = 0;
    virtual Numero* multiplicacion(Numero* n) = 0;
    virtual void print() = 0;
    virtual string toString() = 0;
    virtual ~Numero() = default;
};

class Entero: public Numero{
private:
    int valor;
public:
    Entero(int v);
    Numero* suma(Numero* n) override;
    Numero* resta(Numero* n) override;
    Numero* multiplicacion(Numero* n) override;
    void print() override;
    string toString() override;
    ~Entero() override = default;
};

class Decimal: public Numero{
private:
    double valor;
public:
    Decimal(double v);
    Numero* suma(Numero* n) override;
    Numero* resta(Numero* n) override;
    Numero* multiplicacion(Numero* n) override;
    void print() override;
    string toString() override;
    ~Decimal() override = default;
};

class Complejo: public Numero{
private:
    double real;
    double imaginario;
public:
    Complejo(double r, double i);
    Numero* suma(Numero* n) override;
    Numero* resta(Numero* n) override;
    Numero* multiplicacion(Numero* n) override;
    void print() override;
    string toString() override;
    ~Complejo() override = default;
};