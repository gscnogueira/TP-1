#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include <ncurses.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
//----------------------------------------------------------
//-----------------Móulo-Autenticação-Controle--------------
//----------------------------------------------------------
class CntrApresentacaoControle{
	private:
		CPF cpf;
		IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
		IApresentacaoPessoal *cntrApresentacaoPessoal;
		IApresentacaoProdutosFinanceiros *cntrApresentacaoProdutosFinanceiros;
	public:
		void executar();
		void set_cntr_apresentacao_autenticacao(IApresentacaoAutenticacao*);
		void set_cntr_apresentacao_pessoal(IApresentacaoPessoal*);
		void set_cntr_apresentacao_produtos_financeiros(IApresentacaoProdutosFinanceiros*);
};

inline void CntrApresentacaoControle::set_cntr_apresentacao_autenticacao(IApresentacaoAutenticacao *cntr){
	cntrApresentacaoAutenticacao=cntr;
}
inline void CntrApresentacaoControle::set_cntr_apresentacao_pessoal(IApresentacaoPessoal* cntr){
	cntrApresentacaoPessoal=cntr;
}
inline void CntrApresentacaoControle::set_cntr_apresentacao_produtos_financeiros(IApresentacaoProdutosFinanceiros *cntr){
	cntrApresentacaoProdutosFinanceiros=cntr;
}

//----------------------------------------------------------
//-----------------Móulo-Apresentação-Autenticação---------
//----------------------------------------------------------
class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
	private:
		IServicoAutenticacao *cntr;
	public:
		bool autenticar(CPF*);
		void set_cntr_servico_autenticacao(IServicoAutenticacao*);
};
inline void CntrApresentacaoAutenticacao::set_cntr_servico_autenticacao(IServicoAutenticacao *cntr){
	this->cntr=cntr;
}

//----------------------------------------------------------
//-----------------Móulo-Apresentação-Pessoal---------------
//----------------------------------------------------------
class CntrApresentacaoPessoal:public IApresentacaoPessoal{
	private:
		IServicoPessoal* cntrServicoPessoal;
		IServicoProdutosFinanceiros* cntrServicoProdutosFinanceiros;
	public:
		void executar(CPF);
		void cadastrar();
		void set_cntr_servico_pessoal(IServicoPessoal*);
		void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*);
		
};
inline void CntrApresentacaoPessoal::set_cntr_servico_pessoal(IServicoPessoal* cntr){
	cntrServicoPessoal=cntr;
}
inline void CntrApresentacaoPessoal::setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros* cntr){
	cntrServicoProdutosFinanceiros=cntr;
}
//----------------------------------------------------------
//----------Móulo-Apresentação-Produtos-Financeiros---------
//----------------------------------------------------------
class CntrApresentacaoProdutosFinanceiros: public IApresentacaoProdutosFinanceiros{
	private:
		IServicoProdutosFinanceiros *cntrServicoProdutosFinanceiros;
	public:
		void executar();
		void executar(CPF);
		void set_cntr_servico_produtos_financeiros(IServicoProdutosFinanceiros*);
};
inline void CntrApresentacaoProdutosFinanceiros::set_cntr_servico_produtos_financeiros(IServicoProdutosFinanceiros *cntr){
	cntrServicoProdutosFinanceiros=cntr;
}
#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
