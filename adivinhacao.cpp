#include <iostream>
#include <string.h>
#include <locale.h>

void loadMatriz(int m[5][5], char m2[5][5][2]);

void verificarNumeros(int m[5][5], char m2[5][5][2]);

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    std::cout << "Bem vindo ao jogo da advinhação!" << std::endl;
    int matriz[5][5];
    char esconderNumeros[5][5][2];
    loadMatriz(matriz, esconderNumeros);
}

void loadMatriz(int matriz[5][5], char esconderNumeros[5][5][2]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            strcpy(esconderNumeros[i][j], "-");
            matriz[i][j] = rand() % 10 + 1;
        }
    }
    verificarNumeros(matriz, esconderNumeros);
}

void verificarNumeros(int m[5][5], char m2[5][5][2]) {
    int acertos = 0;
    int linhaAtual = 0;
    int colunaAtual = 0;

    while (acertos < 25) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                std::cout << m2[i][j] << "   ";
            }
            std::cout << std::endl;
        }

        std::cout << "\nTente adivinhar o " << colunaAtual + 1 << " °numero na linha " << linhaAtual + 1 << ": ";
        int valor;
        std::cin >> valor;

        bool acertou = false;
        if (m[linhaAtual][colunaAtual] == valor && m2[linhaAtual][colunaAtual][0] == '-') {
            std::string str_num = std::to_string(valor);
            strcpy(m2[linhaAtual][colunaAtual], str_num.c_str());
            acertou = true;
            acertos++;
        }

        if (acertou) {
            std::cout << "Você acertou um número!\n";
            bool linhaCompleta = true;
            colunaAtual++;
            for (int j = 0; j < 5; ++j) {
                if (m2[linhaAtual][j][0] == '-') {
                    linhaCompleta = false;
                    break;
                }
            }
            if (linhaCompleta) {
                std::cout << "\nParabéns! Você completou a linha " << linhaAtual + 1 << "!\n";
                linhaAtual++;
            }
            if (colunaAtual == 5) {
                colunaAtual = 0;
            }
        } else {
            std::cout << "Número errado, tente novamente.\n";
        }

        if (linhaAtual == 5) {
            break;
        }
        std::cout << std::endl << linhaAtual;
        std::cout << std::endl << colunaAtual << std::endl << std::endl;
    }

    std::cout << "\nParabéns! Você descobriu todos os números!\n";
}
