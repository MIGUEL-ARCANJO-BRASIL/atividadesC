package atividades.lista5.questao3;

public class Produto {
    private static int id = 1;
    private String nome;
    private float preco;
    private int quantidade = 1;

    public Produto(String nome, float preco) {
        Produto.id++;
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    public void addQtd() {
        quantidade++;
    }


    public static void setId(int id) {
        Produto.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    @Override
    public String toString() {
        return "Produto {" +
                "nome='" + nome + '\'' +
                ", preco=" + preco +
                ", quantidade=" + quantidade +
                "} ";
    }


}
