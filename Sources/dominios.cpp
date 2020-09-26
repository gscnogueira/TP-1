#include "../Headers/dominios.h"
#include <bits/stdc++.h>

using namespace std;

//----------------------------------------------------------
//-------------------------CEP------------------------------
//----------------------------------------------------------
const vector<pair<int,int>> CEP::REGIOES  = {
            make_pair(1000000,5999999),
            make_pair(8000000,8499999),
            make_pair(20000000,26600999),
            make_pair(70000000,70999999),
            make_pair(40000000,41999999),
            make_pair(60000000,60999999)};

void CEP::validar(int valor){
    bool valido=false;
    for(pair<int,int> e: REGIOES)
        if(valor>=e.first and valor<=e.second){
            valido=true;
            break;
        }
    if(!valido)
        throw invalid_argument("CEP::validar");
}
CEP::CEP(int valor){
    validar(valor); 
    this->valor=valor;
}

void CEP::set_valor(int valor){
    validar(valor);
    this->valor=valor;
}
//----------------------------------------------------------
//------------------------CLASSE----------------------------
//----------------------------------------------------------
const set<string> Classe::CLASSES_VALIDAS ={"CDB","LCA","LCI","LF","LC"};

void Classe::validar(string nome){
    if(!CLASSES_VALIDAS.count(nome))
        throw invalid_argument("Classe::validar");
}
Classe::Classe(string nome){
    validar(nome);
    this->nome=nome;
}
void Classe::set_classe(string nome){
    validar(nome);
    this->nome=nome;
}
//----------------------------------------------------------
//-------------------CÓDIGO-DE-AGÊNCIA----------------------
//----------------------------------------------------------
const string CodigoDeAgencia::EXCESSAO = "0000";

void CodigoDeAgencia::validar(string codigo){
    if(codigo.length()!=TAMANHO)
        throw invalid_argument("CodigoDeAgencia::validar");
    if(codigo==EXCESSAO)
        throw invalid_argument("CodigoDeAgencia::validar");
    for(char e: codigo)
        if(!isdigit(e))
            throw invalid_argument("CodigoDeAgencia::validar");
}
CodigoDeAgencia::CodigoDeAgencia(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
void CodigoDeAgencia::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-APLICAÇÃO---------------------
//----------------------------------------------------------

const string CodigoDeAplicacao::EXCESSAO = "00000";

void CodigoDeAplicacao::validar(string codigo){
    if(codigo.length()!=TAMANHO)
        throw invalid_argument("CodigoDeAplicacao::validar");
    if(codigo==EXCESSAO)
        throw invalid_argument("CodigoDeAplicacao::validar");
    for(char e: codigo)
        if(!isdigit(e))
            throw invalid_argument("CodigoDeAplicacao::validar");
}
CodigoDeAplicacao::CodigoDeAplicacao(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
void CodigoDeAplicacao::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-BANCO-------------------------
//----------------------------------------------------------

const set<string> CodigoDeBanco::BANCOS={"341","001","237","104","033"};

void CodigoDeBanco::validar(string codigo){
    if(!BANCOS.count(codigo))
        throw invalid_argument("CodigoDeBanco::validar");
}

CodigoDeBanco::CodigoDeBanco(string codigo){
    validar(codigo);
    this->codigo=codigo;

}
void CodigoDeBanco::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
//----------------------------------------------------------
//-------------------CÓDIGO-DE-PRODUTO----------------------
//----------------------------------------------------------

const string CodigoDeProduto::EXCESSAO="000";

void CodigoDeProduto::validar(string codigo){
    if(codigo.length()!=TAMANHO)
        throw invalid_argument("CodigoDeProduto::validar");
    if(codigo==EXCESSAO)
        throw invalid_argument("CodigoDeProduto::validar");
    for(char e:codigo)
        if(!isdigit(e))
            throw invalid_argument("CodigoDeProduto::validar");
}

CodigoDeProduto::CodigoDeProduto(string codigo){
    validar(codigo);
    this->codigo=codigo;
}

void CodigoDeProduto::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}

//----------------------------------------------------------
//------------------------CPF-------------------------------
//----------------------------------------------------------

void CPF::validar(string cpf){
    if(cpf.length()!=TAMANHO)
        throw invalid_argument("CPF::validar");

    if(!regex_match(cpf,regex("[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}")))
        throw invalid_argument("CPF::validar");

    vector<int> cpf_numeros, v1, v2;
    bool flag=false;


    for(char e:cpf){
        if(isdigit(e)){
            cpf_numeros.push_back(e -'0');
        }
    }
    for(int i =1; i<(int)cpf_numeros.size();i++){
        if(cpf_numeros[i]!=cpf_numeros[i-1])
        {
            flag=true;
        }
    }
    if(!flag)
        throw invalid_argument("CPF::validar");

    for(int i=0, j= 10;j>1;i++,j--){
        v1.push_back(cpf_numeros[i]*j);
    }
    int d1=accumulate(v1.begin(),v1.end(),0)*10;
    d1 %=11;
    if(d1!=cpf_numeros[9])
        throw invalid_argument("CPF::validar");


    for(int i=0, j= 11;j>1;i++,j--){
        v2.push_back(cpf_numeros[i]*j);
    }
    int d2=accumulate(v2.begin(),v2.end(),0)*10;
    d2 %=11;
    if(d2!=cpf_numeros[10])
        throw invalid_argument("CPF::validar");
}
void CPF::set_cpf(string cpf){
    validar(cpf);
    this->cpf=cpf;
}
