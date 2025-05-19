package atividades.lista6.questao8;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MainUser {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        DatabaseConnection db = DatabaseConnection.getInstance();
        Set<User> setUser = new HashSet<>();
        db.connect();
        while (true) {
            System.out.println("[0] - Sair");
            System.out.println("[1] - Criar um Usuário");
            int op = s.nextInt();
            s.nextLine();

            if (op == 0) {
                System.out.println("Saindo...");
                db.disconnect();
                return;
            }

            System.out.println("Nome: ");
            String name = s.nextLine();
            System.out.println("Senha: ");
            String password = s.nextLine();

            User newUser = new User(name, password);
            if (setUser.contains(newUser)) {
                System.out.println("O usuário já existe.");
            } else {
                setUser.add(newUser);
                System.out.println("Usuário criado com sucesso.");
                db.create();
            }
        }
    }
}

