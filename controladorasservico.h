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
};







#endif
