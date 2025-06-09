package atividades.lista5.questao9;

import java.time.LocalDateTime;
import java.util.Date;

public class HotelReservation {
    private String guest_name;
    private int number_room;
    private LocalDateTime date_in;
    private LocalDateTime date_out;


    public HotelReservation(String guest_name, int number_room, LocalDateTime date_in) {
        this.guest_name = guest_name;
        this.number_room = number_room;
        this.date_in = date_in;

    }

    public String getGuest_name() {
        return guest_name;
    }

    public void setGuest_name(String guest_name) {
        this.guest_name = guest_name;
    }

    public int getNumber_room() {
        return number_room;
    }

    public void setNumber_room(int number_room) {
        this.number_room = number_room;
    }

    public LocalDateTime getDate_in() {
        return date_in;
    }

    public void setDate_in(LocalDateTime date_in) {
        this.date_in = date_in;
    }

    public LocalDateTime getDate_out() {
        return date_out;
    }

    public void setDate_out(LocalDateTime date_out) {
        this.date_out = date_out;
    }

    @Override
    public String toString() {
        return "HotelReservation{" +
                "guest_name='" + guest_name + '\'' +
                ", number_room=" + number_room +
                ", date_in=" + date_in +
                ", date_out=" + date_out +
                '}';
    }
}
