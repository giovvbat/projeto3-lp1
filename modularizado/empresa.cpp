#include <iostream>
#include "util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include "empresa.hpp"
#include <fstream>
#include <vector>

using namespace std;

//construtor sem parâmetro
Empresa::Empresa() {}

//construtor parametrizado
Empresa::Empresa(string nome, string cnpj, float faturamento) {
    this->cnpj=cnpj;
    this->faturamentoMensal=faturamento;
    this->nomeEmpresa=nome;
}

//métodos get/set
float Empresa::getFaturamentoMensal() { return this->faturamentoMensal; }
void Empresa::setFaturamentoMensal(float faturamento) { this->faturamentoMensal=faturamento; }
string Empresa::getNomeEmpresa() { return this->nomeEmpresa; }
void Empresa::setNomeEmpresa(string nome) { this->nomeEmpresa=nome; }
string Empresa::getCnpj() { return this->cnpj; }
void Empresa::setCnpj(string cnpj) { this->cnpj=cnpj; }
vector<Asg> Empresa::getAsgs() { return this->asgs; }
vector<Vendedor> Empresa::getVendedores() { return this->vendedores; }
vector<Gerente> Empresa::getGerentes() { return this->gerentes; }

//função para ler e executar cada função escrita no arquivo "funcoes.txt"
void Empresa::carregarFuncoes() {
    //abrindo o arquivo
    ifstream file("funcoes.txt");
    string linha;

    //checando se o arquivo foi aberto corretamente
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    //lendo cada linha do arquivo e executando a função correspondente
    while(getline(file, linha)) {
        if(linha=="carregarEmpresa()") carregarEmpresa();
        else if(linha=="carregarAsg()") carregarAsg();
        else if(linha=="carregarVendedor()") carregarVendedor();
        else if(linha=="carregarGerente()") carregarGerente();
        else if(linha=="carregaDono()") carregaDono();
        else if(linha=="imprimeAsgs()") imprimeAsgs();
        else if(linha=="imprimeVendedores()") imprimeVendedores();
        else if(linha=="imprimeGerentes()") imprimeGerentes();
        else if(linha=="imprimeDono()") imprimeDono();
        else if(linha=="buscaFuncionario()") {
            //lendo os parâmetros necessários
            string parametro;
            getline(file, parametro);
            buscaFuncionario(parametro);
        }
        else if(linha=="calculaSalarioFuncionario()") {
            //lendo os parâmetros necessários para a chamada da função
            string parametro;
            getline(file, parametro);
            calculaSalarioFuncionario(parametro);
        }
        else if(linha=="calculaTodosOsSalarios()") calculaTodosOsSalarios();
        else if(linha=="calcularRecisao()") {
            //lendo os parâmetros necessários para a chamada da função
            string matricula;
            string datas;
            Data data;

            getline(file, matricula);

            getline(file, datas);
            data.ano=stoi(datas);
            getline(file, datas);
            data.mes=stoi(datas);
            getline(file, datas);
            data.dia=stoi(datas);

            calcularRecisao(matricula, data);
        }
        else if(linha == "contratarFuncionario()") contratarFuncionario();
        else if(linha=="demitirFuncionario()") {
            //lendo os parâmetros necessários para a chamada da função
            string matricula;
            string datas;
            Data data;

            getline(file, matricula);

            getline(file, datas);
            data.ano=stoi(datas);
            getline(file, datas);
            data.mes=stoi(datas);
            getline(file, datas);
            data.dia=stoi(datas);

            demitirFuncionario(matricula, data);
        }
    }
}

//função para ler "dono.txt" e armazenar cada informação do dono, que é atributo de Empresa e um objeto da classe Pessoa
void Empresa::carregaDono() {
    //abrindo o arquivo
    ifstream file("dono.txt");

    //checando se o arquivo foi aberto corretamente
    string linha;
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    getline(file, linha);
    getline(file, linha);

    //lendo armazenando o nome
    getline(file, linha);
    dono.setNome(linha);

    //lendo armazenando o cpf
    getline(file, linha);
    dono.setCpf(linha);

    //lendo armazenando a quantidade de filhos
    getline(file, linha);
    int filhos=stoi(linha);
    dono.setQtdFilhos(filhos);

    //lendo armazenando o estado civil
    getline(file, linha);
    dono.setEstadoCivil(linha);

    //lendo armazenando o endereço
    Endereco endereco;
    getline(file, linha);
    endereco.cidade=linha;
    getline(file, linha);
    endereco.cep=linha;
    getline(file, linha);
    endereco.bairro=linha;
    getline(file, linha);
    endereco.rua=linha;
    getline(file, linha);
    int num=stoi(linha);
    endereco.numero=num;
    dono.setEnderecoPessoal(endereco);

    //lendo armazenando a data de nascimento
    Data nascimento;
    getline(file, linha);
    int ano=stoi(linha);
    nascimento.ano=ano;
    getline(file, linha);
    int mes=stoi(linha);
    nascimento.mes=mes;
    getline(file, linha);
    int dia=stoi(linha);
    nascimento.dia=dia;
    dono.setDataNascimento(nascimento);

    //fechando o arquivo
    file.close();
}

//função para ler "empresa.txt" e armazenar cada informação da empresa
void Empresa::carregarEmpresa() {
    //abrindo o arquivo 
    ifstream file("empresa.txt");
    string linha;

    //checando se o arquivo foi aberto corretamente
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    getline(file, linha);
    getline(file, linha);

    //lendo armazenando o nome da empresa
    getline(file, linha);
    setNomeEmpresa(linha);

    //lendo armazenando o cnpj da empresa
    getline(file, linha);
    setCnpj(linha);

    //lendo armazenando o faturamento mensal da empresa
    getline(file, linha);
    setFaturamentoMensal(stof(linha));

    //fechando o arquivo
    file.close();
}

//função para ler "asg.txt" e preencher o vetor de asgs com as informações presentes no arquivo
void Empresa::carregarAsg() {
    //abrindo o arquivo
    ifstream file("asg.txt");
    string linha;

    //checando se o arquivo foi aberto corretamente
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    Asg asg;
    Endereco endereco;
    Data datan, datai;

    //lendo todas as linhas do arquivo, armazenando as informações contidas em cada uma em um objeto Asg e adicionando-o no vetor de asgs
    while(getline(file, linha)) {
        getline(file, linha);
        getline(file, linha);

        getline(file, linha);
        asg.setNome(linha);
        getline(file, linha);
        asg.setCpf(linha);
        getline(file, linha);
        asg.setQtdFilhos(stoi(linha));
        getline(file, linha);
        asg.setEstadoCivil(linha);

        getline(file, linha);

        getline(file, linha);
        endereco.cidade=linha;
        getline(file, linha);
        endereco.cep=linha;
        getline(file, linha);
        endereco.bairro=linha;
        getline(file, linha);
        endereco.rua=linha;
        getline(file, linha);
        endereco.numero=stoi(linha);
        asg.setEnderecoPessoal(endereco);

        getline(file, linha);

        getline(file, linha);
        datan.ano=stoi(linha);
        getline(file, linha);
        datan.mes=stoi(linha);
        getline(file, linha);
        datan.dia=stoi(linha);
        asg.setDataNascimento(datan);

        getline(file, linha);

        getline(file, linha);
        asg.setMatricula(linha);
        getline(file, linha);
        asg.setSalario(linha);
        getline(file, linha);
        asg.setAdicionalInsalubridade(stof(linha));
        getline(file, linha);
        asg.setFaltas(stoi(linha));

        getline(file, linha);

        getline(file, linha);
        datai.ano=stoi(linha);
        getline(file, linha);
        datai.mes=stoi(linha);
        getline(file, linha);
        datai.dia=stoi(linha);
        asg.setIngressoEmpresa(datai);

        asgs.push_back(asg);
    }
    
    //fechando o arquivo
    file.close();
}

//função para ler "vendedor.txt" e preencher o vetor de vendedores com as informações presentes no arquivo
void Empresa::carregarVendedor() {
    //abrindo o arquivo
    ifstream file("vendedor.txt");
    string linha;

    //checando se o arquivo foi aberto corretamente
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    Vendedor vendedor;
    Endereco endereco;
    Data datan, datai;

    //lendo todas as linhas do arquivo, armazenando as informações contidas em cada uma em um objeto Vendedor e adicionando-o no vetor de vendedores
    while(getline(file, linha)) {
        getline(file, linha);
        getline(file, linha);

        getline(file, linha);
        vendedor.setNome(linha);
        getline(file, linha);
        vendedor.setCpf(linha);
        getline(file, linha);
        vendedor.setQtdFilhos(stoi(linha));
        getline(file, linha);
        vendedor.setEstadoCivil(linha);

        getline(file, linha);

        getline(file, linha);
        endereco.cidade=linha;
        getline(file, linha);
        endereco.cep=linha;
        getline(file, linha);
        endereco.bairro=linha;
        getline(file, linha);
        endereco.rua=linha;
        getline(file, linha);
        endereco.numero=stoi(linha);
        vendedor.setEnderecoPessoal(endereco);

        getline(file, linha);

        getline(file, linha);
        datan.ano=stoi(linha);
        getline(file, linha);
        datan.mes=stoi(linha);
        getline(file, linha);
        datan.dia=stoi(linha);
        vendedor.setDataNascimento(datan);

        getline(file, linha);

        getline(file, linha);
        vendedor.setMatricula(linha);
        getline(file, linha);
        vendedor.setSalario(linha);
        getline(file, linha);
        char tipo=linha[0];
        vendedor.setTipoVendedor(tipo);
        getline(file, linha);
        vendedor.setFaltas(stoi(linha));

        getline(file, linha);

        getline(file, linha);
        datai.ano=stoi(linha);
        getline(file, linha);
        datai.mes=stoi(linha);
        getline(file, linha);
        datai.dia=stoi(linha);
        vendedor.setIngressoEmpresa(datai);

        vendedores.push_back(vendedor);
    }
    
    //fechando o arquivo
    file.close();
}

//função para ler "gerente.txt" e preencher o vetor de vendedores com as informações presentes no arquivo
void Empresa::carregarGerente() {
    //abrindo o arquivo
    ifstream file("gerente.txt");
    string linha;

    //verificando se o arquivo foi aberto corretamente
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    Gerente gerente;
    Endereco endereco;
    Data datan, datai;

    //lendo todas as linhas do arquivo, armazenando as informações contidas em cada uma em um objeto Gerente e adicionando-o no vetor de gerentes
    while(getline(file, linha)) {
        getline(file, linha);
        getline(file, linha);

        getline(file, linha);
        gerente.setNome(linha);
        getline(file, linha);
        gerente.setCpf(linha);
        getline(file, linha);
        gerente.setQtdFilhos(stoi(linha));
        getline(file, linha);
        gerente.setEstadoCivil(linha);

        getline(file, linha);

        getline(file, linha);
        endereco.cidade=linha;
        getline(file, linha);
        endereco.cep=linha;
        getline(file, linha);
        endereco.bairro=linha;
        getline(file, linha);
        endereco.rua=linha;
        getline(file, linha);
        endereco.numero=stoi(linha);
        gerente.setEnderecoPessoal(endereco);

        getline(file, linha);

        getline(file, linha);
        datan.ano=stoi(linha);
        getline(file, linha);
        datan.mes=stoi(linha);
        getline(file, linha);
        datan.dia=stoi(linha);
        gerente.setDataNascimento(datan);

        getline(file, linha);

        getline(file, linha);
        gerente.setMatricula(linha);
        getline(file, linha);
        gerente.setSalario(linha);
        getline(file, linha);
        gerente.setParticipacaoLucros(stof(linha));
        getline(file, linha);
        gerente.setFaltas(stoi(linha));

        getline(file, linha);

        getline(file, linha);
        datai.ano=stoi(linha);
        getline(file, linha);
        datai.mes=stoi(linha);
        getline(file, linha);
        datai.dia=stoi(linha);
        gerente.setIngressoEmpresa(datai);

        gerentes.push_back(gerente);
    }
    
    //fechando o arquivo
    file.close();
}

//função que imprime as informações de todos os asgs
void Empresa::imprimeAsgs() {
    //percorrendo o vetor de asgs e imprimindo as informações principais de cada um
    cout<<"Lista de profissionais ASG:"<<endl;
    for(auto i:asgs) {
        cout<<"Nome: "<<i.getNome()<<endl;
        cout<<"CPF: "<<i.getCpf()<<endl;
        cout<<"Data de nascimento: "<<i.getDataNascimento().dia<<"/"<<i.getDataNascimento().mes<<"/"<<i.getDataNascimento().ano<<endl;
        cout<<"Endereço: Rua "<<i.getEnderecoPessoal().rua<<", "<<i.getEnderecoPessoal().numero<<endl;
        cout<<"Estado civil: "<<i.getEstadoCivil()<<endl;
        cout<<"Número de filhos: "<<i.getQtdFilhos()<<endl;
        cout<<"Salário: "<<i.calcularSalario()<<endl;
        cout<<"Número de faltas: "<<i.getFaltas()<<endl;
        cout<<"Matrícula: "<<i.getMatricula()<<endl;
        cout<<"Data de ingresso na empresa: "<<i.getIngressoEmpresa().dia<<"/"<<i.getIngressoEmpresa().mes<<"/"<<i.getIngressoEmpresa().ano<<endl;
        cout<<"**********************************"<<endl;
    }
}

//função que imprime as informações de todos os vendedores
void Empresa::imprimeVendedores() {
    //percorrendo o vetor de vendedores e imprimindo as informações principais de cada um
    cout<<"Lista de vendedores:"<<endl;
    for(auto i:vendedores) {
        cout<<"Nome: "<<i.getNome()<<endl;
        cout<<"CPF: "<<i.getCpf()<<endl;
        cout<<"Data de nascimento: "<<i.getDataNascimento().dia<<"/"<<i.getDataNascimento().mes<<"/"<<i.getDataNascimento().ano<<endl;
        cout<<"Endereço: Rua "<<i.getEnderecoPessoal().rua<<", "<<i.getEnderecoPessoal().numero<<endl;
        cout<<"Estado civil: "<<i.getEstadoCivil()<<endl;
        cout<<"Número de filhos: "<<i.getQtdFilhos()<<endl;
        cout<<"Salário: "<<i.calcularSalario()<<endl;
        cout<<"Número de faltas: "<<i.getFaltas()<<endl;
        cout<<"Matrícula: "<<i.getMatricula()<<endl;
        cout<<"Data de ingresso na empresa: "<<i.getIngressoEmpresa().dia<<"/"<<i.getIngressoEmpresa().mes<<"/"<<i.getIngressoEmpresa().ano<<endl;
        cout<<"**********************************"<<endl;
    }
}

//função que imprime as informações de todos os gerentes
void Empresa::imprimeGerentes() {
    //percorrendo o vetor de gerentes e imprimindo as informações principais de cada um
    cout<<"Lista de gerentes:"<<endl;
    for(auto i:gerentes) {
        cout<<"Nome: "<<i.getNome()<<endl;
        cout<<"CPF: "<<i.getCpf()<<endl;
        cout<<"Data de nascimento: "<<i.getDataNascimento().dia<<"/"<<i.getDataNascimento().mes<<"/"<<i.getDataNascimento().ano<<endl;
        cout<<"Endereço: Rua "<<i.getEnderecoPessoal().rua<<", "<<i.getEnderecoPessoal().numero<<endl;
        cout<<"Estado civil: "<<i.getEstadoCivil()<<endl;
        cout<<"Número de filhos: "<<i.getQtdFilhos()<<endl;
        cout<<"Salário: "<<i.calcularSalario()<<endl;
        cout<<"Número de faltas: "<<i.getFaltas()<<endl;
        cout<<"Matrícula: "<<i.getMatricula()<<endl;
        cout<<"Data de ingresso na empresa: "<<i.getIngressoEmpresa().dia<<"/"<<i.getIngressoEmpresa().mes<<"/"<<i.getIngressoEmpresa().ano<<endl;
        cout<<"**********************************"<<endl;
    }
}

//função que imprime as informações do dono
void Empresa::imprimeDono() {
    //imprimindo as informações sobre atributo 'dono'
    cout<<"Informações sobre dono:"<<endl;
    cout<<"Nome: "<<dono.getNome()<<endl;
    cout<<"CPF: "<<dono.getCpf()<<endl;
    cout<<"Data de nascimento: "<<dono.getDataNascimento().dia<<"/"<<dono.getDataNascimento().mes<<"/"<<dono.getDataNascimento().ano<<endl;
    cout<<"Endereço: Rua "<<dono.getEnderecoPessoal().rua<<", "<<dono.getEnderecoPessoal().numero<<endl;
    cout<<"Estado civil: "<<dono.getEstadoCivil()<<endl;
    cout<<"Número de filhos: "<<dono.getQtdFilhos()<<endl;
}

//função que demite um funcionário de acordo com sua matrícula
void Empresa::demitirFuncionario(string matricula, Data desligamento) {
    for(auto it = asgs.begin(); it != asgs.end(); it++) {
        if((*it).getMatricula() == matricula) {
            int diastotais = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia - (*it).getIngressoEmpresa().ano*365 - (*it).getIngressoEmpresa().mes*30 - (*it).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            diastotais -= 365*anos;
            int meses = diastotais/30;
            diastotais -= 30*meses;
            int dias = diastotais;

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: ASG"<<endl;
            cout<<"Nome: "<<(*it).getNome()<<endl;
            cout<<"CPF: "<<(*it).getCpf()<<endl;
            cout<<"Matrícula: "<<(*it).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*it).getIngressoEmpresa().dia<<"/"<<(*it).getIngressoEmpresa().mes<<"/"<<(*it).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*it).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<anos<<" anos, "<<meses<<" meses e "<<dias<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: ASG"<<endl;
            file<<"Nome: "<<(*it).getNome()<<endl;
            file<<"CPF: "<<(*it).getCpf()<<endl;
            file<<"Matrícula: "<<(*it).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*it).getIngressoEmpresa().dia<<"/"<<(*it).getIngressoEmpresa().mes<<"/"<<(*it).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*it).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<anos<<" anos, "<<meses<<" meses e "<<dias<<" dias"<<endl;
            file.close();

            asgs.erase(it);
            return;
        }
    }

    for(auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if((*it).getMatricula() == matricula) {
            int diastotais = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia - (*it).getIngressoEmpresa().ano*365 - (*it).getIngressoEmpresa().mes*30 - (*it).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            diastotais -= 365*anos;
            int meses = diastotais/30;
            diastotais -= 30*meses;
            int dias = diastotais;

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: Vendedor"<<endl;
            cout<<"Nome: "<<(*it).getNome()<<endl;
            cout<<"CPF: "<<(*it).getCpf()<<endl;
            cout<<"Matrícula: "<<(*it).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*it).getIngressoEmpresa().dia<<"/"<<(*it).getIngressoEmpresa().mes<<"/"<<(*it).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*it).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<anos<<" anos, "<<meses<<" meses e "<<dias<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: Vendedor"<<endl;
            file<<"Nome: "<<(*it).getNome()<<endl;
            file<<"CPF: "<<(*it).getCpf()<<endl;
            file<<"Matrícula: "<<(*it).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*it).getIngressoEmpresa().dia<<"/"<<(*it).getIngressoEmpresa().mes<<"/"<<(*it).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*it).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<anos<<" anos, "<<meses<<" meses e "<<dias<<" dias"<<endl;
            file.close();

            vendedores.erase(it);
            return;
        }
    }

    for(auto it = gerentes.begin(); it != gerentes.end(); it++) {
        if((*it).getMatricula() == matricula) {
            int diastotais = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia - (*it).getIngressoEmpresa().ano*365 - (*it).getIngressoEmpresa().mes*30 - (*it).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            diastotais -= 365*anos;
            int meses = diastotais/30;
            diastotais -= 30*meses;
            int dias = diastotais;

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: Gerente"<<endl;
            cout<<"Nome: "<<(*it).getNome()<<endl;
            cout<<"CPF: "<<(*it).getCpf()<<endl;
            cout<<"Matrícula: "<<(*it).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*it).getIngressoEmpresa().dia<<"/"<<(*it).getIngressoEmpresa().mes<<"/"<<(*it).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*it).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<anos<<" anos, "<<meses<<" meses e "<<dias<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: Gerente"<<endl;
            file<<"Nome: "<<(*it).getNome()<<endl;
            file<<"CPF: "<<(*it).getCpf()<<endl;
            file<<"Matrícula: "<<(*it).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*it).getIngressoEmpresa().dia<<"/"<<(*it).getIngressoEmpresa().mes<<"/"<<(*it).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*it).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<anos<<" anos, "<<meses<<" meses e "<<dias<<" dias"<<endl;
            file.close();

            gerentes.erase(it);
            return;
        }
    }
}

//função que contrata um funcionário
void Empresa::contratarFuncionario() {
    ifstream file("novoFuncionario.txt");
    string line;
    getline(file, line);
    if(line == "ASG") {
        Asg asg;
        getline(file, line);
        asg.setNome(line);
        getline(file, line);
        asg.setCpf(line);
        getline(file, line);
        asg.setQtdFilhos(stoi(line));
        getline(file, line);
        asg.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        asg.setEnderecoPessoal(endereco);

        getline(file, line);

        Data data;
        getline(file, line);
        data.ano=stoi(line);
        getline(file, line);
        data.mes=stoi(line);
        getline(file, line);
        data.dia=stoi(line);
        asg.setDataNascimento(data);

        getline(file, line);

        getline(file, line);
        asg.setMatricula(line);
        getline(file, line);
        asg.setSalario(line);
        getline(file, line);
        asg.setAdicionalInsalubridade(stof(line));
        getline(file, line);
        asg.setFaltas(stoi(line));

        getline(file, line);

        Data ing;
        getline(file, line);
        ing.ano=stoi(line);
        getline(file, line);
        ing.mes=stoi(line);
        getline(file, line);
        ing.dia=stoi(line);
        asg.setIngressoEmpresa(ing);

        asgs.push_back(asg);

        return;
    }
    if(line == "Vendedor") {
        Vendedor vendedor;
        getline(file, line);
        vendedor.setNome(line);
        getline(file, line);
        vendedor.setCpf(line);
        getline(file, line);
        vendedor.setQtdFilhos(stoi(line));
        getline(file, line);
        vendedor.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        vendedor.setEnderecoPessoal(endereco);

        getline(file, line);

        Data data;
        getline(file, line);
        data.ano=stoi(line);
        getline(file, line);
        data.mes=stoi(line);
        getline(file, line);
        data.dia=stoi(line);
        vendedor.setDataNascimento(data);

        getline(file, line);

        getline(file, line);
        vendedor.setMatricula(line);
        getline(file, line);
        vendedor.setSalario(line);
        getline(file, line);
        vendedor.setTipoVendedor(line[0]);
        getline(file, line);
        vendedor.setFaltas(stoi(line));

        getline(file, line);

        Data ing;
        getline(file, line);
        ing.ano=stoi(line);
        getline(file, line);
        ing.mes=stoi(line);
        getline(file, line);
        ing.dia=stoi(line);
        vendedor.setIngressoEmpresa(ing);

        vendedores.push_back(vendedor);

        return;
    }
    if(line == "Gerente") {
        Gerente gerente;
        getline(file, line);
        gerente.setNome(line);
        getline(file, line);
        gerente.setCpf(line);
        getline(file, line);
        gerente.setQtdFilhos(stoi(line));
        getline(file, line);
        gerente.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        gerente.setEnderecoPessoal(endereco);

        getline(file, line);

        Data data;
        getline(file, line);
        data.ano=stoi(line);
        getline(file, line);
        data.mes=stoi(line);
        getline(file, line);
        data.dia=stoi(line);
        gerente.setDataNascimento(data);

        getline(file, line);

        getline(file, line);
        gerente.setMatricula(line);
        getline(file, line);
        gerente.setSalario(line);
        getline(file, line);
        gerente.setParticipacaoLucros(stof(line));
        getline(file, line);
        gerente.setFaltas(stoi(line));

        getline(file, line);

        Data ing;
        getline(file, line);
        ing.ano=stoi(line);
        getline(file, line);
        ing.mes=stoi(line);
        getline(file, line);
        ing.dia=stoi(line);
        gerente.setIngressoEmpresa(ing);

        gerentes.push_back(gerente);

        return;
    }
}

//função que determina se um funcionário existe no sistema a partir de sua matrícula
bool Empresa::buscaFuncionario(string matricula) {
    //percorrendo todos os três vetores possíveis e comparando a matrícula de cada funcionário com a que foi passada como parâmetro
    for(auto i:asgs) {
        //caso a matrícula coincidir, imprime uma mensagem e a função é encerrada retornando true
        if(i.getMatricula()==matricula) {
            cout<<"Funcionário encontrado!"<<endl;
            return true;
        }
    }
    for(auto i:vendedores) {
        if(i.getMatricula()==matricula) {
            cout<<"Funcionário encontrado!"<<endl;
            return true;
        }
    }
    for(auto i:gerentes) {
        if(i.getMatricula()==matricula) {
            cout<<"Funcionário encontrado!"<<endl;
            return true;
        }
    }
    //caso a função ainda não tenha sido encerrada, o funcionário não foi encontrado e retorna falso
    cout<<"Funcionário não encontrado no sistema!"<<endl;
    return false;
}

//função que determina o salário de um funcionário a partir de sua matrícula
float Empresa::calculaSalarioFuncionario(string matricula) {
    //percorrendo todos os três vetores possíveis e comparando a matrícula de cada funcionário com a que foi passada como parâmetro
    for(auto i:asgs) {
        //caso a matrícula coincidir, retornamos o salário do funcionário e imprimimos uma mensagem
        if(i.getMatricula()==matricula) {
            cout<<"O salário do funcionário é: "<<i.calcularSalario()<<endl;
            return i.calcularSalario();
        }
    }
    for(auto i:vendedores) {
        if(i.getMatricula()==matricula) {
            cout<<"O salário do funcionário é: "<<i.calcularSalario()<<endl;
            return i.calcularSalario();
        }
    }
    for(auto i:gerentes) {
        if(i.getMatricula()==matricula) {
            cout<<"O salário do funcionário é: "<<i.calcularSalario()<<endl;
            return i.calcularSalario();
        }
    }
    //caso a função ainda não tenha sido encerrada, o funcionário não foi encontrado e retorna um valor padrão -1
    cout<<"Funcionário não encontrado no sistema!"<<endl;
    return -1;
}

//função para imprimir em um arquivo "salarios.txt" e no console informações sobre os salários da emrpesa
void Empresa::calculaTodosOsSalarios() {
    float total=0, totala=0, totalv=0, totalg=0;

    //abrindo o arquivo
    ofstream file("salarios.txt");

    //checando se o arquivo foi aberto corretamente
    if (!(file.is_open())) {
        cout<<"Arquivo não pôde ser aberto!"<<endl;
        return;
    }

    //percorrendo o vetor de asgs
    for(auto i:asgs) {
        file<<"Nome do funcionário: "<<i.getNome()<<endl;
        cout<<"Nome do funcionário: "<<i.getNome()<<endl;
        file<<"Cargo do funcionário: ASG"<<endl;
        cout<<"Cargo do funcionário: ASG"<<endl;
        file<<"Salário do funcionário: "<<i.calcularSalario()<<endl;
        cout<<"Salário do funcionário: "<<i.calcularSalario()<<endl;
        file<<"****************************************"<<endl;
        cout<<"****************************************"<<endl;
        /*incrementação do total de salários gerais e dos asgs*/
        total+=i.calcularSalario();
        totala+=i.calcularSalario();
    }
    file<<"-----------------------------"<<endl;
    cout<<"-----------------------------"<<endl;

    //percorrendo o vetor de vendedores
    for(auto i:vendedores) {
        file<<"Nome do funcionário: "<<i.getNome()<<endl;
        cout<<"Nome do funcionário: "<<i.getNome()<<endl;
        file<<"Cargo do funcionário: vendedor"<<endl;
        cout<<"Cargo do funcionário: vendedor"<<endl;
        file<<"Salário do funcionário: "<<i.calcularSalario()<<endl;
        cout<<"Salário do funcionário: "<<i.calcularSalario()<<endl;
        file<<"****************************************"<<endl;
        cout<<"****************************************"<<endl;
        /*incrementação do total de salários gerais e dos vendedores*/
        total+=i.calcularSalario();
        totalv+=i.calcularSalario();
    }
    file<<"-----------------------------"<<endl;
    cout<<"-----------------------------"<<endl;

    //percorrendo o vetor de gerentes
    for(auto i:gerentes) {
        file<<"Nome do funcionário: "<<i.getNome()<<endl;
        cout<<"Nome do funcionário: "<<i.getNome()<<endl;
        file<<"Cargo do funcionário: gerente"<<endl;
        cout<<"Cargo do funcionário: gerente"<<endl;
        file<<"Salário do funcionário: "<<i.calcularSalario()<<endl;
        cout<<"Salário do funcionário: "<<i.calcularSalario()<<endl;
        file<<"****************************************"<<endl;
        cout<<"****************************************"<<endl;
        /*incrementação do total de salários gerais e dos gerentes*/
        total+=i.calcularSalario();
        totalg+=i.calcularSalario();
    }
    file<<"-----------------------------"<<endl;
    cout<<"-----------------------------"<<endl;

    file<<"Total de salários dos funcionários ASG: "<<totala<<endl;
    cout<<"Total de salários dos funcionários ASG: "<<totala<<endl;
    file<<"Total de salários dos vendedores: "<<totalv<<endl;
    cout<<"Total de salários dos vendedores: "<<totalv<<endl;
    file<<"Total de salários dos gerentes: "<<totalg<<endl;
    cout<<"Total de salários dos gerentes: "<<totalg<<endl;

    file<<"-----------------------------"<<endl;
    cout<<"-----------------------------"<<endl;
    file<<"Total de salários dos funcionários: "<<total<<endl;
    cout<<"Total de salários dos funcionários: "<<total<<endl;

    //fechando o arquivo
    file.close();

    ofstream relatorio("relatorioFinanceiro.txt");
    relatorio<<"######### Relatório Financeiro #########"<<endl<<endl;
    cout<<"######### Relatório Financeiro #########"<<endl<<endl;

    relatorio<<"Cargo: ASG"<<endl;
    cout<<"Cargo: ASG"<<endl;
    for(auto i : asgs) {
        relatorio<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
        cout<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
    }
    relatorio<<"Total ASG: "<<totala<<endl<<endl;
    cout<<"Total ASG: "<<totala<<endl<<endl;

    relatorio<<"Cargo: Vendedor"<<endl;
    cout<<"Cargo: Vendedor"<<endl;
    for(auto i : vendedores) {
        relatorio<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
        cout<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
    }
    relatorio<<"Total Vendedor: "<<totalv<<endl<<endl;
    cout<<"Total Vendedor: "<<totalv<<endl<<endl;

    relatorio<<"Cargo: Gerente"<<endl;
    cout<<"Cargo: Gerente"<<endl;
    for(auto i : gerentes) {
        relatorio<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
        cout<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
    }
    relatorio<<"Total Gerente: "<<totalg<<endl<<endl;
    cout<<"Total Gerente: "<<totalg<<endl<<endl;

    relatorio<<"CUSTO TOTAL: R$ "<<total<<endl<<endl;
    cout<<"CUSTO TOTAL: R$ "<<total<<endl<<endl;

    relatorio<<"FATURAMENTO MENSAL: R$ "<<faturamentoMensal<<endl<<endl;
    cout<<"FATURAMENTO MENSAL: R$ "<<faturamentoMensal<<endl<<endl;

    relatorio<<"CUSTO ASG(%): "<<(totala/total)*100<<"%"<<endl;
    relatorio<<"CUSTO Vendedor(%): "<<(totalv/total)*100<<"%"<<endl;
    relatorio<<"CUSTO Gerente(%): "<<(totalg/total)*100<<"%"<<endl<<endl;
    cout<<"CUSTO ASG(%): "<<(totala/total)*100<<"%"<<endl;
    cout<<"CUSTO Vendedor(%): "<<(totalv/total)*100<<"%"<<endl;
    cout<<"CUSTO Gerente(%): "<<(totalg/total)*100<<"%"<<endl<<endl;

    float lucro = faturamentoMensal - total;
    relatorio<<"LUCRO DA EMPRESA: "<<lucro<<endl<<endl;
    cout<<"LUCRO DA EMPRESA: "<<lucro<<endl<<endl;

    if(lucro >= 0) {
        relatorio<<"SITUAÇÃO: Lucro"<<endl;
        cout<<"SITUAÇÃO: Lucro"<<endl;
    }
    else {
        relatorio<<"SITUAÇÃO: Prejuízo"<<endl;
        cout<<"SITUAÇÃO: Prejuízo"<<endl;
    }

    relatorio.close();
}

//função que determina a recisão de um funcionário a partir de sua matrícula
float Empresa::calcularRecisao(string matricula, Data desligamento) {
    //percorrendo todos os três vetores possíveis e comparando a matrícula de cada funcionário com a que foi passada como parâmetro
    for(auto i:asgs) {
        //caso a matrícula coincidir, retornamos o salário do funcionário e imprimimos uma mensagem
        if(i.getMatricula()==matricula) {
            cout<<"A recisão do funcionário é: "<<i.calcularRecisao(desligamento)<<endl;
            return i.calcularRecisao(desligamento);
        }
    }
    for(auto i:vendedores) {
        if(i.getMatricula()==matricula) {
            cout<<"A recisão do funcionário é: "<<i.calcularRecisao(desligamento)<<endl;
            return i.calcularRecisao(desligamento);
        }
    }
    for(auto i:gerentes) {
        if(i.getMatricula()==matricula) {
            cout<<"A recisão do funcionário é: "<<i.calcularRecisao(desligamento)<<endl;
            return i.calcularRecisao(desligamento);
        }
    }
    //caso a função ainda não tenha sido encerrada, o funcionário não foi encontrado e retorna um valor padrão -1
    cout<<"Funcionário não encontrado no sistema!"<<endl;
    return -1;
}