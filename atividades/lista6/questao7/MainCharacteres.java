package atividades.lista6.questao7;

import java.util.Scanner;

public class MainCharacteres {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (true){
            System.out.println("[0]- Sair");
            System.out.println("[1]- Digite uma palavra");
            int op = s.nextInt();
            if (op == 0){
                System.out.println("saindo...");
                return;
            }
            s.nextLine();
            System.out.println("Digite uma palavra: ");
            ManipulateCharacters.manipulate(s.nextLine());
        }
    }
}
