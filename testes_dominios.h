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
        CEP cep;
        int estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
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
//----------------------------------------------------------
//------------------CÓDIGO-DE-AGÊNCIA-----------------------
//----------------------------------------------------------
class TUCodigoDeAgencia{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        CodigoDeAgencia codigo_de_agencia;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
};
//----------------------------------------------------------
//------------------CÓDIGO-DE-APLICAÇÃO---------------------
//----------------------------------------------------------
class TUCodigoDeAplicacao{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        CodigoDeAplicacao codigo_de_aplicacao;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
};
//----------------------------------------------------------
//------------------CÓDIGO-DE-BANCO-------------------------
//----------------------------------------------------------
class TUCodigoDeBanco{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        CodigoDeBanco codigo_de_banco;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
};
//----------------------------------------------------------
//-------------------CÓDIGO-DE-PRODUTO----------------------
//----------------------------------------------------------

class TUCodigoDeProduto{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        CodigoDeProduto codigo_de_produto;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();

};
//----------------------------------------------------------
//------------------------CPF-------------------------------
//----------------------------------------------------------

class TUCPF{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        CPF* cpf;
        bool estado;
        void set_up();
        void testa_sucesso();
        void testa_falha();
        void tear_down();
    public:
        bool run(); 
};
//----------------------------------------------------------
//------------------------DATA------------------------------
//----------------------------------------------------------
class TUData{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Data data;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();

};
//----------------------------------------------------------
//------------------------EMISSOR---------------------------
//----------------------------------------------------------

class TUEmissor{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Emissor* ptr_emissor;
        bool estado;
        void set_up();
        void testa_sucesso();
        void testa_falha();
        void tear_down();
    public:
        bool run(); 
};

//----------------------------------------------------------
//------------------------ENDEREÇO--------------------------
//----------------------------------------------------------

class TUEndereco{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Endereco* ptr_endereco;
        bool estado;
        void set_up();
        void testa_sucesso();
        void testa_falha();
        void tear_down();
    public:
        bool run(); 
};
//----------------------------------------------------------
//------------------------HORÁRIO---------------------------
//----------------------------------------------------------
class TUHorario{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Horario horario;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();

};
//----------------------------------------------------------
//------------------------NOME------------------------------
//----------------------------------------------------------

class TUNome{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Nome* ptr_nome;
        bool estado;
        void set_up();
        void testa_sucesso();
        void testa_falha();
        void tear_down();
    public:
        bool run(); 
};

//----------------------------------------------------------
//------------------------NÚMERO----------------------------
//----------------------------------------------------------

class TUNumero{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Numero* ptr_numero;
        bool estado;
        void set_up();
        void testa_sucesso();
        void testa_falha();
        void tear_down();
    public:
        bool run(); 
};
//----------------------------------------------------------
//------------------------PRAZO-----------------------------
//----------------------------------------------------------
class TUPrazo{
    private:
        const static int VALOR_VALIDO = 48;
        const static int VALOR_INVALIDO = 16;
        Prazo prazo;
        int estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
};
//----------------------------------------------------------
//------------------------SENHA-----------------------------
//----------------------------------------------------------
class TUSenha{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        Senha* ptr_senha;
        bool estado;
        void set_up();
        void testa_sucesso();
        void testa_falha();
        void tear_down();
    public:
        bool run(); 
};

//----------------------------------------------------------
//------------------------TAXA------------------------------
//----------------------------------------------------------
class TUTaxa{
    private:
        const static int VALOR_VALIDO = 50;
        const static int VALOR_INVALIDO = 250;
        Taxa taxa;
        int estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run();
};
//----------------------------------------------------------
//------------------VALOR-DE-APLICAÇÃO----------------------
//----------------------------------------------------------


class TUValorDeAplicacao{
    private:
        static const string VALOR_VALIDO;
        static const string VALOR_INVALIDO;
        ValorDeAplicacao valor;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run(); 
};
//----------------------------------------------------------
//----------------------VALOR-MÍNIMO------------------------
//----------------------------------------------------------

class TUValorMinimo{
    private:
        static const int VALOR_VALIDO=10000;
        static const int VALOR_INVALIDO=15000;
        ValorMinimo valor;
        bool estado=true;
        void testa_sucesso();
        void testa_falha();
    public:
        bool run(); 
};
#endif
