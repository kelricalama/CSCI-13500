#include "MenuItem.h"
#include <iostream>

//Default constructor
MenuItem::MenuItem()
{
    name = "";
    category = "";
    price = 0.0;
    stock = 0;
}

// Creates a menu item using the given information
MenuItem::MenuItem(std::string name, std::string category, double price, int stock)
{
    this->name = name;
    this->category = category;
    this->price = price;
    this->stock = stock;
}

// Returns the item name
std::string MenuItem::GetName() const
{
    return name;
}

// Returns the item category
std::string MenuItem::GetCategory() const
{
    return category;
}

// Returns the item price
double MenuItem::GetPrice() const
{
    return price;
}

// Returns the item stock amount
int MenuItem::GetStock() const
{
    return stock;
}

// Changes the item name
void MenuItem::SetName(const std::string& name)
{
    this->name = name;
}

// Changes the item category
void MenuItem::SetCategory(const std::string& category)
{
    this->category = category;
}

// Changes the item price
void MenuItem::SetPrice(double price)
{
    this->price = price;
}

// Changes the item stock amount
void MenuItem::SetStock(int stock) 
{
    this->stock = stock;
}

// Prints the menu item information
void MenuItem::PrintItem() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << std::endl;
}
