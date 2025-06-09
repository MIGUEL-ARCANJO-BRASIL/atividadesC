package atividades.lista5.questao3;

import java.util.Scanner;

public class MainPedido {
    public static void main(String[] args) {

        Pedido pedido = new Pedido();
        Scanner s = new Scanner(System.in);

        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[1] - Adicionar Produto");
            System.out.println("[2] - Remover Produto");
            System.out.println("[3] - Listar Produtos");
            System.out.println("[4] - Finalizar Pedido");
            opcao = s.nextInt();

            switch (opcao) {
                case 1:
                    pedido.save(s);
                    break;
                case 2:
                    pedido.delete(s);
                    break;
                case 3:
                    System.out.println(pedido.findAll().toString());
                    break;
                case 4:
                    pedido.calcularPrecoTotal();
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }

            System.out.println("Deseja continuar? [1 - SIM / 2 -NAO]");
            opcao = s.nextInt();
            if (opcao == 2) {
                break;
            }
        }

    }
}
