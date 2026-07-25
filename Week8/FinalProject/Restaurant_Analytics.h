#ifndef RESTAURANT_ANALYTICS_H
#define RESTAURANT_ANALYTICS_H

#include <string>
#include <vector>
#include "MenuItem.h"

namespace RestaurantAnalytics
{
    // Function One
    int StringToInt(const std::string& str);

    // For converting price strings
    double StringToDouble(const std::string& str);

    // Function Two
    void LoadInventory(const std::string& filename, std::vector<MenuItem>& inventory);

    // Function Three
    void DisplayInventory(const std::vector<MenuItem>& inventory);

    // Function Four
    void DisplayCategory(const std::vector<MenuItem>& inventory, const std::string& category);

    // Function Five
    void DisplayPriceRange(const std::vector<MenuItem>& inventory, double minPrice, double maxPrice);

    // Function Six
    MenuItem* FindItem(std::vector<MenuItem>& inventory, const std::string& name);

    // Function Seven
    void ApplyDiscount(std::vector<MenuItem>& inventory, const std::string& category, double discount);

    // Function Nine
    std::vector<MenuItem> LowestStock(std::vector<MenuItem> inventory, int k);

    // Function Ten
    std::vector<MenuItem> HighestPrice(std::vector<MenuItem> inventory, int k);

    // Function Eleven
    void SaveLowStock(const std::vector<MenuItem>& inventory, const std::string& filename, int threshold);
}

#endif