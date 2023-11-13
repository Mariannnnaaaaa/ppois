#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/Client.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FoodDeliveryTest
{
    TEST_CLASS(FoodDeliveryTest)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            Client client1("John", 30, "Italian", "123 Main St");
            client1.setPhoneNumber("555-1234");
            client1.setBankCard("1234-5678-9012-3456");
            client1.setDeliveryMethod("Delivery");
            client1.setPaymentMethod("Credit Card");
            client1.setCourierRating(5);
            client1.setRestaurantRating(4);
            client1.setDeliveryAdress("123 Main St");
            client1.setLeaveAtDoor(true);
            client1.setDeliveryTime("ASAP");

            Order order1;
            order1.setRestaurantName("Pizza Place");
            order1.increaseTotalCost(25.99);
            order1.setNeedsUtensils("yes");
            order1.setComment("Extra cheese, please!");
            order1.usePromocode("PIZZA50");

            Assert::AreEqual(client1.getAge(), 30);
        }
    };
}
