#include <iostream>
#include "util.hpp"
#include "funcionario.hpp"
using namespace std;

/*implementação dos métodos get/set*/
string Funcionario::getSalario() { return this->salario; }
void Funcionario::setSalario(string salario) { this->salario=salario; }
string Funcionario::getMatricula() { return this->matricula; }
void Funcionario::setMatricula(string matricula) { this->matricula=matricula; }
Data Funcionario::getIngressoEmpresa() { return this->ingressoEmpresa; }
void Funcionario::setIngressoEmpresa(Data ingressoEmpresa) { this->ingressoEmpresa=ingressoEmpresa; }
int Funcionario::getFaltas() { return this->faltas; }
void Funcionario::setFaltas(int diasfaltas) { this->faltas=diasfaltas; }