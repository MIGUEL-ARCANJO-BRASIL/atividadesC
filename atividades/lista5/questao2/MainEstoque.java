package atividades.lista5.questao2;

import java.util.Scanner;

public class MainEstoque {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Estoque estoque = new Estoque();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[1] - Adicionar Produto");
            System.out.println("[2] - Remover Produto");
            System.out.println("[3] - Listar Produtos");
            opcao = s.nextInt();

            switch (opcao) {
                case 1:
                    estoque.save(s);
                    break;
                case 2:
                    estoque.delete(s);
                    break;
                case 3:
                    System.out.println(estoque.findAll().toString());
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
