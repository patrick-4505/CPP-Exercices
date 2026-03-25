#include <iostream>
#include "rectangle.hpp"

int main() {
    Rectangle rect(5.0, 3.0);
    std::cout << "Rectangle created:" << std::endl;
    std::cout << "Width: "     << rect.getWidth()     << std::endl;
    std::cout << "Height: "    << rect.getHeight()    << std::endl;
    std::cout << "Area: "      << rect.area()         << std::endl;
    std::cout << "Perimeter: " << rect.perimeter()    << std::endl;

    std::cout << std::endl;

    rect.setWidth(10.0);
    rect.setHeight(6.0);

    std::cout << "After modification:" << std::endl;
    std::cout << "Width: "  << rect.getWidth()  << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: "   << rect.area()      << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    return 0;
}