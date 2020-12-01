#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
// Adequar as declarações das interfaces de acordo com as necessidades.
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

// Forward declarations.

class IServicoAutenticacao;
class IServicoPessoal;
class IServicoProdutosFinanceiros;

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(CPF*) = 0;
        virtual void set_cntr_servico_autenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(CPF) = 0;
        virtual void cadastrar() = 0;
        virtual void set_cntr_servico_pessoal(IServicoPessoal*) = 0;
        virtual void set_cntr_servico_produtos_financeiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoProdutosFinanceiros{
    public:
        virtual void executar() = 0;
        virtual void executar(CPF) = 0;
        virtual void set_cntr_servico_produtos_financeiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoProdutosFinanceiros(){}
};

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(CPF, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
public:
        virtual bool cadastrar_usuario(Usuario, Numero) = 0;
		virtual bool consultar_usuario(Usuario*, CPF) =0;
        virtual ~IServicoPessoal(){}
};

class IServicoProdutosFinanceiros{
public:
        virtual bool cadastrar_conta(Conta) = 0;
        virtual bool consultar_conta(Conta*, CPF) = 0;
        virtual bool cadastrar_produto(Produto) = 0;
        virtual bool descadastrar_produto(CodigoDeProduto) = 0;
        virtual int realizar_aplicacao(Aplicacao,CPF,CodigoDeProduto) = 0;
        virtual bool recuperar_aplicacao(Aplicacao*) = 0;                        // Adaptar aos requisitos.
        virtual ~IServicoProdutosFinanceiros(){}
};

#endif // INTERFACES_H_INCLUDED
