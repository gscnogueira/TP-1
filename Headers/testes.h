#ifndef TESTES_H
#define TESTES_H
#include "dominios.h"

using namespace std;


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


#endif
