#include "controladora.hotel.hpp"
#include <iostream>
#include <limits>
#include <string>

void opcoesHotel(){
    while(1){
        limparTela();
        cout << "\n================================" << endl;
        cout << "          OPCOES HOTEL         " << endl;
        cout << "================================" << endl;
        cout << "[1] Criar hotel\n";
        cout << "[2] Visualizar hoteis\n";
        cout << "[3] Editar hotel\n";
        cout << "[4] Excluir hotel\n";
        cout << "[5] Sair\n";
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                validarCriarHotel();
                break;

            case 2:
                mostrarHoteis();
                break;

            case 3:
                editarHotel();
                break;

            case 4:
                excluirHotel();
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

void validarCriarHotel(){
    string nome, endereco, telefone, codigo, responsavel;
    maHotel maNovoHotel;
    msHotel msNovoHotel;

    while(1){
        limparTela();

        cout << "================================" << endl;
        cout << "          Criar  Hotel          " << endl;
        cout << "================================" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Endereco: ";
        getline(cin, endereco);
        cout << "Telefone: ";
        getline(cin, telefone);
        cout << "Codigo: ";
        getline(cin, codigo);
        cout << "Email do responsavel: ";
        getline(cin, responsavel);
        cout << endl << endl;

        if(maNovoHotel.validarCriar(nome, endereco, telefone, codigo)){
            Nome nomeHotel(nome); Endereco enderecoHotel(endereco); Telefone telefoneHotel(telefone); Codigo codigoHotel(codigo);
            Hotel hotelCriado(nomeHotel, enderecoHotel, telefoneHotel, codigoHotel);
            if (msNovoHotel.criarHotel(hotelCriado, responsavel)){
                cout << "Hotel criado com sucesso!" << endl;
                esperar(3);
                return;
            }
            cout << "Nao foi possivel criar o Hotel" << endl;
            esperar(3);
            return;
        }else{
            cout << "\n==================================" << endl;
            cout << " Falha na validacao. Tente novamente." << endl;
            cout << "==================================" << endl;
            esperar(2);
        }
    }
}

void editarHotel(){
    maHotel maEdicaoHotel;
    msHotel msEdicaoHotel;

    limparTela();
    mostrarHoteis();
    string codigo;
    cout << "\n=========================================" << endl;
    cout << "\nDigite o codigo do hotel a ser editado: " << endl;
    getline(cin, codigo);

    Nome nomeHotel("Qualquer um");
    Endereco enderecoHotel("Qualquer Lugar");
    Telefone telefoneHotel("1234567890123");
    Codigo codigoHotel(codigo);
    Hotel hotelEdicao(nomeHotel, enderecoHotel, telefoneHotel, codigoHotel);
    string nulo = "0";
    msEdicaoHotel.updateHotel(hotelEdicao, nulo);

    while(1){

        limparTela();
        cout << "\n==================================" << endl;
        cout << "          Editar dados      " << endl;
        cout << "==================================" << endl;
        cout << "[1] Nome: " << hotelEdicao.getNome().getNome() << endl;
        cout << "[2] Endereco: " << hotelEdicao.getEndereco().getEndereco() << endl;
        cout << "[3] Telefone: " << hotelEdicao.getTelefone().getTelefone() << endl;
        cout << "[4] Codigo: " << hotelEdicao.getCodigo().getValor() << endl;
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
            cout << "Digite o novo nome: ";
            getline(cin, novoDado);
            try{
                if(maEdicaoHotel.validarEditar(novoDado, "nome")){
                    nomeHotel.setNome(novoDado);
                    hotelEdicao.setNome(nomeHotel);
                }
            } catch (exception& erro){
                cout << erro.what() << endl;
                esperar(2);
            }
        }
        else if(tipoDado == 2){
                cout << "Digite o novo endereco: ";
                getline(cin, novoDado);
            if(maEdicaoHotel.validarEditar(novoDado, "endereco")){
                enderecoHotel.setEndereco(novoDado);
                hotelEdicao.setEndereco(enderecoHotel);
            }
        }
        else if (tipoDado == 3){
            cout << "Digite o novo telefone: ";
            getline(cin, novoDado);
            if(maEdicaoHotel.validarEditar(novoDado, "telefone")){
                telefoneHotel.setTelefone(novoDado);
                hotelEdicao.setTelefone(telefoneHotel);
            }
        }
        else if(tipoDado == 4){
            cout << "Digite o novo codigo: ";
            getline(cin, novoDado);
            if(maEdicaoHotel.validarEditar(novoDado, "codigo")){
                codigoHotel.setValor(novoDado);
                hotelEdicao.setCodigo(codigoHotel);
            }
        }
        else if(tipoDado == 5){
            msEdicaoHotel.updateHotel(hotelEdicao, codigo);
            return;
        }

    }
}

void mostrarHoteis(){
    msHotel listaHoteis;

    listaHoteis.listarHotel();

    return;
}

void excluirHotel(){
    maHotel maExcluir;
    msHotel msExcluir;
    int opcao;

    while(1){

        limparTela();
        cout << "========================================" << endl;
        cout << "             Excluir   Hotel      " << endl;
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
            cout << "\nDigite o codigo do hotel que deseja excluir:\n-> ";
            string codigo;
            getline(cin, codigo);

            if(maExcluir.validarEditar(codigo, "codigo")){
                while(1){
                    cout << "\n==================================" << endl;
                    cout << "ATENCAO: Esta acao eh irreversivel.\nConfirmar exclusao? [s/n]\n-> ";
                    string confirmacao;
                    getline(cin, confirmacao);
                    std::transform(confirmacao.begin(), confirmacao.end(), confirmacao.begin(),
                               [](unsigned char c){ return std::tolower(c); });

                    if(confirmacao == "s"){
                        msExcluir.apagarHotel(codigo);
                        return;
                    }else if (confirmacao == "n"){
                        cout << "Acao cancelada.\nVoltando ao menu Gerente.." << endl;
                        esperar(3);
                        return;
                    }
                }
            }else{
                cout << "E-mail invalido!" << endl;
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
                    msExcluir.apagarHoteis();
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
