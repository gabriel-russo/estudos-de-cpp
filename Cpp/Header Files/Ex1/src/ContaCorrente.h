#pragma once

#include "ContaBancaria.h"

class ContaCorrente : public ContaBancaria {
private:
    float limite_credito;
public:
    ContaCorrente(int num_conta,
                  float saldo,
                  string proprietario,
                  float limite_credito);

    virtual bool verificarLimite();

    virtual float verLimite();
};
