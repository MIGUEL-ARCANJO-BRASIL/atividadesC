#include <iostream>
#include<windows.h>
#include<locale.h>
int dama[8][8];
char matrizDama[8][8][2];

void loadDama();

void listDama();

void escolherJogadas();

bool validMovimento(int linhaOrigem, int linhaDestino, int colunaOrigem, int colunaDestino, bool turn);

bool verifyIsDama(int linhaDestino, int colunaDestino, bool turn);

bool verifyEndGame(bool turn);

void changeTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    loadDama();
    escolherJogadas();
}

void loadDama() {
    bool isPar;
    char damas;
    for (int i = 0; i < 8; i++) {
        changeTextColor(15);
        if (i % 2 != 0) {
            isPar = true;
        } else {
            isPar = false;
        }

        for (int j = 0; j < 8; j++) {
            if (i == 3 || i == 4) {
                matrizDama[i][j][0] = '-';
                std::cout << matrizDama[i][j] << "   ";
                continue;
            }
            if (i < 3) {
                changeTextColor(2);
                damas = 'X';
            } else if (i > 4) {
                changeTextColor(3);
                damas = 'O';
            }

            if (isPar) {
                if (j % 2 == 0) {
                    matrizDama[i][j][0] = damas;
                } else {
                    changeTextColor(15);
                    matrizDama[i][j][0] = '-';
                }
            } else {
                if (j % 2 != 0) {
                    matrizDama[i][j][0] = damas;
                } else {
                    changeTextColor(15);
                    matrizDama[i][j][0] = '-';
                }
            }
        }
    }
}

void listDama() {
    std::cout << std::endl;
    std::cout << "         A   B   C   D   E   F   G   H" << std::endl;
    std::cout << "        --------------------------------" << std::endl << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << i + 1 << "|       ";
        for (int j = 0; j < 8; j++) {
            if (matrizDama[i][j][0] == 'X' || matrizDama[i][j][0] == 'K') {
                changeTextColor(2);
            } else if (matrizDama[i][j][0] == 'O' || matrizDama[i][j][0] == 'L') {
                changeTextColor(3);
            } else {
                changeTextColor(15);
            }
            std::cout << matrizDama[i][j] << "   ";
        }
        std::cout << std::endl << std::endl;
        changeTextColor(15);
    }
    std::cout << "         A   B   C   D   E   F   G   H" << std::endl;
    std::cout << "        --------------------------------" << std::endl << std::endl;
    std::cout << std::endl;
}

void escolherJogadas() {
    bool turn = true; //true = O | false = X
    do {
        listDama();
        char jogadaOrigem[3], jogadaDestino[3];

        std::cout << "jogador " << (turn ? "O" : "X") << " é sua vez!" << std::endl;

        std::cout << "Escolha sua jogada de origem! (EXEMPLO: 1-A, 1-C, 5-H...)" << std::endl;
        std::cin >> jogadaOrigem;

        int linhaOrigem = jogadaOrigem[0] - '1';
        int colunaOrigem;
        char colunaCharOrigem;

        if (jogadaOrigem[1] == '-') {
            colunaCharOrigem = std::toupper(jogadaOrigem[2]);
            colunaOrigem = colunaCharOrigem - 'A';
        } else {
            colunaCharOrigem = std::toupper(jogadaOrigem[1]);
            colunaOrigem = colunaCharOrigem - 'A';
        }
        std::cout << colunaOrigem << std::endl;


        std::cout << "Escolha sua jogada de destino! (EXEMPLO: 1-A, 1-C, 5-H...)" << std::endl;
        std::cout << "Ou... Digite 0 para escolher outra peça: " << std::endl << std::endl;
        std::cin >> jogadaDestino;

        int linhaDestino = jogadaDestino[0] - '1';
        int colunaDestino;
        char colunaCharDestino;
        if (jogadaDestino[0] == '0') {
            system("cls");
            continue;
        }
        if (jogadaDestino[1] == '-') {
            colunaCharDestino = std::toupper(jogadaDestino[2]);
            colunaDestino = colunaCharDestino - 'A';
        } else {
            colunaCharDestino = std::toupper(jogadaDestino[1]);
            colunaDestino = colunaCharDestino - 'A';
        }

        if (!validMovimento(linhaOrigem, linhaDestino, colunaOrigem, colunaDestino, turn)) {
            continue;
        }
        if (verifyEndGame(turn)) {
            std::cout << "FIM DE JOGO!" << std::endl << "A equipe " << (turn ? 'O' : 'X') << " venceu o jogo.";
            break;
        }
        turn = !turn;
    } while (true);
}

bool validMovimento(int linhaOrigem, int linhaDestino, int colunaOrigem, int colunaDestino, bool turn) {
    if (linhaOrigem < 0 || linhaOrigem >= 8 || colunaOrigem < 0 || colunaOrigem >= 8 || linhaDestino < 0 ||
        linhaDestino >= 8 || colunaDestino < 0 || colunaDestino >= 8) {
        std::cout << linhaOrigem << " " << colunaOrigem << std::endl;
        std::cout << linhaDestino << " " << colunaDestino << std::endl;
        std::cout << "Jogada Inválida... Tente novamente!";
        return false;
    }

    if ((turn && (matrizDama[linhaOrigem][colunaOrigem][0] != 'O' && matrizDama[linhaOrigem][colunaOrigem][0] != 'L'))
        ||
        (!turn && (matrizDama[linhaOrigem][colunaOrigem][0] != 'X' && matrizDama[linhaOrigem][colunaOrigem][0] !=
                   'K'))) {
        std::cout << "Por favor, mova apenas a sua peça" << std::endl;
        return false;
    }

    if (matrizDama[linhaOrigem][colunaOrigem][0] == '-') {
        std::cout << "Impossível mover espaços vazios!" << std::endl;
        std::cout << "Por favor, mova apenas a sua peça" << std::endl;
        return false;
    }

    if ((turn && matrizDama[linhaDestino][colunaDestino][0] == 'O') || (
            !turn && matrizDama[linhaDestino][colunaDestino][0] == 'X')) {
        std::cout << "Movimento inválido!" << std::endl << "Não é possível capturar peça aliada." << std::endl;
        return false;
    }

    //verificação para peças comuns
    if (matrizDama[linhaOrigem][colunaOrigem][0] == 'O' || matrizDama[linhaOrigem][colunaOrigem][0] == 'X') {
        if (abs(linhaDestino - linhaOrigem) == 2 && abs(colunaDestino - colunaOrigem) == 2) {
            int linhaMeio = (linhaDestino + linhaOrigem) / 2;
            int colunaMeio = (colunaDestino + colunaOrigem) / 2;

            if ((turn && (matrizDama[linhaMeio][colunaMeio][0] == 'X' || matrizDama[linhaMeio][colunaMeio][0] == 'K'))
                || (
                    !turn && (matrizDama[linhaMeio][colunaMeio][0] == 'O' || matrizDama[linhaMeio][colunaMeio][0] ==
                              'L'))) {
                strcpy(matrizDama[linhaMeio][colunaMeio], "-");

                strcpy(matrizDama[linhaOrigem][colunaOrigem], "-");
                strcpy(matrizDama[linhaDestino][colunaDestino], turn ? "O" : "X");

                std::cout << "Captura realizada!\n";

                verifyIsDama(linhaDestino, colunaDestino, turn);
                return true;
            } else {
                std::cout << "Movimento inválido! Não há peça inimiga para capturar.\n";
                return false;
            }
        } else if (abs(linhaDestino - linhaOrigem) == 1 && abs(colunaDestino - colunaOrigem) == 1) {
            if (turn && matrizDama[linhaDestino][colunaDestino][0] == 'X' ||
                !turn && matrizDama[linhaDestino][colunaDestino][0] == 'O') {
                std::cout << "Movimento Inválido!" << std::endl;
                std::cout << "Tente novamente" << std::endl << std::endl;
                return false;
            }
            strcpy(matrizDama[linhaOrigem][colunaOrigem], "-");
            strcpy(matrizDama[linhaDestino][colunaDestino], turn ? "O" : "X");

            verifyIsDama(linhaDestino, colunaDestino, turn);
            return true;
        } else {
            std::cout << "Movimento inválido! As damas se movem apenas na diagonal.\n";
            return false;
        }
    }
    //verificar peças q são DAMAS
    if (matrizDama[linhaOrigem][colunaOrigem][0] == 'K' || matrizDama[linhaOrigem][colunaOrigem][0] == 'L') {
        bool capturasRealizadas = false;
        int passoI = (linhaDestino > linhaOrigem) ? 1 : -1;
        int passoJ = (colunaDestino > colunaOrigem) ? 1 : -1;

        int linha = linhaOrigem + passoI;
        int coluna = colunaOrigem + passoJ;

        int linhaDiag = abs(linhaDestino - linhaOrigem);
        int colunaDiag = abs(colunaDestino - colunaOrigem);

        if (linhaDiag != colunaDiag) {
            std::cout << "Movimento inválido!" << std::endl;
            return false;
        }

        while (linha != linhaDestino && coluna != colunaDestino) {
            if (matrizDama[linha][coluna][0] != '-') {
                if ((turn && (matrizDama[linha][coluna][0] == 'X' || matrizDama[linha][coluna][0] ==
                              'K')) ||
                    (!turn && (matrizDama[linha][coluna][0] == 'O' || matrizDama[linha][coluna][0]
                               == 'L'))) {
                    matrizDama[linha][coluna][0] = '-';
                    capturasRealizadas = true;
                } else {
                    std::cout << "Movimento inválido! A dama não pode pular sobre peças aliadas." << std::endl;
                    return false;
                }
            }
            linha += passoI;
            coluna += passoJ;
        }
        if (capturasRealizadas) {
            std::cout << "Captura realizada!" << std::endl;
        }

        strcpy(matrizDama[linhaOrigem][colunaOrigem], "-");
        strcpy(matrizDama[linhaDestino][colunaDestino], turn ? "L" : "K");
        return true;
    }
}

bool verifyIsDama(int linhaDestino, int colunaDestino, bool turn) {
    if (turn && linhaDestino == 0) {
        matrizDama[linhaDestino][colunaDestino][0] = 'L';
        std::cout << "A peça O virou dama" << std::endl;
        return true;
    } else if (!turn && linhaDestino == 7) {
        matrizDama[linhaDestino][colunaDestino][0] = 'K';
        std::cout << "A peça X virou dama" << std::endl;
        return true;
    }
    return false;
}

bool verifyEndGame(bool turn) {
    char pecaAdversaria = turn ? 'X' : 'O';
    char damaAdversaria = (pecaAdversaria == 'O') ? 'L' : 'K';

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (matrizDama[i][j][0] == pecaAdversaria ||
                matrizDama[i][j][0] == damaAdversaria) {
                return false;
            }
        }
    }
    return true;
}
