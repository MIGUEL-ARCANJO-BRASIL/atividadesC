#include <iostream>
#include <stdio.h>
#include <locale.h>
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

//Utilizando Struct - Declaração
typedef struct {
    char nome[20];
    float preco;
} ItemCardapio;

typedef struct {
    char nome[30];
    int nmr_mesa;
    ItemCardapio item;
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
        printf("0. Sair.\n");
        printf("1. Reservar Mesa.\n");
        printf("2. Visualizar Todas as Mesas.\n");
        printf("3. Visualizar as mesas Disponíveis.\n");
        printf("4. Visualizar as mesas Reservadas.\n");
        printf("5. Anotar Pedidos.\n");
        printf("6. Atualizar Informações.\n");
        printf("7. Limpar uma reserva.\n");
        printf("8. Limpar todas as reservas.\n");
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
            pessoas[i][j].item.nome[0] = '0';
            pessoas[i][j].item.preco = 0;
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
    if (hasTableAvailable()) {
        printf("Seja bem vindo à reserva de Mesas!\n\n");
        int user_choose, hasReserved = 0;
        char nome[50];
        listAllTables();
        while (true) {
            printf("\nDigite 0 para sair: ");
            printf("\nPor gentileza, digite o seu nome: ");
            getchar();
            scanf("%[^\n]", &nome);

            if (verifyString(nome)) {
                break;
            }
        }

        if (nome[0] == '0') {
            return;
        }

        do {
            while (true) {
                printf("Por favor, digite o número da mesa que você deseja reservar: ");
                int valid = scanf("%d", &user_choose);

                if (user_choose == 0) {
                    return;
                }

                if (valid != 1) {
                    changeTextColor(12);
                    printf("Entrada inválida! Por favor, insira um número inteiro.\n\n");
                    changeTextColor(15);
                    pauseAndClear();
                    while (getchar() != '\n');
                    continue;
                }
                break;
            }

            if (user_choose <= 0 || user_choose > 900) {
                changeTextColor(12);
                printf("Tente novamente...\n");
                printf("Por favor, insira uma opção válida.\n");
                printf("Números entre 1 e 9.\n\n");
                changeTextColor(15);
                system("pause");
            } else {
                int cont = 1;
                for (int i = 0; i < 30; ++i) {
                    for (int j = 0; j < 30; ++j) {
                        if (cont == user_choose && mesas[i][j] != 0) {
                            changeTextColor(10);
                            printf("\n\nMesa de Numero %d° reservada para %s.\n", mesas[i][j], nome); //texto na tela

                            strcpy(pessoas[i][j].nome, nome);
                            pessoas[i][j].nmr_mesa = cont;

                            mesas[i][j] = 0; //marcando a mesa como reservada
                            hasReserved = 1; //alguma mesa foi reservada
                            changeTextColor(15);

                            printf("\n");
                            break;
                        }
                        cont++;
                    }
                    if (hasReserved == 1) {
                        break;
                    }
                }

                if (hasReserved == 0) {
                    changeTextColor(14);
                    printf("Mesa de número já reservada!\n");
                    printf("Por favor, tente novamente.\n\n");
                    changeTextColor(15);
                }
            }
        } while (hasReserved == 0); //se foi resevada, saí do loop e continua o código
        fflush(stdin);
    } else {
        changeTextColor(14);
        printf("Desculpe, não estamos com mesas disponíveis!...\n");

        changeTextColor(15);
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
            printf(cont % 15 == 0 ? "[" : "");
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
                printf("| %3d  - %s | ", pessoas[i][j].nmr_mesa, pessoas[i][j].nome);

                if (pessoas[i][j].item.preco != 0 && pessoas[i][j].item.nome[0] != '0') {
                    printf("Item escolhido: %s - R$ %.2f\n", pessoas[i][j].item.nome, pessoas[i][j].item.preco);
                } else {
                    printf("Nenhum pedido!\n");
                }
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
            if (pessoas[i][j].nmr_mesa != 0 && pessoas[i][j].nome[0] != '0') {
                return true; // Existe pelo menos uma reserva
            }
        }
    }
    return false;
}

void deleteOneReserve() {
    listraTela();
    bool breakInternLoop = false;
    bool breakExternLoop = false;
    while (!breakExternLoop) {
        int nmr_mesa = 0;
        int cont = 1;
        if (!listReservedTables()) {
            return;
        }
        printf("Digite 0 para sair: \n");
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
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (cont == nmr_mesa) {
                    if (mesas[i][j] == cont) {
                        changeTextColor(14);
                        printf("Mesa sem reserva! Tente novamente...!\n");
                        breakInternLoop = true;
                        changeTextColor(15);
                        system("pause");
                    } else {
                        changeTextColor(10);
                        printf("A reservada de número %d foi excluída com sucesso!\n", nmr_mesa);
                        mesas[i][j] = cont;
                        strcpy(pessoas[i][j].nome, "0");
                        pessoas[i][j].nmr_mesa = 0;
                        breakInternLoop = true;
                        breakExternLoop = true;
                        changeTextColor(15);
                    }
                }
                cont++;
            }
            if (breakInternLoop == true) {
                break;
            }
        }
    }
}

void showMenu() {
    listraTela();
    printf("\n\nSeja Bem vindo ao cardápio!\n");
    printf("Por favor, escolha somente um item!\n\n");
    printf("\n========= CARDÁPIO =========\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - (R$ %.2f)\n", i + 1, itens[i].nome, itens[i].preco);
    }
    printf("0 - Sair\n\n");
}

void updateInfos() {
    listraTela();
    while (true) {
        if (!listReservedTables()) {
            return;
        }

        printf("\nATUALIZAÇÃO DE INFORMAÇÕES!\n\n ");
        int user_choice = 0;
        int nmr_mesa = 0;

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

        printf("Escolha o Número da mesa reservada para as informações serem atualizadas: \n");
        if (scanf("%d", &nmr_mesa) != 1) {
            changeTextBold();
            printf("Entrada inválida! Digite apenas números");
            resetText();
            system("pause");
            while (getchar() != '\n');
            continue;
        }

        if (nmr_mesa == 0) {
            return;
        }
        bool find = false;
        int index_i = 0, index_j = 0;

        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (nmr_mesa == pessoas[i][j].nmr_mesa) {
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
            printf("Mesa não encontrada! Informe novamente!\n");
            resetText();
            system("pause");
            while (getchar() != '\n');
            continue;
        }

        switch (user_choice) {
            case 1:
                while (true) {
                    char nome[30];
                    printf("\n\nDigite o novo nome! \n");
                    while (getchar() != '\n');
                    scanf("%[^\n]", nome);
                    if (!verifyString(nome)) { continue; }

                    printf("Nome antigo: %s\n", pessoas[index_i][index_j].nome);
                    printf("Nome novo: %s\n", nome);
                    strcpy(pessoas[index_i][index_j].nome, nome);
                    changeTextColor(10);
                    printf("\nNome alterado com suceso!\n");
                    changeTextColor(15);
                    break;
                }
                break;
            case 2:
                while (true) {
                    int newMesa = 0;

                    printf("%d %d", index_i, index_j);
                    printf("\n\nDigite o novo número da mesa! \n");
                    if (scanf("%d", &newMesa) != 1) {
                        changeTextBold();
                        printf("Por favor, Digite um número válido! \n");
                        printf("Número digitado: \n\n", newMesa);
                        resetText();
                        system("pause");
                        while (getchar() != '\n');
                        continue;
                    }

                    pessoas[index_i][index_j].nmr_mesa = 0; // Resetar a mesa antiga
                    mesas[index_i][index_j] = nmr_mesa;

                    int cont = 1;
                    int new_i = 0;
                    int new_j = 0;
                    bool hasReserved = false;
                    for (int i = 0; i < 30; ++i) {
                        for (int j = 0; j < 30; ++j) {
                            if (cont == newMesa && mesas[i][j] != 0) {
                                mesas[i][j] = 0; //marcando a mesa como reservada
                                hasReserved = true; //alguma mesa foi reservada
                                changeTextColor(15);
                                new_i = i;
                                new_j = j;
                                break;
                            }
                            cont++;
                        }
                        if (hasReserved) { break; }
                    }

                    char nome[30];

                    strcpy(nome, pessoas[index_i][index_j].nome);
                    pessoas[index_i][index_j].nome[0] = '0';
                    strcpy(pessoas[new_i][new_j].nome, nome);

                    pessoas[new_i][new_j].nmr_mesa = newMesa;
                    printf("Número novo: %d\n", pessoas[new_i][new_j].nmr_mesa);
                    printf("Número antigo: %d\n", mesas[index_i][index_j]);;
                    changeTextColor(10);
                    printf("\nNúmero da mesa alterado com suceso!\n");
                    changeTextColor(15);

                    break;
                }
                break;
            case 3:
                if (pessoas[index_i][index_j].item.nome[0] == '0' &&
                    pessoas[index_i][index_j].item.preco == 0) {
                    changeTextBold();
                    printf("Nenhum pedido ainda realizado para ser alterado!");
                    system("pause");
                    while (getchar() != '\n');
                    resetText();
                    break;
                }

                while (true) {
                    int newItem = 0;
                    showMenu();
                    if (scanf("%d", &newItem) != 1) {
                        changeTextBold();
                        printf("Por favor, Digite um número válido! \n");
                        printf("Número digitado: \n\n", newItem);
                        resetText();
                        system("pause");
                        while (getchar() != '\n');
                        continue;
                    }
                    printf("Pedido antigo: %s\n", pessoas[index_i][index_j].item.nome);
                    pessoas[index_i][index_j].item = itens[newItem - 1];
                    printf("Número novo: %s\n", pessoas[index_i][index_j].item.nome);
                    changeTextColor(10);
                    printf("\nPedido alterado com suceso!\n");
                    changeTextColor(15);
                    break;
                }
                break;
            case 4:
                while (true) {
                    char nome[30];
                    printf("\n\nDigite o novo nome! \n");
                    while (getchar() != '\n');
                    scanf("%[^\n]", nome);
                    if (!verifyString(nome)) { continue; }

                    strcpy(pessoas[index_i][index_j].nome, nome);

                     int newMesa = 0;

                    printf("%d %d", index_i, index_j);
                    printf("\n\nDigite o novo número da mesa! \n");
                    if (scanf("%d", &newMesa) != 1) {
                        changeTextBold();
                        printf("Por favor, Digite um número válido! \n");
                        printf("Número digitado: \n\n", newMesa);
                        resetText();
                        system("pause");
                        while (getchar() != '\n');
                        continue;
                    }

                    pessoas[index_i][index_j].nmr_mesa = 0; // Resetar a mesa antiga
                    mesas[index_i][index_j] = nmr_mesa;

                    int cont = 1;
                    int new_i = 0;
                    int new_j = 0;
                    bool hasReserved = false;
                    for (int i = 0; i < 30; ++i) {
                        for (int j = 0; j < 30; ++j) {
                            if (cont == newMesa && mesas[i][j] != 0) {
                                mesas[i][j] = 0; //marcando a mesa como reservada
                                hasReserved = true; //alguma mesa foi reservada
                                changeTextColor(15);
                                new_i = i;
                                new_j = j;
                                break;
                            }
                            cont++;
                        }
                        if (hasReserved) { break; }
                    }

                    char newNome[30];

                    strcpy(newNome, pessoas[index_i][index_j].nome);
                    pessoas[index_i][index_j].nome[0] = '0';
                    strcpy(pessoas[new_i][new_j].nome, newNome);

                    pessoas[new_i][new_j].nmr_mesa = newMesa;
                    printf("Número novo: %d\n", pessoas[new_i][new_j].nmr_mesa);
                    printf("Número antigo: %d\n", mesas[index_i][index_j]);;
                    changeTextColor(10);
                    printf("\nNúmero da mesa alterado com suceso!\n");
                    changeTextColor(15);



                    int newItem = 0;
                    showMenu();

                    if (scanf("%d", &newItem) != 1) {
                        changeTextBold();
                        printf("Por favor, Digite um número válido! \n");
                        printf("Número digitado: \n\n", newItem);
                        resetText();
                        system("pause");
                        while (getchar() != '\n');
                        continue;
                    }

                    pessoas[new_i][new_j].item = itens[newItem - 1];
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
        while (true) {
            int user_choice = 0;

            //mostra o cardápio
            showMenu();

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

            pessoas[index_i][index_j].item = itens[nmr_item_menu - 1];

            changeTextBold();
            printf("\nVocê selecionou %s.\n", itens[nmr_item_menu - 1].nome);
            resetText();

            printf("Confirme seu pedido, por favor.\n");
            printf("[1] - Sim\n[2] - Não\n[0] - Sair\n");
            scanf("%d", &user_choice);
            if (user_choice == 2) {
                printf("Por favor, faça seu pedido novamente!\n");
                continue;
            } else if (user_choice == 0) {
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


bool verifyString(char str[30]) {
    bool hasNumber = false, hasSpace = true;
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
        }
    }
    if (hasNumber && hasSpace) {
        changeTextColor(12);
        printf("Entrada inválida! Digite seu nome corretamente.\n\n");
        changeTextColor(15);
        return false;
    }
    return true;
}
