#include "../Headers/Biblioteca.hpp"
#include<fstream>

/**Get listas*/

vector<Livro>* Biblioteca::getListaLivros(){
    return &(this->listaLivros);
} 

vector<Usuario>* Biblioteca::getListaUsuario(){
    return &(this->listaUsuario);
}

vector<Aluguel>* Biblioteca::getListaAluguel(){
    return &(this->listaAluguel);
}

/**menu principal e auxiliar*/

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

void Biblioteca::menuPrincipal(vector<Aluguel> &alugueis, vector<Usuario> &usuarios, vector<Livro> &livros){
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
            menuLivros(livros);
            break;
        case 3:
            menuAlugueis(alugueis,usuarios,livros);  
            break;
        default:
            break;
        }
    }while(escolha!=0);

}

/**UTILS*/

void Biblioteca::pause(){
    cout << "Pressione <Enter> para continuar...";
    getchar();
}

/**PERSISTENCIA*/

void Biblioteca::recuperaUsuarios(vector<Usuario> &usuarios){
    ifstream inUsuarios;

    inUsuarios.open("../BancoDeDados/Usuarios.txt",ios_base::out);
    if(inUsuarios.is_open()){
        string id,nome,cpf,endereco,telefone;
        int idd;
        while (inUsuarios.eof() == false)
        {
            
            getline(inUsuarios,id);
            getline(inUsuarios,nome);
            getline(inUsuarios,cpf);
            getline(inUsuarios,endereco);
            getline(inUsuarios,telefone);
            if(!id.empty()){
                Usuario usuario(nome,cpf,endereco,telefone);
                idd = stoi(id);
                usuario.setId(idd);
                if(idd > Usuario::getquantidadeDeIdentificadores()){
                    Usuario::setQuantidadeDeIdentificadores(idd);
                }
                usuarios.push_back(usuario);
            }
        }
        inUsuarios.close();
    }
}

void Biblioteca::recuperaLivros(vector<Livro> &livros){
    ifstream inLivros;

    inLivros.open("../BancoDeDados/Livros.txt",ios_base::in);

    if(inLivros.is_open()){
        string id,titulo,author,numeroDePaginas,numeroDeCopiasDisponiveis;
        int idd,numeroDePaginasINT,numeroDeCopiasDisponiveisINT;
        while(inLivros.eof()==false){
            
            getline(inLivros,id);
            getline(inLivros,titulo);
            getline(inLivros,author);
            getline(inLivros,numeroDePaginas);
            getline(inLivros,numeroDeCopiasDisponiveis);
            if(id.empty() == false){
                idd = stoi(id);
                numeroDePaginasINT = stoi(numeroDePaginas);
                numeroDeCopiasDisponiveisINT = stoi(numeroDeCopiasDisponiveis);
                Livro livro(titulo,author,numeroDePaginasINT,numeroDeCopiasDisponiveisINT);
                idd = stoi(id);
                livro.setId(idd);
                if(idd > Livro::getquantidadeDeIdentificadores()){
                    Livro::setQuantidadeDeIdentificadores(idd);
                }
                livros.push_back(livro);
            }
        }
        inLivros.close();
    }
}

void Biblioteca::recuperaAlugueis(vector<Aluguel> &alugueis,vector<Usuario> &usuarios,vector<Livro> &livros){
    ifstream inAlugueis;
    inAlugueis.open("../BancoDeDados/Alugueis.txt",ios_base::in);
    string idAluguel,idUsuario,idLivro,diaAluguel,mesAluguel,anoAluguel,ativo;
    int idAluguelINT,idUsuarioINT,idLivroINT, diaAluguelINT,mesAluguelINT,anoAluguelINT,ativoINT;
    Usuario* usuario;
    Livro* livro;
    if(inAlugueis.is_open()){
        while(inAlugueis.eof() == false){
            getline(inAlugueis,idAluguel);
            getline(inAlugueis,idUsuario);
            getline(inAlugueis,idLivro);
            getline(inAlugueis,diaAluguel);
            getline(inAlugueis,mesAluguel);
            getline(inAlugueis,anoAluguel);
            getline(inAlugueis,ativo);
            if(!idAluguel.empty()){
                idAluguelINT = stoi(idAluguel);
                idUsuarioINT = stoi(idUsuario);
                idLivroINT = stoi(idLivro);
                diaAluguelINT = stoi(diaAluguel);
                mesAluguelINT = stoi(mesAluguel);
                anoAluguelINT = stoi(anoAluguel);
                ativoINT = stoi(ativo);


                for(auto it=usuarios.begin() ; it!=usuarios.end() ; it++){
                    if(it->getId() == idUsuarioINT){
                        usuario = &(*it);
                        break;
                    }
                }

                for(auto it=livros.begin() ; it!=livros.end() ; it++){
                    if(it->getId() == idLivroINT){
                        livro = &(*it);
                        break;
                    }
                }

                Data data;
                data.tm_mday = diaAluguelINT;
                data.tm_mon = mesAluguelINT;
                data.tm_year = anoAluguelINT;


                Aluguel aluguel(true, usuario,livro,data);
                if(ativoINT == 0){
                    aluguel.setAtivo(false);
                }
                alugueis.push_back(aluguel);
            
            }
        }
        inAlugueis.close();
    }
}


/**USUARIOS*/

void Biblioteca::menuUsuarios(vector<Usuario> &usuarios){
    int escolha;
    do{
        Biblioteca::mostraMenuSecundario();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            insereUsuario(usuarios);
            break;
        case 2:
            encontraUsuario(usuarios);
            break;
        case 3:
            excluiUsuario(usuarios);
            break;
        case 4:
            listarUsuarios(usuarios);
            break;
        case 5:
            modificaUsuario(usuarios);
        default:
            break;
        }
    }while(escolha!=0);
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

    ofstream ofUsuarios;

    ofUsuarios.open("../BancoDeDados/Usuarios.txt",ios_base::app);

    if(ofUsuarios.is_open()){
        ofUsuarios << usuario.getId() << endl;
        ofUsuarios << usuario.getNome() << endl;
        ofUsuarios << usuario.getCpf() << endl;
        ofUsuarios << usuario.getEndereco() << endl;
        ofUsuarios << usuario.getTelefone() << endl;
        ofUsuarios.close();
        cout << "USUARIO CADASTRADO COM SUCESSO!" << endl;
        pause();
    }else{
        cout << "Não foi possivel abrir o arquivo Usuarios.txt" << endl;
        exit(0);
    }



}

void Biblioteca::encontraUsuario(vector<Usuario> &usuarios){
    int id;
    cout << "Digite o id do usuario que deseja buscar : ";
    cin >> id;
    cin.get();

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        if(id == it->getId()){
            it->mostraUsuario();
            pause();
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
    bool usuarioExcluido=false;
    bool usuarioEncontrado = false;

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        if(id == it->getId()){
            usuarios.erase(it);
            usuarioExcluido=true;
            usuarioEncontrado=true;
            break;
        }
    }

    if(usuarioExcluido){
        ofstream ofUsuarios;
        ofUsuarios.open("../BancoDeDados/Usuarios.txt",ios_base::out);
        if(ofUsuarios.is_open()){
            for(auto it=usuarios.begin() ; it!=usuarios.end() ; it++){
                ofUsuarios << it->getId() << endl;
                ofUsuarios << it->getNome() << endl;
                ofUsuarios << it->getCpf() << endl;
                ofUsuarios << it->getEndereco() << endl;
                ofUsuarios << it->getTelefone() << endl;
                cout << "USUARIO EXCLUIDO COM SUCESSO!" << endl;
                pause();
            }
        }
    }else if(!usuarioEncontrado){
        cout << "Usuario não Encontrado em nossa base de dados" << endl;
    }

}

void Biblioteca::listarUsuarios(vector<Usuario> &usuarios){

    system("clear || cls");
    cout << "-----LISTA DE USUARIOS-----" << endl;

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        cout << "-----------------------------" << endl; 
            it->mostraUsuario();
        cout << "-----------------------------" << endl; 
    }
    cout << "-----FIM DA LISTA-----" << endl;
    pause();

}

void Biblioteca::modificaUsuario(vector<Usuario> &usuarios){
    int id;
    cout << "Id do usuario que deseja alterar : ";
    cin >> id;
    cin.get();
    int escolha;
    bool usuarioModificado = false;
    bool usuarioEncontrado = false;

    for(auto it = usuarios.begin() ; it!=usuarios.end() ; it++){
        if(id == it->getId()){
            usuarioEncontrado=true;
            string nome,cpf,endereco,telefone;

            do{
                cout << "O que deseja alterar ? ";
                cout << "[1] Nome" << endl;
                cout << "[2] CPF " << endl;
                cout << "[3] Endereco " << endl;
                cout << "[4] Telefone " << endl;
                cout << "[0] Sair" << endl; 
                cin >> escolha;

                switch (escolha)
                {
                case 1:
                    cout << "Novo nome : " ;
                    getline(cin,nome);
                    it->setNome(nome);
                    usuarioModificado = true;
                    break;
                case 2:
                    cout << "Novo cpf : " ;
                    getline(cin,cpf);
                    it->setCpf(cpf);
                    usuarioModificado = true;
                    break;
                case 3:
                    cout << "Novo endereço : " ;
                    getline(cin,endereco);
                    it->setEndereco(endereco);
                    usuarioModificado = true;
                    break;
                case 4:
                    cout << "Novo telefone : " ;
                    getline(cin,telefone);
                    it->setTelefone(telefone);
                    usuarioModificado = true; 
                    break;
                default:
                    break;
                }

            }while(escolha!=0);
        }
    }

    if(usuarioModificado){
        ofstream ofUsuarios;
        ofUsuarios.open("../BancoDeDados/Usuarios.txt",ios_base::out);
        if(ofUsuarios.is_open()){
            for(auto it=usuarios.begin() ; it!=usuarios.end() ; it++){
                ofUsuarios << it->getId() << endl;
                ofUsuarios << it->getNome() << endl;
                ofUsuarios << it->getCpf() << endl;
                ofUsuarios << it->getEndereco() << endl;
                ofUsuarios << it->getTelefone() << endl;
            }
        }
    }else if(usuarioEncontrado==false){
        cout << "Usuario não Encontrado em nossa base de dados" << endl;
    }
    
}


/***LIVROS*/

void Biblioteca::menuLivros(vector<Livro> &livros){
    int escolha;
    do{
        Biblioteca::mostraMenuSecundario();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            insereLivros(livros);
            break;
        case 2:
            encontraLivros(livros);
            break;
        case 3:
            excluiLivros(livros);
            break;
        case 4:
            listarLivros(livros);
            break;
        case 5:
            modificaLivros(livros);
            break;
        default:
            break;
        }
    }while(escolha!=0);

}

void Biblioteca::insereLivros(vector<Livro> &livros){
    string titulo,author;
    int numPaginas;
    int numCopiasDisponiveis;

    cout << "Titulo : ";
    getline(cin,titulo);
    cout << "Author : ";
    getline(cin,author);
    cout << "Número de Paginas : ";
    cin >> numPaginas;
    cout << "Numero de Copias Disponiveis : ";
    cin >> numCopiasDisponiveis;

    Livro livro(titulo,author,numPaginas,numCopiasDisponiveis);
    livros.push_back(livro);

    ofstream ofLivros;

    ofLivros.open("../BancoDeDados/Livros.txt",ios_base::app);

    if(ofLivros.is_open()){
        ofLivros << livro.getId() << endl;
        ofLivros << livro.getTitulo() << endl;
        ofLivros << livro.getAuthor() << endl;
        ofLivros << livro.getNumPaginas() << endl;
        ofLivros << livro.getNumCopiasDisponiveis() << endl;
        ofLivros.close();
        cout << "USUARIO CADASTRADO COM SUCESSO!" << endl;
        pause();
    }else{
        cout << "Não foi possivel abrir o arquivo Livros.txt" << endl;
        exit(0);
    }

}

void Biblioteca::encontraLivros(vector<Livro> &livros){
    int id;
    cout << "Digite o id do livro que deseja buscar : ";
    cin >> id;
    cin.get();

    for(auto it = livros.begin() ; it!=livros.end() ; it++){
        if(id == it->getId()){
            it->mostraLivro();
            pause();
            return;
        }
    }

    cout << "Usuario não Encontrado em nossa base de dados" << endl;
}

void Biblioteca::excluiLivros(vector<Livro> &livros){
    int id;
    cout << "Digite o id do livro que deseja buscar : ";
    cin >> id;
    cin.get();
    bool livroExcluido=false;
    bool livroEncontrado = false;

    for(auto it = livros.begin() ; it!=livros.end() ; it++){
        if(id == it->getId()){
            livroExcluido=true;
            livroEncontrado=true;
            livros.erase(it);
            break;
        }
    }

    if(livroExcluido){
        ofstream ofLivros;
        ofLivros.open("../BancoDeDados/Livros.txt",ios_base::out);
        if(ofLivros.is_open()){
            for(auto it=livros.begin() ; it!=livros.end() ; it++){
                ofLivros << it->getId() << endl;
                ofLivros << it->getTitulo() << endl;
                ofLivros << it->getAuthor() << endl;
                ofLivros << it->getNumPaginas() << endl;
                ofLivros << it->getNumCopiasDisponiveis() << endl;
                cout << "LIVRO EXCLUIDO COM SUCESSO!" << endl;
                pause();
            }
            ofLivros.close();
        }
    }else if(!livroEncontrado){
        cout << "Livro não Encontrado em nossa base de dados" << endl;
    }


}

void Biblioteca::listarLivros(vector<Livro> &livros){
    system("clear || cls");
    cout << "-----LISTA DE LIVROS-----" << endl;

    for(auto it = livros.begin() ; it!=livros.end() ; it++){
        cout << "-----------------------------" << endl; 
            it->mostraLivro();
        cout << "-----------------------------" << endl; 
    }
    cout << "-----FIM DA LISTA-----" << endl;
    pause();

}

void Biblioteca::modificaLivros(vector<Livro> &livros){
    int id;
    cout << "Id do Livro que deseja alterar : ";
    cin >> id;
    cin.get();
    int escolha;
    bool livroModificado = false;
    bool livroEncontrado = false;

    for(auto it = livros.begin() ; it!=livros.end() ; it++){
        if(id == it->getId()){
            livroEncontrado=true;
            string titulo,author;
            int numPaginas;
            int numCopiasDisponiveis;

            do{
                cout << "O que deseja alterar ? ";
                cout << "[1] Titulo" << endl;
                cout << "[2] Author " << endl;
                cout << "[3] Numero de Paginas " << endl;
                cout << "[4] Numero de Copias " << endl;
                cout << "[0] Sair" << endl; 
                cin >> escolha;

                switch (escolha)
                {
                case 1:
                    cout << "Novo Titulo : " ;
                    getline(cin,titulo);
                    it->setTitulo(titulo);
                    livroModificado = true;
                    break;
                case 2:
                    cout << "Novo Author : " ;
                    getline(cin,author);
                    it->setAuthor(author);
                    livroModificado = true;
                    break;
                case 3:
                    cout << "Numero de Paginas : " ;
                    cin >> numPaginas;
                    cin.get();
                    it->setNumPaginas(numPaginas);
                    livroModificado = true;
                    break;
                case 4:
                    cout << "Numero de Copias : " ;
                    cin >> numCopiasDisponiveis;
                    cin.get();
                    it->setNumCopiasDisponiveis(numCopiasDisponiveis);
                    livroModificado = true;
                    break;
                default:
                    break;
                }

            }while(escolha!=0);
        }
    }

    if(livroModificado){
        ofstream ofLivros;
        ofLivros.open("../BancoDeDados/Livros.txt",ios_base::out);
        if(ofLivros.is_open()){
            for(auto it=livros.begin() ; it!=livros.end() ; it++){
                ofLivros << it->getId() << endl;
                ofLivros << it->getTitulo() << endl;
                ofLivros << it->getAuthor() << endl;
                ofLivros << it->getNumPaginas() << endl;
                ofLivros << it->getNumCopiasDisponiveis() << endl;
            }
        }
    }else if(!livroEncontrado){
        cout << "Livro não Encontrado em nossa base de dados" << endl;
    }



}


/**ALUGUEIS*/


void Biblioteca::menuAlugueis(vector<Aluguel> &alugueis,vector<Usuario> &usuarios,vector<Livro> &livros){
    int escolha;
    do{
        Biblioteca::mostraMenuAluguel();
        cin >> escolha;
        cin.get();
        switch (escolha)
        {
        case 1:
            insereAluguel(alugueis,usuarios,livros);
            break;
        case 2:
            encontraAluguel(alugueis);
            break;
        case 3:
            finalizaAluguel(alugueis);
            break;
        case 4:
            listaAluguelAtivo(alugueis);
            break;
        case 5:
            listaAluguelInativo(alugueis);
            break;
        case 6:
            listaAluguelPorCliente(alugueis);
            break;
        default:
            break;
        }
    }while(escolha!=0);

}

void Biblioteca::mostraMenuAluguel(){
    system("clear || cls");
    cout << "-------MENU-------" << endl;
    cout << "[1] INSERIR :" << endl;
    cout << "[2] ESCONTRAR :" << endl;
    cout << "[3] FINALIZAR :" << endl;
    cout << "[4] LISTAR ATIVOS :" << endl;
    cout << "[5] LISTAR INATIVOS: " << endl;
    cout << "[6] LISTAR POR CLIENTE: " << endl;
    cout << "[0] SAIR" << endl;
    cout << "Escolha : ";
}

void Biblioteca::insereAluguel(vector<Aluguel> &alugueis,vector<Usuario> &usuarios,vector<Livro> &livros){
    system("clear || cls");
    int idUsuario;
    bool encontrouUsuario=false;


    /*Busca usuario*/
    Usuario* usuario;
    cout << "Insira id do usuario : ";
    cin >> idUsuario;
    cin.get();
    for(auto it=usuarios.begin() ; it!=usuarios.end() ; it++){
        if(it->getId() == idUsuario){
            encontrouUsuario=true;
            usuario = &(*it);
            break;
        }
    }
    if(!encontrouUsuario){
        cout << "Usuario não encontrado em nossa base de dados!" << endl;
        pause();
        return;
    }


    /*Busca livro*/
    bool encontrouLivro=false;
    Livro* livro;
    int idLivro;
    cout << "Insira id do livro : ";
    cin >> idLivro;
    cin.get();
    for(auto it=livros.begin() ; it!=livros.end() ; it++){
        if(it->getId() == idLivro){
            encontrouLivro=true;
            livro = &(*it);
            break;
        }
    }
    if(!encontrouLivro){
        cout << "Livro não encontrado em nossa base de dados!" << endl;
        pause();
        return;
    }

    if(livro->getNumCopiasDisponiveis() == 0){
        cout << "Esse livro não possui copias disponiveis" << endl;
        return;
    }else{
        livro->setNumCopiasDisponiveis(livro->getNumCopiasDisponiveis()-1);

        ofstream ofLivros;
        ofLivros.open("../BancoDeDados/Livros.txt",ios_base::out);
        if(ofLivros.is_open()){
            for(auto it=livros.begin() ; it!=livros.end() ; it++){
                ofLivros << it->getId() << endl;
                ofLivros << it->getTitulo() << endl;
                ofLivros << it->getAuthor() << endl;
                ofLivros << it->getNumPaginas() << endl;
                ofLivros << it->getNumCopiasDisponiveis() << endl;
            }
            ofLivros.close();
        }
    }

    time_t tempoAtual = time(nullptr);
    Data* dataInicio = localtime(&tempoAtual);
    dataInicio->tm_mon +=1;
    dataInicio->tm_year +=1900;

    Aluguel aluguel(true,usuario,livro,*dataInicio);
    alugueis.push_back(aluguel);

    ofstream ofAlugueis;
    ofAlugueis.open("../BancoDeDados/Alugueis.txt",ios_base::app);
    if(ofAlugueis.is_open()){
        ofAlugueis << aluguel.getId() << endl;
        ofAlugueis << aluguel.getUsuario()->getId() << endl;
        ofAlugueis << aluguel.getLivro()->getId() << endl;
        ofAlugueis << aluguel.getDataInicio().tm_mday << endl;
        ofAlugueis << aluguel.getDataInicio().tm_mon << endl;
        ofAlugueis << aluguel.getDataInicio().tm_year << endl;
        ofAlugueis << aluguel.getAtivo() << endl;
        ofAlugueis.close();
    }else{
        cout << "Não foi possivei abrir o arquivo Alugueis.txt" << endl;
        exit(0);
    }


}

void Biblioteca::encontraAluguel(vector<Aluguel> &alugueis){
    system("clear || cls");
    int idUsuario,idLivro;
    cout << "Insira id do usuario : ";
    cin >> idUsuario;
    cin.get();
    cout << "Insira id do livro : ";
    cin >> idLivro;
    cin.get();

    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getUsuario()->getId() == idUsuario && it->getLivro()->getId()==idLivro && it->getAtivo()){
            it->mostraAluguel();
            pause();
            return;
        }
    }
    cout << "Não foi encontrado um aluguel ativo para essas credenciais" << endl;
}

void Biblioteca::finalizaAluguel(vector<Aluguel> &alugueis){
    system("clear || cls");
    int idUsuario,idLivro;
    cout << "Insira id do usuario : ";
    cin >> idUsuario;
    cin.get();
    cout << "Insira id do livro : ";
    cin >> idLivro;
    cin.get();

    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getUsuario()->getId() == idUsuario && it->getLivro()->getId()==idLivro && it->getAtivo()){
            it->setAtivo(false);
            cout << "Aluguel finalizado com sucesso!" << endl;
            ofstream inAlugueis;
            inAlugueis.open("../BancoDeDados/Alugueis.txt",ios_base::out);
            if(inAlugueis.is_open()){
                for(auto it=alugueis.begin(); it!= alugueis.end() ; it++){
                    inAlugueis << it->getId() << endl;
                    inAlugueis << it->getUsuario()->getId() << endl;
                    inAlugueis << it->getLivro()->getId() << endl;
                    inAlugueis << it->getDataInicio().tm_mday << endl;
                    inAlugueis << it->getDataInicio().tm_mon << endl;
                    inAlugueis << it->getDataInicio().tm_year << endl;
                    inAlugueis << it->getAtivo() << endl;
                }
                inAlugueis.close();
            }
            pause();
            return;
        }
    }
    cout << "Não foi encontrado um aluguel ativo para essas credenciais" << endl;
}

void Biblioteca::listaAluguelAtivo(vector<Aluguel> &alugueis){
    system("clear || cls");
    cout << "----------LISTA DE ALUGUEIS ATIVOS----------" << endl;
    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getAtivo()){
            it->mostraAluguel();
            cout << "----------------------------------" << endl;
        }
    }
    cout << "----------FIM DA LISTA----------" << endl;
    pause();
}

void Biblioteca::listaAluguelInativo(vector<Aluguel> &alugueis){
    system("clear || cls");
    cout << "----------LISTA DE ALUGUEIS INATIVOS----------" << endl;
    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(!it->getAtivo()){
            it->mostraAluguel();
            cout << "----------------------------------" << endl;
        }
    }
    cout << "----------FIM DA LISTA----------" << endl;
    pause();
}

void Biblioteca::listaAluguelPorCliente(vector<Aluguel> &alugueis){
    system("clear || cls");
    int idUsuario;
    cout << "Insira id do usuario : ";
    cin >> idUsuario;
    cin.get();
    bool clienteEncontrado = false;
    cout << "----------LISTA DE ALUGUEIS----------" << endl;
    for(auto it=alugueis.begin() ; it!=alugueis.end() ; it++){
        if(it->getUsuario()->getId() == idUsuario && it->getAtivo()){
            clienteEncontrado=true;
            it->mostraAluguel();
            cout << "----------------------------------" << endl;
        }
    }
    cout << "----------FIM DA LISTA----------" << endl;
    if(!clienteEncontrado){
        cout << "Não foi encontrado um aluguel ativo para essas credenciais" << endl;
    }
    pause();
}
