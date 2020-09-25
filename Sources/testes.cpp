#include "../Headers/testes.h"

//----------------------------------------------------------
//-------------------------CEP------------------------------
//----------------------------------------------------------
void TUCEP::testa_sucesso(){
    try{
        cep.set_valor(VALOR_VALIDO);
        if(cep.get_valor()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}
void TUCEP::testa_falha(){
    try{
        cep.set_valor(VALOR_INVALIDO);
        estado = false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUCEP::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}
//----------------------------------------------------------
//------------------------CLASSE----------------------------
//----------------------------------------------------------
const string TUClasse::VALOR_VALIDO="LCI";
const string TUClasse::VALOR_INVALIDO="BLAU";

void TUClasse::testa_sucesso(){
    try{
        classe.set_classe(VALOR_VALIDO);
        if(classe.get_classe()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUClasse::testa_falha(){
    try{
        classe.set_classe(VALOR_INVALIDO);
        if(classe.get_classe()==VALOR_INVALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUClasse::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-AGÊNCIA-----------------------
//----------------------------------------------------------
const string TUCodigoDeAgencia::VALOR_VALIDO="9999";
const string TUCodigoDeAgencia::VALOR_INVALIDO="11b1";

void TUCodigoDeAgencia::testa_sucesso(){
    try{
        codigo_de_agencia.set_codigo(VALOR_VALIDO);
        if(codigo_de_agencia.get_codigo()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUCodigoDeAgencia::testa_falha(){
    try{
        codigo_de_agencia.set_codigo(VALOR_INVALIDO);
        if(codigo_de_agencia.get_codigo()==VALOR_INVALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUCodigoDeAgencia::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-APLICAÇÃO---------------------
//----------------------------------------------------------
const string TUCodigoDeAplicacao::VALOR_VALIDO="99999";
const string TUCodigoDeAplicacao::VALOR_INVALIDO="128b1";

void TUCodigoDeAplicacao::testa_sucesso(){
    try{
        codigo_de_aplicacao.set_codigo(VALOR_VALIDO);
        if(codigo_de_aplicacao.get_codigo()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUCodigoDeAplicacao::testa_falha(){
    try{
        codigo_de_aplicacao.set_codigo(VALOR_INVALIDO);
        if(codigo_de_aplicacao.get_codigo()==VALOR_INVALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUCodigoDeAplicacao::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-BANCO-------------------------
//----------------------------------------------------------

const string TUCodigoDeBanco::VALOR_VALIDO="104";
const string TUCodigoDeBanco::VALOR_INVALIDO="125";

void TUCodigoDeBanco::testa_sucesso(){
    try{
        codigo_de_banco.set_codigo(VALOR_VALIDO);
        if(codigo_de_banco.get_codigo()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUCodigoDeBanco::testa_falha(){
    try{
        codigo_de_banco.set_codigo(VALOR_INVALIDO);
        if(codigo_de_banco.get_codigo()==VALOR_INVALIDO)
            estado = false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUCodigoDeBanco::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}

