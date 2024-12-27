// package ABS DESIGN;

abstract class Bird {

    abstract void eat();
    abstract void fly();

};

class Sparrow extends Bird {

    @Override
    void eat() {

        System.out.println("Sparrow is flying...");
    }

    @Override
    void fly() {

        System.out.println("Sparrow is eating...");
    }
};

class Eagle extends Bird {

    @Override
    void eat() {

        System.out.println("Eagle is flying...");
    }

    @Override
    void fly() {

        System.out.println("Eagle is eating...");
    }
};


public class Main {

    public static void main (String[] args) {

        Bird bird1 = new Sparrow();
        bird1.eat();
        bird1.fly();

        Bird bird2 = new Eagle();
        bird2.eat();
        bird2.fly();
    }
}