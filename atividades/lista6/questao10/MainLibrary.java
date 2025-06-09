package atividades.lista6.questao10;

import java.util.Scanner;

public class MainLibrary {
    public static void main(String[] args) {
        Library library = new Library();

        library.addItem(new Books("Dom Quixote", "Miguel de Cervantes"));
        library.addItem(new Books("1984", "George Orwell"));
        library.addItem(new Magazine("Revista Ciência Hoje", 42));
        library.addItem(new Magazine("Revista Veja", 101));

        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("[0] - Sair");
            System.out.println("[1] - Listar itens");
            System.out.println("[2] - Emprestar item");
            System.out.println("[3] - Devolver item");
            System.out.print("Escolha uma opção: ");

            int option = scanner.nextInt();
            scanner.nextLine();

            if (option == 0) {
                System.out.println("Encerrando sistema.");
                break;
            }

            switch (option) {
                case 1:
                    System.out.println("\nItens na biblioteca:");
                    for (LibraryItem item : library.getItems()) {
                        System.out.println("- " + item);
                    }
                    break;
                case 2:
                    System.out.print("Título do item para empréstimo: ");
                    String borrowTitle = scanner.nextLine();
                    if (library.borrowItem(borrowTitle)) {
                        System.out.println("Item '" + borrowTitle + "' emprestado com sucesso!");
                    } else {
                        System.out.println("Item indisponível para empréstimo ou não encontrado.");
                    }
                    break;
                case 3:
                    System.out.print("Título do item para devolução: ");
                    String returnTitle = scanner.nextLine();
                    if (library.returnItem(returnTitle)) {
                        System.out.println("Item '" + returnTitle + "' devolvido com sucesso!");
                    } else {
                        System.out.println("Item não está emprestado ou não encontrado.");
                    }
                    break;
                default:
                    System.out.println("Opção inválida.");
            }
        }


    }
}
