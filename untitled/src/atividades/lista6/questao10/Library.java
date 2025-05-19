package atividades.lista6.questao10;

import java.util.ArrayList;
import java.util.List;

public class Library {
    private List<LibraryItem> items;

    public Library() {
        items = new ArrayList<>();
    }

    public void addItem(LibraryItem item) {
        items.add(item);
    }

    public List<LibraryItem> getItems() {
        return items;
    }

    public LibraryItem findItemByTitle(String title) {
        for (LibraryItem item : items) {
            if (item.getTitle().equalsIgnoreCase(title)) {
                return item;
            }
        }
        return null;
    }

    public boolean borrowItem(String title) {
        LibraryItem item = findItemByTitle(title);
        if (item != null && !item.isBorrowed()) {
            item.borrow();
            return true;
        }
        return false;
    }

    public boolean returnItem(String title) {
        LibraryItem item = findItemByTitle(title);
        if (item != null && item.isBorrowed()) {
            item.returnItem();
            return true;
        }
        return false;
    }
}
