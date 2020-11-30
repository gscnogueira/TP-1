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
		throw ErroPersistencia(comandoSQL);
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

ComandoPesquisarUsuario::ComandoPesquisarUsuario(CPF cpf){
	comandoSQL = "SELECT * FROM usuarios WHERE cpf = \"";
	comandoSQL+=cpf.get_cpf();
	comandoSQL+="\"";
}

Usuario ComandoPesquisarUsuario::get_resultado(){
	ElementoResultado resultado;
	Usuario usuario;
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	Nome nome;
	nome.set_nome(resultado.get_valor_coluna());
	usuario.set_nome(nome);
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	Endereco endereco;
	endereco.set_endereco(resultado.get_valor_coluna());
	usuario.set_endereco(endereco);
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	CEP cep;
	cep.set_valor(stoi(resultado.get_valor_coluna()));
	usuario.set_cep(cep);
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	CPF cpf;
	cpf.set_cpf(resultado.get_valor_coluna());
	usuario.set_cpf(cpf);
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	Senha senha;
	senha.set_senha(resultado.get_valor_coluna());
	usuario.set_senha(senha);

	return usuario;
}

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario){
	comandoSQL= "INSERT INTO usuarios VALUES (";
	comandoSQL+="'"+usuario.get_nome().get_nome()+"', ";
	comandoSQL+="'"+usuario.get_endereco().get_endereco()+"', ";
	comandoSQL+="'"+to_string(usuario.get_cep().get_valor() )+"', ";
	comandoSQL+="'"+usuario.get_cpf().get_cpf()+"', ";
	comandoSQL+="'"+usuario.get_senha().get_senha()+"')";
}

ComandoCadastraConta::ComandoCadastraConta(Conta conta){
	comandoSQL="INSERT INTO conta VALUES (";
	comandoSQL+="'"+conta.get_banco().get_codigo()+"', ";
	comandoSQL+="'"+conta.get_agencia().get_codigo()+"', ";
	comandoSQL+="'"+conta.get_numero().get_numero()+"')";
}

