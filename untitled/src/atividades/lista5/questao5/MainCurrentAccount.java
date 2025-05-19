package atividades.lista5.questao5;

import atividades.lista5.questao4.Biblioteca;

import java.util.Scanner;

public class MainCurrentAccount {
    public static void main(String[] args) {
        Operations operations = new Operations();
        Scanner s = new Scanner(System.in);
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[0] - Sair]");
            System.out.println("[1] - Adicionar conta corrente");
            System.out.println("[2] - Remover conta corrente");
            System.out.println("[3] - Listar contas corrente");
            System.out.println("[4] - Realizar Depósito");
            System.out.println("[5] - Realizar Saque");
            System.out.println("[6] - Listar extrato da conta corrente");
            opcao = s.nextInt();

            switch (opcao) {
                case 0:
                    return;
                case 1:
                    operations.save(s);
                    break;
                case 2:
                    operations.delete(s);
                    break;
                case 3:
                    System.out.println(operations.findAll().toString());
                    break;
                case 4:
                    operations.deposit(s);
                    break;
                case 5:
                    operations.withdrawal(s);
                    break;
                case 6:
                    operations.listAllTransactions(s);
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }

        }
    }
}
