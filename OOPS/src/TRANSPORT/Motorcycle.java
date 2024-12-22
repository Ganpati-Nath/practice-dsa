public class Motorcycle extends Vehicles {

    public String handleBarStyle;
    public String suspensionType;

    Motorcycle(String name, String model, int noOfTyres, String handleBarStyle, String suspensionType) {
        super(name, model, noOfTyres);
        this.handleBarStyle = handleBarStyle;
        this.suspensionType = suspensionType;
    }

    public void wheelie() {

        System.out.println("wheelie kr rhi h " + name);
    }
}