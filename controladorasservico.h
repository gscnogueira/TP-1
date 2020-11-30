#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include<bits/stdc++.h>
#include "dominios.h"
#include"entidades.h"
#include "interfaces.h"

using namespace std;

class CntrServicoAutenticacao:public IServicoAutenticacao{
	public:
		bool autenticar(CPF,Senha);
};

class CntrServicoPessoal:public IServicoPessoal{
	public:
		bool cadastrar_usuario(Usuario);
		bool consultar_usuario(Usuario*, CPF);
};
class CntrServicoProdutosFinanceiros:public IServicoProdutosFinanceiros{
	public:
		bool cadastrar_conta(Conta);
		bool consultar_conta(Conta*);
		bool cadastrar_produto(Produto) ;
		bool descadastrar_produto(CodigoDeProduto);
		bool realizar_aplicacao(Aplicacao);
		bool recuperar_aplicacao(Aplicacao*);
};







#endif
