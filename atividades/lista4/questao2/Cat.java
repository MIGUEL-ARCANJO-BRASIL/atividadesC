package atividades.lista4.questao2;
public class Cat extends Animal {
    private boolean indoorOnly;

    public Cat(String name, int age, String breed, boolean indoorOnly) {
        super(name, age, breed);
        this.indoorOnly = indoorOnly;
    }

    public boolean isIndoorOnly() {
        return indoorOnly;
    }

    @Override
    public void displayDetails() {
        System.out.println("Cat - Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Breed: " + getBreed());
        System.out.println("Indoor Only: " + (indoorOnly ? "Yes" : "No"));
        System.out.println("----------------------------------");
    }
}
