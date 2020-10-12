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
//----------------------------------------------------------
//-----------------------PRODUTO----------------------------
//----------------------------------------------------------
class TUProduto{
    private:
        bool estado;
        Produto* produto;
        const static string CODIGO_VALIDO;
        const static string CLASSE_VALIDO;
        const static string EMISSOR_VALIDO;
        const static int PRAZO_VALIDO=24;
        const static string VENCIMENTO_VALIDO;
        const static int TAXA_VALIDO=50;
        const static string HORARIO_VALIDO;
        const static int VALOR_VALIDO=10000;
        void set_up();
        void tear_down();
        void testa_codigo();
        void testa_classe();
        void testa_emissor();
        void testa_prazo();
        void testa_vencimento();
        void testa_taxa();
        void testa_horario();
        void testa_valor();
    public:
        bool run();
};
//----------------------------------------------------------
//----------------------USUÁRIO-----------------------------
//----------------------------------------------------------
class TUUsuario{
    private:
        const static string NOME_VALIDO;
        const static string ENDERECO_VALIDO;
        const static int CEP_VALIDO=1234567;
        const static string CPF_VALIDO;
        const static string SENHA_VALIDO;
        Usuario* usuario;
        bool estado;
        void set_up();
        void tear_down();
        void testa_nome();
        void testa_endereco();
        void testa_cep();
        void testa_cpf();
        void testa_senha();
    public:
        bool run();
};
#endif

