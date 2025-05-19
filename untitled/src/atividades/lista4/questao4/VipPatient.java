package atividades.lista4.questao4;

public class VipPatient extends Patient {
    private String vipBenefits;

    public VipPatient(String name, int age, String document, String vipBenefits) {
        super(name, age, document);
        this.vipBenefits = vipBenefits;
    }

    public String getVipBenefits() {
        return vipBenefits;
    }

    @Override
    public void displayInfo() {
        System.out.println("Paciente VIP:");
        System.out.println("Nome: " + getName());
        System.out.println("Idade: " + getAge());
        System.out.println("Documento: " + getDocument());
        System.out.println("Benefícios VIP: " + vipBenefits);
        System.out.println("Tipo de Atendimento: Consulta prioritária com sala exclusiva");
        System.out.println("----------------------------------");
    }
}
