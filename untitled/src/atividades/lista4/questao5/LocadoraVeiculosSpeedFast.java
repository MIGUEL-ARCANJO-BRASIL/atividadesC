package atividades.lista4.questao5;

public class LocadoraVeiculosSpeedFast {
    public static void main(String[] args) {
        Vehicle econ = new EconomicCar("Fiat", "Mobi", 120.00);
        Vehicle suv = new SUV("Toyota", "Hilux", 280.00, true);
        Vehicle premium = new PremiumCar("BMW", "X6", 600.00, "Serviço de bordo, seguro completo, assistência 24h");

        econ.displayRentalInfo();
        suv.displayRentalInfo();
        premium.displayRentalInfo();
    }

}
