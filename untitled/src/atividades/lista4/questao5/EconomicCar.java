package atividades.lista4.questao5;

public class EconomicCar extends Vehicle {
    public EconomicCar(String brand, String model, double dailyRate) {
        super(brand, model, dailyRate);
    }

    @Override
    public void displayRentalInfo() {
        System.out.println("Carro Econômico:");
        System.out.println("Marca: " + getBrand());
        System.out.println("Modelo: " + getModel());
        System.out.println("Diária: R$" + getDailyRate());
        System.out.println("Política: Baixo consumo de combustível, ideal para cidade.");
        System.out.println("----------------------------------");
    }
}