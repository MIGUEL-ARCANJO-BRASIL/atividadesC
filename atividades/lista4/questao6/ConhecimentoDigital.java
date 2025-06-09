package atividades.lista4.questao6;

public class ConhecimentoDigital {
    public static void main(String[] args) {
        Book book1 = new PhysicalBook("O Alquimista", "Paulo Coelho", 39.90, 208);
        Book book2 = new EBook("Clean Code", "Robert C. Martin", 59.90, "PDF", true);
        Book book3 = new AudioBook("A Arte da Guerra", "Sun Tzu", 49.90, 2.5, "João Mendes");

        book1.displayInfo();
        book2.displayInfo();
        book3.displayInfo();
    }
}
