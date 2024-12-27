// // package ABS DESIGN;

// abstract class Bird {

//     abstract void eat();
//     abstract void fly();

// };

// class Sparrow extends Bird {

//     @Override
//     void eat() {

//         System.out.println("Sparrow is flying...");
//     }

//     @Override
//     void fly() {

//         System.out.println("Sparrow is eating...");
//     }
// };

// class Eagle extends Bird {

//     @Override
//     void eat() {

//         System.out.println("Eagle is flying...");
//     }

//     @Override
//     void fly() {

//         System.out.println("Eagle is eating...");
//     }
// };


// public class Main {

//     public static void doBird(Bird bird) {
//         bird.eat();
//         bird.fly();
//     }

//     public static void main (String[] args) {

//         doBird(new Sparrow());
//         doBird(new Eagle());

//     }
// }

// using Interface...

// package ABS DESIGN;

interface Bird {

    void fly();
    void eat();
}

class Sparrow implements Bird {

    @Override
    public void eat() {

        System.out.println("Sparrow is flying...");
    }

    @Override
    public void fly() {

        System.out.println("Sparrow is eating...");
    }
};

class Eagle implements Bird {

    @Override
    public void eat() {

        System.out.println("Eagle is flying...");
    }

    @Override
    public void fly() {

        System.out.println("Eagle is eating...");
    }
};


public class Main {

    public static void doBird(Bird bird) {
        bird.eat();
        bird.fly();
    }

    public static void main (String[] args) {

        doBird(new Sparrow());
        doBird(new Eagle());
        
    }
}