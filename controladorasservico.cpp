#include "controladorasservico.h"
#include "persistencia.h"
#include<ncurses.h>

bool CntrServicoAutenticacao::autenticar(CPF cpf, Senha senha){
	ComandoLerSenha comandoLerSenha(cpf);
	try{
		comandoLerSenha.executar();
		string senhaRecuperada;
		senhaRecuperada=comandoLerSenha.get_resultado();
		if(senhaRecuperada!=senha.get_senha())
			return false;
	}
	catch(ErroPersistencia &exp){
		return false;
	}
	return true;
}

bool CntrServicoPessoal::cadastrar_usuario(Usuario usuario, Numero numero){
	ComandoCadastrarUsuario comandoCadastrarUsuario(usuario,numero);
	try{
		comandoCadastrarUsuario.executar();
	}
	catch(ErroPersistencia &exp){
		printw("%s",exp.what().c_str());
		return false;

	}
	return true;
}
bool CntrServicoPessoal::consultar_usuario(Usuario* usuario,CPF cpf){
	ComandoPesquisarUsuario comando(cpf);
	try{
		comando.executar();
		*usuario=comando.get_resultado();
	}
	catch(ErroPersistencia &exp){
		return false;
	}
	return true;
}


bool CntrServicoProdutosFinanceiros::cadastrar_conta(Conta conta){
	ComandoCadastraConta cmd(conta);
	try{
		cmd.executar();
	}
	catch(ErroPersistencia &exp){
		printw("%s",exp.what().c_str());
		getch();
		return false;
	}
	return true;
}
bool CntrServicoProdutosFinanceiros::consultar_conta(Conta* conta,CPF cpf){
	ComandoAcessaNumeroConta cmd_acessa(cpf);
	Numero numero;
	try{
		cmd_acessa.executar();
		numero=cmd_acessa.get_resultado();
		printw("%s",numero.get_numero().c_str());
		ComandoPesquisarConta cmd_conta(numero);
		cmd_conta.executar();
		*conta=cmd_conta.get_resultado();
	}
	catch(ErroPersistencia &exp){
		printw("%s",exp.what().c_str());
		refresh();
		getch();
		return false;
	}

	return true;
}
bool CntrServicoProdutosFinanceiros::cadastrar_produto(Produto produto){
	ComandoCadastraProduto cmd(produto);
	try{
		cmd.executar();
	}
	catch(ErroPersistencia &exp){
		return false;
	}
	return true;
}
bool CntrServicoProdutosFinanceiros::descadastrar_produto(CodigoDeProduto codigo){
	return (codigo.get_codigo()!="123");
}
int CntrServicoProdutosFinanceiros::realizar_aplicacao(Aplicacao aplicacao,CPF cpf, CodigoDeProduto codigo){
	ComandoAplicacao cmd(aplicacao,cpf,codigo);
	ComandoPesquisaProduto cmdPesquisa(codigo);
	Produto produto;
	try{
		ComandoContaAplicacoes cmdConta(cpf);
		cmdConta.executar();
		if(cmdConta.get_resultado()>=5)
			return 4;
		cmdPesquisa.executar();
		produto=cmdPesquisa.get_resultado();
		if(stod(aplicacao.get_valor().get_valor())<produto.get_valor().get_valor())
			return 1;
		cmd.executar();
	}
	catch(ErroPersistencia &exp){
		if(exp.what()=="Lista de resultados vazia.")
			return 2;
		if(exp.what()=="Erro na execucao do comando SQL")
			return 3;
		return 5;
	}
	return 0;
}
bool CntrServicoProdutosFinanceiros::recuperar_aplicacao(Aplicacao* aplicacao){
	return true;
}

