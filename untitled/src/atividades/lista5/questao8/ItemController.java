package atividades.lista5.questao8;

import atividades.lista5.CrudRepository;

import java.util.List;
import java.util.Scanner;

public class ItemController implements CrudRepository<Item> {
    private Cart cart;

    public ItemController() {
        cart = new Cart();
    }


    @Override
    public void save(Scanner s) {
        System.out.println("ADICIONAR PRODUTO AO CARRINHO");
        s.nextLine();
        System.out.println("Nome do Produto: ");
        String name = s.nextLine();
        System.out.println("Preço do Produto: ");
        float price = s.nextFloat();
        cart.getItemList().add(new Item(name, price));
        System.out.println("Produto adicionado ao carrinho com sucesso!");
    }

    @Override
    public void delete(Scanner s) {
        if (cart.getItemList().isEmpty()) {
            System.err.println("Lista vazia! Adicione um produto primeiro");
            return;
        }
        System.out.println("REMOVER PRODUTO DO CARRINHO");
        s.nextLine();
        System.out.println("Nome do Produto: ");
        String name = s.nextLine();

        cart.getItemList().removeIf(item -> item.getName().trim()
                .equalsIgnoreCase(name.trim()));
        System.out.println("Produto removido do carrinho com sucesso!");
    }

    public void calculateTotal() {
        float total = 0;
        if (cart.getItemList().isEmpty()) {
            System.err.println("Lista vazia! Adicione um produto primeiro");
            return;
        }
        for (Item item : cart.getItemList()) {
            total += item.getPrice();
        }
        System.out.println("Total: " + total);
    }

    @Override
    public List<Item> findAll() {
        return cart.getItemList();
    }
}
