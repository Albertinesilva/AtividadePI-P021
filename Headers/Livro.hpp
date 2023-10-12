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
    int numCopiasDisponiveis;

    public:
        

        static int getquantidadeDeIdentificadores();
        static void setQuantidadeDeIdentificadores(int qtd);

        Livro();
        Livro(const string &titulo , const string &author , const int &numPaginas , const int &numCopiaisDisponiveis);
        string getTitulo();
        string getAuthor();
        int getNumPaginas();
        int getId();
        int getNumCopiasDisponiveis();
        void setTitulo(string titulo);
        void setAuthor(string author);
        void setNumPaginas(int numPaginas);
        void setId(int id);
        void setNumCopiasDisponiveis(int numCopiasDisponiveis);
        void mostraLivro();


};


#endif