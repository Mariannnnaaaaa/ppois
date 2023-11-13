#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "FoodAddition.h"
#include "Dish.h"
#include "CuisineType.h"

using namespace std;
class Order
{
private:
    string restaurantName;
    vector <Dish> dishes;
    double totalCost;
    CuisineType cuisine;
    vector<FoodAddition> foodAdditions;
    bool needsUtensils;
    string comment;
    string promocode;
    map<string, double> promocodes;

public:
    Order();

    string getRestaurantName();
    void setRestaurantName(const string& restaurantName);

    vector<Dish> getDishes();
    void setDishes(const vector<Dish>& dishes);

    double getTotalCost();
    void setTotalCost(double totalCost);

    CuisineType getCuisine();
    void setCuisine(const CuisineType& cuisine);

    vector<FoodAddition> getFoodAdditions();
    void setFoodAdditions(const vector<FoodAddition>& foodAdditions);

    bool getNeedsUtensils();
    void setNeedsUtensils(bool needsUtensils);

    string getComment();
    void setComment(const string& comment);

    string getPromocode();
    void setPromocode(const string& promocode);

    map<string, double> getPromocodes();
    void setPromocodes(const map<string, double>& promocodes);

    void addFoodAddition(FoodAddition addition);

    void setNeedsUtensils(string input);

    void usePromocode(string promocode);

    void increaseTotalCost(double cost);
    void decreaseTotalCost(double cost);

    void printOrderDetails();
};

