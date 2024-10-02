public class Car {
    // Attributes
    private String make;
    private String model;
    private int year;
    
    // Constructor
    public Car(String _make, String _model, int _year){
        this.make = _make;
        this.model = _model;
        this.year = _year;
    }
    
    // Method to display car information
    public void displayInfo(){
        System.out.printf("Make: %s\nModel: %s\nYear: %d\n", this.make, this.model, this.year);
    }

    public static void main(String[] args) {
        // Create a Car object
        var car1 = new Car("Mercedes", "Benc", 2002);
        // Display car details
        car1.displayInfo();
    }
}