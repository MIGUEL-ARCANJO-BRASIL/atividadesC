package atividades.lista4.questao3;

public class EscolaFuturoBrilhante {
    public static void main(String[] args) {
        Course regular = new RegularCourse("Ensino Médio", 36, 850.00, true);
        Course technical = new TechnicalCourse("Informática", 24, 950.00, 200);
        Course professional = new ProfessionalCourse("Manutenção de Celulares", 6, 500.00, true);

        regular.displayDetails();
        technical.displayDetails();
        professional.displayDetails();
    }
}
