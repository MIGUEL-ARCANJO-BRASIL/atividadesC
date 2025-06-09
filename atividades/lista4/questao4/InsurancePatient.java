package atividades.lista4.questao4;


public class InsurancePatient extends Patient {
    private String insuranceProvider;
    private boolean preAuthorized;

    public InsurancePatient(String name, int age, String document, String insuranceProvider, boolean preAuthorized) {
        super(name, age, document);
        this.insuranceProvider = insuranceProvider;
        this.preAuthorized = preAuthorized;
    }

    public String getInsuranceProvider() {
        return insuranceProvider;
    }

    public boolean isPreAuthorized() {
        return preAuthorized;
    }

    @Override
    public void displayInfo() {
        System.out.println("Paciente de Convênio:");
        System.out.println("Nome: " + getName());
        System.out.println("Idade: " + getAge());
        System.out.println("Documento: " + getDocument());
        System.out.println("Convênio: " + insuranceProvider);
        System.out.println("Autorização Prévia: " + (preAuthorized ? "Sim" : "Não"));
        System.out.println("Tipo de Atendimento: Conforme regras do convênio");
        System.out.println("----------------------------------");
    }
}

