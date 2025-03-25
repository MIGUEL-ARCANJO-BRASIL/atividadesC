#include <iostream>
#include<stdio.h>
#include<locale.h>
#include <ostream>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int matriz[3][3], vetor[3], acm_sum = 0, count = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Informe o " << count++ << "° número da matriz: " << std::endl;;
            std::cin >> matriz[i][j];
            acm_sum += matriz[i][j];
        }
        vetor[i] = acm_sum;
        acm_sum = 0;
        printf("\n");
    }
    std::cout << "SOMA DAS LINHAS: " << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "linha " << i << ": " << vetor[i] << std::endl;
    }
}
