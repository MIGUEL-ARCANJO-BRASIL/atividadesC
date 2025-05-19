package atividades.lista4.questao6;

public class PhysicalBook extends Book {
    private int pages;

    public PhysicalBook(String title, String author, double price, int pages) {
        super(title, author, price);
        this.pages = pages;
    }

    public int getPages() {
        return pages;
    }

    @Override
    public void displayInfo() {
        System.out.println("Livro Físico:");
        System.out.println("Título: " + getTitle());
        System.out.println("Autor: " + getAuthor());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Número de páginas: " + pages);
        System.out.println("Disponível para entrega física.");
        System.out.println("----------------------------------");
    }
}

