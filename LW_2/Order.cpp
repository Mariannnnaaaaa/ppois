#include "Order.h"
using namespace std;

Order::Order() :totalCost(0) {
    promocodes["PROMO10"] = 0.1;
    promocodes["PROMO20"] = 0.2;
    promocodes["PROMO30"] = 0.3;
    promocodes["PROMO40"] = 0.4;
    promocodes["PROMO50"] = 0.5;
    promocodes["PROMO60"] = 0.6;
    promocodes["PROMO70"] = 0.7;
    promocodes["PROMO80"] = 0.8;
    promocodes["PROMO90"] = 0.9;
    promocodes["PROMO100"] = 1;
}


string Order::getRestaurantName() { return restaurantName; }
void Order::setRestaurantName(const string& restaurantName) { this->restaurantName = restaurantName; }

vector<Dish> Order::getDishes() { return dishes; }
void Order::setDishes(const vector<Dish>& dishes) { this->dishes = dishes; }

double Order::getTotalCost() { return totalCost; }
void Order::setTotalCost(double totalCost) { this->totalCost = totalCost; }

CuisineType Order::getCuisine() { return cuisine; }
void Order::setCuisine(const CuisineType& cuisine) { this->cuisine = cuisine; }

vector<FoodAddition> Order::getFoodAdditions() { return foodAdditions; }
void Order::setFoodAdditions(const vector<FoodAddition>& foodAdditions) { this->foodAdditions = foodAdditions; }

bool Order::getNeedsUtensils() { return needsUtensils; }
void Order::setNeedsUtensils(bool needsUtensils) { this->needsUtensils = needsUtensils; }

string Order::getComment() { return comment; }
void Order::setComment(const string& comment) { this->comment = comment; }

string Order::getPromocode() { return promocode; }
void Order::setPromocode(const string& promocode) { this->promocode = promocode; }

map<string, double> Order::getPromocodes() { return promocodes; }
void Order::setPromocodes(const map<string, double>& promocodes) { this->promocodes = promocodes; }

void Order::addFoodAddition(FoodAddition addition) { foodAdditions.push_back(addition); }

void Order::setNeedsUtensils(string input) {
    if (input == "yes") needsUtensils = true;
    else if (input == "no") needsUtensils = false;
    else cout << "Invalid input. Please enter 'yes' if you need appliances, or 'no' if you don't need them.\n";
}

void Order::usePromocode(string promocode) {
    this->promocode = promocode;
    if (promocodes.count(promocode) > 0) {
        double discount = promocodes[promocode];
        totalCost *= (1.0 - discount);
    }
    else cout << "Wrong promocode.\n";
}

void Order::increaseTotalCost(double cost) { totalCost += cost; }
void Order::decreaseTotalCost(double cost) { totalCost -= cost; }

void Order::printOrderDetails() {
    cout << "Restaurant Name: " << restaurantName << "\n";
    cout << "Total Cost: " << totalCost << "\n";
    cout << "Cuisine Type: " << cuisine.getName() << "\n";
    cout << "Needs Utensils: " << (needsUtensils ? "Yes" : "No") << "\n";
    cout << "Comment: " << comment << "\n";
    cout << "Promocode: " << promocode << "\n";

    cout << "Dishes: \n";
    for (int i = 0; i < dishes.size(); i++) {
        dishes[i].printDishDetails();
    }

    cout << "Food Additions: \n";
    for (int i = 0; i < foodAdditions.size(); i++) {
        foodAdditions[i].printFoodAdditionDetails();
    }
}