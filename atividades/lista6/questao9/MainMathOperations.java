package atividades.lista6.questao9;

import java.util.Scanner;

public class MainMathOperations {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while (true) {
            System.out.println("[0] - Sair");
            System.out.println("[1] - Soma");
            System.out.println("[2] - Subtração");
            System.out.println("[3] - Multiplicação");
            System.out.println("[4] - Divisão");
            System.out.print("Escolha uma operação: ");

            int option = s.nextInt();

            if (option == 0) {
                System.out.println("Saindo...");
                break;
            }

            System.out.print("Digite o primeiro número: ");
            double num1 = s.nextDouble();

            System.out.print("Digite o segundo número: ");
            double num2 = s.nextDouble();

            try {
                double result = 0;
                switch (option) {
                    case 1:
                        result = MathOperations.add(num1, num2);
                        break;
                    case 2:
                        result = MathOperations.subtract(num1, num2);
                        break;
                    case 3:
                        result = MathOperations.multiply(num1, num2);
                        break;
                    case 4:
                        result = MathOperations.divide(num1, num2);
                        break;
                    default:
                        System.out.println("Opção inválida.");
                        continue;
                }
                System.out.println("Resultado: " + result);
            } catch (IllegalArgumentException e) {
                System.out.println("Erro: " + e.getMessage());
            }
        }
    }
}
