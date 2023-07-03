#include <iostream>
#include "gerente.hpp"
#include "util.hpp"
#include "funcionario.hpp"
#include "pessoa.hpp"
using namespace std;

//construtor sem parâmetro
Gerente::Gerente() {}

//construtor parametrizado
Gerente::Gerente(float lucro) { this->participacaoLucros=lucro; }

//métodos get/set
float Gerente::getParticipacaoLucros() { return this->participacaoLucros; }
void Gerente::setParticipacaoLucros(float lucro) { this->participacaoLucros=lucro; }

//função para calcular o salário de um objeto que pertence a Gerente
float Gerente::calcularSalario() {
    int diasfaltas=getFaltas();
    float salario=stof(getSalario());
    //penalização pelos dias de falta
    salario-=(salario/30)*diasfaltas;
    //somando a participação do gerente no lucro ao salário
    salario+=participacaoLucros;
    //adicional de 100 reais por filho
    salario+=getQtdFilhos()*100;
    return salario;
}
float Gerente::calcularRecisao(Data desligamento) {
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