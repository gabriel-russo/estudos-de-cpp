#pragma once

#include <iostream>

using std::string;

class ContaBancaria {
protected:
    int num_conta;
    float saldo;
    string proprietario;

public:
    ContaBancaria(int num_conta, float saldo, string proprietario);

    virtual void depositar(float valor);

    virtual void sacar(float valor);

    virtual float verSaldo();

    virtual int verNum_conta();

    virtual string verProprietario();
};
