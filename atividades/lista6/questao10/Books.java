package atividades.lista6.questao10;

public class Books extends LibraryItem {
    private String author;

    public Books(String title, String author) {
        super(title);
        this.author = author;
    }

    public String getAuthor() {
        return author;
    }

    @Override
    public String getItemType() {
        return "Livro";
    }

    @Override
    public String toString() {
        return super.toString() + " - Autor: " + author;
    }
}