package atividades.lista6.questao4;

public enum Category {
    FICCAO,
    CIENCIAS,
    HISTORIA,
    BIOGRAFIA,
    TECNOLOGIA;

    public static void listCategories() {
        for (int i = 0; i < values().length; i++) {
            System.out.println("[" + i + "] - " + values()[i]);
        }
    }

    public static Category getByIndex(int index) {
        if (index < 0 || index >= values().length) {
            return null;
        }
        return values()[index];
    }
}
