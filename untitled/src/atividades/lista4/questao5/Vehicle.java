package atividades.lista4.questao5;

public abstract class Vehicle {
    private String brand;
    private String model;
    private double dailyRate;

    public Vehicle(String brand, String model, double dailyRate) {
        this.brand = brand;
        this.model = model;
        this.dailyRate = dailyRate;
    }

    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    public double getDailyRate() {
        return dailyRate;
    }

    public abstract void displayRentalInfo();
}