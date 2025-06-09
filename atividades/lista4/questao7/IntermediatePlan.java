package atividades.lista4.questao7;

public class IntermediatePlan extends WorkoutPlan {
    private boolean groupClasses;

    public IntermediatePlan(double monthlyPrice, boolean groupClasses) {
        super("Plano Intermediário", monthlyPrice);
        this.groupClasses = groupClasses;
    }

    public boolean hasGroupClasses() {
        return groupClasses;
    }

    @Override
    public void displayPlanDetails() {
        System.out.println("Plano: " + getPlanName());
        System.out.println("Preço mensal: R$" + getMonthlyPrice());
        System.out.println("Acesso: Musculação");
        System.out.println("Inclui aulas em grupo: " + (groupClasses ? "Sim" : "Não"));
        System.out.println("Sem personal trainer.");
        System.out.println("----------------------------------");
    }
}

