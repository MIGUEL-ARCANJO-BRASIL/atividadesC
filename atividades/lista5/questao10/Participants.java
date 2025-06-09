package atividades.lista5.questao10;

public class Participants {
    private String name;
    private int age;
    private String type_ticket;

    public Participants(String name, int age, String type_ticket) {
        this.name = name;
        this.age = age;
        this.type_ticket = type_ticket;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getType_ticket() {
        return type_ticket;
    }

    public void setType_ticket(String type_ticket) {
        this.type_ticket = type_ticket;
    }

    @Override
    public String toString() {
        return "Participants{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", type_ticket='" + type_ticket + '\'' +
                '}';
    }
}
