package atividades.lista6.questao2;

import java.util.Scanner;

public class MainMathOperations {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (true) {
            System.out.println("Digite a operação que deseja realizar: ");
            System.out.println("[0] - Sair");
            System.out.println("[1] - Soma de dois números");
            System.out.println("[2] - Calcular área do círculo");
            int operation = s.nextInt();


            switch (operation) {
                case 0:
                    return;
                case 1:
                    System.out.println("Digite o primeiro e o segundo número para a soma: ");
                    double sum = MathOperations.sum(s.nextDouble(), s.nextDouble());
                    System.out.println("Soma: " + sum);
                    break;
                case 2:
                    System.out.println("Digite o número do raio do círculo:");
                    double ray = MathOperations.calcCircleArea(s.nextDouble());
                    System.out.println("Raio: " + ray);
                    break;
            }
        }
    }
}
