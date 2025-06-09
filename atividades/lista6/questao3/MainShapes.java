package atividades.lista6.questao3;

import java.util.Scanner;

public class MainShapes {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (true) {
            System.out.println("[0] - Sair");
            System.out.println("[1] - Perimetro");
            System.out.println("[2] - Area");
            int op = s.nextInt();
            System.out.println("[1] - Triângulo");
            System.out.println("[2] - Quadrado");
            System.out.println("[3] - Retângulo");
            int shape = s.nextInt();
            switch (op) {
                case 0:
                    return;
                case 1:
                    GeometricShapes.calculatePerimeter(shape, s);
                    break;
                case 2:
                    GeometricShapes.calculateArea(shape, s);
                    break;
            }
        }
    }
}
