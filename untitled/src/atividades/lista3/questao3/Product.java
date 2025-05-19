package atividades.lista3.questao3;

public class Product {
    private String name;
    private double price;
    private int quantity;

    public Product(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public void buyProduct(int quantity){
        if (quantity <= this.quantity) {
            this.quantity -= quantity;
            System.out.println("Compra realizada: " + quantity + " unidade(s) de " + this.name);
        } else {
            System.out.println("Estoque insuficiente para o produto: " + name);
        }
    }

    public void showDetails(){
        System.out.println("Name: "+name);
        System.out.println("price: "+price);
        System.out.println("quantity: "+quantity);
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }
}
