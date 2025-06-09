package atividades.lista5.questao5;

import java.time.LocalDateTime;

public class Transaction {
    private LocalDateTime date;
    private float value;
    private String type_operation;

    public Transaction(LocalDateTime date, float value, String type_operation) {
        this.date = date;
        this.value = value;
        this.type_operation = type_operation;
    }

    @Override
    public String toString() {
        return "Transaction{" +
                " date=" + date +
                ", value=" + value +
                ", type_operation='" + type_operation + '\'' +
                "}\n";
    }
}
