package atividades.lista5.questao10;

import atividades.lista5.CrudRepository;

import java.util.List;
import java.util.Scanner;

public class EventController implements CrudRepository<Participants> {

    private Event event;

    public EventController() {
        event = new Event();
    }

    @Override
    public void save(Scanner s) {
        System.out.println("CADASTRO DE PARTICIPANTES");
        s.nextLine();
        System.out.println("Nome do Pariticpante: ");
        String name = s.nextLine();
        System.out.println("Idade do participante: ");
        int age = s.nextInt();
        s.nextLine();
        System.out.println("Tipo do ingresso: ");
        String type_ticket = s.nextLine();

        event.getParticipants().add(new Participants(name, age, type_ticket));
        System.out.println("Participante cadastrado com sucesso!");
    }

    @Override
    public void delete(Scanner s) {
        System.out.println("REMOVER PARTICIPANTE");
        s.nextLine();
        System.out.println("Nome do participante: ");
        String name = s.nextLine();
        if (event.getParticipants().isEmpty()) {
            System.err.println("Lista vazia! Cadastre um participante primeiro!");
            return;
        }
        event.getParticipants().removeIf(participant -> participant.getName().equalsIgnoreCase(name));
        System.out.println("Participante removido com sucesso!");
    }

    @Override
    public List<Participants> findAll() {
        return event.participants;
    }
}
