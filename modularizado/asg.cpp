#include <iostream>
#include "asg.hpp"
#include "util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

/*construtor sem parâmetro*/
Asg::Asg() {}

/*construtor parametrizado*/
Asg::Asg(float adicional) { this->adicionalInsalubridade=adicional; }

/*métodos get/set*/
float Asg::getAdicionalInsalubridade() { return this->adicionalInsalubridade; }
void Asg::setAdicionalInsalubridade(float adicional) { this->adicionalInsalubridade=adicional; }

/*função para calcular o salário de um objeto da classe*/
float Asg::calcularSalario() {
    float salario=stof(getSalario());
    /*penalização po cada dia de trabalho desperdiçado*/
    salario-=(salario/30)*getFaltas();
    /*aplicação do adicional insalubridade*/
    salario=salario*(1+adicionalInsalubridade);
    /*adicional de 100 reais para cada filho*/
    salario=salario+getQtdFilhos()*100;
    return salario;
}
float Asg::calcularRecisao(Data desligamento) {
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