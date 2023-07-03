#include <iostream>
#include "vendedor.hpp"
#include "util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

//construtor sem parâmetro
Vendedor::Vendedor() {}

//construtor parametrizado
Vendedor::Vendedor(char tipo) { this->tipoVendedor=tipo; }

//métodos get/set
char Vendedor::getTipoVendedor() { return this->tipoVendedor; }
void Vendedor::setTipoVendedor(char tipo) { this->tipoVendedor=tipo; }

//função para calcular o salário de um objeto da classe
float Vendedor::calcularSalario() {
    int diasFaltas=getFaltas();
    float salario=stof(getSalario());
    //penalização pelos dias de falta
    salario-=(salario/30)*diasFaltas;
    //bônus no salário de acordo com o tipo de vendedor
    if(tipoVendedor=='A')
        salario*=1.25;
    else if(tipoVendedor=='B')
        salario*=1.1;
    else if(tipoVendedor=='C')
        salario*=1.05;
    //bônus de 100 reais para cada filho do vendedor
    salario+=getQtdFilhos()*100;
    return salario;
}
float Vendedor::calcularRecisao(Data desligamento) {
    float desligamentodias, ingressodias;
    //transformando ambas as datas para suas respectivas quantidade de dias
    ingressodias=getIngressoEmpresa().ano*365+(getIngressoEmpresa().mes)*30+getIngressoEmpresa().dia;
    desligamentodias=desligamento.ano*365+desligamento.mes*30+desligamento.dia;
    /*encontrando a diferença em anos entre as duas datas*/
    float diferencaano=(desligamentodias-ingressodias)/365;
    /*multiplicando o salário base pela quantidade de anos trabalhados*/
    float adicional=stof(getSalario())*diferencaano;
    return adicional;
}
