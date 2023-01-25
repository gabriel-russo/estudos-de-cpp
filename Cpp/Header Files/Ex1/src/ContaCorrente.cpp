#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(int num_conta,
                             float saldo,
                             string proprietario,
                             float limite_credito
) : ContaBancaria(num_conta, saldo, proprietario), limite_credito(limite_credito) {}

bool ContaCorrente::verificarLimite() {
    if ((this->saldo > 0) || (this->limite_credito > 0))
        return true;
    else
        return false;
}

float ContaCorrente::verLimite() {
    return this->limite_credito;
}
