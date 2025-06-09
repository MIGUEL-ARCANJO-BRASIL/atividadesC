package atividades.lista5.questao4;

import atividades.lista5.CrudRepository;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Biblioteca implements CrudRepository<Livro> {
    private List<Livro> livrosList;

    public Biblioteca() {
        livrosList = new ArrayList<>();
    }

    @Override
    public void save(Scanner s) {
        System.out.println("CADASTRO DE LIVROS!");

        s.nextLine();
        System.out.println("Título: ");
        String title = s.nextLine();
        System.out.println("Autor: ");
        String author = s.nextLine();
        System.out.println("ISBN: ");
        String isbn = s.nextLine();

        livrosList.add(new Livro(title, author, isbn));
    }

    @Override
    public void delete(Scanner s) {
        System.out.println("REMOVER LIVRO!");
        s.nextLine();
        System.out.println("Código do livro:");
        String isbn = s.nextLine();
        if (livrosList.isEmpty()) {
            System.err.println("Nenhum livro cadastrado!");
            return;
        }
        for (Livro livro : livrosList) {
            if (isbn.trim().equals(livro.getIsbn().trim())) {
                System.out.println("Livro removido com sucesso!");
                livrosList.remove(livro);
                break;
            }
        }
    }

    @Override
    public List<Livro> findAll() {
        return livrosList;
    }

    public void getBookByTitle(Scanner s) {
        System.out.println("BUSCAR LIVRO PELO TÍTULO");
        s.nextLine();
        System.out.println("Título: ");
        String title = s.nextLine();
        Livro l = livrosList.stream().filter(livro -> livro.getTitle().trim().
                equalsIgnoreCase(title.trim())).findFirst().orElse(null);

        System.out.println(l.toString());
    }
}
