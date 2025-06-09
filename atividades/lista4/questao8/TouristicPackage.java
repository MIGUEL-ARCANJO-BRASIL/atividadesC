package atividades.lista4.questao8;

public class TouristicPackage extends TravelPackage {
    private int numberOfTours;

    public TouristicPackage(String destination, double price, int numberOfTours) {
        super(destination, price);
        this.numberOfTours = numberOfTours;
    }

    public int getNumberOfTours() {
        return numberOfTours;
    }

    @Override
    public void displayPackageDetails() {
        System.out.println("Pacote Turístico:");
        System.out.println("Destino: " + getDestination());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Número de passeios inclusos: " + numberOfTours);
        System.out.println("Hospedagem confortável com passeios guiados.");
        System.out.println("----------------------------------");
    }
}

