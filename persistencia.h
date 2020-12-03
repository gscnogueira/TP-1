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
		ComandoCadastrarUsuario(Usuario, Numero);
};

class ComandoDescadastraUsuario:public ComandoSQL{
	public:
		ComandoDescadastraUsuario(CPF);
};

class ComandoCadastraConta:public ComandoSQL{
	public:
		ComandoCadastraConta(Conta);
};
class ComandoDescadastraConta:public ComandoSQL{
	public:
		ComandoDescadastraConta(Numero);
};
class ComandoAcessaNumeroConta:public ComandoSQL{
	public:
		ComandoAcessaNumeroConta(CPF);
		Numero get_resultado();
};
class ComandoPesquisarConta:public ComandoSQL{
	public:
		ComandoPesquisarConta(Numero);
		Conta get_resultado();

};
class ComandoCadastraProduto:public ComandoSQL{
	public:
		ComandoCadastraProduto(Produto, CPF);
};

class ComandoAplicacao:public ComandoSQL{
	public:
		ComandoAplicacao(Aplicacao,CPF,CodigoDeProduto);
};

class ComandoPesquisaProduto:public ComandoSQL{
	public:
		ComandoPesquisaProduto(CodigoDeProduto);
		Produto get_resultado();
};
class ComandoNumeroContaProduto: public ComandoSQL{
	public:
		ComandoNumeroContaProduto(CodigoDeProduto);
		Numero get_resultado();
};
class ComandoDescadastrarProduto:public ComandoSQL{
	public:
		ComandoDescadastrarProduto(CodigoDeProduto);
		ComandoDescadastrarProduto(Numero);
};
class ComandoAcessaProdutos:public ComandoSQL{
	public:
		ComandoAcessaProdutos(string);
		vector<Produto> get_resultado();
};
class ComandoDescadastraAplicacao:public ComandoSQL{
	public:
		ComandoDescadastraAplicacao(CodigoDeProduto);
		ComandoDescadastraAplicacao(Numero);
};

class ComandoContaAplicacoes:public ComandoSQL{
	public:
		ComandoContaAplicacoes(CPF);
		int get_resultado();
};

class ComandoAcessaAplicacoes:public ComandoSQL{
	public:
		ComandoAcessaAplicacoes(Numero);
		vector<Aplicacao> get_resultado(vector<CodigoDeProduto>&);
};

#endif
