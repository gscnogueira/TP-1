#include "controladorasapresentacao.h"
#include <curses.h>

const string DESC="Preencha o campo abaixo:";
const char AVISO[200]="Dados invalidos foram fornecidos, gostaira de tentar novamanete? (y/n)";
char son(){
	char ans;
	while(true){
		ans=getch();
		if(ans=='y' or ans=='n')
			return ans;
	}
}
string invoca_texto(string descricao, string nome){

	clear();
	curs_set(1);
	echo();
	int linha, coluna;
	int linha_win, coluna_win;
	int linha_s, coluna_s;
	char dado[100];
    getmaxyx(stdscr,linha,coluna);
	WINDOW *text_win=newwin(linha/10,coluna*3/4,( linha/2 ),( coluna/8 ));
    getmaxyx(text_win,linha_win,coluna_win);
	getbegyx(text_win,linha_s,coluna_s);
	char titulo[]="SISTEMA DE INVESTIMENTOS";
	mvprintw(1,(coluna - strlen(titulo))/2,titulo);
	mvprintw(linha_s-1,coluna_s+1,descricao.c_str());
	refresh();
	box(text_win,0,0);
	attron(A_REVERSE);
	mvprintw(linha_s+1,coluna_s+1,nome.c_str());
	attroff(A_REVERSE);
	printw(" ");
	wrefresh(text_win);
	getstr(dado);
	return (string)dado;

}
int invoca_menu(vector<string>& choices){
	clear();
	int linha, coluna;
	int linha_win, coluna_win;
	curs_set(0);
    getmaxyx(stdscr,linha,coluna);
	WINDOW *menu_win= newwin(linha/2,coluna*3/4,( linha/4 ),( coluna/8 ));
    getmaxyx(menu_win,linha_win,coluna_win);
	keypad(menu_win,true);
	int highlight=0;
	int choice, size=(int)choices.size();
	char titulo[]="SISTEMA DE INVESTIMENTOS";
	mvprintw(1,(coluna - strlen(titulo))/2,titulo);
	refresh();
	box(menu_win,0,0);
	wrefresh(menu_win);
	noecho();
	while(1){
		for(int i=0;i<size ;i++){
			if(i==highlight)
				wattron(menu_win,A_REVERSE);
			mvwprintw(menu_win,i+2,2,choices[i].c_str());
			wattroff(menu_win,A_REVERSE);
			printw("\n");

		}
		choice=wgetch(menu_win);
		switch(choice){
			case KEY_UP:
				highlight--;
				if(highlight==-1)
					highlight=size-1;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight==size)
					highlight=0;
				break;
			default:
				break;
		}
		if(choice==10)
			break;
	}
	return highlight;
}
//----------------------------------------------------------
//-----------------Móulo-Apresentação-Controle--------------
//----------------------------------------------------------
void CntrApresentacaoControle::executar(){
	vector<string> choices={"Acessar Produtos de Investimento","Autenticar Usuario", "Cadastrar Usuario",  "Sair"};
	vector<string> choices_autenticado={"Acessar Produtos de Investimento","Consultar Dados Pessoais", "Consultar Conta Corrente", "Cadastrar Produto de Investimento","Descadastrar Produto de Investimento","Listar Aplicacoes em Produtos de Investimento", "Encerrar Secao"};
	bool autenticado;
	while(1){
		clear();
		int escolha=invoca_menu(choices);
		if(escolha==3)
			break;
		if(escolha==0)
			cntrApresentacaoProdutosFinanceiros->executar();
		if(escolha==1){
			if(cntrApresentacaoAutenticacao->autenticar(&cpf)){
				autenticado=true;

				while(autenticado){
					int escolha_usuario=invoca_menu(choices_autenticado);
					if(escolha_usuario==0){
						cntrApresentacaoProdutosFinanceiros->executar();
					}
					if(escolha_usuario==1){
						clear();
						printw("Mostra Dados Pessoais");
						getch();
						clear();
							
					}
					if(escolha_usuario==2){
						clear();
						printw("Mostra Conta Corrente");
						getch();
						clear();
						
					}
					if(escolha_usuario==3){

					}
					if(escolha_usuario==4){
						clear();
						printw("Descadastra Produto");
						getch();
						clear();
					}
					if(escolha_usuario==5){
						cntrApresentacaoProdutosFinanceiros->executar(cpf);
					}
					if(escolha_usuario==6)
						autenticado=false;
				}

			}
		}
		if(escolha==2)
			cntrApresentacaoPessoal->cadastrar();

	}
}
//----------------------------------------------------------
//-----------------Móulo-Apresentação-Autenticação---------
//----------------------------------------------------------
bool CntrApresentacaoAutenticacao::autenticar(CPF* cpf){
	Senha senha;
	char ans;
	bool autenticar=true;
	int linha, coluna;
    getmaxyx(stdscr,linha,coluna);
	while(autenticar){
		try{
			cpf->set_cpf(invoca_texto(DESC,"CPF:"));
			senha.set_senha(invoca_texto(DESC,"Senha:"));

		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='y')
				continue;
			else
				return false;
		}
		autenticar=false;
	}
	if( cntr->autenticar(*cpf,senha) ){
		return true;;
	}

	return false;

}
//----------------------------------------------------------
//-----------------Móulo-Apresentação-Pessoal---------------
//----------------------------------------------------------
void CntrApresentacaoPessoal::cadastrar(){
	clear();
	Nome nome;
	Endereco endereco;
	CEP cep;
	CPF cpf;
	Senha senha;
	CodigoDeBanco codigoDeBanco;
	CodigoDeAgencia codigoDeAgencia;
	Numero numero;
	bool cadastrar=true;
	char ans;
	int linha,coluna;
    getmaxyx(stdscr,linha,coluna);
	while(cadastrar){
		try{
			nome.set_nome(invoca_texto(DESC,"Nome:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	cadastrar=true;
	while(cadastrar){
		try{
			endereco.set_endereco(invoca_texto(DESC,"Endereco:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	cadastrar=true;
	while(cadastrar){
		try{
			cep.set_valor(stoi(invoca_texto(DESC,"CEP:")));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	cadastrar=true;
	while(cadastrar){
		try{
			cpf.set_cpf(invoca_texto(DESC,"CPF:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	cadastrar=true;
	while(cadastrar){
		try{
			senha.set_senha(invoca_texto(DESC,"Senha:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	cadastrar=true;
	while(cadastrar){
		try{
			codigoDeBanco.set_codigo(invoca_texto(DESC,"Codigo de Banco:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	cadastrar=true;
	while(cadastrar){
		try{
			codigoDeAgencia.set_codigo(invoca_texto(DESC,"Codigo de Agencia:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}

	cadastrar=true;
	while(cadastrar){
		try{
			numero.set_numero(invoca_texto(DESC,"Numero da Conta:"));
		}
		catch(invalid_argument &exp){
			mvprintw(linha-2,0,AVISO);
			refresh();
			ans=son();
			if(ans=='n')
				return;
			else 
				continue;
		}
		cadastrar=false;
	}
	attron(A_REVERSE);
	mvprintw(linha-2,0,"Cadastro realizado com sucesso.");
	attroff(A_REVERSE);
	mvprintw(linha-1,0,"Pressione qualquer tecla para continuar.");
	getch();

}
void CntrApresentacaoPessoal::executar(CPF){
	clear();
	printw("vou te executar");
	getch();
}
//----------------------------------------------------------
//----------Móulo-Apresentação-Produtos-Financeiros---------
//----------------------------------------------------------
void CntrApresentacaoProdutosFinanceiros::executar(){
	bool consulta=true;
	vector<string> choices={"CDB","LCA","LCI","LF","LC","Retornar"};
	while(consulta){
		int choice=invoca_menu(choices);
		switch (choice) {
			case 5:
				consulta=false;
					break;
			default:
				clear();
				printw("Mostra lista");
				getch();
		}
	}
}
void CntrApresentacaoProdutosFinanceiros::executar(CPF cpf){
	clear();
	printw("vou executar os SEUS produtos");
	getch();
}

