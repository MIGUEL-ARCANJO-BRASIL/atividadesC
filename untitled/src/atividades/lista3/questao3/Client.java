package atividades.lista3.questao3;

public class Client {
    private String name;
    private String email;
    private String addres;

    public Client(String name, String email, String addres) {
        this.name = name;
        this.email = email;
        this.addres = addres;
    }
    public void showDetails(){
        System.out.println("Name: "+name);
        System.out.println("email: "+email);
        System.out.println("addres: "+addres);
    }

    public void placeOrder(Order order){
        System.out.println("Pedido realizado pelo cliente: " + name);
        order.calculateTotalValue();
        order.showDetails();
    }
}
