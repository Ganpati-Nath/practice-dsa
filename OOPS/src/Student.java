public class Student {

    // Attributes...
    public int id;
    public int age;
    public String name;
    public int nos;

    // default ctor...
    public Student() {

        System.out.println("Student default ctor called...");
    }

    // parameterised ctor...
    public Student(int id, int age, String name, int nos) {

        System.out.println("Student parameterised ctor called...");
        this.id = id;
        this.age = age;
        this.name = name;
        this.nos = nos;
    }

    // copy ctor...
    public Student(Student srcObj) {

        System.out.println("Student copy ctor called...");
        this.id = srcObj.id;
        this.age = srcObj.age;
        this.name = srcObj.name;
        this.nos = srcObj.nos;
    }

    // Behaviours...
    public void studying() {

        System.out.println(name + " Studying...");
    }

    public void sleeping() {

        System.out.println(name + " Sleeping...");
    }

    public void bunking() {

        System.out.println(name + " Bunking...");
    }
}