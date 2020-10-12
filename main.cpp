#include <bits/stdc++.h>
#include "dominios.h"
#include "entidades.h"
#include "testes_dominios.h"
#include "testes_entidades.h"
 
using namespace std;

int main(){

    TUAplicacao t_aplicacao;
    if(t_aplicacao.run()) cout<<"SUCESSO - APLICAÇÃO"<<endl;
    else cout<<"FALHA - APLICAÇÃO"<<endl;

    TUConta t_conta;
    if(t_conta.run())cout<<"SUCESSO - CONTA"<<endl;
    else cout<<"FALHA - CONTA"<<endl;

    TUProduto t_produto;
    if(t_produto.run())cout<<"SUCESSO - PRODUTO"<<endl;
    else cout<<"FALHA - CONTA"<<endl;

    TUUsuario t_usuario;
    if(t_usuario.run())cout<<"SUCESSO - USUÁRIO"<<endl;
    else cout<<"FALHA - USUÁRIO"<<endl;

}
