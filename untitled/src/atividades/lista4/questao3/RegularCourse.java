package atividades.lista4.questao3;

public class RegularCourse extends Course {
    private boolean includesLunch;

    public RegularCourse(String name, int durationInMonths, double monthlyFee, boolean includesLunch) {
        super(name, durationInMonths, monthlyFee);
        this.includesLunch = includesLunch;
    }

    public boolean isIncludesLunch() {
        return includesLunch;
    }

    @Override
    public void displayDetails() {
        System.out.println("Curso Regular: " + getName());
        System.out.println("Duração: " + getDurationInMonths() + " meses");
        System.out.println("Mensalidade: R$" + getMonthlyFee());
        System.out.println("Inclui almoço: " + (includesLunch ? "Sim" : "Não"));
        System.out.println("----------------------------------");
    }
}
