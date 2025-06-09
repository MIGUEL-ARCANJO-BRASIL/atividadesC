package atividades.lista3.questao3;

import java.util.Arrays;

public class LojaOnline {
    public static void main(String[] args) {
        Product p1 = new Product("Smartphone XYZ", 1200.00, 10);
        Product p2 = new Product("Fone Bluetooth", 150.00, 20);

        Client client = new Client("João Silva", "joao@email.com", "Rua A, 123");

        Order order = new Order(client, Arrays.asList(p1, p2));;

        client.placeOrder(order);

        p1.buyProduct(1);
        p2.buyProduct(2);

        p1.showDetails();
        p2.showDetails();
    }
}
