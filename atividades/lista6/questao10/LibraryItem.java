package atividades.lista6.questao10;

public abstract class LibraryItem {
    private String title;
    private boolean isBorrowed;

    public LibraryItem(String title) {
        this.title = title;
        this.isBorrowed = false;
    }

    public String getTitle() {
        return title;
    }

    public boolean isBorrowed() {
        return isBorrowed;
    }

    public void borrow() {
        if (isBorrowed) {
            throw new IllegalStateException("Item já está emprestado.");
        }
        isBorrowed = true;
    }

    public void returnItem() {
        if (!isBorrowed) {
            throw new IllegalStateException("Item não está emprestado.");
        }
        isBorrowed = false;
    }

    public abstract String getItemType();

    @Override
    public String toString() {
        return getItemType() + ": " + title + (isBorrowed ? " (emprestado)" : " (disponível)");
    }
}