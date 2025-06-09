package atividades.lista4.questao9;

public class ALaCarteDish extends MenuItem {
    private String description;

    public ALaCarteDish(String name, double price, String description) {
        super(name, price);
        this.description = description;
    }

    public String getDescription() {
        return description;
    }

    @Override
    public void displayDetails() {
        System.out.println("Prato à la carte:");
        System.out.println("Nome: " + getName());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Descrição: " + description);
        System.out.println("----------------------------------");
    }
}
