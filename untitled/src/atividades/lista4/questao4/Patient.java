package atividades.lista4.questao4;

public abstract class Patient {
    private String name;
    private int age;
    private String document;

    public Patient(String name, int age, String document) {
        this.name = name;
        this.age = age;
        this.document = document;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getDocument() {
        return document;
    }

    public abstract void displayInfo();
}

