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
            
            client1.getBankCard();
            client1.getLeaveAtDoor();
            client1.getDeliveryAdress();
            client1.getCourierRating();
            client1.getDeliveryMethod();
            client1.getPaymentMethod();
            client1.getRestaurantRating();
            client1.getDeliveryTime();

            Order order1;
            order1.setRestaurantName("Pizza Nravizza");
            order1.setNeedsUtensils("yes");
            order1.setComment("Extra cheese, please!");
            order1.usePromocode("PIZZA50");

            order1.getComment();
            order1.getNeedsUtensils();
            order1.getRestaurantName();

            Assert::AreEqual(client1.getAge(), 30);
        }

        TEST_METHOD(TestMethod2)
        {
            Client client1;
            client1.setPreferredCuisine("Fast Food");
            client1.setDeliveryAddress("4 Beruta");
            Dish dish1("Pizza Margarita", 10.25);
            Order order1;
            client1.createOrder(order1);
            client1.addToOrder(dish1, 2);
            CuisineType cuisine1;
            cuisine1.setName("Chinese");
            client1.selectCuisine(cuisine1);
            client1.setUpperPriceLimit(13.50);
            client1.setLowerPriceLimit(9.50);
            Restaurant restaurant1;
            restaurant1.setName("Noodles");
            client1.chooseRestaurant(restaurant1);
            Dish dish2("Chicken udon", 11.25);
            dish2.getName();
            dish2.printDishDetails();
            client1.selectDish(dish2, 1);
            client1.placeOrder(order1);
            order1.printOrderDetails();
            string str = "Chinese";
            client1.addPhoneNumber("+375291039450");
            client1.getPhoneNumber();
            client1.viewOrderHistory();
            client1.printClientDetails();
            Courier courier1("Maxim", 23, "bike", true);
            courier1.takeOrder(order1);
            client1.setCourierRating(5);
            client1.addCommentToOrder(0,"Please, run as fast as you can!");
            DeliveryService deliveryService1;
            deliveryService1.setName("Yandex Dostavka");
            deliveryService1.getName();
            client1.chooseDeliveryService(deliveryService1);
            
            Assert::AreEqual(cuisine1.getName(),str);
        }
        TEST_METHOD(TestMethod3)
        {
            Courier courier1;
            courier1.setVehicleType("bike");
            courier1.getVehicleType();
            courier1.setPhoneNumber("+375445860294");
            courier1.setIsAvailable(true);
            Order order1;
            order1.setNeedsUtensils("no");
            FoodAddition foodAddition1;
            foodAddition1.setName("Sause");
            order1.addFoodAddition(foodAddition1);
            courier1.takeOrder(order1);
            courier1.getCurrentOrder();
            courier1.getIsAvailable();
            courier1.completeOrder();
            Client client1;
            client1.callCourier(courier1);
            Assert::AreEqual(courier1.getIsAvailable(), true);
        }
        TEST_METHOD(TestMethod4)
        {
            Client client1("Carl", 12, "Georgian", "56 Kolas");
            client1.getAge();
            client1.getName();
            client1.getDeliveryAddress();
            client1.getPreferredCuisine();
            client1.linkBankCard("484930249048");
            client1.unlinkBankCard();
            Order order1;
            PriceRange priceRange1;
            priceRange1.setLower(4);
            priceRange1.setUpper(7);
            Assert::AreEqual(priceRange1.getLower(), 4.00);
        }
    };
}
