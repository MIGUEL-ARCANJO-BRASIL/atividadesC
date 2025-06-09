package atividades.lista4.questao4;

public class RegularPatient extends Patient {
    public RegularPatient(String name, int age, String document) {
        super(name, age, document);
    }

    @Override
    public void displayInfo() {
        System.out.println("Paciente Comum:");
        System.out.println("Nome: " + getName());
        System.out.println("Idade: " + getAge());
        System.out.println("Documento: " + getDocument());
        System.out.println("Tipo de Atendimento: Consulta padrão");
        System.out.println("----------------------------------");
    }
}
