#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
using namespace std;

/*construtor sem parâmetro*/
Pessoa::Pessoa() {}
/*construtor parametrizado*/
Pessoa::Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadociv, int qtdFilhos) {
    this->nome=nome;
    this->cpf=cpf;
    this->dataNascimento=dataNascimento;
    this->enderecoPessoal=enderecoPessoal;
    this->estadoCivil=estadociv;
    this->qtdFilhos=qtdFilhos;
}

/*métodos get/set implementados*/
string Pessoa::getNome() { return this->nome; }
void Pessoa::setNome(string nome) { this->nome=nome; }
string Pessoa::getCpf() { return this->cpf; }
void Pessoa::setCpf(string cpf) { this->cpf=cpf; }
Data Pessoa::getDataNascimento() { return this->dataNascimento; }
void Pessoa::setDataNascimento(Data dataNascimento) { this->dataNascimento=dataNascimento; }
Endereco Pessoa::getEnderecoPessoal() { return this->enderecoPessoal; }
void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal) { this->enderecoPessoal=enderecoPessoal; }
string Pessoa::getEstadoCivil() { return this->estadoCivil; }
void Pessoa::setEstadoCivil(string estadoCivil) { this->estadoCivil=estadoCivil; }
int Pessoa::getQtdFilhos() { return this->qtdFilhos; }
void Pessoa::setQtdFilhos(int qtdFilhos) { this->qtdFilhos=qtdFilhos; }