package atividades.lista4.questao8;

public class ViagensMundoAberto {
    public static void main(String[] args) {
        TravelPackage economic = new EconomicPackage("Rio de Janeiro", 1500.00, "Pousada");
        TravelPackage touristic = new TouristicPackage("Foz do Iguaçu", 3200.00, 5);
        TravelPackage luxury = new LuxuryPackage("Fernando de Noronha", 10000.00, true);

        economic.displayPackageDetails();
        touristic.displayPackageDetails();
        luxury.displayPackageDetails();
    }
}
