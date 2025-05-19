package atividades.lista5.questao1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainAluno {

    public static void main(String[] args) {
        List<Aluno> alunos = new ArrayList<Aluno>();
        Scanner s = new Scanner(System.in);
        while (true) {
            System.out.println("Digite seu nome: ");
            String nome = s.nextLine();
            float notas[] = new float[3];
            for (int i = 0; i < 3; i++) {
                System.out.println("Digite sua " + (i + 1) + "° nota: ");
                notas[i] = s.nextFloat();
            }
            s.nextLine();
            alunos.add(new Aluno(nome, notas));
            System.out.println("Continuar? [S/N]");
            String continuar = s.nextLine();
            if (continuar.equals("S")) {
                break;
            }
        }
    }
}
