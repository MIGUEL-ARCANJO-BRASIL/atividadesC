package atividades.lista4.questao8;

public class LuxuryPackage extends TravelPackage {
    private boolean privateTransfer;

    public LuxuryPackage(String destination, double price, boolean privateTransfer) {
        super(destination, price);
        this.privateTransfer = privateTransfer;
    }

    public boolean hasPrivateTransfer() {
        return privateTransfer;
    }

    @Override
    public void displayPackageDetails() {
        System.out.println("Pacote Luxo:");
        System.out.println("Destino: " + getDestination());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Traslado privativo: " + (privateTransfer ? "Sim" : "Não"));
        System.out.println("Benefícios exclusivos e hospedagem premium.");
        System.out.println("----------------------------------");
    }
}
