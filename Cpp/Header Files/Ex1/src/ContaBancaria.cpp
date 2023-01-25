#include <iostream>
#include "ContaBancaria.h"

using std::cout;

ContaBancaria::ContaBancaria(int num_conta, float saldo, string proprietario)
        : num_conta(num_conta), saldo(saldo), proprietario(proprietario) {}

void ContaBancaria::depositar(float valor) {
    if (valor > 0)
        this->saldo += valor;
}

void ContaBancaria::sacar(float valor) {
    if (valor > 0)
        this->saldo -= valor;
}

float ContaBancaria::verSaldo() {
    return this->saldo;
}

int ContaBancaria::verNum_conta() {
    return this->num_conta;
}

string ContaBancaria::verProprietario() {
    return this->proprietario;
}
