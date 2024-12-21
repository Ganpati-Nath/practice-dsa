public class Student {

    // Attributes...
    private int id;
    private int age;
    private String name;
    private int nos;
    private String gf;

    // default ctor...
    public Student() {

        System.out.println("Student default ctor called...");
    }

    public void setAge(int age) {

        this.age = age;
    }

    public int getAge() {

        return this.age;
    }

    public String getName() {

        return this.name;
    }
    // parameterised ctor...
    public Student(int id, int age, String name, int nos, String gf) {

        System.out.println("Student parameterised ctor called...");
        this.id = id;
        this.age = age;
        this.name = name;
        this.nos = nos;
        this.gf = gf;
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

    private void gfChatting() {

        System.out.println(name + " Chatting...");
    }
}