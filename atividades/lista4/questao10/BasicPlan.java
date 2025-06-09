package atividades.lista4.questao10;

public class BasicPlan extends SubscriptionPlan {

    public BasicPlan(double monthlyPrice) {
        super("Plano Básico", monthlyPrice);
    }

    @Override
    public void displayPlanDetails() {
        System.out.println("Plano: " + getPlanName());
        System.out.println("Preço mensal: R$" + getMonthlyPrice());
        System.out.println("Acesso a filmes em qualidade padrão.");
        System.out.println("----------------------------------");
    }
}
