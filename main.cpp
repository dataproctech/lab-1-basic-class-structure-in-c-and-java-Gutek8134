#include<iostream>

class Car{
public:
    std::string make;
    std::string model;
    int year;

    Car(std::string _make, std::string _model, int _year);
    void displayInfo() const;
};

Car::Car(std::string _make, std::string _model, int _year){
    this->make = _make;
    this->model = _model;
    this->year = _year;
}

void Car::displayInfo() const{
    std::cout << "Make: " << this->make << "\nModel: " << this->model << "\nYear: " << this->year << std::endl;
}

int main(){
    auto car1 = Car("Mercedes", "Benc", 2002);
    car1.displayInfo();
    return 0;
}