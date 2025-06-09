package atividades.lista5.questao2;

import atividades.lista5.CrudRepository;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Estoque implements CrudRepository<Produto> {

    private List<Produto> produtosList;

    Estoque() {
        produtosList = new ArrayList<>();
    }

    @Override
    public void save(Scanner s) {
        String nome;
        float preco;
        System.out.println("CADASTRO DE PRODUTOS");
        System.out.println();
        s.nextLine();
        System.out.println("NOME:");
        nome = s.nextLine();
        for (Produto produto : produtosList) {
            if (produto.getNome().trim().equalsIgnoreCase(nome.trim())) {
                System.out.println("Adicionando mais 1 no estoque");
                produto.addQtd();
                return;
            }
        }
        System.out.println("PRECO:");
        preco = s.nextFloat();

        produtosList.add(new Produto(nome, preco));
        System.out.println("Adicionando novo produto.");
    }

    @Override
    public void delete(Scanner s) {
        s.nextLine();
        System.out.println("Qual o nome do produto deseja excluir?");
        findAll().forEach(produto -> System.out.println(produto.getNome()));
        String nome = s.nextLine();
        for (Produto produto : produtosList) {
            if (produto.getNome().equals(nome)) {
                if (produto.getQuantidade() == 1) {
                    System.out.println("Removendo do estoque!");
                    produtosList.remove(produto);
                }
                System.out.println("Tirando 1 da quantidade total");
                produto.setQuantidade(produto.getQuantidade() - 1);
            }
        }

    }

    @Override
    public List<Produto> findAll() {
        return produtosList;
    }
}
