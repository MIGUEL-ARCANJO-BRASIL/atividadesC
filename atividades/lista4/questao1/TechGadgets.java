package atividades.lista4.questao1;

public class TechGadgets {
    public static void main(String[] args) {
        EletronicDevice celular = new SmartPhone("Samsung", "Galaxy S23", 4500.00, 256);
        EletronicDevice notebook = new Notebook("Dell", "XPS 13", 8500.00, 16);
        EletronicDevice relogio = new SmartWatch("Apple", "Watch Series 8", 3200.00, 2000);

        celular.displayDetails();
        notebook.displayDetails();
        relogio.displayDetails();
    }
}
