#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

/*criando a classe Vendedor, que herda de Pessoa e Funcionario*/
class Vendedor:public Pessoa, public Funcionario {
    private:
    char tipoVendedor;

    public:
    /*construtores*/
    Vendedor();
    Vendedor(char tipo);

    //métodos get/set
    char getTipoVendedor();
    void setTipoVendedor(char tipo);

    //funções
    float calcularSalario();
    float calcularRecisao(Data desligamento);
};

#endif