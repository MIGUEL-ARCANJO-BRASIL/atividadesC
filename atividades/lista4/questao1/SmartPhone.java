package atividades.lista4.questao1;

public class SmartPhone extends EletronicDevice {
    private int storage;

    public SmartPhone(String name, String brand, double price, int storage) {
        super(name, brand, price);
        this.storage = storage;
    }

    public int getStorage() {
        return storage;
    }

    @Override
    public void displayDetails() {
        System.out.println("Smartphone: " + this.getName() + " " + this.getBrand());
        System.out.println("Preço: R$" + this.getPrice());
        System.out.println("Armazenamento: " + this.getStorage() + "GB");
        System.out.println("----------------------------------");
    }
}
