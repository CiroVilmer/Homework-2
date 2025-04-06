using namespace std;
#include <string>

/*En BankAccount, usamos protected para que las clases derivadas puedan acceder a los atributos de la clase base.

En SavingsAccount, usamos private para que los atributos no puedan ser accedidos directamente desde fuera de la clase, ya que estos atributos
son específicos de la implementación de SavingsAccount y se manipulan a través de los métodos de la clase.
Tambien usamos friend para que la clase CheckingAccount pueda acceder a los atributos privados de SavingsAccount. 
Esto es necesario porque CheckingAccount necesita poder retirar dinero de SavingsAccount directamente. 

En CheckingAccount, usamos private para que la savings account no pueda ser accedida directamente desde fuera de la clase, 
ya que es un atributo específico de la implementación de CheckingAccount y se manipula a través de los métodos de la clase.


Tambíen se hacen overrides de los métodos withdraw y showInfo en ambas clases derivadas, para proporcionar implementaciones específicas para cada tipo de cuenta.
*/

class BankAccount {
    protected:
    string accountOwner = "";
    double balance = 0.0;
    
    public:
    BankAccount(string acc, double balance);
    void deposit(double amount);
    virtual void withdraw(double amount) = 0;
    virtual void showInfo() = 0;
    virtual ~BankAccount() = default;
};



class SavingsAccount: public BankAccount {
    private:
    int count_display = 0;
    const int max_display = 2;
    const int display_cost = 20;

    public:
    SavingsAccount(string owner, double balance);
    void withdraw(double amount) override;
    void showInfo() override;
    friend class CheckingAccount; //
};

class CheckingAccount: public BankAccount {
    private:
    SavingsAccount* savingsAcount;

    public:
    CheckingAccount(SavingsAccount& acc);
    void withdraw(double amount) override;
    void showInfo() override;

};