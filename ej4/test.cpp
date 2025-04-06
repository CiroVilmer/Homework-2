#include "hw2ej4.cpp"

// Función para mostrar el menú y manejar la interacción con el usuario
// Permite crear cuentas de ahorro y corriente, depositar y retirar dinero, y mostrar información de las cuentas
void menu(){
    bool option = true;

    SavingsAccount* savingsAccount = nullptr;
    CheckingAccount* checkingAccount = nullptr;

    while(option){
        cout << "1. Crear cuenta de ahorro" << endl;
        cout << "2. Depositar dinero en cuenta de ahorro" << endl;
        cout << "3. Retirar dinero de cuenta de ahorro" << endl;
        cout << "4. Mostrar información de cuenta de ahorro" << endl;
        cout << "5. Crear cuenta corriente" << endl;
        cout << "6. Depositar dinero en cuenta corriente" << endl;
        cout << "7. Retirar dinero de cuenta corriente" << endl;
        cout << "8. Mostrar información de cuenta corriente" << endl;
        cout << "9. Salir" << endl;

        int choice;
        cin >> choice;

        switch(choice){
            case 1:
            {
                // Crear cuenta de ahorro
                string owner;
                double balance;
                cout << "Ingrese el nombre del propietario: ";
                cin >> owner;
                cout << "Ingrese el saldo inicial: ";
                cin >> balance;
                savingsAccount = new SavingsAccount(owner, balance);
                cout << "Cuenta de ahorro creada con éxito." << endl;
                break;
            }
            case 2:
            {
                // Depositar dinero en cuenta de ahorro
                double amount;
                cout << "Ingrese el monto a depositar: ";
                cin >> amount;
                if(savingsAccount != nullptr){
                    savingsAccount->deposit(amount);
                    cout << "Monto depositado con éxito." << endl;
                }else{
                    cout << "No hay cuenta de ahorro creada." << endl;
                };
                cout << endl;
                break;
            }
            case 3:
            {
                // Retirar dinero de cuenta de ahorro
                double amount;
                cout << "Ingrese el monto a retirar: ";
                cin >> amount;
                if(savingsAccount != nullptr){
                    cout << "Intentando retirar monto." << endl;
                    savingsAccount->withdraw(amount);
                }else{
                    cout << "No hay cuenta de ahorro creada." << endl;
                };
                cout << endl;
                break;
            }
            case 4:
            {
                // Mostrar información de cuenta de ahorro
                if(savingsAccount != nullptr){
                    savingsAccount->showInfo();
                }else{
                    cout << "No hay cuenta de ahorro creada." << endl;
                };
                cout << endl;
                break;
            }
            case 5:
            {
                // Crear cuenta corriente
                if(savingsAccount != nullptr){
                    checkingAccount = new CheckingAccount(*savingsAccount);
                    cout << "Cuenta corriente creada con éxito." << endl;
                }else{
                    cout << "No hay cuenta de ahorro creada." << endl;
                };
                cout << endl;
                break;
            }
            case 6:
            {
                // Depositar dinero en cuenta corriente
                double amount;
                cout << "Ingrese el monto a depositar: ";
                cin >> amount;
                if(checkingAccount != nullptr){
                    checkingAccount->deposit(amount);
                    cout << "Monto depositado con éxito." << endl;
                }else{
                    cout << "No hay cuenta corriente creada." << endl;
                };
                cout << endl;
                break;
            }
            case 7:
            {
                // Retirar dinero de cuenta corriente
                double amount;
                cout << "Ingrese el monto a retirar: ";
                cin >> amount;
                if(checkingAccount != nullptr){
                    checkingAccount->withdraw(amount);
                }else{
                    cout << "No hay cuenta corriente creada." << endl;
                };
                cout << endl;
                break;
            }
            case 8:
            {
                // Mostrar información de cuenta corriente
                if(checkingAccount != nullptr){
                    checkingAccount->showInfo();
                }else{
                    cout << "No hay cuenta corriente creada." << endl;
                };
                cout << endl;
                break;
            }
            case 9:
            {
                // Salir
                option = false;
                cout << "Saliendo del programa." << endl;
                break;
            }
            default:
            {
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
            }
        }
    }

}
int main(){
    menu();
    return 0;
}