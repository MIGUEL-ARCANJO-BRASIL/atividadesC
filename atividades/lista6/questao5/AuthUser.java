package atividades.lista6.questao5;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AuthUser {
    private static List<User> usersList = new ArrayList<>();

    static {
        loadSampleUsers();
    }


    public static void authenticate(Scanner s) {
        User user = new User();
        System.out.println("Nome de usuário: ");
        user.setName(s.nextLine());
        System.out.println("Senha: ");
        user.setPassword(s.nextLine());

        for (User u : usersList) {
            if (u.getName().trim().equals(user.getName().trim()) &&
                    u.getPassword().trim().equals(user.getPassword().trim())) {
                System.out.println("Usuário '" + user.getName().toUpperCase() + "' autenticado com sucesso!");
                return;
            }
        }
        System.err.println("Nome e/ou Senha incorreta. Acesso negado.");
    }

    private static void loadSampleUsers() {
        usersList.add(new User("alice", "pass123"));
        usersList.add(new User("bob", "qwerty"));
        usersList.add(new User("charlie", "abc123"));
        usersList.add(new User("david", "senha456"));
        usersList.add(new User("eva", "1234"));
        usersList.add(new User("frank", "test321"));
        usersList.add(new User("grace", "java2025"));
        usersList.add(new User("helen", "code789"));
        usersList.add(new User("ian", "secure99"));
        usersList.add(new User("julia", "mypassword"));
    }
}
