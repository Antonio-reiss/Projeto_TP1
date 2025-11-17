#include "bancoDeDados.hpp"
using namespace std;

void criarTabelas(sqlite3* bancoDados){
    char* erro = nullptr;

    string sql = "CREATE TABLE gerente("
                      "nome TEXT,"
                      "email TEXT PRIMARY KEY,"
                      "ramal INTEGER UNIQUE,"
                      "senha TEXT"
                      ")";
    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        return;
    }

    sql = "CREATE TABLE IF NOT EXISTS hospede("
                      "nome TEXT,"
                      "email TEXT PRIMARY KEY,"
                      "endereco TEXT,"
                      "cartao TEXT"
                      ")";

    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = "CREATE TABLE IF NOT EXISTS hotel("
                      "nome TEXT,"
                      "endereco TEXT,"
                      "telefone TEXT,"
                      "codigo TEXT PRIMARY KEY"
                      ")";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = "CREATE TABLE IF NOT EXISTS quarto ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT"
                      "numero INTEGER,"
                      "capacidade INTEGER,"
                      "diaria REAL,"
                      "ramal INTEGER"
                      "codigo_hotel TEXT"
                      "FOREIGN KEY (codigo_hotel)"
                         "REFERENCES hotel(codigo)"
                         "ON DELETE CASCADE"
                      ")";
    execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK){
        cout << "Erro SQLite: " << erro << endl;
        sqlite3_free(erro);
    }

    sql = "CREATE TABLE IF NOT EXISTS reserva ("
                      "chegada TEXT,"
                      "partida TEXT,"
                      "valor REAL,"
                      "codigo TEXT PRIMARY KEY"
                      "quarto_id INTEGER"
                      "hospede_email TEXT"
                      "FOREIGN KEY (quarto_id)"
                         "REFERENCES quarto(id)"
                         "ON DELETE CASCADE"
                      "FOREIGN KEY (hospede_email)"
                         "REFERENCES hospede(email)"
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

/*
bool bancoDeDados::executar(const string& sql){
    char* error = nullptr;
    int conexao = sqlite3_exec(bancoDados, sql.c_str(), mostrar, nullptr, &error);
    if (conexao != SQLITE_OK){
        cerr << "Erro ao executar SQL: " << error << endl;
        sqlite3_free(error);
        return false;
    }
    return true;
}*/

//---------------------------------------------------------------------------------------

int bancoDeDados::mostrar(void* NaoUsado, int qtdCol, char** valor, char** nomeCol) {
    for (int i = 0; i < qtdCol; i++) {
        cout << nomeCol[i] << " = " << (valor[i] ? valor[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}
//---------------------------------------------------------------------------------------

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

bool bancoDeDados::criarReserva(Reserva& reserva, int idQuarto){
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

    string sql ="INSERT INTO reserva (chegada, partida, valor, codigo, quarto_id)"
                "VALUES ('"+ chegada +"','"+ partida +"'," + to_string(valor) +",'"+ codigo +"',"+ to_string(quarto_id) +");";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK) {
        cerr << "Erro ao criar " << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}

bool bancoDeDados::criarQuarto(Quarto& quarto, string& codigoHotel){
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
        cerr << "Erro ao criar " << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}

bool bancoDeDados::criarHotel(Hotel& hotel){
    string nome, endereco, telefone, codigo;
    char* erro = nullptr;

    nome = hotel.getNome().getNome();
    endereco = hotel.getEndereco().getEndereco();
    telefone = hotel.getTelefone().getTelefone();
    codigo = hotel.getCodigo().getValor();

    string sql ="INSER INTO hotel (nome, endereco, telefone, codigo)"
                "VALUES ('"+ nome +"', '"+ endereco +"', '"+ telefone +"', '"+ codigo +"');";

    int execucao = sqlite3_exec(bancoDados, sql.c_str(), nullptr, nullptr, &erro);

    if (execucao != SQLITE_OK) {
        cerr << "Erro ao criar" << erro << endl;
        sqlite3_free(erro);
        return false;
    }
    return true;
}

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

    hotel.setNome(dados[0]);
    hotel.setEndereco(dados[1]);
    hotel.setTelefone(dados[2]);
    hotel.setCodigo(dados[3]);

    return;
}

/*
void montarGerente(Gerente&);
void montarHospede(Hospede&);
void montarReserva(Reserva&);
void montarQuarto(Quarto&);
void montarHotel(Hotel&);
void editarGerente(Gerente&);
void editarHospede(Hospede&);
void editarReserva(Reserva&);
void editarQuarto(Quarto&);
void editarHotel(Hotel&);
*/

int bancoDeDados::pegarLinha(void* dado, int argc, char** argv, char** colNames) {

    auto* resultado = static_cast<vector<string>*>(dado);

    resultado->clear();

    for (int i = 0; i < argc; i++) {
        resultado->push_back(argv[i]);
    }

    return 0;
}
