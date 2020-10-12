#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "dominios.h"
#include <bits/stdc++.h>

using namespace std;

//----------------------------------------------------------
//----------------------APLICAÇÃO---------------------------
//----------------------------------------------------------

/// \brief Padrão para representação de aplicação financeira.
//
///**Aplicação financeira** pode ser definida como a compra de um ativo financeiro na expectativa de que, com o tempo, ele produza um retorno financeiro. Assim, se demonstra necessário saber o **valor** da uma aplicação e a **data** em que foi feita, bem como o **código** que identifica a aplicação.
class Aplicacao{
    private:
        CodigoDeAplicacao codigo;
        ValorDeAplicacao valor;
        Data data;
    public:
        /// Função destinada à armazenar, em instância da classe, o código identificador de uma aplicação financeira, caso o mesmo seja considerado **válido**.
        /// \param codigo : objeto da classe CodigoDeAplicacao, responsável por identificar a aplicação.
        void set_codigo(const CodigoDeAplicacao&);
        /// \return Código responsável por identificar a aplicação financeira.
        CodigoDeAplicacao get_codigo() const;
        /// Função destinada à armazenar, em instância da classe, o valor de uma aplicação financeira, caso o mesmo seja considerado **válido**.
        /// \param valor : objeto da classe ValorDeAplicacao , o qual representa o valor da aplicação financeira.
        void set_valor(const ValorDeAplicacao&);
        /// \return Valor da aplicação financeira
        ValorDeAplicacao get_valor() const;
        /// Função destinada à armazenar, em instância da classe, a data em que uma aplicação foi feita, caso a data fornecida seja válida.
        /// \param data : objeto da classe Data, responsável por representar a data em que a aplicação foi feita.
        void set_data(const Data&);
        /// \return Data em que uma aplicação financeira foi feita.
        Data get_data() const;
};

inline void Aplicacao::set_codigo(const CodigoDeAplicacao &codigo){
    this->codigo=codigo;
}

inline CodigoDeAplicacao Aplicacao::get_codigo() const{
    return codigo;
}

inline void Aplicacao::set_valor(const ValorDeAplicacao &valor){
    this->valor=valor;
}

inline ValorDeAplicacao Aplicacao::get_valor() const{
    return valor;
}

inline void Aplicacao::set_data(const Data &data){
    this->data=data;
}

inline Data Aplicacao::get_data()const{
    return data;
}
//----------------------------------------------------------
//--------------------------CONTA---------------------------
//----------------------------------------------------------

/// \brief Padrão para representação de conta-corrente.
//
/// A **conta-corrente** é uma conta de depósito mantida num banco ou instituição financeira por uma pessoa física ou jurídica. Sendo assim, para a representação de uma conta-corrente, é necessário identificar o banco onde a conta está hospedada, por meio de um **código de banco**. Também é necessário a **agência** e **número** da conta para identificá-la.
class Conta{
    private:
        CodigoDeBanco banco;
        CodigoDeAgencia agencia;
        Numero numero;
    public:
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o código do banco em que a conta está hospedado. 
        /// \param banco : instância da classe CodigoDeBanco, representando o código do banco em que a conta está hospedada.
        void set_banco(const CodigoDeBanco&);
        /// \return Código do banco em que a conta está hospedada.
        CodigoDeBanco get_banco() const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o número da agência da conta.
        /// \param agencia : instância da classe CodigoDeAgencia, representando o código de agência da conta.
        void set_agencia(const CodigoDeAgencia&);
        /// \return Código de agencia da conta.
        CodigoDeAgencia get_agencia() const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o número da conta. 
        /// \param numero : instância da classe Numero, representa o número da conta armazenado na instância da classe.
        void set_numero(const Numero&);
        /// \return Número da conta.
        Numero get_numero() const;
};
inline void Conta::set_banco(const CodigoDeBanco &banco){
    this->banco=banco;
}
inline CodigoDeBanco Conta::get_banco() const{
    return banco;
}
inline void Conta::set_agencia(const CodigoDeAgencia &agencia){
    this->agencia=agencia;
}
inline CodigoDeAgencia Conta::get_agencia()const{
    return agencia;
}
inline void Conta::set_numero(const Numero &numero){
    this->numero=numero;
}
inline Numero Conta::get_numero()const{
    return numero;
}
//----------------------------------------------------------
//-----------------------PRODUTO----------------------------
//----------------------------------------------------------

/// \brief Padrão para representação de produto de investimento.
//
/// Para realizar um investimento, é necessário um **produto de investimento**, ao qual o investimento será aplicado. Assim, ele precisa ser identificado por parâmetros, sendo eles: código, classe, emissor, prazo, vencimento, taxa, horário e valor mínimo.

class Produto{
    private:
        CodigoDeProduto codigo;
        Classe classe;
        Emissor emissor;
        Prazo prazo;
        Data vencimento;
        Taxa taxa;
        Horario horario;
        ValorMinimo valor;
    public:

        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o código identificador do produto de investimento.
        /// \param codigo : instância da classe CodigoDeProduto,sendo o código do produto de investimento.
        void set_codigo(const CodigoDeProduto&);
        /// \return Código do produto de investimento.
        CodigoDeProduto get_codigo()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando a classe de um produto de investimento.
        /// \param classe : instância da classe Classe, sendo a classe do produto de investimento.
        void set_classe(const Classe&);
        /// \return Classe do produto de investimento.
        Classe get_classe()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o emissor de um produto de investimento.
        /// \param emissor : instância da classe Emissor, representando o emissor do produto de investimento.
        void set_emissor(const Emissor&);
        /// \return Emissor do produto de investimento.
        Emissor get_emissor()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o prazo em que o retorno do investimento será obtido.
        /// \param prazo : instância da classe Prazo, representando o prazo em que o retorno do investimento será obtido.
        void set_prazo(const Prazo&);
        /// \return Prazo em que o retorno do investimento será obtido.
        Prazo get_prazo()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando a data de vencimento na qual os recursos estarão disponíveis.
        /// \param vencimento : instância da classe Data, representa a data de vencimento na qual os recursos estarão disponíveis.
        void set_vencimento(const Data&);
        /// \return Data de vencimento na qual os recursos estarão disponíveis.
        Data get_vencimento()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando a taxa de remuneração do produto de investimento.
        /// \param taxa : objeto da classe Taxa, responsável por representar a taxa de remuneração; 
        void set_taxa(const Taxa &);
        /// \return Taxa de remuneração.
        Taxa get_taxa()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o horário limite para aplicação no produto de investimento.
        /// \param taxa : objeto da classe Horario, responsável por representar o horário limite.
        void set_horario(const Horario&);
        /// \return Horário limite para aplicação no produto de investimento.
        Horario get_horario()const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o valor mínimo para a aplicação no produto de investimento. 
        /// \param valor : instância da classe ValorMinimo, representa o valor mínimo para a aplicação.
        void set_valor(const ValorMinimo&);
        /// \return Valor mínimo para a aplicação no produto de investimento.
        ValorMinimo get_valor()const;
};
inline void Produto::set_codigo(const CodigoDeProduto &codigo){
    this->codigo=codigo;
}
inline CodigoDeProduto Produto::get_codigo()const{
    return codigo;
}
inline void Produto::set_classe(const Classe &classe){
    this->classe=classe;
}
inline Classe Produto::get_classe()const{
    return classe;
}
inline void Produto::set_emissor(const Emissor &emissor){
    this->emissor=emissor;
}
inline Emissor Produto::get_emissor()const{
    return emissor;
}
inline void Produto::set_prazo(const Prazo &prazo){
    this->prazo=prazo;
}
inline Prazo Produto::get_prazo() const{
    return prazo;
}
inline void Produto::set_vencimento(const Data &vencimento){
    this->vencimento=vencimento;
}
inline Data Produto::get_vencimento() const{
    return vencimento;
}
inline void Produto::set_taxa(const Taxa &taxa){
    this->taxa=taxa;
}
inline Taxa Produto::get_taxa() const{
    return taxa;
}
inline void Produto::set_horario(const Horario &horario){
    this->horario=horario;
}
inline Horario Produto::get_horario() const{
    return horario;
}
inline void Produto::set_valor(const ValorMinimo &valor){
    this->valor=valor;
}
inline ValorMinimo Produto::get_valor() const{
    return valor;
}
//----------------------------------------------------------
//----------------------USUÁRIO-----------------------------
//----------------------------------------------------------

class Usuario{
    private:
        Nome nome;
        Endereco endereco;
        CEP cep;
        CPF cpf;
        Senha senha;
    public:
        void set_nome(Nome&);
        Nome get_nome();
        void set_endereco(Endereco&);
        Endereco get_endereco();
        void set_cep(CEP&);
        CEP get_cep();
        void set_cpf(CPF&);
        CPF get_cpf();
        void set_senha(Senha&);
        Senha get_senha();
};
inline void Usuario::set_nome(Nome &nome){
    this->nome=nome;
}
inline Nome Usuario::get_nome(){
    return nome;
}
inline void Usuario::set_endereco(Endereco &endereco){
    this->endereco=endereco;
}
inline Endereco Usuario::get_endereco(){
    return endereco;
}
inline void Usuario::set_cep(CEP &cep){
    this->cep=cep;
}
inline CEP Usuario::get_cep(){
    return cep;
}
inline void Usuario::set_cpf(CPF &cpf){
    this->cpf=cpf;
}
inline CPF Usuario::get_cpf(){
    return cpf;
}
inline void Usuario::set_senha(Senha &senha){
    this->senha=senha;
}
inline Senha Usuario::get_senha(){
    return senha;
}


#endif
