package atividades.lista4.questao5;

public class SUV extends Vehicle {
    private boolean has4x4;

    public SUV(String brand, String model, double dailyRate, boolean has4x4) {
        super(brand, model, dailyRate);
        this.has4x4 = has4x4;
    }

    public boolean has4x4() {
        return has4x4;
    }

    @Override
    public void displayRentalInfo() {
        System.out.println("SUV:");
        System.out.println("Marca: " + getBrand());
        System.out.println("Modelo: " + getModel());
        System.out.println("Diária: R$" + getDailyRate());
        System.out.println("Possui tração 4x4: " + (has4x4 ? "Sim" : "Não"));
        System.out.println("Política: Espaçoso, ideal para viagens em família.");
        System.out.println("----------------------------------");
    }
}
