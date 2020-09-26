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
//----------------------------------------------------------
//-------------------CÓDIGO-DE-PRODUTO----------------------
//----------------------------------------------------------


const string TUCodigoDeProduto::VALOR_VALIDO="104";
const string TUCodigoDeProduto::VALOR_INVALIDO="1b4";

void TUCodigoDeProduto::testa_sucesso(){
    try{
        codigo_de_produto.set_codigo(VALOR_VALIDO);
        if(codigo_de_produto.get_codigo()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUCodigoDeProduto::testa_falha(){
    try{
        codigo_de_produto.set_codigo(VALOR_INVALIDO);
        if(codigo_de_produto.get_codigo()==VALOR_INVALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUCodigoDeProduto::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}
//----------------------------------------------------------
//------------------------CPF-------------------------------
//----------------------------------------------------------

const string TUCPF::VALOR_VALIDO="200.094.918-56";
const string TUCPF::VALOR_INVALIDO="111.111.111-11";

void  TUCPF::set_up(){
    cpf=new CPF();
    estado=true;
}
void TUCPF::tear_down(){
    delete cpf;
}
void TUCPF::testa_sucesso(){
    try{
        cpf->set_cpf(VALOR_VALIDO);
        if(cpf->get_cpf()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUCPF::testa_falha(){
    try{
        cpf->set_cpf(VALOR_INVALIDO);
        if(cpf->get_cpf()==VALOR_INVALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUCPF::run(){
    set_up();
    testa_sucesso();
    testa_falha();
    tear_down();
    return estado;
}
//----------------------------------------------------------
//------------------------DATA------------------------------
//----------------------------------------------------------

const string TUData::VALOR_VALIDO="29/02/2020";
const string TUData::VALOR_INVALIDO="31/09/2020";

void TUData::testa_sucesso(){
    try{
        data.set_data(VALOR_VALIDO);
        if(data.get_data()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        estado=false;
    }
}

void TUData::testa_falha(){
    try{
        data.set_data(VALOR_INVALIDO);
        if(data.get_data()==VALOR_INVALIDO)
           estado=false; 

    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUData::run(){
    testa_sucesso();
    testa_falha();
    return estado;
}
//----------------------------------------------------------
//------------------------EMISSOR---------------------------
//----------------------------------------------------------

const string TUEmissor::VALOR_VALIDO="Meu Amor 2000";
const string TUEmissor::VALOR_INVALIDO="Minha nossa";


void  TUEmissor::set_up(){
    ptr_emissor=new Emissor();
    estado=true;
}
void TUEmissor::tear_down(){
    delete ptr_emissor;
}
void TUEmissor::testa_sucesso(){
    try{
        ptr_emissor->set_emissor(VALOR_VALIDO);
        if(ptr_emissor->get_emissor()!=VALOR_VALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        cout<<e.what()<<endl;
        estado=false;
    }
}

void TUEmissor::testa_falha(){
    try{
        ptr_emissor->set_emissor(VALOR_INVALIDO);
        if(ptr_emissor->get_emissor()==VALOR_INVALIDO)
            estado=false;
    }
    catch(invalid_argument &e){
        return;
    }
}

bool TUEmissor::run(){
    set_up();
    testa_sucesso();
    testa_falha();
    tear_down();
    return estado;
}

