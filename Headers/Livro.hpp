#ifndef LIVRO_HPP
#define LIVRO_HPP

#include<iostream>

using namespace std;

class Livro{

    private:

    static int quantidadeDeIdentificadores;
    int id;
    string titulo;
    string author;
    int numPaginas;

    public:
        
        Livro();
        Livro(const string &titulo , const string &author , const int &numPaginas);
        string getTitulo();
        string getAuthor();
        int getNumPaginas();
        int getId();
        void setTitulo(string titulo);
        void setAuthor(string author);
        void setNumPaginas(int numPaginas);
        void setId(int id);


};


#endif