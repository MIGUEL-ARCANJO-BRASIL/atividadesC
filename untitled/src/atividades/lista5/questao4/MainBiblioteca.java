package atividades.lista5.questao4;

import java.util.Scanner;

public class MainBiblioteca {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Biblioteca biblioteca = new Biblioteca();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[1] - Adicionar livro");
            System.out.println("[2] - Remover livro");
            System.out.println("[3] - Listar livros");
            System.out.println("[4] - Busca livro pelo título");
            opcao = s.nextInt();

            switch (opcao) {
                case 1:
                    biblioteca.save(s);
                    break;
                case 2:
                    biblioteca.delete(s);
                    break;
                case 3:
                    System.out.println(biblioteca.findAll().toString());
                    break;
                case 4:
                    biblioteca.getBookByTitle(s);
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
