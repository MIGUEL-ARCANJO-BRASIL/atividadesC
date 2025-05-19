package atividades.lista3.questao5;

public abstract class Account {
    private String accountNumber;
    protected double balance;

    public Account(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Depósito de R$ " + amount + " realizado com sucesso.");
        } else {
            System.out.println("Valor de depósito inválido.");
        }
    }

    public boolean withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            System.out.println("Saque de R$ " + amount + " realizado com sucesso.");
            return true;
        } else {
            System.out.println("Saldo insuficiente para saque de R$ " + amount + ".");
            return false;
        }
    }
}
