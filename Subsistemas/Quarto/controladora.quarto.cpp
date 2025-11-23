#include "controladora.quarto.hpp"


void opcoesQuarto(){
    while(1){
        limparTela();
        cout << "\n================================" << endl;
        cout << "          OPCOES QUARTO         " << endl;
        cout << "================================" << endl;
        cout << "[1] Criar quarto\n";
        cout << "[2] Visualizar quartos\n";
        cout << "[3] Editar quarto\n";
        cout << "[4] Excluir quarto\n";
        cout << "[5] Sair\n";
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                validarCriarQuarto();
                break;

            case 2:
                mostrarQuartos();
                break;

            case 3:
                editarQuarto();
                break;

            case 4:
                excluirQuarto();
                break;

            case 5:
                cout << "Saindo do sistema..." << endl;
                esperar(2);
                return;
            default:
                cout << "\n\n\n==================================" << endl;
                cout << "Opcao invalida!\nDigite um numero do menu." << endl;
                cout << "==================================" << endl;
                esperar(2);
            }
        }

    }

}

void validarCriarQuarto(){
    int numero, capacidade, ramal;
    string diaria, codigo;
    maQuarto maNovoQuarto;
    msQuarto msNovoQuarto;

    while(1){
    inicio:
        limparTela();

        cout << "================================" << endl;
        cout << "          Criar  Quarto          " << endl;
        cout << "================================" << endl;
        cout << "Numero: ";
        cin >> numero;
        if (cin.fail()){
            cout << "Valor invalido. Tente novamente." << endl;
            esperar(2);
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            goto inicio;
        }
        cout << "Capacidade: ";
        cin >> capacidade;
        if (cin.fail()){
            cout << "Valor invalido. Tente novamente." << endl;
            esperar(2);
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            goto inicio;
        }
        cout << "Diaria: ";
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin >> diaria;
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        cout << "Ramal: ";
        cin >> ramal;
        if (cin.fail()){
            cout << "Valor invalido. Tente novamente." << endl;
            esperar(2);
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            goto inicio;
        }
        cout << "Codigo do hotel: ";
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin >> codigo;
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << endl;

        if(maNovoQuarto.validarCriar(numero, capacidade, diaria, ramal, codigo)){
            Quarto quartoNovo(numero, capacidade, diaria, ramal);
            msNovoQuarto.criarQuarto(quartoNovo, codigo);
            return;
        }else{
            cout << "\n====================================" << endl;
            cout << "Falha na validacao. Tente novamente." << endl;
            cout << "====================================" << endl;
            esperar(2);
        }
    }
}

void mostrarQuartos(){
    msQuarto listarQuarto;
    maQuarto validar;
    string codigo;

    while(1){
        limparTela();
        cout << "\n================================" << endl;
        cout << "       Vizualizar   Quarto          " << endl;
        cout << "================================" << endl;
        cout << "[1] Ver todos os quartos" << endl;
        cout << "[2] Ver quartos do mesmo hotel" << endl;
        cout << "[3] Sair" << endl;
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                listarQuarto.listarQuarto();
                break;

            case 2:
                cout << "Digite o codigo do hotel de referencia\n->";
                getline(cin, codigo);
                if(validar.validarEditar(codigo, "codigo")){
                    esperar(2);
                    listarQuarto.listarQuartoFiltro(codigo);
                }
                break;

            case 3:
                cout << "Saindo.." << endl;;
                esperar(3);
                return;

            default:
                cout << "\n\n\n==================================" << endl;
                cout << "Opcao invalida!\nDigite um numero do menu." << endl;
                cout << "==================================" << endl;
                esperar(2);
            }
        }
    }
}

void editarQuarto(){
    int numero, capacidade, ramal;
    string diaria;

    maQuarto maEdicaoQuarto;
    msQuarto msEdicaoQuarto;

    limparTela();
    msEdicaoQuarto.listarQuarto();
    int ID;
    cout << "\n=========================================" << endl;
    cout << "\nDigite o ID do quarto a ser editado\n->";
    cin >> ID;

    Quarto quartoEdicao(1, 1, "200,00", 1);
    bool edicao = false;
    msEdicaoQuarto.updateQuarto(quartoEdicao, ID, edicao);
    edicao = true;

    while(1){

        limparTela();
        cout << "\n==================================" << endl;
        cout << "          Editar dados      " << endl;
        cout << "==================================" << endl;
        cout << "[1] Numero: " << quartoEdicao.getNumero() << endl;
        cout << "[2] Capacidade: " << quartoEdicao.getCapacidade() << endl;
        cout << "[3] Diaria: " << quartoEdicao.getDiaria() << endl;
        cout << "[4] Ramal: " << quartoEdicao.getRamal() << endl;
        cout << "[5] Salvar tudo e sair\n";
        cout << "==================================\n" << endl;
        cout << "-> Digite o numero do dado que deseja editar: ";
        int tipoDado;
        cin.clear();
        cin >> tipoDado;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "\n==================================\n" << endl;
        string novoDado;

        if(tipoDado == 1){
                cout << "Digite o novo numero: ";
                cin >> numero;
            if(maEdicaoQuarto.validarEditar(numero, "numero")){
                quartoEdicao.setNumero(numero);
            }
        }
        else if(tipoDado == 2){
                cout << "Digite a nova capacidade: ";
                cin >> capacidade;
            if(maEdicaoQuarto.validarEditar(capacidade, "capacidade")){
                quartoEdicao.setCapacidade(capacidade);
            }
        }
        else if (tipoDado == 3){
            cout << "Digite o novo valor: ";
            getline(cin, diaria);
            if(maEdicaoQuarto.validarEditar(diaria, "diaria")){
                quartoEdicao.setDiaria(diaria);
            }
        }
        else if(tipoDado == 4){
            cout << "Digite o novo ramal: ";
            cin >> ramal;
            if(maEdicaoQuarto.validarEditar(ramal, "ramal")){
                quartoEdicao.setRamal(ramal);
            }
        }
        else if(tipoDado == 5){
            msEdicaoQuarto.updateQuarto(quartoEdicao, ID, edicao);
            return;
        } else {
            cout << "Opcao invalida!" << endl;
            esperar(3);
        }

    }
}

void excluirQuarto(){
    maQuarto maExcluir;
    msQuarto msExcluir;
    int opcao, ID;

    while(1){

        limparTela();
        cout << "========================================" << endl;
        cout << "             Excluir   Quarto      " << endl;
        cout << "========================================" << endl;
        cout << "[1] Excluir um" << endl;
        cout << "[2] Excluir todos" << endl;
        cout << "[3] Sair" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma das opcoes: ";
        cin >> opcao;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcao == 1){
            cout << "\nDigite o ID do quarto que deseja excluir:\n-> ";
            cin >> ID;

            while(1){
                cout << "\n==================================" << endl;
                cout << "ATENCAO: Esta acao eh irreversivel.\nConfirmar exclusao? [s/n]\n-> ";
                string confirmacao;
                getline(cin, confirmacao);
                std::transform(confirmacao.begin(), confirmacao.end(), confirmacao.begin(),
                           [](unsigned char c){ return std::tolower(c); });

                if(confirmacao == "s"){
                    msExcluir.apagarQuarto(ID);
                    return;
                }else if (confirmacao == "n"){
                    cout << "Acao cancelada.\nVoltando ao menu Gerente.." << endl;
                    esperar(3);
                    return;
                }
            }
        }
        else if (opcao == 2){
            while(1){
                cout << "\n==================================" << endl;
                cout << "ATENCAO: Esta acao eh irreversivel.\nConfirmar exclusao? [s/n]\n-> ";
                string confirmacao;
                getline(cin, confirmacao);
                std::transform(confirmacao.begin(), confirmacao.end(), confirmacao.begin(),
                           [](unsigned char c){ return std::tolower(c); });

                if(confirmacao == "s"){
                    msExcluir.apagarQuartos();
                    return;
                }else if (confirmacao == "n"){
                    cout << "Acao cancelada.\nVoltando ao menu.." << endl;
                    esperar(3);
                    break;
                }
            }
        }
        else if (opcao == 3){
            cout << "Saindo.." << endl;
            esperar(3);
            return;
        } else {
            cout << "\n\n\n==================================" << endl;
            cout << "Opcao invalida!\nDigite um numero do menu." << endl;
            cout << "==================================" << endl;
            esperar(2);
        }
    }
}
