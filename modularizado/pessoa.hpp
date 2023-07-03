#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"
using namespace std;

class Pessoa {
    /*criando a classe Pessoa*/
    private:
    string nome;
    string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    string estadoCivil;
    int qtdFilhos;

    public:
    /*construtores*/
    Pessoa();
    Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadociv, int qtdFilhos);

    /*métodos get/set*/
    string getNome();
    void setNome(string nome);
    string getCpf();
    void setCpf(string cpf);
    Data getDataNascimento();
    void setDataNascimento(Data dataNascimento);
    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(Endereco enderecoPessoal);
    string getEstadoCivil();
    void setEstadoCivil(string estadoCivil);
    int getQtdFilhos();
    void setQtdFilhos(int qtdFilhos);
};

#endif