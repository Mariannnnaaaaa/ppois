#include "Courier.h"
using namespace std;

Courier::Courier(string name, int age, string vehicleType, bool isAvailable)
    : Human(name, age), vehicleType(vehicleType), isAvailable(isAvailable) {}

string Courier::getVehicleType() { return vehicleType; }
void Courier::setVehicleType(const string& vehicleType) { this->vehicleType = vehicleType; }

bool Courier::getIsAvailable() { return isAvailable; }
void Courier::setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }

Order Courier::getCurrentOrder() { return currentOrder; }
void Courier::setCurrentOrder(const Order& currentOrder) { this->currentOrder = currentOrder; }

string Courier::getPhoneNumber() { return phoneNumber; }
void Courier::setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }

void Courier::takeOrder(Order& order) {
    if (isAvailable) {
        currentOrder = order;
        isAvailable = false;
    }
    else cout << "The courier is busy and cannot accept the order at the moment.\n";
}

void Courier::completeOrder() {
    if (!isAvailable) {
        currentOrder = Order(); //dropped the order
        isAvailable = true;
    }
    else cout << "The courier does not have an active order to complete.\n";
}