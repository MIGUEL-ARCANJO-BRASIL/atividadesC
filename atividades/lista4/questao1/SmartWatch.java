package atividades.lista4.questao1;

public class SmartWatch extends EletronicDevice {
    private int steps;
    public SmartWatch(String name, String brand, double price, int steps) {
        super(name, brand, price);
        this.steps = steps;
    }

    public int getSteps() {
        return steps;
    }

    @Override
    public void displayDetails() {
        System.out.println("Smartwatch: " + this.getName() + " " + this.getBrand());
        System.out.println("Preço: R$" + this.getPrice());
        System.out.println("Passo dados: " + this.getSteps());
        System.out.println("----------------------------------");
    }
}
