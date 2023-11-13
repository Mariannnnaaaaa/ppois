#include "DeliveryService.h"
using namespace std;

DeliveryService::DeliveryService() {}
DeliveryService::DeliveryService(string name) : name(name) {}
string DeliveryService::getName() { return name; }
void DeliveryService::setName(const string& name) { this->name = name; }