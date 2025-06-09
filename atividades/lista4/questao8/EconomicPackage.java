package atividades.lista4.questao8;

public class EconomicPackage extends TravelPackage {
    private String accommodationType;

    public EconomicPackage(String destination, double price, String accommodationType) {
        super(destination, price);
        this.accommodationType = accommodationType;
    }

    public String getAccommodationType() {
        return accommodationType;
    }

    @Override
    public void displayPackageDetails() {
        System.out.println("Pacote Econômico:");
        System.out.println("Destino: " + getDestination());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Hospedagem: " + accommodationType);
        System.out.println("Hospedagem simples e econômica.");
        System.out.println("----------------------------------");
    }
}

