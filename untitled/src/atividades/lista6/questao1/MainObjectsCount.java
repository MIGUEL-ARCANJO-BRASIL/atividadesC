package atividades.lista6.questao1;

import java.util.Scanner;

public class MainObjectsCount {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (true) {
            System.out.println("Deseja criar um objeto? [ 1 - SIM / 2 -NÃO]");
            int option = s.nextInt();
            if (option == 2) {
                System.out.println("\nSaindo...");
                ObjectCount.getCount();
                return;
            }

            new ObjectCount();
        }
    }
}
