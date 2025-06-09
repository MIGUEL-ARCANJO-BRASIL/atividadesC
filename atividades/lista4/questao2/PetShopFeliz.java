package atividades.lista4.questao2;

public class PetShopFeliz {
    public static void main(String[] args) {
        Animal dog = new Dog("Buddy", 3, "Labrador", true);
        Animal cat = new Cat("Whiskers", 2, "Persian", true);
        Animal bird = new Bird("Polly", 1, "Parrot", true);

        dog.displayDetails();
        cat.displayDetails();
        bird.displayDetails();
    }
}
