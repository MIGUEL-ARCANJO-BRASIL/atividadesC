package atividades.lista5.questao7;

import java.util.Scanner;

public class MainTeam {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        TeamController controller = new TeamController();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[0] - Sair");
            System.out.println("[1] - Adicionar time");
            System.out.println("[2] - Remover time");
            System.out.println("[3] - Listar times");
            System.out.println("[4] - Adicionar Jogadores num Time");
            System.out.println("[5] - Remover Jogadores num Time");
            opcao = s.nextInt();

            switch (opcao) {
                case 0:
                    return;
                case 1:
                    controller.save(s);
                    break;
                case 2:
                    controller.delete(s);
                    break;
                case 3:
                    System.out.println(controller.findAll().toString());
                    break;
                case 4:
                    controller.addPlayerOnTeam(s);
                    break;
                case 5:
                    controller.removePlayerOnTeam(s);
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }
        }
    }
}
