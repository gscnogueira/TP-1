#ifndef TESTES_H
#define TESTES_H
#include "dominios.h"

using namespace std;

//----------------------------------------------------------
//-------------------------CEP------------------------------
//----------------------------------------------------------

class TUCEP{
    private:
        const static int VALOR_VALIDO = 8000000;
        const static int VALOR_INVALIDO = 999999;
        CEP *cep;
        int estado;
        
        void set_up();
        void tear_down();
        void testa_sucesso();
        void testa_falha();
    public:

        const static int  SUCESSO =  0;
        const static int  FALHA   = -1;

        int run();
};

//----------------------------------------------------------
//------------------------CLASSE----------------------------
//----------------------------------------------------------


class TUClasse{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Classe classe;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
};
#endif
