package atividades.lista4.questao3;

public class TechnicalCourse extends Course {
    private int internshipHours;

    public TechnicalCourse(String name, int durationInMonths, double monthlyFee, int internshipHours) {
        super(name, durationInMonths, monthlyFee);
        this.internshipHours = internshipHours;
    }

    public int getInternshipHours() {
        return internshipHours;
    }

    @Override
    public void displayDetails() {
        System.out.println("Curso Técnico: " + getName());
        System.out.println("Duração: " + getDurationInMonths() + " meses");
        System.out.println("Mensalidade: R$" + getMonthlyFee());
        System.out.println("Carga horária de estágio: " + internshipHours + " horas");
        System.out.println("----------------------------------");
    }
}
