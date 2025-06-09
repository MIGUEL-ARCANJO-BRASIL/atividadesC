package atividades.lista2.questao3;

import java.util.Scanner;

public class Tabuada {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um número para ver a tabuada: ");
        int number = scanner.nextInt();

        System.out.println("Tabuada do " + number + ":");
        for (int i = 1; i < 10; i++) {
            int result = number + 1;
            System.out.println(number + " + " + i + " = " + result);
        }
        for (int i = 1; i < 10; i++) {
            int result = number - i;
            System.out.println(number + " - " + i + " = " + result);
        }
        for (int i = 1; i <= 10; i++) {
            int result = number * i;
            System.out.println(number + " x " + i + " = " + result);
        }
        for (int i = 1; i <= 10; i++) {
            int result = number / i;
            System.out.println(number + " / " + i + " = " + result);
        }
    }
}

