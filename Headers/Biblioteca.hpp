#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Aluguel.hpp"
#include<vector>

class Biblioteca{

    private:

    vector<Livro> listaLivros;
    vector<Usuario> listaUsuario;
    vector<Aluguel> listaAluguel;


    public:

    vector<Livro>* getListaLivros();
    vector<Usuario>* getListaUsuario();
    vector<Aluguel>* getListaAluguel();

    static void menuPrincipal(vector<Aluguel> &alugueis, vector<Usuario> &usuarios, vector<Livro> &livros);
    static void mostraMenuPrincipal();

    static void menuUsuarios(vector<Usuario> &usuarios);
    static void menuLivros(vector<Livro> &livros);
    static void menuAlugueis(vector<Aluguel> &alugueis,vector<Usuario> &usuarios,vector<Livro> &livros);

    static void mostraMenuSecundario();

    static void insereUsuario(vector<Usuario> &usuarios);
    static void encontraUsuario(vector<Usuario> &usuarios);
    static void excluiUsuario(vector<Usuario> &usuarios);
    static void listarUsuarios(vector<Usuario> &usuarios);
    static void modificaUsuario(vector<Usuario> &usuarios);

    static void insereLivros(vector<Livro> &livros);
    static void encontraLivros(vector<Livro> &livros);
    static void excluiLivros(vector<Livro> &livros);
    static void listarLivros(vector<Livro> &livros);
    static void modificaLivros(vector<Livro> &livros);

    static void recuperaUsuarios(vector<Usuario> &usuarios);
    static void recuperaLivros(vector<Livro> &livros);
    static void recuperaAlugueis(vector<Aluguel> &alugueis,vector<Usuario> &usuarios,vector<Livro> &livros);

    static void insereAluguel(vector<Aluguel> &alugueis,vector<Usuario> &usuarios,vector<Livro> &livros);
    static void encontraAluguel(vector<Aluguel> &alugueis);
    static void finalizaAluguel(vector<Aluguel> &alugueis);
    static void listaAluguelAtivo(vector<Aluguel> &alugueis);
    static void listaAluguelInativo(vector<Aluguel> &alugueis);
    static void listaAluguelPorCliente(vector<Aluguel> &alugueis);

    static void mostraMenuAluguel();


    static void pause();
};



#endif