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
		throw ErroPersistencia("Erro na execucao do comando SQL");
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
	listaResultado.pop_back();

	return usuario;
}

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario,Numero numero){
	comandoSQL= "INSERT INTO usuarios VALUES (";
	comandoSQL+="'"+usuario.get_nome().get_nome()+"', ";
	comandoSQL+="'"+usuario.get_endereco().get_endereco()+"', ";
	comandoSQL+="'"+to_string(usuario.get_cep().get_valor() )+"', ";
	comandoSQL+="'"+usuario.get_cpf().get_cpf()+"', ";
	comandoSQL+="'"+usuario.get_senha().get_senha()+"', ";
	comandoSQL+="'"+numero.get_numero()+"') ";
}

ComandoDescadastraUsuario::ComandoDescadastraUsuario(CPF cpf){
	comandoSQL="DELETE FROM usuarios WHERE cpf = ";
	comandoSQL+="'"+cpf.get_cpf()+"'";
}

ComandoCadastraConta::ComandoCadastraConta(Conta conta){
	comandoSQL="INSERT INTO conta VALUES (";
	comandoSQL+="'"+conta.get_banco().get_codigo()+"', ";
	comandoSQL+="'"+conta.get_agencia().get_codigo()+"', ";
	comandoSQL+="'"+conta.get_numero().get_numero()+"')";
}

ComandoDescadastraConta::ComandoDescadastraConta(Numero numero){
	comandoSQL="DELETE FROM conta WHERE numero = ";
	comandoSQL+="'"+numero.get_numero()+"'";
}

ComandoAcessaNumeroConta::ComandoAcessaNumeroConta(CPF cpf){
	comandoSQL="SELECT conta FROM usuarios WHERE cpf = '";
	comandoSQL+=cpf.get_cpf()+"'";
}
Numero ComandoAcessaNumeroConta::get_resultado(){
	ElementoResultado resultado;
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	Numero numero;
	numero.set_numero(resultado.get_valor_coluna());
	return numero;
}

ComandoCadastraProduto::ComandoCadastraProduto(Produto produto,CPF cpf){
	ComandoAcessaNumeroConta cmdNumero(cpf);
	cmdNumero.executar();
	comandoSQL+="INSERT INTO produto VALUES(";
	comandoSQL+="'"+produto.get_codigo().get_codigo()+"', ";
	comandoSQL+="'"+produto.get_classe().get_classe()+"', ";
	comandoSQL+="'"+produto.get_emissor().get_emissor()+"', ";
	comandoSQL+="'"+to_string(produto.get_prazo().get_prazo())+"', ";
	comandoSQL+="'"+produto.get_vencimento().get_data()+"', ";
	comandoSQL+="'"+to_string( produto.get_taxa().get_taxa() )+"', ";
	comandoSQL+="'"+produto.get_horario().get_horario()+"', ";
	comandoSQL+="'"+to_string(produto.get_valor().get_valor())+"', ";
	comandoSQL+="'"+cmdNumero.get_resultado().get_numero()+"')";

}

ComandoPesquisarConta::ComandoPesquisarConta(Numero numero){
	comandoSQL+="SELECT * FROM conta WHERE numero = '";
	comandoSQL+=numero.get_numero()+="'";
}

Conta ComandoPesquisarConta::get_resultado(){
	ElementoResultado resultado;
	Conta conta;
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	CodigoDeBanco banco;
	banco.set_codigo(resultado.get_valor_coluna());
	conta.set_banco(banco);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	CodigoDeAgencia agencia;
	agencia.set_codigo(resultado.get_valor_coluna());
	conta.set_agencia(agencia);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vaziaa.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	Numero numero;
	numero.set_numero(resultado.get_valor_coluna());
	conta.set_numero(numero);
	return conta;
}

ComandoAplicacao::ComandoAplicacao(Aplicacao aplicacao,CPF cpf,CodigoDeProduto codigo){
	ComandoAcessaNumeroConta cmdConta(cpf);
	cmdConta.executar();
	Numero numero=cmdConta.get_resultado();
	comandoSQL="INSERT INTO aplicacao VALUES (";
	comandoSQL+="'"+aplicacao.get_codigo().get_codigo()+"', ";
	comandoSQL+="'"+aplicacao.get_valor().get_valor()+"', ";
	comandoSQL+="'"+aplicacao.get_data().get_data()+"', ";
	comandoSQL+="'"+numero.get_numero()+"', ";
	comandoSQL+="'"+codigo.get_codigo()+"')";
}

ComandoPesquisaProduto::ComandoPesquisaProduto(CodigoDeProduto codigo){
	comandoSQL="SELECT * FROM produto WHERE codigo = ";
	comandoSQL+="'"+codigo.get_codigo()+"'";
}

Produto ComandoPesquisaProduto::get_resultado(){
	ElementoResultado resultado;
	Produto produto;
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	CodigoDeProduto codigo(resultado.get_valor_coluna());
	produto.set_codigo(codigo);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	Classe classe(resultado.get_valor_coluna());
	produto.set_classe(classe);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	Emissor emissor;
	emissor.set_emissor(resultado.get_valor_coluna());
	produto.set_emissor(emissor);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	Prazo prazo(stoi(resultado.get_valor_coluna()));
	produto.set_prazo(prazo);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	Data vencimento(resultado.get_valor_coluna());
	produto.set_vencimento(vencimento);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	Taxa taxa(stoi(resultado.get_valor_coluna()));
	produto.set_taxa(taxa);

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	Horario horario(resultado.get_valor_coluna());
	produto.set_horario(horario);


	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");

	resultado=listaResultado.back();
	listaResultado.pop_back();
	ValorMinimo valorMinimo(stoi(resultado.get_valor_coluna()));
	produto.set_valor(valorMinimo);

	listaResultado.pop_back();
	return produto;
}

ComandoNumeroContaProduto::ComandoNumeroContaProduto(CodigoDeProduto codigo){
	comandoSQL="SELECT conta FROM produto WHERE codigo = ";
	comandoSQL+="'"+codigo.get_codigo()+"'";
}
Numero ComandoNumeroContaProduto::get_resultado(){
	ElementoResultado resultado;
	Numero numero;

	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vaiza.");
	resultado=listaResultado.back();
	listaResultado.pop_back();
	numero.set_numero(resultado.get_valor_coluna());
	return numero;
}

ComandoDescadastrarProduto::ComandoDescadastrarProduto(CodigoDeProduto codigo){
	comandoSQL="DELETE FROM produto WHERE codigo = ";
	comandoSQL+="'"+codigo.get_codigo()+"'";
}
ComandoDescadastrarProduto::ComandoDescadastrarProduto(Numero numero){
	comandoSQL="DELETE FROM produto WHERE conta = ";
	comandoSQL+="'"+numero.get_numero()+"'";
}

ComandoAcessaProdutos::ComandoAcessaProdutos(string classe){
	comandoSQL="SELECT * FROM produto WHERE classe = ";
	comandoSQL+="'"+classe+"'";
}
vector<Produto> ComandoAcessaProdutos::get_resultado(){
	ElementoResultado resultado;
	vector<Produto> produtos;
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	while(listaResultado.size()){
		Produto produto;
		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_codigo(CodigoDeProduto(resultado.get_valor_coluna()));
		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_classe(Classe(resultado.get_valor_coluna()));
		
		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		Emissor emissor;
		emissor.set_emissor(resultado.get_valor_coluna());
		produto.set_emissor(emissor);

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_prazo(Prazo(stoi(resultado.get_valor_coluna())));

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_vencimento(Data(resultado.get_valor_coluna()));

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_taxa(Taxa(stoi(resultado.get_valor_coluna())));

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_horario(Horario(resultado.get_valor_coluna()));

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		produto.set_valor(ValorMinimo(stoi(resultado.get_valor_coluna())));
		listaResultado.pop_back();
		produtos.push_back(produto);
	}
	return produtos;
}
ComandoDescadastraAplicacao::ComandoDescadastraAplicacao(CodigoDeProduto codigoDeProduto){
	comandoSQL="DELETE FROM aplicacao WHERE produto = ";
	comandoSQL+="'"+codigoDeProduto.get_codigo()+"'";
}

ComandoDescadastraAplicacao::ComandoDescadastraAplicacao(Numero numero){
	comandoSQL="DELETE FROM aplicacao WHERE conta = ";
	comandoSQL+="'"+numero.get_numero()+"'";
}
ComandoContaAplicacoes::ComandoContaAplicacoes(CPF cpf){
	ComandoAcessaNumeroConta cmdNumero(cpf);
	cmdNumero.executar();
	comandoSQL="SELECT COUNT(*) FROM aplicacao WHERE conta =";
	comandoSQL+="'"+cmdNumero.get_resultado().get_numero()+"'";
}

int ComandoContaAplicacoes::get_resultado(){
	ElementoResultado resultado=listaResultado.back();
	listaResultado.pop_back();
	return stoi(resultado.get_valor_coluna());
}

ComandoAcessaAplicacoes::ComandoAcessaAplicacoes(Numero numero){
	comandoSQL="SELECT * FROM aplicacao WHERE conta = ";
	comandoSQL+="'"+numero.get_numero()+"'";
}
vector<Aplicacao> ComandoAcessaAplicacoes::get_resultado(){
	vector<Aplicacao>aplicacoes;
	ElementoResultado resultado;
	if(listaResultado.empty())
		throw ErroPersistencia("Lista de resultados vazia.");
	while(listaResultado.size()){
		Aplicacao aplicacao;
		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		aplicacao.set_codigo(CodigoDeAplicacao(resultado.get_valor_coluna()));


		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		ValorDeAplicacao valor;
		valor.set_valor(resultado.get_valor_coluna());
		aplicacao.set_valor(valor);

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		resultado=listaResultado.back();
		listaResultado.pop_back();
		aplicacao.set_data(Data(resultado.get_valor_coluna()));
		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		listaResultado.pop_back();

		if(listaResultado.empty())
			throw ErroPersistencia("Lista de resultados vazia.");
		listaResultado.pop_back();
		aplicacoes.push_back(aplicacao);

	}
	return aplicacoes;
}


