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

