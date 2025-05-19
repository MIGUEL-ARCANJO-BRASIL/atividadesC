package atividades.lista5.questao6;


import java.util.Scanner;

public class MainEmployee {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        EmployeeController controller = new EmployeeController();
        while (true) {
            int opcao = 0;

            System.out.println("Escolha a opção: ");
            System.out.println("[0] - Sair");
            System.out.println("[1] - Adicionar Funcionario");
            System.out.println("[2] - Remover Funcionario");
            System.out.println("[3] - Listar Funcionarios");
            System.out.println("[4] - Reajusar Salário do Funcionario");
            opcao = s.nextInt();

            switch (opcao) {
                case 0:
                    return;
                case 1:
                    controller.save(s);
                    break;
                case 2:
                    controller.delete(s);
                    break;
                case 3:
                    System.out.println(controller.findAll().toString());
                    break;
                case 4:
                    controller.readjustSalaryController(s);
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }
        }
    }
}
