#include "Client.h"
using namespace std;

    Client::Client() : Human("", 0), preferredCuisine(""), deliveryAddress("") {}
    Client::Client(string name, int age, string preferredCuisine, string deliveryAddress)
        : Human(name, age), preferredCuisine(preferredCuisine), deliveryAddress(deliveryAddress) {}

    string Client::getPreferredCuisine() { return preferredCuisine; }
    void Client:: setPreferredCuisine(const string& preferredCuisine) { this->preferredCuisine = preferredCuisine; }

    string Client::getDeliveryAddress() { return deliveryAddress; }
    void Client::setDeliveryAddress(const string& deliveryAddress) { this->deliveryAddress = deliveryAddress; }

    vector<Order>Client::getOrders() { return orders; }
    void Client::setOrders(const vector<Order>& orders) { this->orders = orders; }

    string Client::getDeliveryAdress() { return deliveryAdress; }
    void Client::setDeliveryAdress(const string& deliveryAdress) { this->deliveryAdress = deliveryAdress; }

    string Client::getDeliveryMethod() { return deliveryMethod; }
    void Client::setDeliveryMethod(const string& deliveryMethod) { this->deliveryMethod = deliveryMethod; }

    string Client::getPaymentMethod() { return paymentMethod; }
    void Client::setPaymentMethod(const string& paymentMethod) { this->paymentMethod = paymentMethod; }

    int Client::getCourierRating() { return courierRating; }
    void Client::setCourierRating(int courierRating) { this->courierRating = courierRating; }

    int Client::getRestaurantRating() { return restaurantRating; }
    void Client::setRestaurantRating(int restaurantRating) { this->restaurantRating = restaurantRating; }

    string Client::getPhoneNumber() { return phoneNumber; }
    void Client::setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }

    string Client::getBankCard() { return bankCard; }
    void Client::setBankCard(const string& bankCard) { this->bankCard = bankCard; }

    bool Client::getLeaveAtDoor() { return leaveAtDoor; }
    void Client::setLeaveAtDoor(bool leave) { leaveAtDoor = leave; }

    string Client::getDeliveryTime() { return deliveryTime; }
    void Client::setDeliveryTime(string time) { deliveryTime = time; }

    void Client::createOrder(Order order) { orders.push_back(order); }

    void Client::deleteOrder(int index) {
        orders.erase(orders.begin() + index);  //deleteOrder(0)-delete the first order
    }

    void Client::addToOrder(Dish dish, int quantity) {
        Order& currentOrder = orders.back();
        for (int i = 0; i < quantity; i++) {
            currentOrder.getDishes().push_back(dish);
        }
        currentOrder.increaseTotalCost(dish.getPrice() * quantity);
    }

    void Client::removeFromOrder(Dish dish, int quantity) {
        Order& currentOrder = orders.back();
        for (int i = 0; i < quantity; i++) {
            for (auto it = currentOrder.getDishes().begin(); it != currentOrder.getDishes().end(); ++it) {
                if (*it == dish) {
                    currentOrder.getDishes().erase(it);
                    break;
                }
            }
        }
        currentOrder.decreaseTotalCost(dish.getPrice() * quantity);
    }

    void Client::setLowerPriceLimit(double limit) { priceRange.setLowerPrice(limit); }

    void Client::setUpperPriceLimit(double limit) { priceRange.setUpperPrice(limit); }

    void Client::selectCuisine(CuisineType cuisine) {
        Order& currentOrder = orders.back();
        currentOrder.getCuisine() = cuisine;
    }

    void Client::selectDish(Dish dish, int quantity) {
        Order& currentOrder = orders.back();
        for (int i = 0; i < quantity; i++) {
            currentOrder.getDishes().push_back(dish);
        }
        currentOrder.increaseTotalCost(dish.getPrice() * quantity);
    }

    void Client::rateCourier(int rating) { courierRating = rating; }

    void Client::rateRestaurant(int rating) { restaurantRating = rating; }

    void Client::addPhoneNumber(string number) { phoneNumber = number; }

    void Client::callCourier(Courier courier) { cout << "Call the courier to the number " << courier.getPhoneNumber() << "\n"; }

    void Client::linkBankCard(string card) { bankCard = card; }

    void Client::unlinkBankCard() { bankCard = ""; }

    void Client::addCommentToOrder(int orderIndex, string comment) {
        if (orderIndex >= 0 && orderIndex < orders.size()) {
            orders[orderIndex].setComment(comment);
        }
        else {
            cout << "Invalid order index.\n";
        }
    }

    void Client::chooseDeliveryService(DeliveryService newService) { deliveryService = newService; }

    void Client::viewOrderHistory() {
        for (int i = 0; i < orders.size(); i++) {
            cout << "Order " << i + 1 << ": \n";
            orders[i].printOrderDetails();
        }
    }

    void Client::chooseRestaurant(Restaurant newRestaurant) { chosenRestaurant = newRestaurant; }

    void Client::printClientDetails() {
        cout << "Client Name: " << getName() << "\n";
        cout << "Age: " << getAge() << "\n";
        cout << "Preferred Cuisine: " << preferredCuisine << "\n";
        cout << "Delivery Address: " << deliveryAddress << "\n";
        cout << "Phone Number: " << phoneNumber << "\n";
        cout << "Bank Card: " << bankCard << "\n";
        cout << "Delivery Method: " << deliveryMethod << "\n";
        cout << "Payment Method: " << paymentMethod << "\n";
        cout << "Courier Rating: " << courierRating << "\n";
        cout << "Restaurant Rating: " << restaurantRating << "\n";
        cout << "Delivery Address: " << deliveryAdress << "\n";
        cout << "Leave At Door: " << (leaveAtDoor ? "Yes" : "No") << "\n";
        cout << "Delivery Time: " << deliveryTime << "\n";
    }

    void Client::placeOrder(Order order) {
        orders.push_back(order);
        cout << "Order placed successfully!\n";
    }