#pragma once
#include <iostream>
using namespace std;

class PriceRange
{
private:
    double lower;
    double upper;
public:
    PriceRange();

    double getLower();
    void setLower(double lower);

    double getUpper();
    void setUpper(double upper);

    void setLowerPrice(double limit);

    void setUpperPrice(double limit);
};

