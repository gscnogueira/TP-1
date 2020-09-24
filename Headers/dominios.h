#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <bits/stdc++.h>

using namespace std;

//----------------------------------------------------------
//-------------------------CEP------------------------------
//----------------------------------------------------------

///
/// \brief Padrão para representação de CEP.
///

///  ### Requezitos de formatação
///
///  Para um valor ser armazenado em uma instância da classe CEP, é necessário que o mesmo esteja nas seguintes faixas (de acordo com a localidade):
///
/// - 1000000 a 5999999 (São Paulo);
/// - 8000000 a 8499999 (São Paulo);
/// - 20000000 a 26600999 (Rio de Janeiro);
/// - 70000000 a 70999999 (Brasília);
/// - 40000000 a 41999999 (Salvador);
/// - 60000000 a 60999999 (Fortaleza).
class CEP{
    private:
        int valor;
    static const vector<pair<int,int>> REGIOES;
        void validar(int valor);
    public:
        /// @return Valor de CEP armazenado na instância da classe.
        int get_valor();

        /// - Armazena valor informado caso o mesmo seja **válido**.
        ///
        /// - Lança exceção caso o valor informado seja **inválido**;
        /// @param valor : Valor de CEP a ser armazenado.
        /// @throw invalid_argument
        void set_valor(int valor);

};

inline int CEP::get_valor(){return valor;};


























#endif
