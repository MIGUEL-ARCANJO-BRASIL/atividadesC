package atividades.lista6.questao8;

import java.util.Objects;

public class DatabaseConnection {
    private static DatabaseConnection instance;

    private DatabaseConnection() {
        System.out.println("Conexão com o banco de dados criada.");
    }

    public static DatabaseConnection getInstance() {
        if (instance == null) {
            instance = new DatabaseConnection();
        }
        return instance;
    }

    public void connect() {
        System.out.println("Conectado ao banco de dados.");
    }

    public void disconnect() {
        System.out.println("Desconectado do banco de dados.");
    }

    public void create(){
        System.out.println("Criando objeto no banco de dados.");
    }
}
