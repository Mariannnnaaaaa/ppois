#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Human.h"
#include "Order.h"

using namespace std;

class Courier:public Human
{
private:
    string vehicleType;
    bool isAvailable;
    Order currentOrder;
    string phoneNumber;
public:
    Courier(string name, int age, string vehicleType, bool isAvailable);

    string getVehicleType();
    void setVehicleType(const string& vehicleType);

    bool getIsAvailable();
    void setIsAvailable(bool isAvailable);

    Order getCurrentOrder();
    void setCurrentOrder(const Order& currentOrder);

    string getPhoneNumber();
    void setPhoneNumber(const string& phoneNumber);

    void takeOrder(Order& order);

    void completeOrder();
};

