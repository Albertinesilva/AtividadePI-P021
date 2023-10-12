#include "../Headers/Livro.hpp"
#include "../Headers/Usuario.hpp"
#include "../Headers/Biblioteca.hpp"

int main(){

    Biblioteca biblioteca;
    Biblioteca::recuperaUsuarios(*(biblioteca.getListaUsuario()));
    Biblioteca::recuperaLivros(*(biblioteca.getListaLivros()));
    Biblioteca::recuperaAlugueis(*(biblioteca.getListaAluguel()),*(biblioteca.getListaUsuario()),*(biblioteca.getListaLivros()));
    Biblioteca::menuPrincipal(*biblioteca.getListaAluguel(),*(biblioteca.getListaUsuario()),*(biblioteca.getListaLivros()));

}