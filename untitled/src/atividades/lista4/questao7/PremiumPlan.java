package atividades.lista4.questao7;

public class PremiumPlan extends WorkoutPlan {
    private boolean personalTrainer;
    private boolean exclusiveNutrition;

    public PremiumPlan(double monthlyPrice, boolean personalTrainer, boolean exclusiveNutrition) {
        super("Plano Premium", monthlyPrice);
        this.personalTrainer = personalTrainer;
        this.exclusiveNutrition = exclusiveNutrition;
    }

    public boolean hasPersonalTrainer() {
        return personalTrainer;
    }

    public boolean hasExclusiveNutrition() {
        return exclusiveNutrition;
    }

    @Override
    public void displayPlanDetails() {
        System.out.println("Plano: " + getPlanName());
        System.out.println("Preço mensal: R$" + getMonthlyPrice());
        System.out.println("Acesso: Musculação");
        System.out.println("Personal trainer: " + (personalTrainer ? "Sim" : "Não"));
        System.out.println("Nutrição exclusiva: " + (exclusiveNutrition ? "Sim" : "Não"));
        System.out.println("----------------------------------");
    }
}
