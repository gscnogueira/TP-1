
#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include<bits/stdc++.h>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

class StubServicoAutenticacao:public IServicoAutenticacao{
	private:
		static const string INVALIDO;
	public:
		bool autenticar(CPF,Senha);
};


#endif
