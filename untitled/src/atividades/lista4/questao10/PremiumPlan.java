package atividades.lista4.questao10;

public class PremiumPlan extends SubscriptionPlan {
    private boolean has4KContent;
    private boolean earlyAccess;

    public PremiumPlan(double monthlyPrice, boolean has4KContent, boolean earlyAccess) {
        super("Plano Premium", monthlyPrice);
        this.has4KContent = has4KContent;
        this.earlyAccess = earlyAccess;
    }

    public boolean has4KContent() {
        return has4KContent;
    }

    public boolean hasEarlyAccess() {
        return earlyAccess;
    }

    @Override
    public void displayPlanDetails() {
        System.out.println("Plano: " + getPlanName());
        System.out.println("Preço mensal: R$" + getMonthlyPrice());
        System.out.println("Conteúdo em 4K: " + (has4KContent ? "Sim" : "Não"));
        System.out.println("Acesso antecipado a lançamentos: " + (earlyAccess ? "Sim" : "Não"));
        System.out.println("----------------------------------");
    }
}
