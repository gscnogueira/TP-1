#include <bits/stdc++.h>
#include "dominios.h"
#include "testes_dominios.h"
 
using namespace std;

int main(){

    TUCEP t_cep;
    if(t_cep.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUClasse t_classe;
    if(t_classe.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUCodigoDeAgencia t_codigo_de_agencia;
    if(t_codigo_de_agencia.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUCodigoDeAplicacao t_codigo_de_aplicacao;
    if(t_codigo_de_aplicacao.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUCodigoDeBanco t_codigo_de_banco;
    if(t_codigo_de_banco.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUCodigoDeProduto t_codigo_de_produto;
    if(t_codigo_de_produto.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUCPF t_CPF;
    if(t_CPF.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUData t_data;
    if(t_data.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUEmissor t_emissor;
    if(t_emissor.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;


    TUEndereco t_endereco;
    if(t_endereco.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUHorario t_horario;
    if(t_horario.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUNome t_nome;
    if(t_nome.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUNumero t_numero;
    if(t_numero.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUPrazo t_prazo;
    if(t_prazo.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUSenha t_senha;
    if(t_senha.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUTaxa t_taxa;
    if(t_taxa.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUValorDeAplicacao t_valor;
    if(t_valor.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

    TUValorMinimo t_valor_min;
    if(t_valor_min.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;

}
