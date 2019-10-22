import java.util.Random;
import java.util.Scanner;

public class Engineer implements Employee {

    private String name;
    private int experience;
    private int completedTasks = 0;
    private int errorCounter = 0;

    public int getExperience() { return experience; }

    public String getName() { return name; }

    public int getErrorCounter() {
        return errorCounter;
    }

    public int getCompletedTasks() {
        return completedTasks;
    }

    Engineer(String name, int experience){
        this.name=name;
        this.experience=experience;
    }

    public void printReport (){
        System.out.println("Я, " + name + ", инженер с опытом " + experience);
        System.out.println("Решил " + completedTasks + " задач, из них неправильно - " + errorCounter);
    }

    @Override
    public void theSolutionOfTheProblem() {
        System.out.println("Требуется решить задачу:");
        Random random = new Random();
        int size1 = 5 + random.nextInt(16);
        int size2= 5 + random.nextInt(16);
        int depth = 1 + random.nextInt(10);
        System.out.println("Требуется выкопать котлован размером " + size1 + "х" + size2 + " метров и глубиной " + depth + " метра.");
        System.out.println("Сколько нужно вывезти машин грунта, если грузоподъёмность одной машины 10м³?");

        int answer = (size1*size2*depth)/10;
        if (answer % 10 != 0) answer++;

        System.out.println("Введите ответ: ");
        Scanner sc = new Scanner(System.in);
        int enteredAnswer = sc.nextInt();
        completedTasks++;

        if (answer!=enteredAnswer){
            errorCounter++;
            System.out.println("Вы решили задачу неверно");
        } else{
            System.out.println("Вы решили задачу верно");
        }

    }
}

