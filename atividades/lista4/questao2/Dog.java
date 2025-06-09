package atividades.lista4.questao2;

public class Dog extends Animal {
    private boolean needsGrooming;

    public Dog(String name, int age, String breed, boolean needsGrooming) {
        super(name, age, breed);
        this.needsGrooming = needsGrooming;
    }

    public boolean isNeedsGrooming() {
        return needsGrooming;
    }

    @Override
    public void displayDetails() {
        System.out.println("Dog - Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Breed: " + getBreed());
        System.out.println("Needs Grooming: " + (needsGrooming ? "Yes" : "No"));
        System.out.println("----------------------------------");
    }
}
