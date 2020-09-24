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
