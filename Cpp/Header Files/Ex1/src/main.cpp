/*
Desafio: Crie uma biblioteca de classes em C++ para gerenciar contas bancárias, incluindo herança de classes e polimorfismo.

Crie uma classe base chamada "ContaBancaria" que contenha os seguintes membros:
- Um número de conta inteiro
- Um saldo flutuante
- Um nome de usuário (string)
- Um método virtual chamado "depositar" que aceita um valor flutuante como parâmetro e adiciona
 esse valor ao saldo atual da conta
- Um método virtual chamado "sacar" que aceita um valor flutuante como parâmetro e subtrai
 esse valor do saldo atual da conta, verificando se o saldo é suficiente antes de realizar a operação
- Um método virtual chamado "verSaldo" que retorna o saldo atual da conta

Crie uma classe derivada chamada "ContaPoupanca" que herda de "ContaBancaria" e adiciona os seguintes membros:
- Um juros flutuante
- Um método virtual chamado "calcularJuros" que adiciona o juros ao saldo atual da conta

Crie uma classe derivada chamada "ContaCorrente" que herda de "ContaBancaria" e adiciona os seguintes membros:
- Um limite de crédito flutuante
- Um método virtual chamado "verificarLimite" que verifica se o saldo e o limite de crédito permitem
 uma operação de retirada antes de realizá-la

Crie um arquivo de cabeçalho chamado "ContaBancaria.h" que contenha as declarações da classe
 "ContaBancaria" e seus membros. Faça o mesmo para as classes derivadas "ContaPoupanca" e "ContaCorrente"

Crie um arquivo de implementação chamado "ContaBancaria.cpp" que contenha as implementações dos
 métodos da classe "ContaBancaria" e as classes derivadas "ContaPoupanca" e "ContaCorrente"

Crie um arquivo de programa principal chamado "main.cpp" que instancie pelo menos duas contas
 bancárias de tipos diferentes (ContaPoupanca e ContaCorrente) e armazene-as em um vetor ou ponteiro
 genérico, e utilize os métodos "depositar", "sacar" e "verSaldo" para realizar operações bancárias,
 e os métodos específicos "calcularJuros" e "verificarLimite" para realizar operações específicas de cada classe derivada.

Certifique-se de incluir os arquivos de cabeçalho "ContaBancaria.h", "ContaPoupanca.h" e "ContaCorrente.h"
 no arquivo de implementação e no arquivo de programa principal para garantir que as classes estejam disponíveis para uso.
*/
#include <iostream>
#include "include/banco/banco.hpp"

using std::cout;

int main() {

    ContaPoupanca cp = ContaPoupanca(22900, 1000, "Gabriel", 0.3);

    ContaCorrente cc = ContaCorrente(54321, 1350.41, "Shaolin", 500.50);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=" << "\n";
    cout << "Conta poupança de " << cp.verProprietario() << "\n";
    cout << "Conta n°: " << cp.verNum_conta() << "\n";
    cout << "Saldo de: " << cp.verSaldo() << "\n";
    cp.calcularJuros();
    cout << "Novo saldo após redimento do juros: " << cp.verSaldo() << "\n";
    cp.sacar(1000.00);
    cp.depositar(1500.00);
    cout << "Novo saldo após sacar $1000 e depositar $1500: " << cp.verSaldo() << "\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=" << "\n";

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=" << "\n";
    cout << "Conta corrente de " << cc.verProprietario() << "\n";
    cout << "Conta n°: " << cc.verNum_conta() << "\n";
    cout << "Saldo da conta: " << cc.verSaldo() << "\n";
    cout << "Saldo de limite: " << cc.verLimite() << "\n";
    cout << "É possível fazer saque com crédito ou saldo?: " << ((cc.verificarLimite()) ? "Sim" : "Não") << "\n";
    cc.sacar(1350.41);
    cout << "Novo saldo após sacar 1350.41: " << cc.verSaldo() << "\n";
    cout << "É possível fazer saque com crédito ou saldo?: " << ((cc.verificarLimite()) ? "Sim" : "Não") << "\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=" << "\n";

    return 0;
}
