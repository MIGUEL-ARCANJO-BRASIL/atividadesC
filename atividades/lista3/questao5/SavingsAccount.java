package atividades.lista3.questao5;

public class SavingsAccount extends Account {
    private double monthlyInterestRate;

    public SavingsAccount(String accountNumber, double initialBalance, double monthlyInterestRate) {
        super(accountNumber, initialBalance);
        this.monthlyInterestRate = monthlyInterestRate;
    }

    public double getMonthlyInterestRate() {
        return monthlyInterestRate;
    }

    public void setMonthlyInterestRate(double monthlyInterestRate) {
        this.monthlyInterestRate = monthlyInterestRate;
    }

    public void applyMonthlyInterest() {
        double interest = getBalance() * monthlyInterestRate;
        deposit(interest);
        System.out.println("Rendimento mensal de R$ " + interest + " aplicado à conta poupança.");
    }
}
