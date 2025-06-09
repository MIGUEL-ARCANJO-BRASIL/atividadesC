package atividades.lista4.questao6;

public class EBook extends Book {
    private String format;
    private boolean hasInteractiveContent;

    public EBook(String title, String author, double price, String format, boolean hasInteractiveContent) {
        super(title, author, price);
        this.format = format;
        this.hasInteractiveContent = hasInteractiveContent;
    }

    public String getFormat() {
        return format;
    }

    public boolean hasInteractiveContent() {
        return hasInteractiveContent;
    }

    @Override
    public void displayInfo() {
        System.out.println("E-Book:");
        System.out.println("Título: " + getTitle());
        System.out.println("Autor: " + getAuthor());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Formato: " + format);
        System.out.println("Conteúdo interativo: " + (hasInteractiveContent ? "Sim" : "Não"));
        System.out.println("Disponível para download imediato.");
        System.out.println("----------------------------------");
    }
}
