#include "stubs.h"

const string StubServicoAutenticacao::INVALIDO = "200.094.918-56";

bool StubServicoAutenticacao::autenticar(CPF cpf, Senha senha){
	if(cpf.get_cpf().compare(INVALIDO)==0){
		return false;
	}
	return true;
}

