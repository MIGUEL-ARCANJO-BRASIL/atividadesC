package atividades.lista4.questao1;

public class Notebook extends EletronicDevice{
    private int RAM;

    public Notebook(String name, String brand, double price, int RAM) {
        super(name, brand, price);
        this.RAM = RAM;
    }

    public int getRAM() {
        return RAM;
    }

    @Override
    public void displayDetails() {
        System.out.println("Notebook: " + this.getName() + " " + this.getBrand());
        System.out.println("Preço: R$" + this.getPrice());
        System.out.println("Memória RAM: " + this.getRAM() + "GB");
        System.out.println("----------------------------------");
    }
}
