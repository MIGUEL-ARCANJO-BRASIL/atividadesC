package atividades.lista5.questao5;

import atividades.lista5.CrudRepository;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Operations implements CrudRepository<CurrentAccount> {

    List<CurrentAccount> currentAccountList;

    public Operations() {
        this.currentAccountList = new ArrayList<>();
    }

    @Override
    public void save(Scanner s) {
        System.out.println("Bem vindo ao Cadastro de contas corrente");
        System.out.println();
        s.nextLine();
        System.out.println("Nome: ");
        String holder = s.nextLine();
        System.out.println("Saldo inicial: ");
        float balance = s.nextFloat();
        currentAccountList.add(new CurrentAccount(holder, balance));

        System.out.println("Conta criada com sucesso!");
    }

    @Override
    public void delete(Scanner s) {
        if (currentAccountList.isEmpty()) {
            System.err.println("Nenhuma conta cadastrada!");
            return;
        }
        s.nextLine();
        System.out.println("Informe o titula da conta corrente: ");
        String holder = s.nextLine();
        for (CurrentAccount currentAccount : currentAccountList) {
            if (currentAccount.getHolder().trim().equalsIgnoreCase(holder.trim())) {
                currentAccountList.remove(currentAccount);
                System.out.println("Conta removida com sucesso!");
            }
        }
    }

    @Override
    public List<CurrentAccount> findAll() {
        if (currentAccountList.isEmpty()) {
            System.err.println("Nenhuma conta cadastrada!");
            return null;
        }
        return currentAccountList;
    }

    public void withdrawal(Scanner s) {
        s.nextLine();
        System.out.println("Informe o titular da conta que vai ser realizado o saque: ");
        for (int i = 0; i < currentAccountList.size(); i++) {
            System.out.println((i + 1) + " " + currentAccountList.get(i).getHolder());
        }
        String holder = s.nextLine();
        for (CurrentAccount currentAccount : currentAccountList) {
            if (currentAccount.getHolder().trim().equalsIgnoreCase(holder.trim())) {
                System.out.println("Informe o valor do saque: ");
                float amount = s.nextFloat();
                if (currentAccount.getBalance() < amount) {
                    System.err.println("Saldo insuficiente!");
                    return;
                } else if (amount < 0) {
                    System.err.println("Não pode valor negativo!");
                    return;
                }
                System.out.println("Saque realizado com sucesso!'");

                Transaction transaction =
                        new Transaction(
                                new Date().toInstant().atZone(java.time.ZoneId.systemDefault()).toLocalDateTime(),
                                amount, "Saque");
                currentAccount.getHistoric().add(transaction);
                currentAccount.setBalance(currentAccount.getBalance() - amount);
                System.out.println("Valor atual do saldo: " + currentAccount.getBalance());
                break;
            }
        }
    }

    public void deposit(Scanner s) {
        s.nextLine();
        System.out.println("Informe o titular da conta que vai ser realizado o depósito: ");
        for (int i = 0; i < currentAccountList.size(); i++) {
            System.out.println((i + 1) + " " + currentAccountList.get(i).getHolder());
        }
        String holder = s.nextLine();

        for (CurrentAccount currentAccount : currentAccountList) {
            if (currentAccount.getHolder().trim().equalsIgnoreCase(holder.trim())) {
                System.out.println("Informe o valor do depósito: ");
                float amount = s.nextFloat();
                if (amount < 0) {
                    System.err.println("Não pode valor negativo!");
                    return;
                }
                System.out.println("Depósito realizado com sucesso!'");

                Transaction transaction =
                        new Transaction(
                                new Date().toInstant().atZone(java.time.ZoneId.systemDefault()).toLocalDateTime(),
                                amount, "Depósito");
                currentAccount.getHistoric().add(transaction);
                currentAccount.setBalance(currentAccount.getBalance() + amount);
                System.out.println("Valor atual do saldo: " + currentAccount.getBalance());
                break;
            }
        }
    }

    public void listAllTransactions(Scanner s) {
        s.nextLine();
        System.out.println("Informe o titular da conta: ");
        for (int i = 0; i < currentAccountList.size(); i++) {
            System.out.println((i + 1) + " " + currentAccountList.get(i).getHolder());
        }
        String holder = s.nextLine();

        for (CurrentAccount currentAccount : currentAccountList) {
            if (currentAccount.getHolder().trim().equalsIgnoreCase(holder.trim())) {
                currentAccount.getHistoric().forEach(transaction ->
                        System.out.println(transaction.toString()));
                break;
            }
        }
    }
}

