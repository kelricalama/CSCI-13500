#include "Restaurant_Analytics.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

namespace RestaurantAnalytics 
{
    // Converts a string into an integer
    int StringToInt(const std::string& str)
    {
        int number = 0;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                number = number * 10 + (str[i] - '0');
            }
        }

        return number;
    }

    // Helper function to convert string to double
    double StringToDouble(const std::string& str)
    {
        double number = 0;
        double decimalPlace = 0.1;
        bool decimal = false;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                decimal = true;
            }
            else
            {
                int digit = str[i] - '0';

                if (decimal)
                {
                    number += digit * decimalPlace;
                    decimalPlace *= 0.1;
                }
                else
                {
                    number = number * 10 + digit;
                }
            }
        }

        return number;
    }
    
    // Reads inventory data from a CSV file
    void LoadInventory(const std::string& filename, std::vector<MenuItem>& inventory)
    {
        std::ifstream inputFile(filename);
        
        if (!inputFile.is_open())
        {
            std::cout << "Error: Unable to open file " << filename << std::endl;
            return;
        }
        
        std::string line;
        
        // Read each remaining line
        while (std::getline(inputFile, line))
        {
            std::stringstream ss(line);
            
            std::string name;
            std::string category;
            std::string priceString;
            std::string stockString;
            
            std::getline(ss, name, ',');
            std::getline(ss, category, ',');
            std::getline(ss, priceString, ',');
            std::getline(ss, stockString, ',');
            
            double price = StringToDouble(priceString);
            int stock = StringToInt(stockString);
            
            MenuItem item(name, category, price, stock);
            
            inventory.push_back(item);
        
        }
    }

    // Function 3: Display entire inventory
    void DisplayInventory(const std::vector<MenuItem>& inventory)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            inventory[i].PrintItem();
        }
    }

    // Function 4: Display items by category
    void DisplayCategory(const std::vector<MenuItem>& inventory, const std::string& category)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].GetCategory() == category)
            {
                inventory[i].PrintItem();
            }
        }
    }

    // Function 5: Display items by price range
    void DisplayPriceRange(const std::vector<MenuItem>& inventory, double minPrice, double maxPrice)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            double price = inventory[i].GetPrice();

            if (price >= minPrice && price <= maxPrice)
            {
                inventory[i].PrintItem();
            }
        }
    }

    // Function 6: Find item and return pointer
    MenuItem* FindItem(std::vector<MenuItem>& inventory,
                       const std::string& name)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].GetName() == name)
            {
                return &inventory[i];
            }
        }

        return nullptr;
    }

    // Function 7: Apply discount
    void ApplyDiscount(std::vector<MenuItem>& inventory,
                       const std::string& category,
                       double discount)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].GetCategory() == category)
            {
                double oldPrice = inventory[i].GetPrice();

                double newPrice = oldPrice * (1 - discount);

                inventory[i].SetPrice(newPrice);
            }
        }
    }

    // Function 9: Lowest stock items
    std::vector<MenuItem> LowestStock(std::vector<MenuItem> inventory, int k)
    {
        // Selection sort
        for (int i = 0; i < inventory.size() - 1; i++)
        {
            int smallest = i;

            for (int j = i + 1; j < inventory.size(); j++)
            {
                if (inventory[j].GetStock() <
                    inventory[smallest].GetStock())
                {
                    smallest = j;
                }
            }

            MenuItem temp = inventory[i];
            inventory[i] = inventory[smallest];
            inventory[smallest] = temp;
        }

        std::vector<MenuItem> result;

        for (int i = 0; i < k && i < inventory.size(); i++)
        {
            result.push_back(inventory[i]);
        }

        return result;
    }

    // Function 10: Highest price items
    std::vector<MenuItem> HighestPrice(std::vector<MenuItem> inventory, int k)
    {
        for (int i = 0; i < inventory.size() - 1; i++)
        {
            int largest = i;


            for (int j = i + 1; j < inventory.size(); j++)
            {
                if (inventory[j].GetPrice() >
                    inventory[largest].GetPrice())
                {
                    largest = j;
                }
            }


            MenuItem temp = inventory[i];
            inventory[i] = inventory[largest];
            inventory[largest] = temp;
        }

        std::vector<MenuItem> result;

        for (int i = 0; i < k && i < inventory.size(); i++)
        {
            result.push_back(inventory[i]);
        }

        return result;
    }

    // Function 11: Save low stock items to CSV
    void SaveLowStock(const std::vector<MenuItem>& inventory, const std::string& filename, int threshold)
    {
        std::ofstream file(filename);

        if (!file)
        {
            std::cout << "Could not create file." << std::endl;
            return;
        }

        file << "Name,Category,Price,Stock\n";

        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].GetStock() < threshold)
            {
                file << inventory[i].GetName() << "," << inventory[i].GetCategory() << "," << inventory[i].GetPrice() << "," << inventory[i].GetStock() << "\n";
            }
        }
    }
}





