package atividades.lista6.questao5;

import java.util.Scanner;

public class MainAuthUser {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        while (true) {
            System.out.println("[0] - Sair");
            System.out.println("[1] - Acessar sistema");
            int option = s.nextInt();
            s.nextLine();

            switch (option) {
                case 0:
                    return;
                case 1:
                    System.out.println("Autenticação necessária para continuar.");
                    AuthUser.authenticate(s);
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }
}
