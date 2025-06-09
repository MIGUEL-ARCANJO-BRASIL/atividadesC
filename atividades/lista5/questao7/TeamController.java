package atividades.lista5.questao7;

import atividades.lista5.CrudRepository;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TeamController implements CrudRepository<Team> {
    private List<Team> teamsList;

    TeamController() {
        teamsList = new ArrayList<>();
    }

    @Override
    public void save(Scanner s) {
        System.out.println("CADASTRO DE TIMES");
        s.nextLine();
        System.out.println("Nome:");
        String name = s.nextLine();
        System.out.println("Jogadores: ");
        List<String> namesPlayer = new ArrayList<>();
        for (int i = 0; i < 11; i++) {
            System.out.println("Nome do jogador " + (i + 1) + ": ");
            String playerName = s.nextLine();
            namesPlayer.add(playerName);
        }
        teamsList.add(new Team(name, namesPlayer));
        System.out.println("Time cadastrado com sucesso!");
    }

    @Override
    public void delete(Scanner s) {
        System.out.println("REMOVER TIME");
        s.nextLine();
        System.out.println("Nome:");
        String name = s.nextLine();

        Team t = findTeamByName(name);
        teamsList.remove(t);
        System.out.println("Time removido com sucesso!");
    }

    @Override
    public List<Team> findAll() {
        return teamsList;
    }

    public void addPlayerOnTeam(Scanner s) {
        System.out.println("ADICIONAR JOGADORES NO TIME");
        s.nextLine();

        System.out.println("Nome:");
        String name = s.nextLine();
        System.out.println("Quanto jogadores deseja adicionar?");
        int qtd = s.nextInt();

        List<String> namesPlayer = new ArrayList<>();
        for (int i = 0; i < qtd; i++) {
            s.nextLine();
            System.out.println("Nome do jogador " + (i + 1) + ": ");
            String playerName = s.nextLine();
            namesPlayer.add(playerName);
        }

        Team t = findTeamByName(name);

        t.getPlayers().addAll(namesPlayer);
        teamsList.set(teamsList.indexOf(t), t);
        System.out.println("Jogadores adicionados com sucesso!");
    }

    public void removePlayerOnTeam(Scanner s) {
        System.out.println("REMOVER JOGADORES NO TIME");
        s.nextLine();
        System.out.println("Nome:");
        String name = s.nextLine();
        System.out.println("Quanto jogadores deseja remover?");
        int qtd = s.nextInt();
        List<String> namesPlayer = new ArrayList<>();
        for (int i = 0; i < qtd; i++) {
            s.nextLine();
            System.out.println("Nome do jogador " + (i + 1) + ": ");
            String playerName = s.nextLine();
            namesPlayer.add(playerName);
        }

        Team t = findTeamByName(name);

        t.getPlayers().removeAll(namesPlayer);
        teamsList.set(teamsList.indexOf(t), t);
        System.out.println("Jogadores removidos com sucesso!");
    }

    private Team findTeamByName(String name) {
        if (teamsList.isEmpty()) {
            System.err.println("Lista Vazia! Cadastre um time primeiro!");
            return null;
        }
        Team t = null;
        for (Team team : teamsList) {
            if (team.getName().trim().equalsIgnoreCase(name.trim())) {
                t = team;
            }
        }
        return t;
    }

}
