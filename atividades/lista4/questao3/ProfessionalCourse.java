package atividades.lista4.questao3;

public class ProfessionalCourse extends Course {
    private boolean jobGuarantee;

    public ProfessionalCourse(String name, int durationInMonths, double monthlyFee, boolean jobGuarantee) {
        super(name, durationInMonths, monthlyFee);
        this.jobGuarantee = jobGuarantee;
    }

    public boolean isJobGuarantee() {
        return jobGuarantee;
    }

    @Override
    public void displayDetails() {
        System.out.println("Curso Profissionalizante: " + getName());
        System.out.println("Duração: " + getDurationInMonths() + " meses");
        System.out.println("Mensalidade: R$" + getMonthlyFee());
        System.out.println("Garantia de emprego: " + (jobGuarantee ? "Sim" : "Não"));
        System.out.println("----------------------------------");
    }
}
