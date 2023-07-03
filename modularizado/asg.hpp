#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "funcionario.hpp"

using namespace std;

class Asg:public Pessoa, public Funcionario {
    /*criando a classe Asg com herança de Pessoa e Funcionario*/
    private:
    float adicionalInsalubridade;

    public:
    /*construtores*/
    Asg();
    Asg(float adicional);

    /*métodos get/set e funções*/
    float getAdicionalInsalubridade();
    void setAdicionalInsalubridade(float adicional);
    float calcularSalario();
    float calcularRecisao(Data desligamento);
};

#endif