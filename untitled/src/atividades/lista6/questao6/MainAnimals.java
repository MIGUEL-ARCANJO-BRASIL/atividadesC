package atividades.lista6.questao6;

import java.util.ArrayList;
import java.util.List;

public class MainAnimals {
    public static void main(String[] args) {
        List<Animal> animals = new ArrayList<>();

        animals.add(new Dog());
        animals.add(new Cat());
        animals.add(new Cow());

        System.out.println("Sons dos animais:");
        for (Animal a : animals) {
            a.makeSound();
        }
    }
}
