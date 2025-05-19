package atividades.lista4.questao10;

public class FamilyPlan extends SubscriptionPlan {
    private int maxUsers;

    public FamilyPlan(double monthlyPrice, int maxUsers) {
        super("Plano Família", monthlyPrice);
        this.maxUsers = maxUsers;
    }

    public int getMaxUsers() {
        return maxUsers;
    }

    @Override
    public void displayPlanDetails() {
        System.out.println("Plano: " + getPlanName());
        System.out.println("Preço mensal: R$" + getMonthlyPrice());
        System.out.println("Número máximo de usuários: " + maxUsers);
        System.out.println("Acesso para múltiplos usuários simultâneos.");
        System.out.println("----------------------------------");
    }
}
