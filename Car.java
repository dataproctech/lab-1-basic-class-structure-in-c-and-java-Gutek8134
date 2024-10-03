public class Car {
    // Attributes
    private String make;
    private String model;
    private int year;
    public static int currentYear;

    // Constructor
    public Car(String _make, String _model, int _year) {
        this.make = _make;
        this.model = _model;
        this.year = _year;
    }

    // Method to display car information
    public void displayInfo() {
        System.out.printf("Make: %s\nModel: %s\nYear: %d\n", this.make, this.model, this.year);
    }

    public int getCarAge() {
        return Car.currentYear - this.year;
    }

    public boolean isSameCar(Car other) {
        return this.model == other.model && this.make == other.make && this.year == other.year;
    }

    public static void main(String[] args) {
        Car.currentYear = 2024;
        // Create a Car object
        var car1 = new Car("Mercedes", "Benc", 2002);
        var car2 = new Car("Mercedes", "Benc", 2002);
        var car3 = new Car("Mercedes", "Benz", 2002);
        // Display car details
        car1.displayInfo();
        System.out.printf("Age: %d\n", car1.getCarAge());
        System.out.printf("Are the same cars the same? %s\nAre different cars the same? %s\n",
                (car1.isSameCar(car2) ? "Yes" : "No"), (car1.isSameCar(car3) ? "Yes" : "No"));
    }
}