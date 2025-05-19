package atividades.lista6.questao1;

public class ObjectCount {
    private static int count = 0;
    ObjectCount(){
        System.out.println("Novo objeto criado!");
        count++;
    }
    public static void getCount() {
        System.out.println("Total de objetos criados: " + count);
    }
}
