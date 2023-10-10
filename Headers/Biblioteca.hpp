#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Livro.hpp"
#include "Usuario.hpp"
#include<vector>

class Biblioteca{

    private:

    vector<Livro> listaLivros;
    vector<Usuario> listaUsuario;


    public:

    vector<Livro>* getListaLivros();
    vector<Usuario>* getListaUsuario();

    static void menuPrincipal(vector<Usuario> &usuarios);
    static void mostraMenuPrincipal();

    static void menuUsuarios(vector<Usuario> &usuarios);
    static void menuLivros();
    static void menuAlugueis();

    static void mostraMenuSecundario();

    static void insereUsuario(vector<Usuario> &usuarios);
    static void encontraUsuario(vector<Usuario> &usuarios);
    static void excluiUsuario(vector<Usuario> &usuarios);
    static void listarUsuarios(vector<Usuario> &usuarios);
    // static void modificaUsuario(vector<Usuario> &usuarios);


};



#endif