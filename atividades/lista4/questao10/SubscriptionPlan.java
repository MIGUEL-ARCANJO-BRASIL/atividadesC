package atividades.lista4.questao10;

public abstract class SubscriptionPlan {
    private String planName;
    private double monthlyPrice;

    public SubscriptionPlan(String planName, double monthlyPrice) {
        this.planName = planName;
        this.monthlyPrice = monthlyPrice;
    }

    public String getPlanName() {
        return planName;
    }

    public double getMonthlyPrice() {
        return monthlyPrice;
    }

    public abstract void displayPlanDetails();
}
