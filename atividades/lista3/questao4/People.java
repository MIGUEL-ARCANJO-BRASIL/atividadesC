package atividades.lista3.questao4;

public abstract class People {
    private String name;
    private int age;
    private String cpf;
    private String addres;

    public People(String name, int age, String cpf, String addres) {
        this.name = name;
        this.age = age;
        this.cpf = cpf;
        this.addres = addres;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getCpf() {
        return cpf;
    }

    public String getAddres() {
        return addres;
    }

}
