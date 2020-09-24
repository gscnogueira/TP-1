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
        ///- Cria objeto e armazena a valor informado caso o mesmo seja **válido**.
        ///- Lança exceção caso o valor informado seja **inválido**.
        ///
        ///@param valor : Valor de CEP a ser armazenado no objeto criado. Caso esse parâmetro seja omitido, o valor **1000000** é armazenado no objeto.
        ///@throw invalid_argument

        CEP(int valor=1000000);
        /// @return Valor de CEP armazenado na instância da classe.
        int get_valor() const;

        /// - Armazena valor informado caso o mesmo seja **válido**.
        ///
        /// - Lança exceção caso o valor informado seja **inválido**.
        /// @param valor : Valor de CEP a ser armazenado.
        /// @throw invalid_argument
        void set_valor(int valor);

};

inline int CEP::get_valor() const{return valor;};



//----------------------------------------------------------
//------------------------CLASSE----------------------------
//----------------------------------------------------------

/// \brief Padrão para representação de classe.

/// ### Requezitos de formatação
/// Cada instância da classe Classe possui um atributo `nome`. Este atributo **deve** ser exatamente igual a uma das seguintes cadeias de caracteres:
/// - "CDB";
/// - "LC";
/// - "LCA";
/// - "LCI";
/// - "LF";
class Classe{
    private:
        static const set<string> CLASSES_VALIDAS;
        string nome;
        void validar(string nome);
    public:
        ///- Cria objeto e armazena a cadeia de caracteres informada,caso a mesmo seja **válida**, no atributo `nome`.
        ///- Lança exceção caso a cadeia de caracteres informada seja **inválida**.
        ///
        ///@param nome : Cadeia de caracteres correspondente ao nome a ser armazenado no objeto. Caso esse parâmetro seja omitido, a cadeia de caracteres **"CDB"** é armazenada no objeto.
        /// @throw invalid_argument
        Classe(string nome = "CDB");
        ///@return Valor do atributo `nome`.
        string get_classe() const;
        /// - Armazena cadeia de caracteres informada,caso o mesmo seja **válida**, no atributo nome.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param valor : Cadeia de caracteres a ser armazena no atributo `nome`.
        /// @throw invalid_argument

        void set_classe(string nome);
};

inline string Classe::get_classe() const{return nome;};
#endif
