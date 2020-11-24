#include <string.h>
#include <stdexcept>
#include <iostream>

#include <ncurses.h>
/* #include "interfaces.h" */
#include "controladorasapresentacao.h"
/* #include "stubs.h" */

using namespace std;

int main()
{

    CntrApresentacaoControle *cntrApresentacaoControle= new CntrApresentacaoControle();
    initscr();                                                                      // Inicia curses.
    cntrApresentacaoControle->executar();                                           // Solicita serviço apresentacao.
    endwin();                                                                       // Finaliza curses.

    return 0;
}

