#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include <vector>

using namespace std;

//criando a classe Empresa
class Empresa {
    private:
    float faturamentoMensal;
    string nomeEmpresa;
    string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

    public:
    //construtores
    Empresa();
    Empresa(string nome, string cnpj, float faturamento);

    //métodos get/set
    float getFaturamentoMensal();
    void setFaturamentoMensal(float faturamento);
    string getNomeEmpresa();
    void setNomeEmpresa(string nome);
    string getCnpj();
    void setCnpj(string cnpj);
    vector<Asg> getAsgs();
    vector<Vendedor> getVendedores();
    vector<Gerente> getGerentes();

    //funções da empresa
    void carregarFuncoes();
    void carregarEmpresa();
    void carregarAsg();
    void carregaDono();
    void carregarVendedor();
    void carregarGerente();
    void imprimeAsgs();
    void imprimeVendedores();
    void imprimeGerentes();
    void imprimeDono();
    void demitirFuncionario(string matricula, Data desligamento);
    void contratarFuncionario();
    bool buscaFuncionario(string matricula);
    float calculaSalarioFuncionario(string matricula);
    void calculaTodosOsSalarios();
    float calcularRecisao(string matricula, Data desligamento);
};

#endif