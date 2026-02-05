#include <iostream>
using namespace std;

// Class definition
class Car 
{
public:
    string brand;
    string model;
    int year; 
    int price;

    Car(string b, string a, int p, int y)
        : brand(b), model(a), year(y), price(p) {}

    void displayInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }

    int getPrice(int qty) const {
        return price * qty;
    }
};m

int main()
{
   Car toyota("Toyota", "Camry", 24000, 2020);
   Car honda("Honda", "Civic", 32000, 2019);

    toyota.displayInfo();
    cout << "Total price for 3 cars: $" << toyota.getPrice(3) << endl;
    honda.displayInfo();
    cout << "Total price for 2 cars: $" << honda.getPrice(2) << endl;
}