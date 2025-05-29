#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

//declaração das funções antes do código implementado
void loadTables();

void mainMenu();

void listraTela();

void bookTable();

void listAllTables();

bool listReservedTables();

void listAvailableTables();

void changeTextColor(int color);

int hasTableAvailable();

void deleteOneReserve();

bool verifyReservedTables();

bool verifyString(char str[30]);

void changeTextBold();

void resteText();

void updateInfos();

bool updateName(int index_i, int index_j);

bool updateTable(int index_i, int index_j, int nmr_mesa);

int confirmAction();

char *parseString(char str[30]);

typedef struct {
    char nome[30];
    int nmr_mesa;
} Pessoa;

//Declaração de variáveis globais
int mesas[30][30];
Pessoa pessoas[30][30];

//Fun  o Principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    loadTables();
    mainMenu();
    return 0;
}

void listraTela() {
    printf("\n\n================= Restaurante WM-Bistr  =================\n\n");
}

//Fun  o para mudar a cor das linhas do console
void changeTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//Fun  o pra destacar (deixar em negrito)
void changeTextBold() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

//Fun  o pra voltar o texto   cor normal
void resetText() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Fun  o para pausar e limpar a tela
void pauseAndClear() {
    printf("\nPressione qualquer tecla para continuar...");
    getchar(); // Aguarda entrada do usu rio
    getchar(); // Captura a tecla e permite prosseguir
    system("cls"); // Limpa a tela
}

// fun  o pra apresentar o menu principal
void mainMenu() {
    int user_choice;
    while (true) {
        user_choice = 0;
        listraTela();
        printf("Seja Bem-Vindo ao Restaurante WM-Bistrô .\n");
        printf("Por favor, insira a opção que você  deseja realizar:\n");
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
        printf("5. Atualizar Informações.\n");
        printf("---------------------------------------------------\n");
        printf("6. Limpar uma reserva.\n");
        printf("---------------------------------------------------\n");
        printf("7. Limpar todas as reservas.\n");
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
                updateInfos();
                pauseAndClear();
                break;
            case 6:
                deleteOneReserve();
                pauseAndClear();
                break;
            case 7:
                changeTextBold();
                printf("Todas as reservas foram limpas!\n");
                resetText();
                loadTables();
                pauseAndClear();
                break;
            default:
                printf("Por favor, insira um op  o v lida\n");
                printf("Tente novamente...\n");
                pauseAndClear();
                break;
        }
    }
}

//Fun  o pra verificar se tem mesas disponíveis
int hasTableAvailable() {
    int cont = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (mesas[i][j] == 0) {
                cont++;
            };
        }
    }
    //Se 'cont' for incrementado at  chegar na ultima mesa, quer dizer que todas foram preenchidas
    return cont == 900 ? 0 : 1;
}

//Fun  o pra preencher as mesas
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
        }
    }
}

//Fun  o pra reservar uma mesa
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
            strcpy(parseString(nome), nome);

            bool findName = false;
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 30; ++j) {
                    if (strcmp(pessoas[i][j].nome, nome) == 0 && pessoas[i][j].nome[0] != '0') {
                        findName = true;
                        break;
                    }
                }
                if (findName) { break; }
            }
            if (findName) {
                changeTextBold();
                printf("Esse nome %s já possui reserva!\n", nome);
                resetText();
                continue;
            }

            if (verifyString(nome)) {
                break;
            }
        }

        if (nome[0] == '0') {
            return;
        }

        do {
            while (true) {
                printf("Por favor, digite o número da mesa que você  deseja reservar: ");
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
                printf("Números entre 1 e 900.\n\n");
                changeTextColor(15);
                system("pause");
            } else {
                int cont = 1;
                for (int i = 0; i < 30; ++i) {
                    for (int j = 0; j < 30; ++j) {
                        if (cont == user_choose && mesas[i][j] != 0) {
                            changeTextColor(10);
                            printf("\n\nMesa de Numero %d  reservada para %s.\n", mesas[i][j], nome); //texto na tela

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
        } while (hasReserved == 0); //se foi resevada, sai  do loop e continua o c digo
    } else {
        changeTextColor(14);
        printf("Desculpe, n o estamos com mesas disponíveis!...\n");
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
        printf("Desculpe,n o estamos com mesas dispon veis\n");
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
    printf("[ Mesa - Nome ]\n\n");

    for (int i = 0; i < 30; ++i) {
        int breakLine = 0;
        for (int j = 0; j < 30; ++j) {
            if (pessoas[i][j].nmr_mesa != 0 && pessoas[i][j].nome[0] != '0') {
                changeTextColor(14);
                printf("| %3d  - %s | ", pessoas[i][j].nmr_mesa, pessoas[i][j].nome);
                breakLine = 1;
                printf("\n");
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

        int returnAction = 0;

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
                        returnAction = confirmAction();
                        if (returnAction == 0) {
                            breakInternLoop = true;
                            break;
                        } else if (returnAction == -1) {
                            return;
                        }

                        mesas[i][j] = cont;
                        strcpy(pessoas[i][j].nome, "0");
                        pessoas[i][j].nmr_mesa = 0;
                        breakInternLoop = true;
                        breakExternLoop = true;

                        changeTextColor(10);
                        printf("A reservada de número %d foi excluída com sucesso!\n", nmr_mesa);
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
        printf("[1] - Nome.\n[2] - Número da mesa.");

        if (scanf("%d", &user_choice) != 1) {
            changeTextBold();
            printf("Entrada inválida! Digite apenas números");
            resetText();
            system("pause");
            while (getchar() != '\n');
            continue;
        }
        if (user_choice < 1 || user_choice > 2) {
            changeTextBold();
            printf("Por favor, apenas digite 1 ou 2.");
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

        changeTextColor(14);
        printf("\n\nInformações atuais:\n[mesa] - [nome]\n");
        printf("%d - %s \n", pessoas[index_i][index_j].nmr_mesa, pessoas[index_i][index_j].nome);
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
                    int oldMesa = pessoas[index_i][index_j].nmr_mesa;
                    char oldNome[30];
                    strcpy(oldNome, pessoas[index_i][index_j].nome);

                    if (!updateTable(index_i, index_j, nmr_mesa)) {
                        continue;
                    }

                    int returnAction = confirmAction();

                    if (returnAction == 0) {
                        continue;
                    }

                    if (returnAction == -1) {
                        strcpy(pessoas[index_i][index_j].nome, oldNome);
                        pessoas[index_i][index_j].nmr_mesa = oldMesa;
                        return;
                    }

                    changeTextColor(10);
                    printf("\nN mero de mesa alterado com suceso!\n");
                    changeTextColor(15);
                    break;
                }
        }
        break;
    }
    listraTela();
}

bool verifyString(char str[30]) {
    bool hasNumber = false, hasSpace = true;
    int inicio = 0, fim = strlen(str) - 1;

    // Remover espa os do início
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
    str[novoTamanho] = '\0';
    // Garante que a string termine corretamente

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

bool updateName(int index_i, int index_j) {
    char novoNome[30];
    printf("Digite 0 para sair.\n");
    printf("\n\nDigite o novo nome! \n");
    while (getchar() != '\n');
    scanf("%[^\n]", novoNome);

    if (!verifyString(novoNome)) { return false; }

    if (novoNome[0] == '0') {
        changeTextBold();
        printf("Saindo...\n");
        resetText();
        system("pause");
        while (getchar() != '\n');
        mainMenu();
    }

    printf("\nNome antigo: %s\n", pessoas[index_i][index_j].nome);
    printf("Nome novo: %s\n", novoNome);
    strcpy(pessoas[index_i][index_j].nome, novoNome);
    return true;
}

bool updateTable(int index_i, int index_j, int nmr_mesa) {
    int newMesa = 0;
    printf("Digite 0 para sair.\n");
    printf("\n\nDigite o novo número da mesa! \n");

    if (scanf("%d", &newMesa) != 1) {
        changeTextBold();
        printf("Por favor, Digite um número válido! \n");
        printf("Número digitado: \n\n", newMesa);
        resetText();
        system("pause");
        while (getchar() != '\n');
        return false;
    }
    if (newMesa < 0 || newMesa > 900) {
        changeTextBold();
        printf("O número da mesa não pode ser menor que 1 ou maior que 900...\n");
        resetText();
        system("pause");
        while (getchar() != '\n');
        return false;
    }
    if (newMesa == 0) {
        changeTextBold();
        printf("Saindo...\n");
        resetText();
        system("pause");
        while (getchar() != '\n');
        mainMenu();
    }
    // Reservando a nova
    pessoas[index_i][index_j].nmr_mesa = 0;
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
    return true;
}

int confirmAction() {
    int userConfirm;
    printf("Voc  deseja confirmar essa ação?.\n");
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
