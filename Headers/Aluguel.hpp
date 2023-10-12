#ifndef ALUGUEL_HPP
#define ALUGUEL_HPP

#include "Usuario.hpp"
#include "Livro.hpp"
#include<ctime>

typedef struct tm Data;

class Aluguel{

    static int quantidadeDeIdentificadores;

    int id;
    bool ativo;
    Usuario* usuario;
    Livro* livro;
    Data dataInicio;
    Data dataFim;

    public:

        static int getquantidadeDeIdentificadores();
        static void setQuantidadeDeIdentificadores(int qtd);

        Aluguel();
        Aluguel(const bool &ativo, Usuario* usuario, Livro* livro, const Data &dataInicio);

        int getId();
        bool getAtivo();
        Usuario* getUsuario();
        Livro* getLivro();
        Data getDataInicio();
        Data getDataFim();

        void setId(int id);
        void setAtivo(bool ativo);
        void setUsuario(Usuario* usuario);
        void setLivro(Livro* livro);
        void setDataInicio(Data dataInicio);
        void setDataFim(Data dataFim);

        void mostraAluguel();

};


#endif