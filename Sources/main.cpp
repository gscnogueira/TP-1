#include <bits/stdc++.h>
#include "../Headers/dominios.h"
#include "../Headers/testes.h"
 
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
}
