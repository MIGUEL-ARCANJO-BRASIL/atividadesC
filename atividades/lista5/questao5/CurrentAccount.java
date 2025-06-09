package atividades.lista5.questao5;

import java.util.ArrayList;
import java.util.List;

public class CurrentAccount {
    private String holder;
    private float balance;
    List<Transaction> historic;

    public CurrentAccount(String holder, float balance) {
        this.holder = holder;
        this.balance = balance;
        this.historic = new ArrayList<>();
    }

    public String getHolder() {
        return holder;
    }

    public void setHolder(String holder) {
        this.holder = holder;
    }

    public float getBalance() {
        return balance;
    }

    public void setBalance(float balance) {
        this.balance = balance;
    }

    public List<Transaction> getHistoric() {
        return historic;
    }

    public void setHistoric(List<Transaction> historic) {
        this.historic = historic;
    }

    @Override
    public String toString() {
        return "CurrentAccount{" +
                "holder='" + holder + '\'' +
                ", balance=" + balance +
                ", historic=" + historic +
                '}';
    }
}
