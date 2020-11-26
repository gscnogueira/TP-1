#include<bits/stdc++.h>
#include <ncurses.h>
#include "interfaces.h"
#include"stubs.h"
#include "controladorasapresentacao.h"
/* #include "stubs.h" */

using namespace std;

int main()
{

    CntrApresentacaoControle *cntrApresentacaoControle= new CntrApresentacaoControle();

	IApresentacaoAutenticacao *cntrApresentacaoAutenticacao=new CntrApresentacaoAutenticacao();
	IApresentacaoPessoal *cntrApresentacaoPessoal=new CntrApresentacaoPessoal();
	IApresentacaoProdutosFinanceiros *cntrApresentacaoProdutosFinanceiros=new CntrApresentacaoProdutosFinanceiros();

	cntrApresentacaoControle->set_cntr_apresentacao_autenticacao(cntrApresentacaoAutenticacao);
	cntrApresentacaoControle->set_cntr_apresentacao_pessoal(cntrApresentacaoPessoal);
	cntrApresentacaoControle->set_cntr_apresentacao_produtos_financeiros(cntrApresentacaoProdutosFinanceiros);

	IServicoAutenticacao *cntrServicoAutenticacao=new StubServicoAutenticacao();
	IServicoPessoal *cntrServicoPessoal=new StubServicoPessoal();
	IServicoProdutosFinanceiros *cntrServicoProdutosFinanceiros=new StubServicoProdutosFinanceiros();

	cntrApresentacaoAutenticacao->set_cntr_servico_autenticacao(cntrServicoAutenticacao);

	cntrApresentacaoPessoal->set_cntr_servico_pessoal(cntrServicoPessoal);
	cntrApresentacaoPessoal->set_cntr_servico_produtos_financeiros(cntrServicoProdutosFinanceiros);

	cntrApresentacaoProdutosFinanceiros->set_cntr_servico_produtos_financeiros(cntrServicoProdutosFinanceiros);


    initscr();
    cntrApresentacaoControle->executar();
    endwin();

    return 0;
}

