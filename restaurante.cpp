#include <iostream>
#include <list>
#include <stdio.h>
#include <locale.h>
#include <map>
#include <string.h>
#include <windows.h>

//declaração das funções antes do código implementado
void mainMenu();

void bookTable();

void listAllTables();

bool listReservedTables();

void listAvailableTables();

void loadTables();

void listraTela();

void changeTextColor(int color);

int hasTableAvailable();

void deleteOneReserve();

void showMenu();

void takeOrder();

bool verifyReservedTables();

bool verifyString(char str[30]);

void changeTextBold();

void resteText();

void updateInfos();

bool updateName(int index_i, int index_j);

bool updateTable(int index_i, int index_j, int nmr_mesa);

bool updateOrder(int index_i, int index_j);

int confirmAction();

char *parseString(char str[30]);

bool findName(char name[30]);

//Utilizando Struct - Declaração
typedef struct {
    char nome[20];
    float preco;
} ItemCardapio;

typedef struct {
    char nome[30];
    int nmr_mesa;
    std::list<int> listMesasReservadas;
    std::list<ItemCardapio> listItems;
} Pessoa;

//Declaração de variáveis globais
int mesas[30][30];
Pessoa pessoas[30][30];
ItemCardapio itens[5];

//Função Principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    loadTables();
    mainMenu();
    return 0;
}


void listraTela() {
    printf("\n\n================= Restaurante WM-Bistrô =================\n\n");
}

//Função para mudar a cor das linhas do console
void changeTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//Função pra destacar (deixar em negrito)
void changeTextBold() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

//Função pra voltar o texto à cor normal
void resetText() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Função para pausar e limpar a tela
void pauseAndClear() {
    printf("\nPressione qualquer tecla para continuar...");
    getchar(); // Aguarda entrada do usuário
    getchar(); // Captura a tecla e permite prosseguir
    system("cls"); // Limpa a tela
}

// função pra apresentar o menu principal
void mainMenu() {
    int user_choice;
    while (true) {
        user_choice = 0;
        listraTela();
        printf("Seja Bem-Vindo ao Restaurante WM-Bistrô.\n");
        printf("Por favor, insira a opção que você deseja realizar:\n");
        printf("---------------------------------------------------\n");
        printf("0. Sair.\n");
        printf("---------------------------------------------------\n");
        printf("1. Reservar Mesa.\n");
        printf("---------------------------------------------------\n");
        printf("2. Visualizar Todas as Mesas.\n");
        printf("---------------------------------------------------\n");
        printf("3. Visualizar as mesas Disponíveis.\n");
        printf("---------------------------------------------------\n");
        printf("4. Visualizar as mesas Reservadas.\n");
        printf("---------------------------------------------------\n");
        printf("5. Anotar Pedidos.\n");
        printf("---------------------------------------------------\n");
        printf("6. Atualizar Informações.\n");
        printf("---------------------------------------------------\n");
        printf("7. Limpar uma reserva.\n");
        printf("---------------------------------------------------\n");
        printf("8. Limpar todas as reservas.\n");
        printf("---------------------------------------------------\n");
        listraTela();

        if (scanf("%d", &user_choice) != 1) {
            changeTextBold();
            printf("Por favor, insira Apenas números!\n");
            resetText();
            while (getchar() != '\n');
            pauseAndClear();
            continue;
        }

        //usuario escolhe uma das opções
        switch (user_choice) {
            case 0:
                printf("Saindo...");
                return;

            case 1:
                bookTable();
                pauseAndClear();
                break;
            case 2:
                listAllTables();
                pauseAndClear();
                break;
            case 3:
                listAvailableTables();
                pauseAndClear();
                break;
            case 4:
                listReservedTables();
                pauseAndClear();
                break;
            case 5:
                takeOrder();
                pauseAndClear();
                break;
            case 6:
                updateInfos();
                pauseAndClear();
                break;
            case 7:
                deleteOneReserve();
                pauseAndClear();
                break;
            case 8:
                if (!verifyReservedTables()) {
                    changeTextColor(10);
                    printf("Nenhuma mesa foi reservada.\n\n");
                    changeTextColor(15);
                    while (getchar() != '\n');
                    system("pause");
                    continue;
                }
                changeTextBold();
                printf("Todas as reservas foram limpas!\n");
                resetText();
                loadTables();
                pauseAndClear();
                break;
            default:
                printf("Por favor, insira um opção válida\n");
                printf("Tente novamente...\n");
                pauseAndClear();
                break;
        }
    }
}

//Função pra verificar se tem mesas disponíveis
int hasTableAvailable() {
    int cont = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (mesas[i][j] == 0) {
                cont++;
            };
        }
    }

    //Se 'cont' for incrementado até chegar na ultima mesa, quer dizer que todas foram preenchidas
    return cont == 900 ? 0 : 1;
}

//Função pra preencher as mesas
void loadTables() {
    int cont = 1;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            mesas[i][j] = cont++;
        }
    }

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            pessoas[i][j].nome[0] = '0';
            pessoas[i][j].nmr_mesa = 0;
            pessoas[i][j].listMesasReservadas.clear();
        }
    }
    itens[0] = (ItemCardapio){"Hamburguer", 15.90};
    itens[1] = (ItemCardapio){"Pizza", 39.90};
    itens[2] = (ItemCardapio){"Sushi", 25.50};
    itens[3] = (ItemCardapio){"Lasanha", 29.00};
    itens[4] = (ItemCardapio){"Salada", 18.50};
}

//Função pra reservar uma mesa
void bookTable() {
    listraTela();
    printf("\nCADASTRO DE MESAS\n\n");
    int contQtdMesas = 0;
    int index_i = 0, index_j = 0;

    if (!hasTableAvailable()) {
        changeTextColor(14);
        printf("Desculpe, não estamos com mesas disponíveis!...\n");
        changeTextColor(15);
        return;
    }

    printf("Seja bem-vindo à reserva de Mesas!\n\n");
    int qtdMesas = 0;
    int user_choose;
    char nome[30];
    bool indexSetted = false;

    listAllTables();

    // Lê nome do usuário
    while (true) {
        printf("\nDigite 0 para sair: ");
        printf("\nPor gentileza, digite o seu nome: ");
        scanf(" %[^\n]", nome);

        if (nome[0] == '0') return;
        strcpy(nome, parseString(nome));
        if (findName(nome)) {
            changeTextBold();
            printf("Esse nome %s já possui reserva!\n", nome);
            resetText();
            continue;
        }
        if (verifyString(nome)) break;
    }

    // Lê quantidade de mesas
    while (true) {
        printf("\nQuantas mesas você deseja reservar? [MAX: 5 MESAS]: ");
        if (scanf("%d", &qtdMesas) != 1) {
            changeTextColor(12);
            printf("Entrada inválida! Por favor, insira um número inteiro.\n\n");
            changeTextColor(15);
            pauseAndClear();
            while (getchar() != '\n');
            continue;
        }

        if (qtdMesas <= 0 || qtdMesas > 5) {
            changeTextBold();
            printf("Por favor, digite a quantidade certa!\n ");
            resetText();
            system("pause");
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    // Loop de reservas
    while (contQtdMesas < qtdMesas) {
        printf("Por favor, digite o número da mesa que você deseja reservar: ");
        if (scanf("%d", &user_choose) != 1) {
            changeTextColor(12);
            printf("Entrada inválida! Por favor, insira um número inteiro.\n\n");
            changeTextColor(15);
            pauseAndClear();
            while (getchar() != '\n');
            continue;
        }

        if (user_choose == 0) return;


        if (user_choose < 0 || user_choose > 900) {
            changeTextColor(12);
            printf("Tente novamente...\n");
            printf("Por favor, insira uma opção válida.\n");
            printf("Números entre 1 e 900.\n\n");
            changeTextColor(15);
            system("pause");
            while (getchar() != '\n');
            continue;
        }

        // Processa reserva
        int cont = 1;
        bool novaReserva = false;
        bool mesaReservada = false;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                //SE O CONTADOR FOR IGUAL AO NUMERO INSERIDO PELO USUARIO
                if (cont == user_choose) {
                    //SE A MESA NAO TENHA SIDO RESERVADA
                    if (mesas[i][j] != 0) {
                        changeTextColor(10);
                        printf("\nMesa %d reservada com sucesso!\n", user_choose);
                        mesas[i][j] = 0;

                        //VAI SETAR O INDEX DA MATRIZ, ONDEX FOI RESERVADO PELA PRIMEIRA VEZ ( COMO SE FOSSE UM ID
                        //CASO RESERVE MAIS DE UMA MESA, VAI PEGAR O INDEX DA PRIMEIRA VEZ QUE FOI RESERVDA
                        if (!indexSetted) {
                            index_i = i;
                            index_j = j;
                            indexSetted = true;
                        }

                        novaReserva = true;
                        contQtdMesas++;
                        changeTextColor(15);
                        break;
                    } else {
                        mesaReservada = true;
                        changeTextColor(14);
                        printf("Mesa de número %d já reservada!\n", user_choose);
                        changeTextColor(15);
                        break;
                    }
                }
                cont++;
            }
            if (novaReserva || mesaReservada) break;
        }
        if (mesaReservada) {
            continue;
        }
        strcpy(pessoas[index_i][index_j].nome, nome);
        //PUSHBACK, ADICIONA O ELEMENTO NO FINAL DA LISTA
        pessoas[index_i][index_j].listMesasReservadas.push_back(user_choose);
        pessoas[index_i][index_j].nmr_mesa = qtdMesas;

        if (!novaReserva) {
            changeTextColor(14);
            printf("Mesa não encontrada!\n");
            changeTextColor(15);
            system("pause");
        }
    }

    // Exibe mesas reservadas
    printf("\nMesas reservadas para %s: ", nome);
    for (int mesa: pessoas[index_i][index_j].listMesasReservadas) {
        printf("%d ", mesa);
    }

    listraTela();
    printf("\n\n");
}


void listAllTables() {
    listraTela();
    printf("Todas as mesas sendo listadas!\n");
    int cont = 0;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {

            //TODA VEZ QUE CHEGA EM 15, VAI COLOCAR COLCHETES

            printf(cont % 15 == 0 ? "[" : "");

            // ==0, JÁ FOI RESERVADA
            if (mesas[i][j] == 0) {
                changeTextColor(12);
                printf("| [-] ");
            } else {
                changeTextColor(10);
                printf("| %3d ", mesas[i][j]);
            }
            cont++;
            changeTextColor(15);
            printf(cont % 15 == 0 ? "]\n" : "");
        }
    }
    printf("\n");
    listraTela();
    printf("\n");
}

void listAvailableTables() {
    if (hasTableAvailable()) {
        printf("Mesas Disponíveis: \n");
        int cont = 0;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (mesas[i][j] != 0) {
                    if (cont % 15 == 0) {
                        printf("[ ");
                    }
                    changeTextColor(10);
                    printf("|%3d| ", mesas[i][j]);
                    cont++;

                    changeTextColor(15);

                    if (cont % 15 == 0) {
                        printf(" ]\n");
                    }
                }
            }
        }
    } else {
        changeTextColor(14);
        printf("Desculpe,não estamos com mesas disponíveis\n");
        changeTextColor(15);
    }
    printf("\n");
}

bool listReservedTables() {
    if (!verifyReservedTables()) {
        changeTextColor(10);
        printf("Nenhuma mesa foi reservada.\n\n");
        changeTextColor(15);
        return false;
    }

    listraTela();
    printf("\nMesas Reservadas: \n");
    printf("[ Mesa - Nome - Pedido do Cliente ]\n\n");

    for (int i = 0; i < 30; ++i) {
        int breakLine = 0;
        for (int j = 0; j < 30; ++j) {
            if (pessoas[i][j].nmr_mesa != 0 && pessoas[i][j].nome[0] != '0') {
                changeTextColor(14);
                if (pessoas[i][j].nmr_mesa == 1) {
                    std::list<int>::iterator it = pessoas[i][j].listMesasReservadas.begin();
                    printf("Mesa reservada: %d \n", *it);
                } else {
                    printf("Mesas reservadas: ");
                    printf("[");
                    for (int mesas: pessoas[i][j].listMesasReservadas) {
                        if (pessoas[i][j].listMesasReservadas.back() == mesas) {
                            printf("%3d ", mesas);
                        } else {
                            printf("%3d, ", mesas);
                        }
                    }
                    printf("]\n");
                }
                printf("Nome: %s\n", pessoas[i][j].nome);
                if (pessoas[i][j].listItems.size() == 1) {
                    std::list<ItemCardapio>::iterator it = pessoas[i][j].listItems.begin();
                    printf("Pedido: %s - R$ %.2f\n", it->nome, it->preco);
                } else if (pessoas[i][j].listItems.size() > 1) {
                    printf("Itens pedidos: [");

                    std::map<std::string, std::pair<float, int> > itemCount;

                    for (auto &item: pessoas[i][j].listItems) {
                        // salva o preço
                        itemCount[item.nome].first = item.preco;
                        // conta quantas vezes apareceu
                        itemCount[item.nome].second++;
                    }

                    int printed = 0;
                    for (auto &pair: itemCount) {
                        printf("(%d) %s - R$ %.2f", pair.second.second, pair.first.c_str(), pair.second.first);
                        printed++;
                        if (printed < itemCount.size()) {
                            printf(", ");
                        }
                    }
                    printf("]\n");
                } else {
                    printf("Nenhum pedido!\n");
                }
                printf("--------------------------------------\n");
                breakLine = 1;
            }
        }
        changeTextColor(15);
        printf(breakLine == 1 ? "\n" : "");
    }

    listraTela();
    return true;
}

bool verifyReservedTables() {
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            //NÚMERO DE MESAS NAO FOR 0 E JÁ TIVER RESERVA
            if (pessoas[i][j].nmr_mesa != 0 && pessoas[i][j].nome[0] != '0') {
                // Existe pelo menos uma reserva
                return true;
            }
        }
    }
    return false;
}

void deleteOneReserve() {
    listraTela();
    printf("\nREMOVER RESERVAS\n\n");
    if (!verifyReservedTables()) {
        return;
    }
    bool breakExternLoop = false;
    int qtdMesas = 0;
    int index_i = 0, index_j = 0;

    while (true) {
        char nome[30];
        printf("Digite 0 para sair.\n");
        printf("Informe o nome que consta na reserva: \n");
        while (getchar() != '\n');
        scanf("%[^\n]", nome);
        printf("nome: %s\n", nome);

        if (nome[0] == '0') {
            changeTextBold();
            printf("Saindo...");
            resetText();
            return;
        }

        strcpy(nome, parseString(nome));
        if (!verifyString(nome)) {
            continue;
        }

        printf("Nome inserido: %s", nome);
        if (!findName(nome)) {
            changeTextBold();
            printf("\nNome não encontrado!\n");
            resetText();

            continue;
        }
        if (pessoas[index_i][index_j].nmr_mesa == 0) {
            printf("Essa pessoa não tem mesas reservadas!\n");
            return;
        }
        break;
    }

    printf("Digite 0 para sair: \n");
    int returnConfirm;
    while (!breakExternLoop) {
        int nmr_mesa = 0;
        if (!listReservedTables()) {
            return;
        }

        //TIRAR RESERVA QUANDO SE TEM APENAS 1 MESA
        if (pessoas[index_i][index_j].listMesasReservadas.size() == 1) {
            std::list<int>::iterator it = pessoas[index_i][index_j].listMesasReservadas.begin();
            printf("Mesa N°%d reservada por %s.\n", *it, pessoas[index_i][index_j].nome);

            int returnConfirm = confirmAction();
            if (returnConfirm == 0) { continue; }
            if (returnConfirm == -1) { return; }
            int cont = 1;

            //FOR EACH PRA ACHAR UM ELEMENTO, E DPS TIRAR A RESERVA
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    if (cont == *it) {
                        mesas[i][j] = *it;
                        breakExternLoop = true;
                        break;
                    }
                    cont++;
                }
                if (breakExternLoop) break;
            }

            //TIRANDO O ELEMNTO DA LISTA (NO FINAL DA LISTA
            pessoas[index_i][index_j].listMesasReservadas.pop_back();
            pessoas[index_i][index_j].nmr_mesa = 0;

            break;
        }

        printf("Quantas mesas você deseja remover? ");
        if (scanf("%d", &qtdMesas) != 1 || qtdMesas <= 0 || qtdMesas > 5) {
            printf("Entrada inválida! Insira um número válido.\n");
            while (getchar() != '\n');
            continue;
        }
        if (qtdMesas == 0) {
            changeTextBold();
            printf("Saindo...");
            resetText();
            return;
        }

        //BACK-UP DE MESAS, CASO O USUARIO NAO CONFIRME A AÇÃO DE REMOVER.
        std::list<int> oldMesas;
        for (int i = 0; i < qtdMesas; ++i) {
            printf("Escolha o número da mesa que você deseja tirar a reserva: ");
            if (scanf("%d", &nmr_mesa) != 1) {
                changeTextColor(12);
                printf("Entrada inválida! Por favor, insira um número inteiro.\n\n");
                changeTextColor(15);
                system("pause");
                while (getchar() != '\n');
                continue;
            }

            if (nmr_mesa == 0) {
                changeTextBold();
                printf("Saindo...");
                resetText();
                return;
            }
            bool findMesas = false;

            //FOR EACH PRA REMOVER O ELEMENTO DA LISTA
            for (int mesa: pessoas[index_i][index_j].listMesasReservadas) {
                if (mesa == nmr_mesa) {
                    pessoas[index_i][index_j].listMesasReservadas.remove(nmr_mesa);
                    oldMesas.push_back(nmr_mesa);
                    findMesas = true;
                    break;
                }
            }
            if (!findMesas) {
                changeTextBold();
                printf("Mesa não encontrada!\n ");
                resetText();
                system("pause");
                while (getchar() != '\n');
                continue;
            }

            // FOR PARA REMOVER DA MATRIZ A RESERVA
            int cont = 1;
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    if (cont == nmr_mesa) {
                        printf("Index: %d - nmr_meas: %d - cont: %d\n", i, nmr_mesa, cont);
                        mesas[i][j] = nmr_mesa;
                        breakExternLoop = true;
                        break;
                    }
                    cont++;
                }
                if (breakExternLoop) break;
            }

        }
        returnConfirm = confirmAction();
        if (returnConfirm == 0) {
            pessoas[index_i][index_j].listMesasReservadas = oldMesas;
            continue;
        } else if (returnConfirm == -1) {
            pessoas[index_i][index_j].listMesasReservadas = oldMesas;
        }
    }

    //SE A LISTA FICAR VAZIA, REMOVER A 'PESSOA' DA MATRIZ DE PESSOAS
    if (pessoas[index_i][index_j].listMesasReservadas.empty()) {
        pessoas[index_i][index_j].nome[0] = '0';
        printf("%s", pessoas[index_i][index_j].nome);
    }
    if (returnConfirm != -1) {
        changeTextColor(10);
        printf("\nMesa(s) excluídas com sucesso!\n");
        changeTextColor(15);
    }
}


void showMenu() {
    listraTela();
    printf("\n\nSeja Bem vindo ao cardápio!\n");
    printf("Por favor, faça sua escolha!\n\n");
    printf("\n========= CARDÁPIO =========\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - (R$ %.2f)\n", i + 1, itens[i].nome, itens[i].preco);
    }
    printf("0 - Sair\n\n");
}

void updateInfos() {
    listraTela();
    printf("\nATUALIZAÇÃO DE INFORMAÇÕES!\n\n");
    while (true) {
        if (!listReservedTables()) {
            changeTextColor(10);
            printf("Nenhuma mesa foi reservada.\n\n");
            changeTextColor(15);
            return;
        }

        int user_choice = 0;
        int nmr_mesa = 0;
        char nome_reserva[30];

        printf("\nDigite 0 para sair\n");
        printf("Informe o nome que consta na reserva para as informações serem atualizadas: \n");
        while (getchar() != '\n');
        scanf("%[^\n]", nome_reserva);
        strcpy(nome_reserva, parseString(nome_reserva));
        if (!verifyString(nome_reserva)) { continue; }

        if (nome_reserva[0] == '0') {
            return;
        }
        bool find = false;
        int index_i = 0, index_j = 0;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (strcmp(pessoas[i][j].nome, nome_reserva) == 0) {
                    find = true;
                    index_i = i;
                    index_j = j;
                    break;
                }
            }
            if (find == true) break;
        }

        if (!find) {
            changeTextBold();
            printf("Nome não encontrada! Informe novamente!\n");
            resetText();
            system("pause");
            while (getchar() != '\n');
            continue;
        }

        printf("\nDigite 0 para sair\n");
        printf("Informe o que você deseja alterar: \n");
        printf("[1] - Nome.\n[2] - Número da mesa.\n[3] - Pedido.\n[4] - Todas as informações.\n");

        if (scanf("%d", &user_choice) != 1) {
            changeTextBold();
            printf("Entrada inválida! Digite apenas números");
            resetText();
            system("pause");
            while (getchar() != '\n');
            continue;
        }
        if (user_choice < 0 || user_choice > 4) {
            changeTextBold();
            printf("Por favor, apenas digite números entre 0 e 4.");
            system("pause");
            while (getchar() != '\n');
            resetText();
            continue;
        }
        if (user_choice == 0) { return; }


        changeTextColor(14);
        printf("\n\nInformações atuais:\n\n");
        printf("Nome: %s\n", pessoas[index_i][index_j].nome);
        printf("Mesa(s) Reservada(s): ");
        for (int mesa: pessoas[index_i][index_j].listMesasReservadas) {
            printf(" %d ", mesa);
        }
        printf("\n");
        resetText();
        switch (user_choice) {
            case 1:
                while (true) {
                    char oldNome[30];
                    strcpy(oldNome, pessoas[index_i][index_j].nome);
                    if (!updateName(index_i, index_j)) {
                        continue;
                    }

                    int returnAction = confirmAction();
                    if (returnAction == 0) {
                        continue;
                    }

                    if (returnAction == -1) {
                        strcpy(pessoas[index_i][index_j].nome, oldNome);
                        return;
                    }

                    changeTextColor(10);
                    printf("\nNome alterado com suceso!\n");
                    changeTextColor(15);
                    break;
                }
                break;
            case 2:
                while (true) {
                    std::list<int> oldMesas = pessoas[index_i][index_j].listMesasReservadas;
                    int oldMesasVector[30][30];
                    for (int i = 0; i < 30; i++) {
                        for (int j = 0; j < 30; j++) {
                            oldMesasVector[i][j] = mesas[i][j];
                        }
                    }

                    if (!updateTable(index_i, index_j, nmr_mesa)) {
                        continue;
                    }

                    int returnAction = confirmAction();

                    if (returnAction == 0) {
                        pessoas[index_i][index_j].listMesasReservadas = oldMesas;

                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 30; j++) {
                                mesas[i][j] = oldMesasVector[i][j];
                            }
                        }

                        changeTextColor(14);
                        printf("Alteração cancelada. Estado anterior restaurado.\n");
                        changeTextColor(15);

                        continue;
                    } else if (returnAction == -1) {
                        pessoas[index_i][index_j].listMesasReservadas = oldMesas;

                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 30; j++) {
                                mesas[i][j] = oldMesasVector[i][j];
                            }
                        }

                        changeTextColor(14);
                        printf("Alteração cancelada. Voltando ao menu!\n");
                        changeTextColor(15);
                    }

                    changeTextColor(10);
                    printf("\nNúmero de mesa alterado com suceso!\n");
                    changeTextColor(15);
                    break;
                }
                break;
            case 3:
                if (pessoas[index_i][index_j].listMesasReservadas.size() == 0 ||
                    pessoas[index_i][index_j].listMesasReservadas.empty()) {
                    changeTextBold();
                    printf("Nenhum pedido ainda realizado para ser alterado!");
                    system("pause");
                    while (getchar() != '\n');
                    resetText();
                    break;
                }

                while (true) {
                    std::list<ItemCardapio> oldItens = pessoas[index_i][index_j].listItems;

                    if (!updateOrder(index_i, index_j)) {
                        continue;
                    }

                    int returnAction = confirmAction();

                    if (returnAction == 0) {
                        continue;
                    }

                    if (returnAction == -1) {
                        pessoas[index_i][index_j].listItems = oldItens;
                        return;
                    }

                    changeTextColor(10);
                    printf("\nPedido alterado com suceso!\n");
                    changeTextColor(15);
                    break;
                }
                break;
            case 4:
                while (true) {
                    char oldNome[30];
                    strcpy(oldNome, pessoas[index_i][index_j].nome);
                    int oldMesa = pessoas[index_i][index_j].nmr_mesa;
                    std::list<ItemCardapio> oldItens = pessoas[index_i][index_j].listItems;

                    if (!updateName(index_i, index_j)) {
                        continue;
                    }
                    if (!updateTable(index_i, index_j, nmr_mesa)) {
                        continue;
                    }
                    if (!updateOrder(index_i, index_j)) {
                        continue;
                    }
                    int returnAction = confirmAction();

                    if (returnAction == 0) {
                        continue;
                    }

                    if (returnAction == -1) {
                        strcpy(pessoas[index_i][index_j].nome, oldNome);
                        pessoas[index_i][index_j].nmr_mesa = oldMesa;
                        pessoas[index_i][index_j].listItems = oldItens;
                        return;
                    }

                    changeTextColor(10);
                    printf("\nTodas as informações foram alteradas com suceso!\n");
                    changeTextColor(15);
                    break;
                }
                break;
        }

        break;
    }
    listraTela();
}

//função pra anotar pedido do usuário
void takeOrder() {
    listraTela();
    printf("\nREALIZAR PEDIDO\n\n");
    //verifica se há mesas reservadas
    if (!verifyReservedTables()) {
        changeTextColor(10);
        printf("Nenhuma mesa foi reservada.\n\n");
        changeTextColor(15);
        return;
    }
    //while para validações
    while (true) {
        int index_i = 0, index_j = 0;
        int nmr_item_menu;
        char nome[30] = "";
        printf("\nDigite 0 para Sair.\n\n");
        printf("Por favor, insira seu nome que foi registrado na reserva: ");
        while (getchar() != '\n');
        scanf("%[^\n]", nome);
        strcpy(nome, parseString(nome));
        //chama função parar verificar se a String 'nome' contém números e/ou se ela está vazia
        if (!verifyString(nome)) {
            continue;
        }

        //se o usuário digitar '0', sai do menu atual e vai para o anterior
        if (nome[0] == '0') {
            changeTextBold();
            printf("Saindo...");
            resetText();
            return;
        }

        bool findNome = false;

        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                //o nome q o usuário digitou for igual ao nome que está salo, ele pega os index e para o loop
                if (strcasecmp(pessoas[i][j].nome, nome) == 0) {
                    printf("%s \n", pessoas[i][j].nome);
                    findNome = true;
                    index_i = i;
                    index_j = j;
                    break;
                }
            }
            if (findNome) break;
        }

        //se o nome nao foi achaado no loop, pede pro usuário inserir novamente o nome:
        if (!findNome) {
            changeTextColor(14);
            printf("Nome não encontrado... Tente Novamente!\n");
            changeTextColor(15);
            continue;
        }

        //validação para escolha do usuário
        int qtdItens = 0;
        bool isEmpty = true;
        std::list<ItemCardapio> oldList;
        while (true) {
            //mostra o cardápio
            showMenu();
            if (pessoas[index_i][index_j].listItems.size() != 0) {
                oldList = pessoas[index_i][index_j].listItems;
                isEmpty = false;
            }

            //verifica se o usuário digitou um número inteiro
            if (scanf("%d", &nmr_item_menu) != 1) {
                changeTextColor(12);
                printf("Entrada inválida! Por favor, insira um número inteiro.\n\n");
                changeTextColor(15);
                while (getchar() != '\n');
                continue;
            }

            //verifica se a opção do usuário é invalida
            if (nmr_item_menu < 0 || nmr_item_menu > 5) {
                changeTextColor(12);
                printf("Opção inválida! Escolha um número entre 1 e 5.\n\n");
                changeTextColor(15);
                continue;
            }

            //se o usuário digitar '0', volta pro menu principal
            if (nmr_item_menu == 0) {
                return;
            }

            pessoas[index_i][index_j].listItems.push_back(itens[nmr_item_menu - 1]);

            changeTextBold();
            printf("\nVocê selecionou %s.\n", itens[nmr_item_menu - 1].nome);
            resetText();

            int moreItens = 0;
            printf("Você deseja adicionar mais alguma coisa?\n");
            printf("[1] - Sim\n[2] - Não\n");
            scanf("%d", &moreItens);

            if (moreItens == 1) {
                qtdItens++;
                continue;
            }

            int returnAction = confirmAction();
            if (returnAction == 0) {
                if (isEmpty) {
                    pessoas[index_i][index_j].listItems.clear();
                } else {
                    pessoas[index_i][index_j].listItems = oldList;
                }
                continue;
            } else if (returnAction == -1) {
                if (isEmpty) {
                    pessoas[index_i][index_j].listItems.clear();
                } else {
                    pessoas[index_i][index_j].listItems = oldList;
                }
                return;
            }
            break;
        }
        changeTextColor(10);
        printf("\nPedido realizado com sucesso!\n");
        changeTextColor(15);
        break;
    }
}

bool updateName(int index_i, int index_j) {
    char nome[30];

    printf("Digite 0 para sair.\n");
    printf("\n\nDigite o novo nome! \n");
    while (getchar() != '\n');
    scanf("%[^\n]", nome);

    strcpy(nome, parseString(nome));

    if (!verifyString(nome)) { return false; }
    if (nome[0] == '0') {
        changeTextBold();
        printf("Saindo...\n");
        resetText();
        system("pause");
        while (getchar() != '\n');
        mainMenu();gi
    }
    printf("\nNome antigo: %s\n", pessoas[index_i][index_j].nome);
    printf("Nome novo: %s\n", nome);
    strcpy(pessoas[index_i][index_j].nome, nome);
    return true;
}

bool updateTable(int index_i, int index_j, int nmr_mesa) {
    int newMesa = 0;
    int oldMesa = 0;
    int qtdMesas = 0;
    std::list<int> listMesasReservadas = pessoas[index_i][index_j].listMesasReservadas;
    printf("Mesas reservadas: \n");
    printf("[ ");
    for (int mesaIt: listMesasReservadas) {
        if (listMesasReservadas.back() == mesaIt) { printf("%d ", mesaIt); } else { printf("%d, ", mesaIt); }
    }
    printf("]\n");
    printf("\nDigite 0 para sair.\n");
    printf("Digite quantas mesas você quer atualizar: [MAX: 5]\n");
    if (scanf("%d", &qtdMesas) != 1 || qtdMesas < 0 || qtdMesas > 5) {
        changeTextBold();
        printf("Entrada inválida! Digite o número corretamente!\n");
        printf("De 1 - 5 mesas!\n");
        resetText();
        return false;
    }
    for (int i = 0; i < qtdMesas; i++) {
        printf("\n\nDigite o número antigo da mesa! \n");
        if (scanf("%d", &oldMesa) != 1) {
            changeTextBold();
            printf("Por favor, Digite um número válido! \n");
            printf("Número digitado: \n\n", oldMesa);
            resetText();
            system("pause");
            while (getchar() != '\n');
            return false;
        }
        if (oldMesa < 0 || oldMesa > 900) {
            changeTextBold();
            printf("O número da mesa não pode ser menor que 1 ou maior que 900...\n");
            resetText();
            system("pause");
            while (getchar() != '\n');
            i--;
            continue;
        }
        if (oldMesa == 0) {
            changeTextBold();
            printf("Saindo...\n");
            resetText();
            system("pause");
            while (getchar() != '\n');
            mainMenu();
        }
        int contOldMesa = 1;
        bool findOldMesa = false;

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (contOldMesa == oldMesa) {
                    mesas[i][j] = oldMesa;
                    findOldMesa = true;
                    break;
                }
                contOldMesa++;
            }
            if (findOldMesa) break;
        }
        if (!findOldMesa) {
            changeTextBold();
            printf("Mesa não encontrada.\nTente novamente.\n");
            resetText();
            i--;
            continue;
        }

        printf("\n\nDigite o novo número da mesa! \n");
        if (scanf("%d", &newMesa) != 1) {
            changeTextBold();
            printf("Por favor, Digite um número válido! \n");
            printf("Número digitado: \n\n", newMesa);
            resetText();
            system("pause");
            while (getchar() != '\n');
            i--;
            continue;
        }
        if (newMesa < 0 || newMesa > 900) {
            changeTextBold();
            printf("O número da mesa não pode ser menor que 1 ou maior que 900...\n");
            resetText();
            system("pause");
            while (getchar() != '\n');
            i--;
            continue;
        }
        if (newMesa == 0) {
            changeTextBold();
            printf("Saindo...\n");
            resetText();
            system("pause");
            while (getchar() != '\n');
            mainMenu();
        }


        int cont = 1;
        bool hasReserved = false;
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (cont == newMesa && mesas[i][j] != 0) {
                    mesas[i][j] = 0;
                    hasReserved = true;
                    changeTextColor(15);
                    break;
                }
                cont++;
            }
            if (hasReserved) { break; }
        }

        for (auto it = listMesasReservadas.begin();
             it != listMesasReservadas.end(); ++it) {
            if (*it == oldMesa) {
                *it = newMesa;
                break;
            }
        }

        pessoas[index_i][index_j].listMesasReservadas = listMesasReservadas;
        printf("Número novo: %d\n", newMesa);
        printf("Numero antigo: %d\n", oldMesa);
    }
    return true;
}

bool updateOrder(int index_i, int index_j) {
    int itemEscolhido;
    int newItem = 0;

    printf("Itens pedidos atualmente:\n");
    int pos = 1;
    for (auto &item: pessoas[index_i][index_j].listItems) {
        printf("%d) %s - R$ %.2f\n", pos++, item.nome, item.preco);
    }

    printf("\nDigite o número do item que deseja alterar (0 para sair): ");
    if (scanf("%d", &itemEscolhido) != 1 || itemEscolhido <= 0 || itemEscolhido > pessoas[index_i][index_j].listItems.
        size()) {
        printf("Entrada inválida.\n");
        while (getchar() != '\n');
        return false;
    }
    showMenu();

    printf("Digite o número do novo item: ");
    if (scanf("%d", &newItem) != 1 || newItem < 0 || newItem > 5) {
        printf("Item inválido.\n");
        while (getchar() != '\n');
        return false;
    }

    if (newItem == 0) {
        changeTextBold();
        printf("Saindo...");
        resetText();
        system("pause");
        while (getchar() != '\n');
        mainMenu();
    }
    auto it = pessoas[index_i][index_j].listItems.begin();
    std::advance(it, itemEscolhido - 1);
    printf("Item antigo: %s\n", it->nome);
    *it = itens[newItem - 1];
    printf("Item novo: %s\n", it->nome);

    changeTextColor(10);
    printf("\nPedido atualizado com sucesso!\n");
    changeTextColor(15);
    return true;
}

bool findName(char str[30]) {
    bool findName = false;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (strcmp(pessoas[i][j].nome, str) == 0) {
                findName = true;
                break;
            }
        }
        if (findName) break;
    }
    return findName;
}

char *parseString(char str[30]) {
    int countString;
    bool hasSpace = true;
    for (countString = 0; str[countString] != '\0'; ++countString) {
        if (isspace(str[countString])) {
            hasSpace = true;
        } else if (hasSpace) {
            str[countString] = toupper(str[countString]);
            hasSpace = false;
        } else {
            str[countString] = tolower(str[countString]);
        }
    }
    return str;
}


bool verifyString(char str[30]) {
    bool hasNumber = false, hasSpace = true, hasSpecialCharacter = false;
    int inicio = 0, fim = strlen(str) - 1;

    // Remover espaços do início
    while (isspace((unsigned char) str[inicio])) {
        inicio++;
    }

    // Remover espaços do fim
    while (fim > inicio && isspace((unsigned char) str[fim])) {
        fim--;
    }

    // Ajusta a string, movendo os caracteres e adicionando o terminador nulo
    int novoTamanho = fim - inicio + 1;
    memmove(str, str + inicio, novoTamanho);
    str[novoTamanho] = '\0'; // Garante que a string termine corretamente

    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] != ' ') {
            if (str[n] >= '1' && str[n] <= '9') {
                hasNumber = true;
                break;
            }
            if (str[n] < '0' || (str[n] > '9' && str[n] < 'A') || (str[n] > 'Z' && str[n] < 'a') || str[n] > 'z') {
                hasSpecialCharacter = true;
            }
        }
    }
    if (hasNumber && hasSpace) {
        changeTextBold();
        printf("Entrada inválida! Digite seu nome corretamente.\n\n");
        resetText();
        return false;
    }
    if (hasSpecialCharacter) {
        changeTextBold();
        printf("Entrada inválida! Digite seu nome corretamente.\n");
        printf("Não é permitido caracteres especiais.\n\n");
        resetText();
        return false;
    }
    return true;
}


int confirmAction() {
    int userConfirm;
    printf("Você deseja confirmar essa ação?.\n");
    printf("[1] - Sim\n[2] - Não\n[0] - Sair\n");
    scanf("%d", &userConfirm);
    if (userConfirm == 2) {
        printf("Por favor, realize esta ação novamente!\n");
        return 0;
    } else if (userConfirm == 0) {
        return -1;
    }
    return 1;
}
