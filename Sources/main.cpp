#include <bits/stdc++.h>
#include "../Headers/dominios.h"
#include "../Headers/testes.h"
 
using namespace std;

int main(){

    TUCEP teste;

    switch(teste.run()){
        case TUCEP::SUCESSO: cout<< "SUCESSO"<<endl;
                             break;
        case TUCEP::FALHA: cout<< "FALHA"<<endl;
                             break;

    }
}
