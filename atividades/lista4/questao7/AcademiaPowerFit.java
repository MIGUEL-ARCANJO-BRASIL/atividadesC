package atividades.lista4.questao7;

public class AcademiaPowerFit {
    public static void main(String[] args) {
        WorkoutPlan basic = new BasicPlan(80.00);
        WorkoutPlan intermediate = new IntermediatePlan(120.00, true);
        WorkoutPlan premium = new PremiumPlan(250.00, true, true);

        basic.displayPlanDetails();
        intermediate.displayPlanDetails();
        premium.displayPlanDetails();
    }

}
