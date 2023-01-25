#pragma once

#include "ContaBancaria.h"

class ContaPoupanca : public ContaBancaria {
private:
    float juros;
public:
    ContaPoupanca(int num_conta,
                  float saldo,
                  string proprietario,
                  float juros
    );

    virtual void calcularJuros();
};
