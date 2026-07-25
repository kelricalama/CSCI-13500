#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

// Stores information about one restaurant menu item
class MenuItem
{
    private:
    std::string name;
    std::string category;
    double price;
    int stock;
    
    public:
    // Constructors
    MenuItem();
    MenuItem(std::string name, std::string category, double price, int stock);

    // Gets item information
    std::string GetName() const;
    std::string GetCategory() const;
    double GetPrice() const;
    int GetStock() const;

    // Changes item information
    void SetName(const std::string& name);
    void SetCategory(const std::string& category);
    void SetPrice(double price);
    void SetStock(int stock);

    // Prints item information
    void PrintItem() const;
};

#endif