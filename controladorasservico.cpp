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

bool CntrServicoPessoal::cadastrar_usuario(Usuario usuario){
	ComandoCadastrarUsuario comandoCadastrarUsuario(usuario);
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
bool CntrServicoProdutosFinanceiros::consultar_conta(Conta* conta){
	return true;
}
bool CntrServicoProdutosFinanceiros::cadastrar_produto(Produto produto){
	return (produto.get_classe().get_classe()!="LCI");
}
bool CntrServicoProdutosFinanceiros::descadastrar_produto(CodigoDeProduto codigo){
	return (codigo.get_codigo()!="123");
}
bool CntrServicoProdutosFinanceiros::realizar_aplicacao(Aplicacao aplicacao){
	return (aplicacao.get_codigo().get_codigo()=="99999");
}
bool CntrServicoProdutosFinanceiros::recuperar_aplicacao(Aplicacao* aplicacao){
	return true;
}

