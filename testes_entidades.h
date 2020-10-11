#ifndef TESTES_ENTIDADES_H
#define TESTES_ENTIDADES_H

#include <bits/stdc++.h>
#include "dominios.h"
#include "entidades.h"

using namespace std;

//----------------------------------------------------------
//----------------------APLICAÇÃO---------------------------
//----------------------------------------------------------

class TUAplicacao{
    private:
        const static string CODIGO_VALIDO;
        const static string VALOR_VALIDO;
        const static string DATA_VALIDA;

        Aplicacao *aplicacao;
        bool estado;
        void set_up();
        void tear_down();
        void testa_codigo();
        void testa_valor();
        void testa_data();
    public:
        bool run();
};

//----------------------------------------------------------
//--------------------------CONTA---------------------------
//----------------------------------------------------------
class TUConta{
    private:
        const static string BANCO_VALIDO;
        const static string AGENCIA_VALIDA;
        const static string NUMERO_VALIDO;
        Conta* conta;
        bool estado;
        void set_up();
        void tear_down();
        void testa_banco();
        void testa_agencia();
        void testa_numero();
    public:
        bool run();

};
#endif

