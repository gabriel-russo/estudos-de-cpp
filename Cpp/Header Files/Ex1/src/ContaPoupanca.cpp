#include <iostream>
#include "ContaPoupanca.h"

using std::string;

ContaPoupanca::ContaPoupanca(int num_conta,
                             float saldo,
                             string proprietario,
                             float juros
) : ContaBancaria(num_conta, saldo, proprietario), juros(juros) {}

void ContaPoupanca::calcularJuros() {
    this->saldo += this->saldo * this->juros;
}
