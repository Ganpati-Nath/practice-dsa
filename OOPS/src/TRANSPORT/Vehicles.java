public class Vehicles {

    public String name;
    public String model;
    public int noOfTyres;

    Vehicles() {
        this.name = "";
        this.model = "";
        this.noOfTyres = -1;
    }

    Vehicles(String name, String model, int noOfTyres) {
        this.name = name;
        this.model = model;
        this.noOfTyres = noOfTyres;

    }

    public void startEngine() {

        System.out.printf("Engine is starting of %s : %s%n", name, model);
    }

    public void stopEngine() {

        System.out.printf("Engine is stopping of %s : %s%n", name, model);
    }
}