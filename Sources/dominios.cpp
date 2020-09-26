#include "../Headers/dominios.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str){

    vector<string> palavras;
    std::size_t current, previous =0;
    current=str.find(" ");
    while(current != string::npos){
        palavras.push_back(str.substr(previous,current-previous));
        previous=current+1;
        current=str.find_first_of(" ",previous);
    }
    palavras.push_back(str.substr(previous,current-previous));
    return palavras;
}
//----------------------------------------------------------
//-------------------------CEP------------------------------
//----------------------------------------------------------
const vector<pair<int,int>> CEP::REGIOES  = {
            make_pair(1000000,5999999),
            make_pair(8000000,8499999),
            make_pair(20000000,26600999),
            make_pair(70000000,70999999),
            make_pair(40000000,41999999),
            make_pair(60000000,60999999)};

void CEP::validar(int valor){
    bool valido=false;
    for(pair<int,int> e: REGIOES)
        if(valor>=e.first and valor<=e.second){
            valido=true;
            break;
        }
    if(!valido)
        throw invalid_argument("CEP::validar");
}
CEP::CEP(int valor){
    validar(valor); 
    this->valor=valor;
}

void CEP::set_valor(int valor){
    validar(valor);
    this->valor=valor;
}
//----------------------------------------------------------
//------------------------CLASSE----------------------------
//----------------------------------------------------------
const set<string> Classe::CLASSES_VALIDAS ={"CDB","LCA","LCI","LF","LC"};

void Classe::validar(string nome){
    if(!CLASSES_VALIDAS.count(nome))
        throw invalid_argument("Classe::validar");
}
Classe::Classe(string nome){
    validar(nome);
    this->nome=nome;
}
void Classe::set_classe(string nome){
    validar(nome);
    this->nome=nome;
}
//----------------------------------------------------------
//-------------------CÓDIGO-DE-AGÊNCIA----------------------
//----------------------------------------------------------
const string CodigoDeAgencia::EXCESSAO = "0000";

void CodigoDeAgencia::validar(string codigo){
    if(codigo.length()!=TAMANHO)
        throw invalid_argument("CodigoDeAgencia::validar");
    if(codigo==EXCESSAO)
        throw invalid_argument("CodigoDeAgencia::validar");
    for(char e: codigo)
        if(!isdigit(e))
            throw invalid_argument("CodigoDeAgencia::validar");
}
CodigoDeAgencia::CodigoDeAgencia(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
void CodigoDeAgencia::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-APLICAÇÃO---------------------
//----------------------------------------------------------

const string CodigoDeAplicacao::EXCESSAO = "00000";

void CodigoDeAplicacao::validar(string codigo){
    if(codigo.length()!=TAMANHO)
        throw invalid_argument("CodigoDeAplicacao::validar");
    if(codigo==EXCESSAO)
        throw invalid_argument("CodigoDeAplicacao::validar");
    for(char e: codigo)
        if(!isdigit(e))
            throw invalid_argument("CodigoDeAplicacao::validar");
}
CodigoDeAplicacao::CodigoDeAplicacao(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
void CodigoDeAplicacao::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
//----------------------------------------------------------
//------------------CÓDIGO-DE-BANCO-------------------------
//----------------------------------------------------------

const set<string> CodigoDeBanco::BANCOS={"341","001","237","104","033"};

void CodigoDeBanco::validar(string codigo){
    if(!BANCOS.count(codigo))
        throw invalid_argument("CodigoDeBanco::validar");
}

CodigoDeBanco::CodigoDeBanco(string codigo){
    validar(codigo);
    this->codigo=codigo;

}
void CodigoDeBanco::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}
//----------------------------------------------------------
//-------------------CÓDIGO-DE-PRODUTO----------------------
//----------------------------------------------------------

const string CodigoDeProduto::EXCESSAO="000";

void CodigoDeProduto::validar(string codigo){
    if(codigo.length()!=TAMANHO)
        throw invalid_argument("CodigoDeProduto::validar");
    if(codigo==EXCESSAO)
        throw invalid_argument("CodigoDeProduto::validar");
    for(char e:codigo)
        if(!isdigit(e))
            throw invalid_argument("CodigoDeProduto::validar");
}

CodigoDeProduto::CodigoDeProduto(string codigo){
    validar(codigo);
    this->codigo=codigo;
}

void CodigoDeProduto::set_codigo(string codigo){
    validar(codigo);
    this->codigo=codigo;
}

//----------------------------------------------------------
//------------------------CPF-------------------------------
//----------------------------------------------------------

void CPF::validar(string cpf){
    if(cpf.length()!=TAMANHO)
        throw invalid_argument("CPF::validar");

    if(!regex_match(cpf,regex("[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}")))
        throw invalid_argument("CPF::validar");

    vector<int> cpf_numeros, v1, v2;
    bool flag=false;


    for(char e:cpf){
        if(isdigit(e)){
            cpf_numeros.push_back(e -'0');
        }
    }
    for(int i =1; i<(int)cpf_numeros.size();i++){
        if(cpf_numeros[i]!=cpf_numeros[i-1])
        {
            flag=true;
        }
    }
    if(!flag)
        throw invalid_argument("CPF::validar");

    for(int i=0, j= 10;j>1;i++,j--){
        v1.push_back(cpf_numeros[i]*j);
    }
    int d1=accumulate(v1.begin(),v1.end(),0)*10;
    d1 %=11;
    if(d1!=cpf_numeros[9])
        throw invalid_argument("CPF::validar");


    for(int i=0, j= 11;j>1;i++,j--){
        v2.push_back(cpf_numeros[i]*j);
    }
    int d2=accumulate(v2.begin(),v2.end(),0)*10;
    d2 %=11;
    if(d2!=cpf_numeros[10])
        throw invalid_argument("CPF::validar");
}
void CPF::set_cpf(string cpf){
    validar(cpf);
    this->cpf=cpf;
}
//----------------------------------------------------------
//------------------------DATA------------------------------
//----------------------------------------------------------

void Data::validar(string data){

    set<int> trinta {4,6,9,11};
    set<int> trinta_e_um {1,3,5,7,8,10,12};

    if(data.length()!=TAMANHO)
        throw invalid_argument("data::validar");
        
    if(!regex_match(data,regex("[0-9]{2}\\/[0-9]{2}\\/[0-9]{4}")))
        throw invalid_argument("data::validar");

    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6));

    if(mes>12 or mes<1)
        throw invalid_argument("data::validar");
    if(ano>2099 or ano<2020)
        throw invalid_argument("data::validar");

    if(trinta.count(mes))
        if(dia>30 or dia<1)
            throw invalid_argument("data::validar");
    
    if(trinta_e_um.count(mes))
        if(dia>31 or dia<1)
            throw invalid_argument("data::validar");
    if(mes==2){
        if(!ano%4)
            if(dia>29 or dia<1)
                throw invalid_argument("data::validar");
        if(ano%4)
            if(dia>28 or dia<1)
                throw invalid_argument("data::validar");
            
    }

}
Data::Data(){

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d/%m/%Y",timeinfo);
    string aux(buffer);
    try{
        validar(aux);
        data=aux;
    }
    catch(invalid_argument &e){
        data="01/01/2020";
    }
}

Data::Data(string data){
    validar(data);
    this->data=data;
}

void Data::set_data(string data){
    validar(data);
    this->data=data;
}
//----------------------------------------------------------
//------------------------EMISSOR---------------------------
//----------------------------------------------------------
const set<char> Emissor::VALIDOS={' ','.','-'};

void Emissor::validar(string emissor){

    vector<string> palavras=split(emissor);

    if(emissor.length()>TAMANHO_MAX or emissor.length()<TAMANHO_MIN)
        throw invalid_argument("Emissor::validar -> Tamanho inválido");

    for(int i=0;i<(int)emissor.length();i++)
        if((!isalnum(emissor[i]))and(!VALIDOS.count(emissor[i])))
            throw invalid_argument("Emissor::validar -> Caractere inválido");

    for(string e : palavras){
        if(isalpha(e[0])){
            if(islower(e[0]))
                throw invalid_argument("Emissor::validar -> Primeira letra da palavra não é minuscula");

            for(char c : e){
                if(!isalpha(c))
                    throw invalid_argument("Emissor::validar-> Apenas dígitos e números podem estar em sequência");
            }
         }           

        if(isdigit(e[0]))
            for(char c : e){
                if(!isdigit(c))
                    throw invalid_argument("Emissor::validar -> Apenas dígitos e números podem estar em sequência");
            }
    }
}

void Emissor::set_emissor(string emissor){
    validar(emissor);
    this->emissor=emissor;
}
//----------------------------------------------------------
//------------------------ENDEREÇO--------------------------
//----------------------------------------------------------

const set<char> Endereco::VALIDOS={' ','.'};

void Endereco::validar(string endereco){
    vector<string> palavras =split(endereco);

    if(endereco.length()>TAMANHO_MAX or endereco.length()<TAMANHO_MIN)
        throw invalid_argument("Endereco::validar -> Tamanho inválido");

    for(int i=0;i<(int)endereco.length();i++)
        if((!isalnum(endereco[i]))and(!VALIDOS.count(endereco[i])))
            throw invalid_argument("Endereco::validar -> Caractere inválido");
    for(string e : palavras){

        if(isalpha(e[0])){
            if(islower(e[0]))
                throw invalid_argument("Endereco::validar -> Primeira letra da palavra não é minuscula");

            for(char c : e){
                if(!isalpha(c))
                    throw invalid_argument("Endereco::validar-> Apenas dígitos e números podem estar em sequência");
            }
         }           

        if(isdigit(e[0]))
            for(char c : e){
                if(!isdigit(c))
                    throw invalid_argument("Endereco::validar -> Apenas dígitos e números podem estar em sequência");
            }
    }
}

void Endereco::set_endereco(string endereco){
    validar(endereco);
    this->endereco=endereco;
}

//----------------------------------------------------------
//------------------------HORÁRIO---------------------------
//----------------------------------------------------------

void Horario::validar(string horario){
    
    if(horario.length()!=TAMANHO)
        throw invalid_argument("Horario::validar -> Tamanho inválido");
        
    if(!regex_match(horario,regex("[0-9]{2}\\:[0-9]{2}")))
        throw invalid_argument("Horario::validar -> Formato inválido");

    int horas   = stoi(horario.substr(0,2));
    int minutos = stoi(horario.substr(3));
    if(horas<13 or horas>17 )
        throw invalid_argument("Horario::validar -> Horário inválido");

    if(minutos<0 or minutos>59 )
        throw invalid_argument("Horario::validar -> Horário inválido");
    if(horas==17 and minutos!= 0)
        throw invalid_argument("Horario::validar -> Horário inválido");
}

Horario::Horario(){

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%H:%M",timeinfo);
    string aux(buffer);
    try{
        validar(aux);
        horario=aux;
    }
    catch(invalid_argument &e){
        horario="13:00";
    }
}

Horario::Horario(string horario){
    validar(horario);
    this->horario=horario;
}

void Horario::set_horario(string horario){
    validar(horario);
    this->horario=horario;
}


