package atividades.lista4.questao2;

public class Bird extends Animal {
    private boolean canTalk;

    public Bird(String name, int age, String breed, boolean canTalk) {
        super(name, age, breed);
        this.canTalk = canTalk;
    }

    public boolean isCanTalk() {
        return canTalk;
    }

    @Override
    public void displayDetails() {
        System.out.println("Bird - Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Breed: " + getBreed());
        System.out.println("Can Talk: " + (canTalk ? "Yes" : "No"));
        System.out.println("----------------------------------");
    }
}
