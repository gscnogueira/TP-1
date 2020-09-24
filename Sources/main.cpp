#include <bits/stdc++.h>
#include "../Headers/dominios.h"
#include "../Headers/testes.h"
 
using namespace std;

int main(){

    TUCEP t_cep;

    switch(t_cep.run()){
        case TUCEP::SUCESSO: cout<< "SUCESSO"<<endl;
                             break;
        case TUCEP::FALHA: cout<< "FALHA"<<endl;
                             break;
    }
    
    TUClasse t_classe;
    if(t_classe.run()) cout<<"SUCESSO"<<endl;
    else cout<<"FALHA"<<endl;
}
