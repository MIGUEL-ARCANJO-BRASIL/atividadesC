package atividades.lista5;

import java.util.List;
import java.util.Scanner;

public interface CrudRepository<T> {
    void save( Scanner s);

    void delete(Scanner s);

    List<T> findAll();

}
