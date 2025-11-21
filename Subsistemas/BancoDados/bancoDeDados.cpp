#include "bancoDeDados.hpp"
using namespace std;

void criarTabelas(sqlite3* bancoDados){
    char* erro = nullptr;

    string sql = "CREATE TABLE gerente("
                      "nome TEXT, "
                      "email TEXT PRIMARY KEY, "
                      "ramal INTEGER UNIQUE, "
                      "senha TEXT"
                      ")";
    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao == SQLITE_ERROR)
        return;
    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
    }

    sql = "CREATE TABLE IF NOT EXISTS hospede("
                      "nome TEXT, "
                      "email TEXT PRIMARY KEY, "
                      "endereco TEXT, "
                      "cartao TEXT"
                      ")";

    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = "CREATE TABLE IF NOT EXISTS hotel("
                      "nome TEXT, "
                      "endereco TEXT, "
                      "telefone TEXT, "
                      "codigo TEXT PRIMARY KEY"
                      "responsavel TEXT, "
                      "FOREIGN KEY (responsavel)"
                        "REFERENCES gerente(email) "
                        "ON DELETE CASCADE"
                      ")";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = "CREATE TABLE IF NOT EXISTS quarto ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "numero INTEGER, "
                      "capacidade INTEGER, "
                      "diaria REAL, "
                      "ramal INTEGER, "
                      "codigo_hotel TEXT, "
                      "FOREIGN KEY (codigo_hotel) "
                         "REFERENCES hotel(codigo) "
                         "ON DELETE CASCADE, "
                      "UNIQUE (codigo_hotel, numero)"
                      ")";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = "CREATE TABLE IF NOT EXISTS reserva ("
                      "chegada TEXT, "
                      "partida TEXT, "
                      "valor REAL, "
                      "codigo TEXT PRIMARY KEY, "
                      "quarto_id INTEGER UNIQUE, "
                      "hospede_email TEXT, "
                      "FOREIGN KEY (quarto_id)"
                         "REFERENCES quarto(id)"
                         "ON DELETE CASCADE, "
                      "FOREIGN KEY (hospede_email) "
                         "REFERENCES hospede(email) "
                         "ON DELETE CASCADE"
                      ")";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = R"(
             CREATE TRIGGER IF NOT EXISTS evitarEmailDuplicadoGerente
             BEFORE INSERT OR UPDATE ON hospede
             FOR EACH ROW
             BEGIN
                SELECT CASE
                    WHEN EXISTS (SELECT 1 FROM gerente WHERE email = NEW.email)
                    THEN RAISE (ABORT, 'Esse email ja esta em uso')
                END
             END
             )";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    sql = R"(
             CREATE TRIGGER IF NOT EXISTS evitarEmailDuplicadoHospede
             BEFORE INSERT OR UPDATE ON gerente
             FOR EACH ROW
             BEGIN
                SELECT CASE
                    WHEN EXISTS (SELECT 1 FROM hospede WHERE email = NEW.email)
                    THEN RAISE (ABORT, 'Esse email ja esta em uso')
                END
              END
              )";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    sql = R"(
             CREATE TRIGGER IF NOT EXISTS evitarCodigoDuplicadoReserva
             BEFORE INSERT OR UPDATE ON Hotel
             FOR EACH ROW
             BEGIN
                SELECT CASE
                    WHEN EXISTS (SELECT 1 FROM reserva WHERE codigo = NEW.codigo)
                    THEN RAISE (ABORT, 'Esse codigo ja esta em uso')
                END
             END
             )";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    sql = R"(
             CREATE TRIGGER IF NOT EXISTS evitarCodigoDuplicadoHotel
             BEFORE INSERT OR UPDATE ON hospede
             FOR EACH ROW
             BEGIN
                SELECT CASE
                    WHEN EXISTS (SELECT 1 FROM hotel WHERE codigo = NEW.codigo)
                    THEN RAISE (ABORT, 'Esse codigo ja esta em uso')
                END
             END
             )";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);
}

bancoDeDados::bancoDeDados(){

    if (sqlite3_open("hotelaria", &bancoDados)) {
        cerr << "Erro ao abrir o banco: " << sqlite3_errmsg(bancoDados) << endl;
        bancoDados = nullptr;
    } else {
        cout << "Banco de dados aberto com sucesso.\n";
    }
    criarTabelas(bancoDados);
}

bancoDeDados::~bancoDeDados(){
    if(bancoDados){
        sqlite3_close(bancoDados);
        cout << "Conexao com o banco encerrada.\n";
    }
}


//CRIACAO -----------------------------------------------------------------

bool bancoDeDados::criarGerente(Gerente& gerente){
    string nome, email, senha;
    int ramal;
    char* erro = nullptr;

    nome = gerente.getGerenteNome();
    email = gerente.getGerenteEmail();
    senha = gerente.getSenha();
    ramal = gerente.getRamal();

    string sql = "INSERT INTO gerente (nome, email, ramal, senha)"
          "VALUES ('"+ nome +"','"+ email +"',"+ to_string(ramal) +",'"+ senha +"');";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);
    if (execucao != SQLITE_OK){
        cerr << "Erro ao criar " << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}

bool bancoDeDados::criarHospede(Hospede& hospede){
    string nome, email, endereco, cartao;
    char* erro = nullptr;

    nome = hospede.getNome();
    email = hospede.getEmail();
    endereco = hospede.getEndereco();
    cartao = hospede.getCartao();

    string sql ="INSERT INTO hospede (nome, email, endereco, cartao)"
                "VALUES ('"+ nome +"','"+ email +"','"+ endereco +"','"+ cartao +"');";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cerr << "Erro ao criar " << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}

bool bancoDeDados::criarReserva(Reserva& reserva, int idQuarto, string emailHospede){
    string chegada, partida, codigo;
    int quarto_id = idQuarto;
    double valor;
    char* erro = nullptr;
    string datas;

    datas = reserva.getChegada();
    if(datas.size() == 10){
        chegada = "0" + reserva.getChegada();
    } else {
        chegada = reserva.getChegada();
    }
    datas = reserva.getPartida();
    if(datas.size() == 10){
        partida = "0" + reserva.getPartida();
    } else {
        partida = reserva.getPartida();
    }
    valor = reserva.getValor();
    codigo = reserva.getCodigo();

    string sql ="INSERT INTO reserva (chegada, partida, valor, codigo, quarto_id, hospede_email)"
                "VALUES ('"+ chegada +"','"+ partida +"'," + to_string(valor) +",'"+ codigo +"',"+ to_string(quarto_id) +",'"+ emailHospede +"');";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK) {
        cerr << "Erro ao criar " << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}

bool bancoDeDados::criarQuarto(Quarto& quarto, string codigoHotel){
    int numero, capacidade, ramal;
    double diaria;
    char* erro = nullptr;

    numero = quarto.getNumero();
    capacidade = quarto.getCapacidade();
    diaria = quarto.getDiaria();
    ramal = quarto.getRamal();

    string sql ="INSERT INTO quarto (numero, capacidade, diaria, ramal, codigo_hotel)"
                "VALUES ("+ to_string(numero) +","+ to_string(capacidade) +","+ to_string(diaria) +","+ to_string(ramal) +",'"+ codigoHotel +"');";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK) {
        cerr << "Erro ao criar" << endl;
    }
    if (execucao == SQLITE_CONSTRAINT) {
        cerr << "O hotel informado ja possui um quarto com esse numero " << endl;
        return false;
    }
    return true;
}

bool bancoDeDados::criarHotel(Hotel& hotel, string& responsavel){
    string nome, endereco, telefone, codigo;
    char* erro = nullptr;

    nome = hotel.getNome().getNome();
    endereco = hotel.getEndereco().getEndereco();
    telefone = hotel.getTelefone().getTelefone();
    codigo = hotel.getCodigo().getValor();

    string sql ="INSERT INTO hotel (nome, endereco, telefone, codigo, responsavel)"
                "VALUES ('"+ nome +"', '"+ endereco +"', '"+ telefone +"', '"+ codigo +"','"+ responsavel +"');";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK) {
        cerr << "Erro ao criar " << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}


//LEITURA ---------------------------------------------------------------------------------------------

void bancoDeDados::listarTodos(const string tabela){
    string sql = "SELECT * FROM "+ tabela +";";
    char* erro = nullptr;

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), mostrar, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cerr << "Erro ao consultar dados  " << erro << endl;
        sqlite3_free(erro);
    }
}

void bancoDeDados::listarComFiltro(const string tabela, const string tipoChave, const string chave){
    char* erro = nullptr;
    string sql;

    if (tipoChave != "quarto"){
        sql = "SELECT * FROM "+ tabela +" WHERE "+ tipoChave +" = '"+ chave +"';";
    } else {
        sql = "SELECT * FROM "+ tabela +" WHERE "+ tipoChave +" = "+ chave +";";
    }

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), mostrar, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cerr << "Erro ao consultar dados  " << erro << endl;
        sqlite3_free(erro);
    }
}

string bancoDeDados::getSenha(const string& email){
    string sql = "SELECT * FROM gerente WHERE email = '"+ email +"';";
    vector<string> dados;

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), pegarLinha, &dados, nullptr);

    if(dados.size() == 0){
        return "404";
    } else {
        return dados[3];
    }
}


//EDICAO --------------------------------------------------------------------------------------------

void bancoDeDados::montarGerente(Gerente& gerente){
    string email = gerente.getGerenteEmail();
    vector<string> dados;

    string sql = "SELECT * FROM gerente WHERE email = '"+ email +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), pegarLinha, &dados , nullptr);
    string ramal = dados[2];
    int ramalInt = stoi(ramal);

    gerente.setNome(dados[0]);
    gerente.setEmail(dados[1]);
    gerente.setRamal(ramalInt);
    gerente.setSenha(dados[3]);

    return;
}

void bancoDeDados::montarHospede(Hospede& hospede){
    string email = hospede.getEmail();
    vector<string> dados;

    string sql = "SELECT * FROM hospede WHERE email = '"+ email +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), pegarLinha, &dados , nullptr);

    hospede.setNome(dados[0]);
    hospede.setEmail(dados[1]);
    hospede.setEndereco(dados[2]);
    hospede.setCartao(dados[3]);

    return;
}

void bancoDeDados::montarReserva(Reserva& reserva){
    string codigo = reserva.getCodigo();
    vector<string> dados;

    string sql = "SELEC * FROM reserva WHERE codigo = '"+ codigo +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), pegarLinha, &dados , nullptr);

    string data = dados[0];
    string dia, mes, ano;

    dia = data[0] + data[1];
    mes = data[3] + data[4] + data[5];
    ano = data[7] + data[8] + data[9] + data[10];
    int diaInt = stoi(dia), anoInt = stoi(ano);

    Data chegada(diaInt, mes, anoInt);
    reserva.setChegada(chegada);

    data = dados[1];

    dia = data[0] + data[1];
    mes = data[3] + data[4] + data[5];
    ano = data[7] + data[8] + data[9] + data[10];
    diaInt = stoi(dia), anoInt = stoi(ano);

    Data partida(diaInt, mes, anoInt);
    reserva.setPartida(partida);

    reserva.setValorDinheiro(stod(dados[2]));
    reserva.setCodigo(dados[3]);

    return;
}

void bancoDeDados::montarQuarto(Quarto& quarto, int ID){
    int id = ID;
    vector<string> dados;

    string sql = "SELECT * FROM quarto WHERE id = "+ to_string(id) +";";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), pegarLinha, &dados , nullptr);

    quarto.setNumero(stoi(dados[1]));
    quarto.setCapacidade(stoi(dados[2]));
    quarto.setDiaria(dados[3]);
    quarto.setRamal(stoi(dados[4]));
}

void bancoDeDados::montarHotel(Hotel& hotel){
    string codigo = hotel.getCodigo().getValor();
    vector<string> dados;

    string sql = "SELECT * FROM quarto WHERE codigo = '"+ codigo +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), pegarLinha, &dados , nullptr);

    string telefone = dados[2].substr(1);

    hotel.setNome(dados[0]);
    hotel.setEndereco(dados[1]);
    hotel.setTelefone(telefone);
    hotel.setCodigo(dados[3]);

    return;
}

void bancoDeDados::editarGerente(Gerente& gerente, string& emailReferencia){
    string nome, email, ramal, senha;
    int ramalInt = gerente.getRamal();

    nome = gerente.getGerenteNome();
    email = gerente.getGerenteEmail();
    ramal = to_string(ramalInt);
    senha = gerente.getSenha();

    string sql= "UPDATE gerente"
                "SET nome = '"+ nome +"',"
                    "email = '"+ email +"',"
                    "ramal = "+ ramal +","
                    "senha = '"+ senha +"'"
                "WHERE email = '"+ emailReferencia +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    if (execucao != SQLITE_OK){
        cout << "Erro ao atualizar." <<  endl;
    } else {
        cout << "Atualizado com sucesso!" << endl;
    }
}

void bancoDeDados::editarHospede(Hospede& hospede, string& emailReferencia){
    string nome, email, endereco, cartao;

    nome = hospede.getNome();
    email = hospede.getEmail();
    endereco = hospede.getEndereco();
    cartao = hospede.getCartao();

    string sql= "UPDATE hospede"
                "SET nome = '"+ nome +"',"
                    "email = '"+ email +"',"
                    "endereco = '"+ endereco +"',"
                    "cartao = '"+ cartao +"'"
                "WHERE email = '"+ emailReferencia +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    if (execucao != SQLITE_OK){
        cout << "Erro ao atualizar." <<  endl;
    } else {
        cout << "Atualizado com sucesso!" << endl;
    }
}

void bancoDeDados::editarReserva(Reserva& reserva, string& codigoReferencia){
    string chegada, partida, valor, codigo;
    double valorNum = reserva.getValor();
    string datas;

    datas = reserva.getChegada();
    if(datas.size() == 10){
        chegada = "0" + reserva.getChegada();
    } else {
        chegada = reserva.getChegada();
    }
    datas = reserva.getPartida();
    if(datas.size() == 10){
        partida = "0" + reserva.getPartida();
    } else {
        partida = reserva.getPartida();
    }
    valor = to_string(valorNum);
    codigo = reserva.getCodigo();

    string sql= "UPDATE reserva"
                "SET chegada = '"+ chegada +"',"
                    "partida = '"+ partida +"',"
                    "valor = "+ valor +","
                    "codigo = '"+ codigo +"'"
                "WHERE codigo = '"+ codigoReferencia +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    if (execucao != SQLITE_OK){
        cout << "Erro ao atualizar." <<  endl;
    } else {
        cout << "Atualizado com sucesso!" << endl;
    }
}

void bancoDeDados::editarQuarto(Quarto& quarto, int ID){
    string numero, capacidade, diaria, ramal, id;
    int numeroInt, capacidadeInt, ramalInt;
    double diariaNum;

    id = to_string(ID);

    numeroInt = quarto.getNumero();
    capacidadeInt = quarto.getCapacidade();
    diariaNum = quarto.getDiaria();
    ramalInt = quarto.getRamal();

    numero = to_string(numeroInt);
    capacidade = to_string(capacidadeInt);
    diaria = to_string(diariaNum);
    ramal = to_string(ramalInt);

    string sql= "UPDATE quarto"
                "SET numero = "+ numero +","
                    "capacidade = "+ capacidade +","
                    "diaria = "+ diaria +","
                    "ramal = "+ ramal +""
                "WHERE id = "+ id +";";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    if (execucao != SQLITE_OK){
        cout << "Erro ao atualizar." <<  endl;
    } else {
        cout << "Atualizado com sucesso!" << endl;
    }
}

void bancoDeDados::editarHotel(Hotel& hotel, string& codigoReferencia){
    string nome, endereco, telefone, codigo;

    nome = hotel.getNome().getNome();
    endereco = hotel.getEndereco().getEndereco();
    telefone = hotel.getTelefone().getTelefone();
    codigo = hotel.getCodigo().getValor();

    string sql= "UPDATE hotel"
                "SET nome = '"+ nome +"',"
                    "endereco = '"+ endereco +"',"
                    "telefone = '"+ telefone +"',"
                    "codigo = '"+ codigo +"'"
                "WHERE codigo = '"+ codigoReferencia +"';";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);

    if (execucao != SQLITE_OK){
        cout << "Erro ao atualizar." <<  endl;
    } else {
        cout << "Atualizado com sucesso!" << endl;
    }
}


//DELETAR -------------------------------------------------------------------------------------

void bancoDeDados::apagarTodos(const string tabela){
    string sql = "DELETE FROM "+ tabela +";";
    char* erro = nullptr;

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao == SQLITE_OK) {
        cout << "Dados apagados com sucesso!" << endl;
    } else {
        cout << "Não foi possível apagar os dados " << erro << endl;
    }
    return;
}

void bancoDeDados::apagarUm(const string tabela, const string tipoChave, const string& chave){
    string sql = "DELETE FROM "+ tabela +" WHERE "+ tipoChave +" = "+ chave +";";
    char* erro = nullptr;

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao == SQLITE_OK) {
        cout << "Dados apagados com sucesso!" << endl;
    } else {
        cout << "Nao foi possivel apagar os dados " << erro << endl;
    }
    return;
}

void bancoDeDados::apagarTabela(const string tabela){
    string sql = "DROP TABLE IF EXISTS "+ tabela +";";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, nullptr);
    cout << "A tabela " << tabela << " foi apagada!" << endl;
    return;
}


//CALLBACK ----------------------------------------------------------------------------------

int bancoDeDados::pegarLinha(void* dado, int argc, char** argv, char** colNames) {

    auto* resultado = static_cast<vector<string>*>(dado);

    resultado->clear();

    for (int i = 0; i < argc; i++) {
        resultado->push_back(argv[i]);
    }

    return 0;
}

int bancoDeDados::mostrar(void* NaoUsado, int qtdCol, char** valor, char** nomeCol) {
    for (int i = 0; i < qtdCol; i++) {
        if (string(nomeCol[i]) != "senha" && string(nomeCol[i]) != "quarto_id" && string(nomeCol[i]) != "hospede_email" && string(nomeCol[i]) != "codigo_hotel"){
            if(string(nomeCol[i]).size() < 6){
                cout << nomeCol[i] << " =\t\t" << valor[i] << endl;
            } else {
                cout << nomeCol[i] << " =\t" << valor[i] << endl;
            }
        }
    }
    cout << endl;
    return 0;
}
