#include "Restaurant_Analytics.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<MenuItem> inventory;

    // Test string conversion functions
    int testNumber = RestaurantAnalytics::StringToInt("25");

    double testPrice = RestaurantAnalytics::StringToDouble("8.50");

    std::cout << "TEST STRING FUNCTIONS" << std::endl;
    std::cout << "String to int: " << testNumber << std::endl;
    std::cout << "String to double: " << testPrice << std::endl;
    std::cout << std::endl;

    // Function 2: Load inventory from CSV
    RestaurantAnalytics::LoadInventory("inventory.csv", inventory);

    // Function 3: Display all inventory
    std::cout << "FULL INVENTORY" << std::endl;

    RestaurantAnalytics::DisplayInventory(inventory);

    // Function 4: Display category
    std::cout << "DESSERT ITEMS" << std::endl;

    RestaurantAnalytics::DisplayCategory(inventory, "Dessert");

    // Function 5: Display price range
    std::cout << "ITEMS BETWEEN $5 AND $10" << std::endl;

    RestaurantAnalytics::DisplayPriceRange(inventory, 5.00, 10.00);

    // Function 6: Find item using pointer
    std::cout << "FIND ITEM" << std::endl;

    MenuItem* item = RestaurantAnalytics::FindItem(inventory, "French Fries");

    if (item != nullptr) {
        std::cout << "Found item:" << std::endl;

        item->PrintItem();


        // Changes the original item's stock using the pointer
        item->SetStock(25);

        std::cout << "After changing stock:" << std::endl;

        item->PrintItem();
    }
    else
    {
        std::cout << "Item not found." << std::endl;
    }

    // Function 7: Apply discount
    std::cout << "APPLY 10% DISCOUNT TO DESSERTS" << std::endl;

    RestaurantAnalytics::ApplyDiscount(inventory,"Dessert", 0.10);

    RestaurantAnalytics::DisplayCategory(inventory,"Dessert");

    // Function 9: Lowest stock
    std::cout << "LOWEST STOCK ITEMS" << std::endl;

    std::vector<MenuItem> lowStock = RestaurantAnalytics::LowestStock(inventory, 3);

    RestaurantAnalytics::DisplayInventory(lowStock);

    // Function 10: Highest price
    std::cout << "MOST EXPENSIVE ITEMS" << std::endl;

    std::vector<MenuItem> expensive = RestaurantAnalytics::HighestPrice(inventory, 3);

    RestaurantAnalytics::DisplayInventory(expensive);

    // Function 11: Save low stock items
    RestaurantAnalytics::SaveLowStock(inventory,"low_stock.csv",5);

    std::cout << "Low stock report created!" << std::endl;

    return 0;
}