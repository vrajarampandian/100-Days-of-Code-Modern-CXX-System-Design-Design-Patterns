#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
    public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle
{
    public:
    void drive() override
    {
        cout << "Car drive" << "\n";
    }
};

class Bike : public Vehicle
{
    public:
    void drive() override
    {
        cout << "Bike drive" << "\n";
    }
};

class Factory
{
    public:
    static Vehicle* create(string type)
    {
        if(type == "car")
            return new Car;
        else if(type == "bike")
            return new Bike;
        return nullptr;
    }
};

int main()
{
    Vehicle* v = Factory::create("car");
    v->drive();
    delete v;
    return 0;
}
