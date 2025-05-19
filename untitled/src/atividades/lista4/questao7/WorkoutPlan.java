package atividades.lista4.questao7;

public abstract class WorkoutPlan {
    private String planName;
    private double monthlyPrice;

    public WorkoutPlan(String planName, double monthlyPrice) {
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
