#include <iostream>
#include "empresa.hpp"
#include <iomanip>

int main() {
    std::cout<<fixed<<setprecision(2);
    
    /*criando uma empresa com o construtor parametrizado e chamando as funções sobre ela*/
    Empresa *atacadoDosCalcados=new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56);
    atacadoDosCalcados->carregarFuncoes();

    return 0;
}