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
//----------------------------------------------------------
//-------------------CÓDIGO-DE-PRODUTO----------------------
//----------------------------------------------------------

///\brief Padrão para representação de código de produto.
///
/// A classe CodigoDeProduto possui o intuito de criar objeto que armazena o código de um produto de investimento.
///
/// ### Requezitos de Formato
/// Para ser considerado válido, o código de produto fornecido à instância da classe deve possuir o formato `XXX`, onde `X` é um digito. O código `000` é considerado **inválido**.

class CodigoDeProduto{
   private:
       static const int TAMANHO = 3;
       static const string EXCESSAO;
       string codigo;
       void validar(string codigo);
    public:
        ///- Cria objeto e armazena código passado no mesmo, em caso de argumento **válido**.
        //
        ///- Lança exceção caso o argumento passado seja **inválido.**
        ///
        ///@param codigo : cadeia de caracteres correspondente ao código de produto que se deseja armazenar no objeto. Caso o parâmetro seja omitido, o código armazenado é `001`.
        /// @throw invalid_argument
       CodigoDeProduto(string codigo="001");
        /// \return Cadeia de caracteres correspondente ao código de produto.
       string get_codigo() const;
        /// - Em caso de argumento **válido**, armazena código no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param codigo : Cadeia de caracteres correspondente ao código de produto que se deseja armazenar no objeto.
        /// @throw invalid_argument
       void set_codigo(string codigo);
};

inline string CodigoDeProduto::get_codigo() const{ return codigo;};

//----------------------------------------------------------
//------------------------CPF-------------------------------
//----------------------------------------------------------

///\brief Padrão para representação de CPF.
///
///
/// ### Requezitos de Formato
/// Para ser considerado válido, o CPF ser passado deve ter o formato `XXX.XXX.XXX-XX`. Além disso, o CPF fornecido deve ser válido de acordo com algorítimo de validação de CPF elaborado pelo ministério da fazenda.

class CPF{
    private:
        static const int TAMANHO = 14;
        string cpf;
        void validar(string cpf);
    public:
        /// \return Cadeia de caracteres correspondente ao CPF armazenado no objeto.
        string get_cpf() const;
/// - Em caso de argumento **válido**, armazena código no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param codigo : Cadeia de caracteres correspondente ao CPF que se deseja armazenar no objeto.
        /// @throw invalid_argument

        void set_cpf(string cpf);

};
inline string CPF::get_cpf() const { return cpf; };
//----------------------------------------------------------
//------------------------DATA------------------------------
//----------------------------------------------------------

///\brief Padrão para representação de data.
///
///
/// ### Requezitos de Formato
/// Para ser considerado válido, a cadeia de caracteres a ser passada deve ter o formato `XX/XX/XXXX`. São validas quaisquer datas existentes no periodo entre 01/01/2020 e 31/12/2099;

class Data{
    private:
        static const int TAMANHO = 10;
        string data;
        void validar(string data);
    public:
        Data();
        ///- Cria objeto e armazena cadeia de caracteres passada no mesmo, em caso de argumento **válido**.
        //
        ///- Lança exceção caso o argumento passado seja **inválido.**
        ///
        ///@param data : Cadeia de caracteres correspondente à data que se deseja armazenar no objeto. Caso o parâmetro seja omitido, a data atual é armazenada. Caso a data atual não seja detectada, a data 01/01/2020 é armazenada.
        /// @throw invalid_argument
        Data(string data);
        /// \return Cadeia de caracteres correspondente à data armazenada no objeto.
        string get_data() const;
        /// - Em caso de argumento **válido**, armazena cadeia de caracteres corresponde à data no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param data : Cadeia de caracteres correspondente à data que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_data(string data);
};
inline string Data::get_data() const { return data; };
//----------------------------------------------------------
//------------------------EMISSOR---------------------------
//----------------------------------------------------------
///\brief Padrão para representação de emissor de produto de investimento.
///
///
/// ### Requezitos de Formato
/// Para ser considerado válido, a cadeia de caracteres a ser passada deve ter de 5 a 30 caracteres. São considerado caracteres **válidos**:
///- Dígito (0-9) 
///- Espaço
///- Hífen
///- Letra (A-Z ou a-z)
///- Ponto
///
/// Apenas letras e digitos podem estar em sequência. Em termo cuja primeira letra é um caractere, a mesma **deve** ser maiúscula.
class Emissor{
    private:
        static const set<char> VALIDOS;
        static const int TAMANHO_MIN = 5;
        static const int TAMANHO_MAX = 30;
        string emissor;
        void validar(string emissor);
    public:
        /// \return Cadeia de caracteres correspondente ao emissor de produto de investimento.
        string get_emissor() const;
        /// - Em caso de argumento **válido**, armazena cadeia de caracteres corresponde ao emissor armazenado no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param emissor : Cadeia de caracteres correspondente ao emissor que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_emissor(string emissor);
};
inline string Emissor::get_emissor()const{return emissor;};

//----------------------------------------------------------
//------------------------ENDEREÇO--------------------------
//----------------------------------------------------------

///\brief Padrão para representação de endereço.
///
///
/// ### Requezitos de Formato
/// Para ser considerado válido, a cadeia de caracteres a ser passada deve ter de 5 a 20 caracteres. São considerado caracteres **válidos**:
///- Dígito (0-9) 
///- Espaço
///- Letra (A-Z ou a-z)
///- Ponto
///
/// Apenas letras e digitos podem estar em sequência. Em termo cuja primeira letra é um caractere, a mesma **deve** ser maiúscula.
class Endereco{
    private:
        static const set<char> VALIDOS;
        static const int TAMANHO_MIN = 5;
        static const int TAMANHO_MAX = 20;
        string endereco;
        void validar(string endereco);
    public:
        /// \return Cadeia de caracteres correspondente ao endereço armazenado no objeto.
        string get_endereco() const;
        /// - Em caso de argumento **válido**, armazena valor de endereço no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param endereco : Cadeia de caracteres correspondente ao endereco que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_endereco(string endereco);

};
inline string Endereco::get_endereco()const{return endereco;};

//----------------------------------------------------------
//------------------------HORÁRIO---------------------------
//----------------------------------------------------------

///\brief Padrão para representação de horário.
///
///
/// ### Requezitos de Formato
/// Para ser considerado válido, a cadeia de caracteres a ser passada deve ter o formato `XX:XX`. São validos **apenas** horários entre 13:00 e 17:00 horas;

class Horario{
    private:
        static const int TAMANHO=5;
        string horario;
        void validar(string horario);
    public:
       Horario();
  ///- Cria objeto e armazena cadeia de caracteres passada no mesmo, em caso de argumento **válido**.
        //
        ///- Lança exceção caso o argumento passado seja **inválido.**
        ///
        ///@param horario : Cadeia de caracteres correspondente ao horario que se deseja armazenar no objeto. Caso o parâmetro seja omitido, o horario atual é armazenado. Caso o horario atual não seja válido, ou detectado, a cadeia de caracteres 13:00 é armazenada.
        /// @throw invalid_argument
        Horario(string horario);
        /// \return Cadeia de caracteres correspondente ao horario armazenado no objeto.
        string get_horario() const;
        /// - Em caso de argumento **válido**, armazena cadeia de caracteres no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param horario : Cadeia de caracteres correspondente ao horário que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_horario(string horario);
};
inline string Horario::get_horario()const{return horario;};

//----------------------------------------------------------
//------------------------NOME------------------------------
//----------------------------------------------------------

///\brief Padrão para representação de Nome.
///
///
/// ### Requezitos de Formato
/// Para ser considerado válido, a cadeia de caracteres a ser passada deve ter de 5 a 30 caracteres. São considerado caracteres **válidos**:
///- Espaço
///- Letra (A-Z ou a-z)
///
/// Não são aceitos espaços em sequência. A primeira letra de cada termo **deve** ser maiúscula.

class Nome{
    private:
        static const int TAMANHO_MIN = 5;
        static const int TAMANHO_MAX = 30;
        string nome;
        void validar(string nome);
    public:
        /// \return Cadeia de caracteres correspondente ao nome armazenado no objeto.
        string get_nome() const;
        /// - Em caso de argumento **válido**, armazena nome no objeto.
        ///
        /// - Caso seja passada uma cadeia de caracteres **inválida** como argumento, uma exceção é lançada.
        /// @param nome : Cadeia de caracteres correspondente ao nome que se deseja armazenar no objeto.
        /// @throw invalid_argument
        void set_nome(string nome);

};
inline string Nome::get_nome()const{return nome;};

#endif
