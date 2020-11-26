#include "stubs.h"

const string StubServicoAutenticacao::INVALIDO = "200.094.918-56";

bool StubServicoAutenticacao::autenticar(CPF cpf, Senha senha){
	if(cpf.get_cpf().compare(INVALIDO)==0){
		return false;
	}
	return true;
}
bool StubServicoPessoal::cadastrar_usuario(Usuario usuario){
	return(usuario.get_nome().get_nome().compare("Ciro Peres Araujo"));
}
bool StubServicoProdutosFinanceiros::cadastrar_conta(Conta conta){
	return(conta.get_agencia().get_codigo().compare("6666"));
}
bool StubServicoProdutosFinanceiros::consultar_conta(Conta* conta){
	return true;
}
bool StubServicoProdutosFinanceiros::cadastrar_produto(Produto produto){
	return (produto.get_classe().get_classe()!="LCI");
}
bool StubServicoProdutosFinanceiros::descadastrar_produto(CodigoDeProduto codigo){
	return (codigo.get_codigo()!="123");
}
bool StubServicoProdutosFinanceiros::realizar_aplicacao(Aplicacao aplicacao){
	return (aplicacao.get_codigo().get_codigo()=="99999");
}
bool StubServicoProdutosFinanceiros::recuperar_aplicacao(Aplicacao* aplicacao){
	return true;
}



