package atividades.lista4.questao6;

public class AudioBook extends Book {
    private double duration;
    private String narrator;

    public AudioBook(String title, String author, double price, double duration, String narrator) {
        super(title, author, price);
        this.duration = duration;
        this.narrator = narrator;
    }

    public double getDuration() {
        return duration;
    }

    public String getNarrator() {
        return narrator;
    }

    @Override
    public void displayInfo() {
        System.out.println("Audiobook:");
        System.out.println("Título: " + getTitle());
        System.out.println("Autor: " + getAuthor());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Duração: " + duration + " horas");
        System.out.println("Narrador: " + narrator);
        System.out.println("Reproduzível em dispositivos móveis e desktop.");
        System.out.println("----------------------------------");
    }
}
