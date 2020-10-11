#include <bits/stdc++.h>
#include "dominios.h"
#include "entidades.h"
#include "testes_entidades.h"


using namespace std;

//----------------------------------------------------------
//----------------------APLICAÇÃO---------------------------
//----------------------------------------------------------


const string TUAplicacao::CODIGO_VALIDO = "25483";
const string TUAplicacao::VALOR_VALIDO = "2400,86";
const string TUAplicacao::DATA_VALIDA = "16/09/2047";

void TUAplicacao::set_up(){
    aplicacao= new Aplicacao();
    estado = true;
}
void TUAplicacao::tear_down(){
    delete aplicacao;
}
void TUAplicacao::testa_codigo(){
    CodigoDeAplicacao codigo;
    codigo.set_codigo(CODIGO_VALIDO);
    aplicacao->set_codigo(codigo);
    if(aplicacao->get_codigo().get_codigo()!=CODIGO_VALIDO)
        estado=false;
}

void TUAplicacao::testa_valor(){
    ValorDeAplicacao valor;
    valor.set_valor(VALOR_VALIDO);
    aplicacao->set_valor(valor);
    if(aplicacao->get_valor().get_valor()!=VALOR_VALIDO)
        estado=false;
}

void TUAplicacao::testa_data(){
    Data data;
    data.set_data(DATA_VALIDA);
    aplicacao->set_data(data);
    if(aplicacao->get_data().get_data()!=DATA_VALIDA)
        estado=false;
}


bool TUAplicacao::run(){
    set_up();
    testa_codigo();
    testa_valor();
    testa_data();
    tear_down();
    return estado;
}



