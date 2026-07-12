#include <iostream>

int mysteryA(int x)
{
    x += 10;
    return x;
}

void mysteryB(int& y)
{
    y *= 2;
}

void mysteryC(int* z)
{
    if (z != nullptr)
    {
        (*z)--;
    }
}

int main()
{
    int value = 5;

    value = mysteryA(value);
    mysteryB(value);
    mysteryC(&value);

    std::cout << value << std::endl;
}