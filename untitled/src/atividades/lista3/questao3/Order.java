package atividades.lista3.questao3;

import java.util.List;

public class Order {
    private Client client;
    private List<Product> products;
    private double totalValue;

    public Order(Client client, List<Product> products) {
        this.client = client;
        this.products = products;
        this.totalValue = 0;
    }

    public void calculateTotalValue() {
        totalValue = 0;
        for (Product product : products) {
            totalValue += product.getPrice();
        }
    }

    public void showDetails() {
        System.out.println("Detalhes do Pedido:");
        client.showDetails();
        System.out.println("Produtos:");
        for (Product product : products) {
            System.out.println("- " + product.getName() + " - R$" + product.getPrice());
        }
        System.out.println("Valor total: R$" + totalValue);
        System.out.println("----------------------------------");
    }
}
