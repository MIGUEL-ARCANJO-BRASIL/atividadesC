package atividades.lista4.questao10;

public class StreaminCinePlus {
    public static void main(String[] args) {
        SubscriptionPlan basic = new BasicPlan(29.90);
        SubscriptionPlan family = new FamilyPlan(59.90, 5);
        SubscriptionPlan premium = new PremiumPlan(89.90, true, true);

        basic.displayPlanDetails();
        family.displayPlanDetails();
        premium.displayPlanDetails();
    }
}
