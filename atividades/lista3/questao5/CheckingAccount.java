package atividades.lista3.questao5;

public class CheckingAccount extends Account {
    private double overdraftLimit;

    public CheckingAccount(String accountNumber, double initialBalance, double overdraftLimit) {
        super(accountNumber, initialBalance);
        this.overdraftLimit = overdraftLimit;
    }

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    public void setOverdraftLimit(double overdraftLimit) {
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public boolean withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Valor de saque inválido.");
            return false;
        }

        double availableFunds = getBalance() + overdraftLimit;

        if (availableFunds >= amount) {
            double currentBalance = getBalance();

            if (currentBalance >= amount) {

                return super.withdraw(amount);
            } else {

                setBalance(currentBalance - amount);
                System.out.println("Saque de R$ " + amount + " realizado com uso do cheque especial.");
                return true;
            }
        } else {
            System.out.println("Saldo e limite de cheque especial insuficientes para saque de R$ " + amount + ".");
            return false;
        }
    }

    protected void setBalance(double balance) {
        super.balance = balance;
    }
}

