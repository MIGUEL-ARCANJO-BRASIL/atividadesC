package atividades.lista5.questao8;

import atividades.lista5.questao7.TeamController;

import java.util.Scanner;

public class MainItem {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ItemController controller = new ItemController();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[0] - Sair");
            System.out.println("[1] - Adicionar produtos");
            System.out.println("[2] - Remover produtos");
            System.out.println("[3] - Listar produtoss");
            System.out.println("[4] - Calcular valor total do carrinho");
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
                    controller.calculateTotal();
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }
        }
    }
}
