#include <iostream>
#include <ostream>
#include <string.h>
#include <windows.h>

void loadVelha();

void reloadVelha();

void mostarVelha();

void escolherJogada();

int isEnd();

char matrizVelha[3][3][2];

void changeTextColor(int color);

int main() {
    escolherJogada();
}

void changeTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


int itsEnd() {
    std::cout << std::endl << std::endl;
    int countDiagonalPrincipal = 0, countDiagonalSecundaria = 0,
            countLinha = 0, countColuna = 0;
    bool empate = true;
    for (int i = 0; i < 3; ++i) {
        countLinha = 0;
        countColuna = 0;

        for (int j = 0; j < 3; ++j) {
            //LINHAS
            if (matrizVelha[i][j][0] == 'X') {
                countLinha++;
            }
            if (matrizVelha[i][j][0] == 'O') {
                countLinha--;
            }

            //COLUNAS
            if (matrizVelha[j][i][0] == 'X') {
                countColuna++;
            }
            if (matrizVelha[j][i][0] == 'O') {
                countColuna--;
            }
            if (matrizVelha[j][i][0] == '-') {
                empate = false;
            }
        }
        if (countLinha == 3 || countColuna == -3) {
            break;
        } else if (countColuna == 3 || countLinha == -3) {
            break;
        } else if (countDiagonalPrincipal == 3) {
            break;
        } else if (countDiagonalSecundaria == 3) {
            break;
        }
    }
    if (countLinha == 3 || countColuna == 3) {
        std::cout << "O jogo acabou" << std::endl << "'X' Ganhou o Jogo! :)" << std::endl;
        return 1;
    } else if (countColuna == -3 || countColuna == -3) {
        std::cout << "O jogo acabou" << std::endl << "'O' Ganhou o Jogo! :)" << std::endl;
        return 1;
    }

    // DIAGONAIS
    for (int i = 0; i < 3; ++i) {
        if (matrizVelha[i][i][0] == 'X') {
            countDiagonalPrincipal++;
        }
        if (matrizVelha[i][i][0] == 'O') {
            countDiagonalPrincipal--;
        }

        if (matrizVelha[i][2 - i][0] == 'X') {
            countDiagonalSecundaria++;
        }
        if (matrizVelha[i][2 - i][0] == 'O') {
            countDiagonalSecundaria--;
        }
    }

    if (countDiagonalPrincipal == 3 || countDiagonalSecundaria == 3) {
        std::cout << "O jogo acabou" << std::endl << "'X' Ganhou o Jogo! :)" << std::endl;
        return 1;
    } else if (countDiagonalPrincipal == -3 || countDiagonalSecundaria == -3) {
        std::cout << "O jogo acabou" << std::endl << "'O' Ganhou o Jogo! :)" << std::endl;
        return 1;
    }

    if (empate) {
        std::cout << "O jogo acabou! Deu velha! :(" << std::endl;
        std::cout << "Tente novamente!" << std::endl;
        system("pause");
        reloadVelha();
    }
    return 0;
}

void loadVelha() {
    std::cout << "     1   2   3" << std::endl << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << "|   ";
        for (int j = 0; j < 3; ++j) {
            changeTextColor(matrizVelha[i][j][0] == 'X' ? 10 : 12);
            if (matrizVelha[i][j][0] != 'X' && matrizVelha[i][j][0] != 'O') {
                changeTextColor(15);
                strcpy(matrizVelha[i][j], "-");
            }
            std::cout << matrizVelha[i][j] << "   ";
        }
        changeTextColor(15);
        std::cout << std::endl;
        std::cout << "   ---|---|----|" << std::endl;
    }
}

void reloadVelha() {
    std::cout << "    1   2   3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << "   ";
        for (int j = 0; j < 3; ++j) {
            strcpy(matrizVelha[i][j], "-");

            std::cout << matrizVelha[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

void escolherJogada() {
    bool jogadaVez = true; //TRUE É X FALSE É O
    do {
        loadVelha();
        std::cout << std::endl << "VEZ DO JOGADOR " << (jogadaVez ? "X" : "O") << std::endl;
        std::cout << "ESCOLHA UMA JOGADA: (EXEMPLO: 1-1 | 1-2| 2-3...)" << std::endl;
        char jogada[3];
        std::cin >> jogada;

        int linha = jogada[0] - '0'; // Converte o primeiro caractere
        int coluna = jogada[2] - '0'; // Converte o terceiro caractere

        int jogadaIndex = linha * 10 + coluna;
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || matrizVelha[linha - 1][coluna - 1][0] != '-') {
            std::cout << "Jogada inválida! Tente novamente." << std::endl;
            system("pause");
            continue;
        }
        switch (jogadaIndex) {
            case 11:
                strcpy(matrizVelha[0][0], jogadaVez ? "X" : "O");
                break;
            case 12:
                strcpy(matrizVelha[0][1], jogadaVez ? "X" : "O");
                break;
            case 13:
                strcpy(matrizVelha[0][2], jogadaVez ? "X" : "O");
                break;
            case 21:
                strcpy(matrizVelha[1][0], jogadaVez ? "X" : "O");
                break;
            case 22:
                strcpy(matrizVelha[1][1], jogadaVez ? "X" : "O");
                break;
            case 23:
                strcpy(matrizVelha[1][2], jogadaVez ? "X" : "O");
                break;
            case 31:
                strcpy(matrizVelha[2][0], jogadaVez ? "X" : "O");
                break;
            case 32:
                strcpy(matrizVelha[2][1], jogadaVez ? "X" : "O");
                break;
            case 33:
                strcpy(matrizVelha[2][2], jogadaVez ? "X" : "O");
                break;
            default:
                std::cout << "Jogada inválida!" << std::endl;
                break;
        }
        jogadaVez = !jogadaVez;
    } while (itsEnd() == 0);
    std::cout << std::endl;
    loadVelha();
}
