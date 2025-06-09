package atividades.lista5.questao6;

import atividades.lista5.CrudRepository;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class EmployeeController implements CrudRepository<Employee> {
    List<Employee> employeeList;

    EmployeeController() {
        employeeList = new ArrayList<>();
    }


    @Override
    public void save(Scanner s) {
        System.out.println("Cadastro de Funcionarios");
        s.nextLine();
        System.out.println("Nome:");
        String name = s.nextLine();
        System.out.println("Cargo:");
        String position = s.nextLine();
        System.out.println("Salário:");
        float salary = s.nextFloat();
        employeeList.add(new Employee(name, position, salary));
        System.out.println("Funcionario cadastrado com sucesso!");
    }

    @Override
    public void delete(Scanner s) {
        System.out.println("Remover Funcionario");
        s.nextLine();
        System.out.println("Nome: ");
        String name = s.nextLine();
        if (employeeList.isEmpty()) {
            System.err.println("Lista Vazia! Cadastre um funcionario primeiro!");
            return;
        }
        employeeList.removeIf(employee -> employee.getName().equalsIgnoreCase(name));
        System.out.println("Funcionario removido com sucesso!");
    }

    public void readjustSalaryController(Scanner s) {
        System.out.println("Reajustar Salário do funcionario");
        s.nextLine();
        System.out.println("Nome: ");
        String name = s.nextLine();
        System.out.println("Percentual do reajuste: ");
        float percent = s.nextFloat();

        if (employeeList.isEmpty()) {
            System.err.println("Lista Vazia! Cadastre um funcionario primeiro!");
            return;
        }
        ;

        for (Employee employee : employeeList) {
            if (employee.getName().equalsIgnoreCase(name)) {
                employee.readjustSalary(percent);
                System.out.println("Salário reajustado para: " + employee.getName());
                return;
            }
        }
        System.out.println("Funcionário não encontrado.");
    }

    @Override
    public List<Employee> findAll() {
        return employeeList;
    }
}
