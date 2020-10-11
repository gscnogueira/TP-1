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
        /// \param codigo : código responsável por identificar a aplicação.
        void set_codigo(const CodigoDeAplicacao&);
        /// \return Código responsável por identificar a aplicação financeira.
        CodigoDeAplicacao get_codigo() const;
        /// Função destinada à armazenar, em instância da classe, o valor de uma aplicação financeira, caso o mesmo seja considerado **válido**.
        /// \param valor : valor da aplicação financeira.
        void set_valor(const ValorDeAplicacao&);
        /// \return Valor da aplicação financeira
        ValorDeAplicacao get_valor() const;
        /// Função destinada à armazenar, em instância da classe, a data em que uma aplicação foi feita, caso a data fornecida seja válida.
        /// \param data : data em que a aplicação foi feita.
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
        /// \param banco : código do banco em que a conta está hospedada.
        void set_banco(const CodigoDeBanco&);
        /// \return Código do banco em que a conta está hospedada.
        CodigoDeBanco get_banco() const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o número da agência da conta.
        /// \param agencia : código de agência da conta.
        void set_agencia(const CodigoDeAgencia&);
        /// \return Código de agencia da conta.
        CodigoDeAgencia get_agencia() const;
        /// Caso um parâmetro válido seja passado, o mesmo é armazenado em instância da classe, representando o número da conta. 
        /// \param numero : número da conta armazenado na instância da classe.
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
        void set_codigo(const CodigoDeProduto&);
        CodigoDeProduto get_codigo()const;
        void set_classe(const Classe&);
        Classe get_classe()const;
        void set_emissor(const Emissor&);
        Emissor get_emissor()const;
        void set_prazo(const Prazo&);
        Prazo get_prazo()const;
        void set_vencimento(const Data&);
        Data get_vencimento()const;
        void set_taxa(const Taxa &);
        Taxa get_taxa()const;
        void set_horario(const Horario&);
        Horario get_horario()const;
        void set_valor(const ValorMinimo&);
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



#endif
