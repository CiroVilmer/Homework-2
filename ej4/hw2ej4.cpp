#include "hw2ej4.hpp"
#include <iostream>
#include <string>
using namespace std;

// Constructor de la clase BankAccount
// Inicializa el propietario de la cuenta y el saldo
// Parametros:
// string acc: propietario de la cuenta
// double bal: saldo de la cuenta
// Retorna:
// BankAccount: objeto BankAccount inicializado con los valores pasados 
BankAccount::BankAccount(string acc, double bal) : accountOwner(acc), balance(bal) {};

// Metodo para depositar dinero en la cuenta
// Recibe un monto y lo suma al saldo de la cuenta (ya sea ahorro o corriente)
// Parametros:
// double amount: monto a depositar
// Retorna:
// void: no retorna nada
void BankAccount::deposit(double amount){
    this->balance += amount;
}

// Constructor de la clase SavingsAccount
// Inicializa el propietario de la cuenta y el saldo
// Parametros:
// string acc: propietario de la cuenta
// double bal: saldo de la cuenta
// Retorna:
// SavingsAccount: objeto SavingsAccount inicializado con los valores pasados
SavingsAccount::SavingsAccount(string acc, double bal) : BankAccount(acc, bal) {};

// Metodo para retirar dinero de la cuenta de ahorro
// Recibe un monto y lo resta del saldo de la cuenta de ahorro
// Si el monto a retirar es mayor al saldo, muestra un mensaje de error
// Parametros:
// double amount: monto a retirar
void SavingsAccount::withdraw(double amount){
    if(this->balance < amount){
        cout << "La cantidad de salgo que se quiere retirar es mayor al saldo en cuenta." << endl;
    }
    else {
        this->balance -= amount;
        cout << "Se ha retirado $" << amount << " de su cuenta de ahorro. \n Su saldo actual es: " << this->balance << endl;
    }
}

// Metodo para mostrar la información de la cuenta de ahorro
// Muestra el nombre del propietario y el saldo de la cuenta
// Si se ha alcanzado el límite de visualizaciones, cobra una tarifa por mostrar la información
void SavingsAccount::showInfo(){

    if(this->count_display >= this->max_display){
        cout << "Alcanzó la cantidad maxima de pedidos para mostrar la información de la cuenta. Se cobrara " << this->display_cost << " para mostrar los datos" << endl;
        this->balance -= this->display_cost;
    }

    cout << "Datos de cuenta \n Nombre: " << this->accountOwner << "\n Saldo: " << this->balance << endl;
    this->count_display++;

    return;
}

// Constructor de la clase CheckingAccount
// Inicializa el propietario de la cuenta y el saldo
// Parametros:
// SavingsAccount& acc: referencia a un objeto SavingsAccount (del cual se obtiene el propietario y el saldo)
// Retorna:
// CheckingAccount: objeto CheckingAccount inicializado con los valores pasados
CheckingAccount::CheckingAccount(SavingsAccount& acc) : BankAccount(acc.accountOwner, 0), savingsAcount(&acc) {}

// Metodo para retirar dinero de la cuenta corriente
// Recibe un monto y lo resta del saldo de la cuenta corriente
// Si el monto a retirar es mayor al saldo, intenta retirar de la cuenta de ahorro
// Si el saldo de la cuenta de ahorro es insuficiente, muestra un mensaje de error
// Parametros:
// double amount: monto a retirar
void CheckingAccount::withdraw(double amount){
    if(this->balance < amount){
        double savingsWithdraw = amount - balance;
        if(this->savingsAcount->balance < savingsWithdraw) {
            cout << "No hay suficiente balance en la cuenta corriente u en la cuenta de ahorro." << endl;
        }else{
            cout << "Fondos insuficientes en la cuenta corriente. Extrayendo fondos de la cuenta de ahorro" << endl;
            this->balance = 0;
            this->savingsAcount->balance -= savingsWithdraw;
            cout << "Su saldo corriente actual es: $0 \n Su saldo de la cuenta de ahorro es: " << this->savingsAcount->balance << endl;
        }
    }
    else{
        this->balance -= amount;
        cout << "Se ha retirado $" << amount << " de su cuenta corriente. \n Su saldo actual es: " << this->balance << endl;
    }
}

// Metodo para mostrar la información de la cuenta corriente
// Muestra el nombre del propietario y el saldo de la cuenta corriente
// Si se ha alcanzado el límite de visualizaciones, cobra una tarifa por mostrar la información
void CheckingAccount::showInfo(){
    cout << "Datos de cuenta \n Nombre: " << this->accountOwner << "\n Saldo: " << this->balance << endl;
}