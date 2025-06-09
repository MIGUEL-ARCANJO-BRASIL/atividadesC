package atividades.lista6.questao3;

import java.util.ArrayList;
import java.util.Scanner;

public class GeometricShapes {


    public static void calculateArea(int shape, Scanner s) {
        switch (shape) {
            case 1:
                System.out.println("Base: ");
                double bT = s.nextDouble();
                System.out.println("Altura: ");
                double h = s.nextDouble();

                System.out.println("Aréa do triangulo: " + (bT * h) / 2);
                break;
            case 2:
                System.out.println("Base: ");
                double bQ = s.nextDouble();
                System.out.println("Aréa do quadrado: " + bQ * bQ);
                break;
            case 3:
                System.out.println("Base: ");
                double bR = s.nextDouble();
                System.out.println("Altura: ");
                double hR = s.nextDouble();

                System.out.println("Aréa do retângulo: " + (bR * hR));
                break;
        }
    }


    public static void calculatePerimeter(int shape, Scanner s) {
        switch (shape) {
            case 1:
                System.out.println("Lado 1: ");
                double l1 = s.nextDouble();
                System.out.println("Lado 2: ");
                double l2 = s.nextDouble();
                System.out.println("Lado 3: ");
                double l3 = s.nextDouble();

                System.out.println("Perímetro do triângulo: " + (l1 + l2 + l3));
                break;

            case 2:
                System.out.println("Lado: ");
                double lado = s.nextDouble();

                System.out.println("Perímetro do quadrado: " + (4 * lado));
                break;

            case 3:
                System.out.println("Base: ");
                double base = s.nextDouble();
                System.out.println("Altura: ");
                double altura = s.nextDouble();

                System.out.println("Perímetro do retângulo: " + (2 * (base + altura)));
                break;

            default:
                System.out.println("Forma inválida!");
        }
    }

}
