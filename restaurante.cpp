//
// Created by migue on 31/03/2025.
//
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

int mesas[30][30];
char *nomes[30][30];
//Função Principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    loadTables();
    mainMenu();
    return 0;
}

void listraTela() {
    printf("============================================\n");
}

//Função para mudar a cor das linhas do console
void changeTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
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
    int user_choose = 0;

    do {
        listraTela();
        printf("Seja Bem-Vindo ao Restaurante WM-Bistrô\n");
        printf("Por favor, insira a opção que você deseja realizar:\n");
        printf("0. Sair\n");
        printf("1. Reservar Mesa\n");
        printf("2. Visualizar Todas as Mesas\n");
        printf("3. Visualizar as mesas Disponíveis\n");
        printf("4. Visualizar as mesas Reservadas\n");
        printf("5. Limpar uma reserva\n");
        printf("6. Limpar todas as reservas\n");
        listraTela();
        scanf("%d", &user_choose);

        //usuario escolhe uma das opções
        switch (user_choose) {
            case 0:
                printf("Saindo...");
                break;

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
                deleteOneReserve();
                pauseAndClear();
                break;
            case 6:
                printf("Todas as reservas foram limpas!\n");
                loadTables();
                pauseAndClear();
                break;
            default:
                printf("Por favor, insira um opção válida\n");
                printf("Tente novamente...\n");
                pauseAndClear();
                break;
        }
    } while (user_choose != 0);
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
    return cont == 9 ? 0 : 1;
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
            nomes[i][j] = " ";
        }
    }
}

//Função pra reservar uma mesa
void bookTable() {
    listraTela();
    if (hasTableAvailable()) {
        printf("Seja bem vindo à reserva de Mesas!\n\n");
        int user_choose, hasReserved = 0;
        char nome[50];
        listAllTables();
        printf("\nDigite 0 para sair: ");
        printf("\nPor gentileza, digite o seu nome: ");
        getchar();
        scanf("%[^\n]", &nome);
        if (nome[0] == '0') {
            mainMenu();
        }
        do {
            printf("Por favor, digite o número da mesa que você deseja reservar: ");
            int valid = scanf("%d", &user_choose);
            if (user_choose == 0) {
                mainMenu();
            }
            printf("%d", valid);
            if (valid != 1) {
                changeTextColor(12);
                printf("Entrada inválida! Por favor, insira um número inteiro.\n\n");
                changeTextColor(15);
                system("pause");
            } else if (user_choose <= 0 || user_choose > 900) {
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
                            nomes[i][j] = (char *) malloc(strlen(nome) + 1); // +1 para o '\0'

                            if (nomes[i][j] != NULL) {
                                strcpy(nomes[i][j], nome); // Copia o nome para a memória alocada
                            }
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
    listraTela();
    printf("Mesas Reservadas: \n");
    printf("[Mesa - Nome]\n");
    int cont = 0, hasReserved = 0;
    hasReserved = 0;
    for (int i = 0; i < 30; ++i) {
        int breakLine = 0;
        for (int j = 0; j < 30; ++j) {
            if (mesas[i][j] == 0) {
                changeTextColor(14);
                printf("| %3d  - %s | ", cont + 1, nomes[i][j]);
                hasReserved = 1;
                breakLine = 1;
            }
            cont++;
        }
        changeTextColor(15);
        printf(breakLine == 1 ? "\n" : "");
    }

    if (hasReserved == 0) {
        changeTextColor(10);
        printf("Nenhuma mesa foi reservada.\n\n");
        changeTextColor(15);
        return false;
    }
    listraTela();
    printf("\n");
    return true;
}

void deleteOneReserve() {
    listraTela();
    int nmr_mesa = 0;
    bool breakInternLoop = false;
    bool breakExternLoop = false;

    while (!breakExternLoop) {
        int cont = 1;
        if (!listReservedTables()) {
            return;
        }
        printf("Digite 0 para sair: \n");
        printf("Escolha o número da mesa que você deseja tirar a reserva: ");
        scanf("%d", &nmr_mesa);
        if (nmr_mesa == 0) {
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
                        nomes[i][j] = " ";
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
