package atividades.lista4.questao4;

public class ClinicaSaudeTotal {
    public static void main(String[] args) {
        Patient p1 = new RegularPatient("Carlos Silva", 45, "123456789");
        Patient p2 = new VipPatient("Ana Souza", 38, "987654321", "Sala VIP, atendimento sem espera");
        Patient p3 = new InsurancePatient("João Lima", 52, "456123789", "SaúdePlus", true);

        p1.displayInfo();
        p2.displayInfo();
        p3.displayInfo();
    }
}
