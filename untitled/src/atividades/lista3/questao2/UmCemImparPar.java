package atividades.lista3.questao2;

public class UmCemImparPar {
    public static void main(String[] args) {
        System.out.println("Números de 1 a 100:");
        for (int i = 1; i < 101; i++) {
            if (i % 2 == 0) {
                System.out.println(i + " é Par.");
            } else {
                System.out.println(i + " é Impar.");
            }
            System.out.println();
        }
    }
}
