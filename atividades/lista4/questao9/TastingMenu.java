package atividades.lista4.questao9;

public class TastingMenu extends MenuItem {
    private String experienceDescription;
    private int numberOfCourses;

    public TastingMenu(String name, double price, String experienceDescription, int numberOfCourses) {
        super(name, price);
        this.experienceDescription = experienceDescription;
        this.numberOfCourses = numberOfCourses;
    }

    public String getExperienceDescription() {
        return experienceDescription;
    }

    public int getNumberOfCourses() {
        return numberOfCourses;
    }

    @Override
    public void displayDetails() {
        System.out.println("Menu degustação:");
        System.out.println("Nome: " + getName());
        System.out.println("Preço: R$" + getPrice());
        System.out.println("Descrição da experiência: " + experienceDescription);
        System.out.println("Número de pratos: " + numberOfCourses);
        System.out.println("----------------------------------");
    }
}
