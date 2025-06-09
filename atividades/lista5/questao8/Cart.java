package atividades.lista5.questao8;

import java.util.ArrayList;
import java.util.List;

public class Cart {
    private List<Item> itemList;

    public Cart() {
        this.itemList = new ArrayList<>();
    }

    public List<Item> getItemList() {
        return itemList;
    }

    public void setItemList(List<Item> itemList) {
        this.itemList = itemList;
    }
}
