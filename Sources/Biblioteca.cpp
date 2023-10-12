#include "../Headers/Biblioteca.hpp"

vector<Livro>* Biblioteca::getListaLivros(){
    return &(this->listaLivros);
} 

vector<Usuario>* Biblioteca::getListaUsuario(){
    return &(this->listaUsuario);
}

void Biblioteca::mostraMenuPrincipal(){
    system("clear || cls");
    cout << "-------MENU PRINCIPAL-------" << endl;
    cout << "[1] GERENCIA USUARIO" << endl;
    cout << "[2] GERENCIA LIVROS" << endl;
    cout << "[3] GERENCIA ALUGUEIS" << endl;
    cout << "[0] SAIR" << endl;
    cout << "Escolha : ";
}

void Biblioteca::mostraMenuSecundario(){
    system("clear || cls");
    cout << "-------MENU-------" << endl;
    cout << "[1] INSERIR :" << endl;
    cout << "[2] ESCONTRAR :" << endl;
    cout << "[3] EXCLUIR :" << endl;
    cout << "[4] LISTAR :" << endl;
    cout << "[5] MODIFICAR : " << endl;
    cout << "[0] SAIR" << endl;
    cout << "Escolha : ";
}

void Biblioteca::menuPrincipal(vector<Usuario> &usuarios){
    int escolha;
    do{
        Biblioteca::mostraMenuPrincipal();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            menuUsuarios(usuarios);
            break;
        case 2: 
            menuLivros();
            break;  
        case 3:
            menuAlugueis();  
        default:
            break;
        }
    }while(escolha!=0);

}

void Biblioteca::menuUsuarios(vector<Usuario> &usuarios){
    int escolha;
    do{
        Biblioteca::mostraMenuSecundario();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            /*insere Usuario/
            break;
        case 2:
            /*encontra Usuario/
            break;
        case 3:
            /*exclui Usuario/
            break;
        case 4:
            /*lista usuarios*/
            break;
        case 5:
            /*Modificar Usuario*/
        default:
            break;
        }
    }while(escolha!=0);
}

void Biblioteca::menuLivros(){
    int escolha;
    do{
        Biblioteca::mostraMenuSecundario();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            /*insere livro*/
            break;
        case 2:
            /*encontra livro*/
            break;
        case 3:
            /*exclui livro*/
            break;
        case 4:
            /*lista livro*/
            break;
        case 5:
            /*modificar livro*/
            break;
        default:
            break;
        }
    }while(escolha!=0);

}

void Biblioteca::menuAlugueis(){
    int escolha;
    Biblioteca::mostraMenuSecundario();

}

void Biblioteca::insereUsuario(vector<Usuario> &usuarios){
    string nome,cpf,endereco,telefone;

    cout << "Nome : ";
    getline(cin,nome);
    cout << "Cpf : ";
    getline(cin,cpf);
    cout << "Endereço : ";
    getline(cin,endereco);
    cout << "Telefone : ";
    getline(cin,telefone);

    Usuario usuario(nome,cpf,endereco,telefone);
    usuarios.push_back(usuario);

}

void Biblioteca::encontraUsuario(vector<Usuario> &usuarios){
    int id;
    cout << "Digite o id do usuario que deseja buscar : ";
    cin >> id;
    cin.get();

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        if(id == it->getId()){
            it->mostraUsuario();
            return;
        }
    }

    cout << "Usuario não Encontrado em nossa base de dados" << endl;
}

void Biblioteca::excluiUsuario(vector<Usuario> &usuarios){
    int id;
    cout << "Digite o id do usuario que deseja buscar : ";
    cin >> id;
    cin.get();

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        if(id == it->getId()){
            usuarios.erase(it);
            return;
        }
    }

    cout << "Usuario não Encontrado em nossa base de dados" << endl;
}

void Biblioteca::listarUsuarios(vector<Usuario> &usuarios){

    cout << "-----LISTA DE USUARIOS-----" << endl;

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        cout << "-----------------------------" << endl; 
            it->mostraUsuario();
        cout << "-----------------------------" << endl; 
    }
    cout << "-----FIM DA LISTA-----" << endl;

}


