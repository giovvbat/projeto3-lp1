#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "funcionario.hpp"
#include "pessoa.hpp"
#include "util.hpp"
using namespace std;

//criação da classe Gerente, que herda de Pessoa e Funcionario
class Gerente:public Pessoa, public Funcionario {
    private:
    float participacaoLucros;

    public:
    //construtores
    Gerente();
    Gerente(float lucro);
    
    //métodos get/set e funções
    float getParticipacaoLucros();
    void setParticipacaoLucros(float lucro);
    float calcularSalario();
    float calcularRecisao(Data desligamento);
};

#endif