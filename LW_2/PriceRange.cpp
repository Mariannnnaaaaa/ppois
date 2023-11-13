#include "PriceRange.h"
using namespace std;

PriceRange::PriceRange() :lower(0), upper(0) {}

double PriceRange::getLower() { return lower; }
void PriceRange::setLower(double lower) { this->lower = lower; }

double PriceRange::getUpper() { return upper; }
void PriceRange::setUpper(double upper) { this->upper = upper; }

void PriceRange::setLowerPrice(double limit) { lower = limit; }

void PriceRange::setUpperPrice(double limit) { upper = limit; }