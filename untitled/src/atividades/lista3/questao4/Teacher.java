package atividades.lista3.questao4;

public class Teacher extends People {

    private double salary;
    private String discipline;
    private String areaActivity;

    public Teacher(String name, int age, String cpf, String addres, double salary, String discipline, String areaActivity) {
        super(name, age, cpf, addres);
        this.salary = salary;
        this.discipline = discipline;
        this.areaActivity = areaActivity;
    }


}
