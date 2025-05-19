package atividades.lista4.questao9;

public class RestauranteSaborEArte {
    public static void main(String[] args) {
        MenuItem dish = new ALaCarteDish("Filé Mignon ao Molho Madeira", 45.00, "Filé mignon grelhado com molho madeira e batatas rústicas.");
        MenuItem combo = new ComboPromotion("Combo Família", 120.00,
                new String[]{"Pizza Grande", "Refrigerante 2L", "Sobremesa"}, 15);
        MenuItem tasting = new TastingMenu("Menu Degustação Sabor & Arte", 200.00, "Experiência gastronômica exclusiva com pratos selecionados.", 5);

        dish.displayDetails();
        combo.displayDetails();
        tasting.displayDetails();
    }
}
