
#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include<bits/stdc++.h>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

class StubServicoAutenticacao:public IServicoAutenticacao{
	private:
		static const string INVALIDO;
	public:
		bool autenticar(CPF,Senha);
};
class StubServicoPessoal:public IServicoPessoal{
	public:
		bool cadastrar_usuario(Usuario);
};
class StubServicoProdutosFinanceiros:public IServicoProdutosFinanceiros{
	public:
		bool cadastrar_conta(Conta);
		bool consultar_conta(Conta*);
		bool cadastrar_produto(Produto) ;
		bool descadastrar_produto(CodigoDeProduto);
		bool realizar_aplicacao(Aplicacao);
		bool recuperar_aplicacao(Aplicacao*);
};


#endif
