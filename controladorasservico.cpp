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
