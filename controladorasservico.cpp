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
		return false;

	}
	return true;
}
bool CntrServicoPessoal::descadastrar_usuario(CPF cpf){
	ComandoDescadastraUsuario cmd(cpf);
	try{
		cmd.executar();
	}
	catch(ErroPersistencia &exp){
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
		return false;
	}
	return true;
}
bool CntrServicoProdutosFinanceiros::acessa_numero_conta(CPF cpf, Numero* numero){
	ComandoAcessaNumeroConta cmd(cpf);
	try{
		cmd.executar();
		*numero=cmd.get_resultado();
	}
	catch(ErroPersistencia &exp){
		return false;
	}
	return true;
}

bool CntrServicoProdutosFinanceiros::descadastrar_conta(CPF cpf){
	Numero* numero=new Numero();
	if(!acessa_numero_conta(cpf,numero)){
		delete numero;
		return false;
	}

	ComandoDescadastraConta cmdConta(*numero);
	ComandoDescadastrarProduto cmdProduto(*numero);
	ComandoDescadastraAplicacao cmdAplicacao(*numero);
	try{
		cmdAplicacao.executar();
		cmdProduto.executar();
		cmdConta.executar();
	}
	catch(ErroPersistencia &exp){
		delete numero;
		return false;
	}
	delete numero;
	return true;
}
bool CntrServicoProdutosFinanceiros::consultar_conta(Conta* conta,CPF cpf){
	ComandoAcessaNumeroConta cmd_acessa(cpf);
	Numero numero;
	try{
		cmd_acessa.executar();
		numero=cmd_acessa.get_resultado();
		ComandoPesquisarConta cmd_conta(numero);
		cmd_conta.executar();
		*conta=cmd_conta.get_resultado();
	}
	catch(ErroPersistencia &exp){
		return false;
	}

	return true;
}
bool CntrServicoProdutosFinanceiros::cadastrar_produto(Produto produto, CPF cpf){
	ComandoCadastraProduto cmd(produto,cpf);
	try{
		cmd.executar();
	}
	catch(ErroPersistencia &exp){
		return false;
	}
	return true;
}
bool CntrServicoProdutosFinanceiros::descadastrar_produto(CodigoDeProduto codigo,CPF cpf){
	ComandoDescadastraAplicacao cmdAplicacao(codigo);
	ComandoDescadastrarProduto cmdProduto(codigo);
	ComandoAcessaNumeroConta cmdContaUsuario(cpf);
	ComandoNumeroContaProduto cmdContaProduto(codigo);

	try{
		cmdContaUsuario.executar();
		cmdContaProduto.executar();

		Numero numero1,numero2;
		numero1=cmdContaUsuario.get_resultado();
		numero2=cmdContaProduto.get_resultado();
		if(numero1.get_numero()!=numero2.get_numero())
			return false;
		cmdProduto.executar();
		cmdAplicacao.executar();
	}
	catch( ErroPersistencia &exp ){
		return false;
	}
	return true;
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

