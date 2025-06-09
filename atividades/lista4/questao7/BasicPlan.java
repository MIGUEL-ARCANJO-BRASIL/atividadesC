package atividades.lista4.questao7;

public class BasicPlan extends WorkoutPlan {

    public BasicPlan(double monthlyPrice) {
        super("Plano Básico", monthlyPrice);
    }

    @Override
    public void displayPlanDetails() {
        System.out.println("Plano: " + getPlanName());
        System.out.println("Preço mensal: R$" + getMonthlyPrice());
        System.out.println("Acesso: Musculação");
        System.out.println("Sem aulas em grupo, sem personal trainer.");
        System.out.println("----------------------------------");
    }
}

