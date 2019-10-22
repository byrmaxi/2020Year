public class Supervisor extends Engineer {

    private String education ;

    Supervisor(String name, int experience, String education) {
        super(name, experience);
        this.education=education;
    }

    @Override
    public void printReport() {
        System.out.println("Я, " + getName() + ", начальник с опытом "  + getExperience());
        System.out.println("Мое образование: " + education);
        System.out.println("Решил задач - " + getCompletedTasks() + ", из них неправильно - " + getErrorCounter() );
    }
}
