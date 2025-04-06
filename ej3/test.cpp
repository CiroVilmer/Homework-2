#include "hw2ej3.cpp"

int testing() {
    // Crear instancias de cada tipo de número
    Entero e1(5), e2(3);
    Decimal d1(2.5), d2(1.5);
    Complejo c1(1.0, 2.0), c2(3.0, 4.0);

    cout << "Testing Entero:" << endl;
    Numero* res;
    res = e1.suma(&e2);
    cout << "Suma entre 5 y 3 = " << res->toString() << endl;
    delete res;
    res = e1.resta(&e2);
    cout << "Resta entre 5 y 3 = " << res->toString() << endl;
    delete res;
    res = e1.multiplicacion(&e2);
    cout << "Multiplicacion entre 5 y 3 = " << res->toString() << endl;
    delete res;
    cout << endl;

    cout << "Testing Decimal:" << endl;
    res = d1.suma(&d2);
    cout << "Suma entre 2.5 y 1.5 = " << res->toString() << endl;
    delete res;
    res = d1.resta(&d2);
    cout << "Resta entre 2.5 y 1.5 = " << res->toString() << endl;
    delete res;
    res = d1.multiplicacion(&d2);
    cout << "Multiplicacion entre 2.5 y 1.5 = " << res->toString() << endl;
    delete res;
    cout << endl;

    cout << "Testing Complejo:" << endl;
    res = c1.suma(&c2);
    cout << "Suma entre 1 + 2i y 3 + 4i = " << res->toString() << endl;
    delete res;
    res = c1.resta(&c2);
    cout << "Resta entre 1 + 2i y 3 + 4i = " << res->toString() << endl;
    delete res;
    res = c1.multiplicacion(&c2);
    cout << "Multiplicacion entre 1 + 2i y 3 + 4i = " << res->toString() << endl;
    delete res;
    cout << endl;
    
     
    return 0;
}


int main() {
    testing();

    return 0;
}


