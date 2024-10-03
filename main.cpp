#include <iostream>

class Car
{
private:
    std::string make;
    std::string model;
    int year;

public:
    static int currentYear;

    Car(std::string _make, std::string _model, int _year);
    void displayInfo() const;
    int getCarAge() const;
    std::string getMake() const { return this->make; };
    std::string getModel() const { return this->model; };
    int getProductionYear() const { return this->year; };

    void setMake(std::string _make) { this->make = _make; };
    void setModel(std::string _model) { this->model = _model; };
    void setProductionYear(int _productionYear) { this->year = _productionYear; };

    bool isSameCar(Car &otherCar);
    bool operator==(Car &other);
};

int Car::currentYear = 0;

Car::Car(std::string _make, std::string _model, int _year)
{
    this->make = _make;
    this->model = _model;
    this->year = _year;
}

bool Car::isSameCar(Car &other)
{
    return this->model == other.model &&
           this->make == other.make &&
           this->year == other.year;
}

bool Car::operator==(Car &other) { return this->isSameCar(other); }

void Car::displayInfo() const
{
    std::cout << "Make: " << this->make << "\nModel: " << this->model << "\nYear: " << this->year << std::endl;
}

int Car::getCarAge() const
{
    return Car::currentYear - this->year;
}

int main()
{
    Car::currentYear = 2024;
    auto car1 = Car("Mercedes", "Benc", 2002);
    auto car2 = Car("Mercedes", "Benc", 2002);
    auto car3 = Car("Mercedes", "Benz", 2002);
    car1.displayInfo();
    std::cout << "Age: " << car1.getCarAge() << std::endl;
    std::cout << "Are the same cars the same? " << (car1.isSameCar(car2) ? "Yes" : "No") << std::endl;
    std::cout << "Are different cars the same? " << (car1.isSameCar(car3) ? "Yes" : "No") << std::endl;
    return 0;
}