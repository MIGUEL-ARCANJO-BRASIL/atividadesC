package atividades.lista3.questao4;

public class Student extends People {
    private String course;
    private String code;

    public Student(String name, int age, String cpf, String addres, String course, String code) {
        super(name, age, cpf, addres);
        this.course = course;
        this.code = code;
    }


}
