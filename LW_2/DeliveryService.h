#pragma once
#include <iostream>
#include <string>

using namespace std;

class DeliveryService
{
private:
    string name;
public:
    DeliveryService();
    DeliveryService(string name);
    string getName();
    void setName(const string& name);
};

