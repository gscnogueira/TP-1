#include"persistencia.h"

list<ElementoResultado> ComandoSQL::listaResultado;

ErroPersistencia::ErroPersistencia(string mensagem){
	this->mensagem=mensagem;
}

string ErroPersistencia::what(){
	return mensagem;
}

void ElementoResultado::set_nome_coluna(const string & nomeColuna){
	this->nomeColuna=nomeColuna;
}

void ElementoResultado::set_valor_coluna(const string & valorColuna){
	this->valorColuna=valorColuna;
}

void ComandoSQL::conectar(){
	rc=sqlite3_open(nomeBancoDados, &bd);
	if(rc!=SQLITE_OK)
		throw ErroPersistencia("Erro na conexao ao banco de dados.");
}

void ComandoSQL::desconectar(){
	rc=sqlite3_close(bd);
	if(rc!=SQLITE_OK)
		throw ErroPersistencia("Erro na desconexao ao banco de dados.");
}

void ComandoSQL::executar(){
	conectar();
	rc=sqlite3_exec(bd, comandoSQL.c_str(), callback, 0,&mensagem);
	if(rc!= SQLITE_OK){
		sqlite3_free(mensagem);
		desconectar();
		throw ErroPersistencia("Erro na execucao do comando SQL.");
	}
	desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char ** valorColuna, char **nomeColuna){
	NotUsed=0;
	ElementoResultado elemento;
	int i;
	for(i=0;i<argc;i++){
		elemento.set_nome_coluna(nomeColuna[i]);
		elemento.set_valor_coluna(valorColuna[i]?valorColuna[i]: "NULL");
		listaResultado.push_front(elemento);
	}
	return 0;
}

ComandoLerSenha::ComandoLerSenha(CPF cpf){
	comandoSQL = "SELECT senha FROM usuarios WHERE cpf = \"";
	comandoSQL+=cpf.get_cpf();
	comandoSQL+="\"";
}

string ComandoLerSenha::get_resultado(){
	ElementoResultado resultado;
	string senha;

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado = listaResultado.back();
	listaResultado.pop_back();
	senha=resultado.get_valor_coluna();

	return senha;
}

