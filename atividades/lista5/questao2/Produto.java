package atividades.lista5.questao2;

public class Produto {
    private static int id = 1;
    private String nome;
    private float preco;
    private int quantidade;

    public Produto(String nome, float preco) {
        this.id++;
        this.nome = nome;
        this.preco = preco;
        quantidade = 1;
    }
    public void addQtd(){
        quantidade++;
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
        return "Produto{" +
                "nome='" + nome + '\'' +
                ", preco=" + preco +
                ", quantidade=" + quantidade +
                '}';
    }
}
