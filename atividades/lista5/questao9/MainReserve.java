package atividades.lista5.questao9;

import atividades.lista5.questao8.ItemController;

import java.util.Scanner;

public class MainReserve {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ReservationController controller = new ReservationController();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[0] - Sair");
            System.out.println("[1] - Adicionar reservas");
            System.out.println("[2] - Remover reservas");
            System.out.println("[3] - Listar Reservas");
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
