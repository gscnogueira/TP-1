#include "controladorasapresentacao.h"

int invoca_menu(vector<string>& choices){

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
			mvwprintw(menu_win,i+1,1,choices[i].c_str());
			wattroff(menu_win,A_REVERSE);

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
void CntrApresentacaoControle::executar(){
	vector<string> choices={"Acessar Produtos de Investimento","Autenticar Usuario", "Cadastrar Usuario",  "Sair"};
	int escolha=invoca_menu(choices);
	cout<<escolha<<endl;
}
