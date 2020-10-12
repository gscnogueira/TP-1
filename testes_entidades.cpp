#include <bits/stdc++.h>
#include "dominios.h"
#include "entidades.h"
#include "testes_entidades.h"


using namespace std;

//----------------------------------------------------------
//----------------------APLICAÇÃO---------------------------
//----------------------------------------------------------
const string TUAplicacao::CODIGO_VALIDO = "25483";
const string TUAplicacao::VALOR_VALIDO = "2400,86";
const string TUAplicacao::DATA_VALIDA = "16/09/2047";

void TUAplicacao::set_up(){
    aplicacao= new Aplicacao();
    estado = true;
}
void TUAplicacao::tear_down(){
    delete aplicacao;
}
void TUAplicacao::testa_codigo(){
    CodigoDeAplicacao codigo;
    codigo.set_codigo(CODIGO_VALIDO);
    aplicacao->set_codigo(codigo);
    if(aplicacao->get_codigo().get_codigo()!=CODIGO_VALIDO)
        estado=false;
}

void TUAplicacao::testa_valor(){
    ValorDeAplicacao valor;
    valor.set_valor(VALOR_VALIDO);
    aplicacao->set_valor(valor);
    if(aplicacao->get_valor().get_valor()!=VALOR_VALIDO)
        estado=false;
}

void TUAplicacao::testa_data(){
    Data data;
    data.set_data(DATA_VALIDA);
    aplicacao->set_data(data);
    if(aplicacao->get_data().get_data()!=DATA_VALIDA)
        estado=false;
}


bool TUAplicacao::run(){
    set_up();
    testa_codigo();
    testa_valor();
    testa_data();
    tear_down();
    return estado;
}
//----------------------------------------------------------
//--------------------------CONTA---------------------------
//----------------------------------------------------------
const string TUConta::BANCO_VALIDO="237";
const string TUConta::AGENCIA_VALIDA="4563";
const string TUConta::NUMERO_VALIDO="261533-4";

void TUConta::set_up(){
    conta = new Conta();
    estado=true;
}

void TUConta::tear_down(){
    delete conta;
}

void TUConta::testa_banco(){
    CodigoDeBanco banco;
    banco.set_codigo(BANCO_VALIDO);
    conta->set_banco(banco);
    if(conta->get_banco().get_codigo()!=BANCO_VALIDO)
        estado=false;
}

void TUConta::testa_agencia(){
    CodigoDeAgencia agencia;
    agencia.set_codigo(AGENCIA_VALIDA);
    conta->set_agencia(agencia);
    if(conta->get_agencia().get_codigo()!=AGENCIA_VALIDA)
        estado=false;
}

void TUConta::testa_numero(){
    Numero numero;
    numero.set_numero(NUMERO_VALIDO);
    conta->set_numero(numero);
    if(conta->get_numero().get_numero()!= NUMERO_VALIDO)
        estado=false;

}

bool TUConta::run(){
    set_up();
    testa_banco();
    testa_agencia();
    testa_numero();
    tear_down();
    return estado;
}
//----------------------------------------------------------
//-----------------------PRODUTO----------------------------
//----------------------------------------------------------

const string TUProduto::CODIGO_VALIDO="549";
const string TUProduto::CLASSE_VALIDO="LCI";
const string TUProduto::EMISSOR_VALIDO="Emissor Exemplo-453";
const string TUProduto::VENCIMENTO_VALIDO="13/07/2049";
const string TUProduto::HORARIO_VALIDO="16:20";

void TUProduto::set_up(){
    produto=new Produto();
    estado=true;
}
void TUProduto::tear_down(){
    delete produto;
}
void TUProduto::testa_codigo(){
    CodigoDeProduto codigo;
    codigo.set_codigo(CODIGO_VALIDO);
    produto->set_codigo(codigo);
    if(produto->get_codigo().get_codigo()!=CODIGO_VALIDO)
        estado=false;
}
void TUProduto::testa_classe(){
    Classe classe;
    classe.set_classe(CLASSE_VALIDO);
    produto->set_classe(classe);
    if(produto->get_classe().get_classe()!=CLASSE_VALIDO)
        estado=false;
}
void TUProduto::testa_emissor(){
    Emissor emissor;
    emissor.set_emissor(EMISSOR_VALIDO);
    produto->set_emissor(emissor);
    if(produto->get_emissor().get_emissor()!=EMISSOR_VALIDO)
        estado=false;
}
void TUProduto::testa_prazo(){
    Prazo prazo;
    prazo.set_prazo(PRAZO_VALIDO);
    produto->set_prazo(prazo);
    if(produto->get_prazo().get_prazo()!=PRAZO_VALIDO)
        estado=false;
}
void TUProduto::testa_vencimento(){
    Data vencimento;
    vencimento.set_data(VENCIMENTO_VALIDO);
    produto->set_vencimento(vencimento);
    if(produto->get_vencimento().get_data()!=VENCIMENTO_VALIDO)
        estado=false;
}
void TUProduto::testa_taxa(){
    Taxa taxa;
    taxa.set_taxa(TAXA_VALIDO);
    produto->set_taxa(taxa);
    if(produto->get_taxa().get_taxa()!=TAXA_VALIDO)
        estado=false;
}
void TUProduto::testa_horario(){
    Horario horario;
    horario.set_horario(HORARIO_VALIDO);
    produto->set_horario(horario);
    if(produto->get_horario().get_horario()!=HORARIO_VALIDO)
        estado=false;
}
void TUProduto::testa_valor(){
    ValorMinimo valor;
    valor.set_valor(VALOR_VALIDO);
    produto->set_valor(valor);
    if(produto->get_valor().get_valor()!=VALOR_VALIDO)
        estado=false;

}
bool TUProduto::run(){
    set_up();
    testa_codigo();
    testa_classe();
    testa_emissor();
    testa_prazo();
    testa_vencimento();
    testa_horario();
    testa_valor();
    tear_down();
    return estado;
}
//----------------------------------------------------------
//----------------------USUÁRIO-----------------------------
//----------------------------------------------------------

const string TUUsuario::NOME_VALIDO="Carlos Eduardo Peres";
const string TUUsuario::ENDERECO_VALIDO="SQN 311 BLOCO B";
const string TUUsuario::CPF_VALIDO="200.094.918-56";
const string TUUsuario::SENHA_VALIDO="123456";

void TUUsuario::set_up(){
    usuario=new Usuario();
    estado=true;
}
void TUUsuario::tear_down(){
    delete usuario;
}
void TUUsuario::testa_nome(){
    Nome nome;
    nome.set_nome(NOME_VALIDO);
    usuario->set_nome(nome);
    if(usuario->get_nome().get_nome()!=NOME_VALIDO)
        estado=false;
}
void TUUsuario::testa_endereco(){
    Endereco endereco;
    endereco.set_endereco(ENDERECO_VALIDO);
    usuario->set_endereco(endereco);
    if(usuario->get_endereco().get_endereco()!=ENDERECO_VALIDO)
        estado=false;
}
void TUUsuario::testa_cep(){
    CEP cep;
    cep.set_valor(CEP_VALIDO);
    usuario->set_cep(cep);
    if(usuario->get_cep().get_valor()!=CEP_VALIDO)
        estado=false;
}
void TUUsuario::testa_cpf(){
    CPF cpf;
    cpf.set_cpf(CPF_VALIDO);
    usuario->set_cpf(cpf);
    if(usuario->get_cpf().get_cpf()!=CPF_VALIDO)
        estado=false;
}
void TUUsuario::testa_senha(){
    Senha senha;
    senha.set_senha(SENHA_VALIDO);
    usuario->set_senha(senha);
    if(usuario->get_senha().get_senha()!=SENHA_VALIDO)
        estado=false;
}
bool TUUsuario::run(){
    set_up();
    testa_nome();
    testa_endereco();
    testa_cep();
    testa_cpf();
    testa_senha();
    tear_down();
    return estado;
}






