public class App {
    public static void main(String[] args)throws Exception {
        // System.out.println("Hello World!...");

        // default ctor...
        // Student A = new Student();

        // naive approach...
        // A.id = 1;
        // A.age = 15;
        // A.name = "Ranu";
        // A.nos = 6;

        // System.out.println(A.name);

        // parameterised ctor...
        Student A = new Student(1, 15, "Ranu", 6);

        // System.out.println(A.name);
 
        // copy ctor...
        Student B = new Student(A);

        System.out.println(A.name);
        A.studying();

    }
}