#include "../Headers/testes.h"

//----------------------------------------------------------
//-------------------------CEP------------------------------
//----------------------------------------------------------

void TUCEP::set_up(){
    cep= new CEP();
    estado=SUCESSO;
}
void TUCEP::tear_down(){
    delete cep;
}

void TUCEP::testa_sucesso(){
    try{
        cep->set_valor(VALOR_VALIDO);
        if(cep->get_valor()!=VALOR_VALIDO)
            estado=FALHA;
    }
    catch(invalid_argument &excessao){
        estado=FALHA;
    }
}
void TUCEP::testa_falha(){
    try{
        cep->set_valor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        return;
    }
}

int TUCEP::run(){
    set_up();
    testa_sucesso();
    testa_falha();
    tear_down();
    return estado;
}
