package atividades.lista4.questao9;

public class ComboPromotion extends MenuItem {
    private String[] itemsIncluded;
    private double discountPercentage;

    public ComboPromotion(String name, double price, String[] itemsIncluded, double discountPercentage) {
        super(name, price);
        this.itemsIncluded = itemsIncluded;
        this.discountPercentage = discountPercentage;
    }

    public String[] getItemsIncluded() {
        return itemsIncluded;
    }

    public double getDiscountPercentage() {
        return discountPercentage;
    }

    @Override
    public void displayDetails() {
        System.out.println("Combo promocional:");
        System.out.println("Nome: " + getName());
        System.out.println("Preço com desconto: R$" + getPrice());
        System.out.println("Itens inclusos:");
        for (String item : itemsIncluded) {
            System.out.println("- " + item);
        }
        System.out.println("Desconto aplicado: " + discountPercentage + "%");
        System.out.println("----------------------------------");
    }
}
