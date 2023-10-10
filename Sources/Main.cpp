#include "../Headers/Livro.hpp"
#include "../Headers/Usuario.hpp"
#include "../Headers/Biblioteca.hpp"

int main(){

    Biblioteca biblioteca;
    Biblioteca::menuPrincipal(*(biblioteca.getListaUsuario()));

}