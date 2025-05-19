package atividades.lista5.questao10;

import atividades.lista5.questao9.ReservationController;

import java.util.Scanner;

public class MainEvent {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        EventController controller = new EventController();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[0] - Sair");
            System.out.println("[1] - Adicionar participante");
            System.out.println("[2] - Remover participante");
            System.out.println("[3] - Listar participantes");
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
                default:
                    System.out.println("Opção inválida");
                    break;
            }
        }
    }
}
