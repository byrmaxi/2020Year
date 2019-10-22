import java.util.Arrays;
import java.util.List;
import java.util.Random;
import  java.util.Scanner;

public class Main {

    public static void main (String []args){
        Engineer Anton = new Engineer("Антон", 12);

        Engineer Alex = new Supervisor("Алекс", 5, "Прикладная математика и инф");
        Engineer Max = new Supervisor("Макс", 10, "ВМК");

        Anton.theSolutionOfTheProblem();
        Alex.theSolutionOfTheProblem();
        Max.theSolutionOfTheProblem();

        List<Engineer> lst = Arrays.asList(Anton, Alex, Max);

        for (Engineer engineer: lst){
            engineer.printReport();         // пример полиморфизма
        }

    }
}
