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

/// ### Requezitos de Formato
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
        /// @return Número inteiro correspondente ao valor de CEP armazenado na instância da classe.
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
//
/// A classe Classe possui o intuito de criar objeto que armazena a classe de um produto de investimento.

/// ### Requezitos de Formato
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
        ///@param nome : Cadeia de caracteres correspondente ao nome a ser armazenado no objeto. Caso esse parâmetro seja omitido, a cadeia de caracteres `CDB` é armazenada no objeto.
        /// @throw invalid_argument
        Classe(string nome = "CDB");
        ///@return Cadeia de caracteres correspondente à classe do produto de investimento.
        string get_classe() const;
        /// - Armazena cadeia de caracteres informada,caso o mesmo seja **válida**, no atributo nome.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param valor : Cadeia de caracteres a ser armazena no atributo `nome`.
        /// @throw invalid_argument

        void set_classe(string nome);
};
inline string Classe::get_classe() const{return nome;};

//----------------------------------------------------------
//------------------CÓDIGO-DE-AGÊNCIA-----------------------
//----------------------------------------------------------

/// \brief Padrão para representação de código de agência.
///
/// A classe CodigoDeAgencia possui o intuito de criar objeto que armazena o código de uma agência bancária.
///
/// ### Requezitos de Formato
/// Para ser considerado válido o código de agência fornecido à instância da classe deve possuir o formato `XXXX`, onde `X` é um digito. O código `0000` é considerado **inválido**.
class CodigoDeAgencia{
    private:
        static const int TAMANHO = 4;
        static const string EXCESSAO;
        string codigo;
        void validar(string codigo);
    public:
        ///- Cria objeto e armazena código passado no mesmo, em caso de argumento **válido**.
        //
        ///- Lança exceção caso o argumento passado seja **inválido.**
        ///
        ///@param codigo : cadeia de caracteres correspondente ao código de agência que se deseja armazenar no objeto. Caso o parâmetro seja omitido, o código armazenado é `0001`.
        /// @throw invalid_argument
        CodigoDeAgencia(string codigo = "0001");
        /// \return Cadeia de caracteres correspondente ao código da agência bancária.
        string get_codigo()const;
        /// - Em caso de argumento **válido**, armazena código no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param codigo : Cadeia de caracteres correspondente ao código de agência que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_codigo(string codigo);
};

inline string CodigoDeAgencia::get_codigo()const{return codigo;};

//----------------------------------------------------------
//------------------CÓDIGO-DE-APLICAÇÃO---------------------
//----------------------------------------------------------

/// \brief Padrão para representação de código de aplicação.
///
/// A classe CodigoDeAplicacao possui o intuito de criar objeto que armazena o código de uma aplicação financeira.
///
/// ### Requezitos de Formato
/// Para ser considerado válido o código de aplicação fornecido à instância da classe deve possuir o formato `XXXXX`, onde `X` é um digito. O código `00000` é considerado **inválido**.
class CodigoDeAplicacao{
    private:
        static const int TAMANHO = 5;
        static const string EXCESSAO;
        string codigo;
        void validar(string codigo);
    public:
        ///- Cria objeto e armazena código passado no mesmo, em caso de argumento **válido**.
        //
        ///- Lança exceção caso o argumento passado seja **inválido.**
        ///
        ///@param codigo : cadeia de caracteres correspondente ao código de aplicação que se deseja armazenar no objeto. Caso o parâmetro seja omitido, o código armazenado é `00001`.
        /// @throw invalid_argument
        CodigoDeAplicacao(string codigo = "00001");
        /// \return Cadeia de caracteres correspondente ao código da aplicação.
        string get_codigo() const;
        /// - Em caso de argumento **válido**, armazena código no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param codigo : Cadeia de caracteres correspondente ao código de aplicação que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_codigo(string codigo);
};

inline string CodigoDeAplicacao::get_codigo()const{return codigo;};

//----------------------------------------------------------
//------------------CÓDIGO-DE-BANCO-------------------------
//----------------------------------------------------------
//
/// \brief Padrão para representação de código de banco.
///
/// A classe CodigoDeBanco possui o intuito de criar objeto que armazena o código de uma instituição bancária;
///
/// ### Requezitos de Formato
/// Para ser considerado válido o código de banco fornecido à instância da classe deve possuir o formato `XXX`, onde `X` é um digito. Apenas os códigos dos 5 maiores bancos brasileiros por ativos totais são válidos, sendo eles:
///
///- Banco Itaú Unibanco (341);
///- Banco do Brasil (001);
///- Banco Bradesco (237); 
///- Caixa Econômica Federal (104);
///- Banco Santander Brasil (033).

class CodigoDeBanco{
    private:
        static const set<string> BANCOS;
        string codigo;
        void validar(string codigo);
    public:
        ///- Cria objeto e armazena código passado no mesmo, em caso de argumento **válido**.
        //
        ///- Lança exceção caso o argumento passado seja **inválido.**
        ///
        ///@param codigo : cadeia de caracteres correspondente ao código de banco que se deseja armazenar no objeto. Caso o parâmetro seja omitido, o código armazenado é `001`.
        /// @throw invalid_argument
        CodigoDeBanco(string codigo = "001");
        /// \return Cadeia de caracteres correspondente ao código de banco.
        string get_codigo()const;
        /// - Em caso de argumento **válido**, armazena código no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param codigo : Cadeia de caracteres que corresponde ao código de banco a ser armazenado no objeto.
        /// @throw invalid_argument
        void set_codigo(string codigo);
};
inline string CodigoDeBanco::get_codigo()const{return codigo;};
#endif
