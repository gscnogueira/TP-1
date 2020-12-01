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
		bool cadastrar_usuario(Usuario,Numero);
		bool descadastrar_usuario(CPF);
		bool consultar_usuario(Usuario*, CPF);
};
class CntrServicoProdutosFinanceiros:public IServicoProdutosFinanceiros{
	private:
		bool acessa_numero_conta(CPF,Numero *);
	public:
		bool cadastrar_conta(Conta);
		bool descadastrar_conta(CPF);
		bool consultar_conta(Conta*, CPF);
		bool cadastrar_produto(Produto, CPF) ;
		bool consultar_produtos(vector<Produto>&, string classe);
		bool descadastrar_produto(CodigoDeProduto, CPF);
		int realizar_aplicacao(Aplicacao, CPF, CodigoDeProduto);
		bool recuperar_aplicacao(Aplicacao*);
};







#endif
