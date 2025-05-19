package atividades.lista6.questao7;

public class ManipulateCharacters {
    public static void manipulate(String str) {
        String aux = "";

        for (int i = str.length() - 1; i >= 0; i--) {
            aux += str.charAt(i);
        }

        System.out.println("Palavra inserida: " + str);
        System.out.println("Palava inserida na ordem inversa: " + aux);
        System.out.println("Quantidade de caracteres: " + str.length());
        System.out.println("----------------------\n");
    }
}
