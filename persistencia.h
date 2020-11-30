#ifndef Persistencia_H
#define Persistencia_H

#include<bits/stdc++.h>
#include"entidades.h"
#include"dominios.h"
#include<sqlite3.h>

using namespace std;

class ErroPersistencia{
	private:
		string mensagem;
	public:
		ErroPersistencia(string);
		string what();
};


class ElementoResultado{
	private:
		string nomeColuna;
		string valorColuna;
	public:
		void set_nome_coluna(const string&);
		string get_nome_coluna() const;
		void set_valor_coluna(const string&);
		string get_valor_coluna() const;
};
inline string ElementoResultado::get_nome_coluna()const{
	return nomeColuna;
}
inline string ElementoResultado::get_valor_coluna()const{
	return valorColuna;
}

class ComandoSQL{
	private:
		const char *nomeBancoDados;
		sqlite3 *bd;
		char *mensagem;
		int rc;
		void conectar();
		void desconectar();
		static int callback(void *, int, char **, char **);
	protected:
		static list<ElementoResultado> listaResultado;
		string comandoSQL;
	public:
		ComandoSQL(){
			nomeBancoDados="SistemaDeInvestimentos.db";
		}
		void executar();
};

class ComandoLerSenha:public ComandoSQL{
	public:
		ComandoLerSenha(CPF);
		string get_resultado();
};
class ComandoPesquisarUsuario:public ComandoSQL{
	public:
		ComandoPesquisarUsuario(CPF);
		Usuario get_resultado();

};
class ComandoCadastrarUsuario:public ComandoSQL{
	public:
		ComandoCadastrarUsuario(Usuario);
};

class ComandoCadastraConta:public ComandoSQL{
	public:
		ComandoCadastraConta(Conta);
};

#endif