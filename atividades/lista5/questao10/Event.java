package atividades.lista5.questao10;

import java.util.ArrayList;
import java.util.List;

public class Event {
    List<Participants> participants;
    Event(){
        participants = new ArrayList<>();
    }

    public List<Participants> getParticipants() {
        return participants;
    }

    public void setParticipants(List<Participants> participants) {
        this.participants = participants;
    }
}
