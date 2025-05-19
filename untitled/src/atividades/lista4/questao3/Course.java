package atividades.lista4.questao3;

public abstract class Course {
    private String name;
    private int durationInMonths;
    private double monthlyFee;

    public Course(String name, int durationInMonths, double monthlyFee) {
        this.name = name;
        this.durationInMonths = durationInMonths;
        this.monthlyFee = monthlyFee;
    }

    public String getName() {
        return name;
    }

    public int getDurationInMonths() {
        return durationInMonths;
    }

    public double getMonthlyFee() {
        return monthlyFee;
    }

    public abstract void displayDetails();
}
