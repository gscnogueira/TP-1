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
        /// \param codigo : Código responsável por identificar a aplicação.
        void set_codigo(const CodigoDeAplicacao&);
        /// \return Código responsável por identificar a aplicação financeira.
        CodigoDeAplicacao get_codigo() const;
        /// Função destinada à armazenar, em instância da classe, o valor de uma aplicação financeira, caso o mesmo seja considerado **válido**.
        /// \param valor : Valor da aplicação financeira.
        void set_valor(const ValorDeAplicacao&);
        /// \return Valor da aplicação financeira
        ValorDeAplicacao get_valor() const;
        /// Função destinada à armazenar, em instância da classe, a data em que uma aplicação foi feita, caso a data fornecida seja válida.
        /// \param data : Data em que a aplicação foi feita.
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

#endif
