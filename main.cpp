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


}
