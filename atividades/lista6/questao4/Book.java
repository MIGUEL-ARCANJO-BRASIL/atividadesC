package atividades.lista6.questao4;

public class Book {
    private String title;
    private String author;
    private Category category;

    public Book(String title, String author, Category category) {
        this.title = title;
        this.author = author;
        this.category = category;
    }

    public void printInfos() {
        System.out.println("Título: " + title);
        System.out.println("Autor: " + author);
        System.out.println("Categoria: " + category);
        System.out.println("---------------------");
    }
}
