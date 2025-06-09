package atividades.lista4.questao5;

public class PremiumCar extends Vehicle {
    private String luxuryServices;

    public PremiumCar(String brand, String model, double dailyRate, String luxuryServices) {
        super(brand, model, dailyRate);
        this.luxuryServices = luxuryServices;
    }

    public String getLuxuryServices() {
        return luxuryServices;
    }

    @Override
    public void displayRentalInfo() {
        System.out.println("Carro Premium:");
        System.out.println("Marca: " + getBrand());
        System.out.println("Modelo: " + getModel());
        System.out.println("Diária: R$" + getDailyRate());
        System.out.println("Serviços de luxo: " + luxuryServices);
        System.out.println("Política: Atendimento diferenciado e alto padrão de conforto.");
        System.out.println("----------------------------------");
    }
}