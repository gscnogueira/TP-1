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
