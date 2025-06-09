package atividades.lista5.questao1;

import java.util.Arrays;

public class Aluno {
    private String nome;
    private float notas[];
    private float media;

    public Aluno(String nome, float notas[]) {
        this.nome = nome;
        this.notas = notas;
        media = calcularMedia(notas);
        imprimir();
    }

    public void imprimir(){
        System.out.println("Nome do aluno: " + nome);
        System.out.println("Notas do aluno: " + Arrays.toString(notas));
        System.out.println("Media do aluno: " + media);
        System.out.println();
    }

    public float calcularMedia(float notas[]) {
        for (int i = 0; i < notas.length; i++) {
            media+= notas[i];
        }
        return media/notas.length;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getMedia() {
        return media;
    }

    public void setMedia(float media) {
        this.media = media;
    }
}
