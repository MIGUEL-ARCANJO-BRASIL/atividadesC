package atividades.lista5.questao9;

import atividades.lista5.CrudRepository;

import java.util.ArrayList;
import java.util.Date;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.List;
import java.util.Scanner;

public class ReservationController implements CrudRepository<HotelReservation> {
    List<HotelReservation> reservationList;

    public ReservationController() {
        reservationList = new ArrayList<>();
    }

    private Boolean checkRoomAvailability(int number_room) {
        boolean isReserved = false;

        for (HotelReservation reserve : reservationList) {
            if (reserve.getNumber_room() == number_room) {
                isReserved = true;
                break;
            }
        }

        return isReserved;
    }

    @Override
    public void save(Scanner s) {
        System.out.println("CADASTRO DE RESERVA");
        s.nextLine();
        System.out.println("Nome do hóspede:");
        String name = s.nextLine();
        System.out.println("Numero do quarto: ");
        int number_room = s.nextInt();
        if (checkRoomAvailability(number_room)) {
            System.err.println("Quarto de número " + number_room + " ocupado!");
            return;
        }

        System.out.println("Reserva realizada com sucesso!");
        reservationList.add(new HotelReservation(name, number_room,
                LocalDateTime.ofInstant(new Date().toInstant(), ZoneId.systemDefault())));
    }

    @Override
    public void delete(Scanner s) {
        System.out.println("LIBERAR RESERVA");
        s.nextLine();
        System.out.println("Numero do quarto: ");
        int number_room = s.nextInt();
        if (reservationList.isEmpty()) {
            System.err.println("Lista vazia! Cadastre uma reserva primeiro!");
            return;
        }
        for (HotelReservation reserve : reservationList) {
            if (reserve.getNumber_room() == number_room) {
                reserve.setDate_out(LocalDateTime.ofInstant(new Date().toInstant(), ZoneId.systemDefault()));
                reservationList.set(reservationList.indexOf(reserve), reserve);
                System.out.println("Reserva liberada com sucesso!");
                return;
            }
        }
    }

    @Override
    public List<HotelReservation> findAll() {
        return reservationList;
    }
}
