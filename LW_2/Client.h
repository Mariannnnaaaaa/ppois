#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Human.h"
#include "Order.h"
#include "PriceRange.h"
#include "DeliveryService.h"
#include "Restaurant.h"
#include "Dish.h"
#include "CuisineType.h"
#include "Courier.h"

using namespace std;
class Client:public Human
{
private:
    string preferredCuisine;
    string deliveryAddress;
    vector <Order> orders;
    PriceRange priceRange;
    string deliveryAdress;
    string deliveryMethod;
    string paymentMethod;
    int courierRating;
    int restaurantRating;
    string phoneNumber;
    string bankCard;
    DeliveryService deliveryService;
    bool leaveAtDoor;
    Restaurant chosenRestaurant;
    string deliveryTime;

public:
    Client();
    Client(string name, int age, string preferredCuisine, string deliveryAddress);

    string getPreferredCuisine();
    void setPreferredCuisine(const string& preferredCuisine);

    string getDeliveryAddress();
    void setDeliveryAddress(const string& deliveryAddress);

    vector<Order> getOrders();
    void setOrders(const vector<Order>& orders);

    string getDeliveryAdress();
    void setDeliveryAdress(const string& deliveryAdress);

    string getDeliveryMethod();
    void setDeliveryMethod(const string& deliveryMethod);

    string getPaymentMethod();
    void setPaymentMethod(const string& paymentMethod);

    int getCourierRating();
    void setCourierRating(int courierRating);

    int getRestaurantRating();
    void setRestaurantRating(int restaurantRating);

    string getPhoneNumber();
    void setPhoneNumber(const string& phoneNumber);

    string getBankCard();
    void setBankCard(const string& bankCard);

    bool getLeaveAtDoor();
    void setLeaveAtDoor(bool leave);

    string getDeliveryTime();
    void setDeliveryTime(string time);

    void createOrder(Order order);

    void deleteOrder(int index);

    void addToOrder(Dish dish, int quantity);

    void removeFromOrder(Dish dish, int quantity);

    void setLowerPriceLimit(double limit);

    void setUpperPriceLimit(double limit);

    void selectCuisine(CuisineType cuisine);

    void selectDish(Dish dish, int quantity);

    void rateCourier(int rating);

    void rateRestaurant(int rating);

    void addPhoneNumber(string number);

    void callCourier(Courier courier);

    void linkBankCard(string card);

    void unlinkBankCard();

    void addCommentToOrder(int orderIndex, string comment);

    void chooseDeliveryService(DeliveryService newService);

    void viewOrderHistory();

    void chooseRestaurant(Restaurant newRestaurant);

    void printClientDetails();

    void placeOrder(Order order);

};


