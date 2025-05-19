package atividades.lista6.questao4;

import java.util.ArrayList;
import java.util.Scanner;

public class MainBooks {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ArrayList<Book> books = new ArrayList<>();

        while (true) {
            System.out.println("[0] - Sair");
            System.out.println("[1] - Cadastrar livro");
            System.out.println("[2] - Listar livros");
            int op = s.nextInt();
            s.nextLine();

            switch (op) {
                case 0:
                    return;
                case 1:
                    System.out.print("Título: ");
                    String title = s.nextLine();

                    System.out.print("Autor: ");
                    String author = s.nextLine();

                    System.out.println("Escolha uma categoria:");
                    Category.listCategories();
                    int catIndex = s.nextInt();
                    Category category = Category.getByIndex(catIndex);

                    if (category == null) {
                        System.out.println("Categoria inválida!");
                    } else {
                        books.add(new Book(title, author, category));
                        System.out.println("Livro cadastrado com sucesso!");
                    }
                    break;
                case 2:
                    if (books.isEmpty()) {
                        System.out.println("Nenhum livro cadastrado.");
                    } else {
                        for (Book book : books) {
                            book.printInfos();
                        }
                    }
                    break;
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }
}
