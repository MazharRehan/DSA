/*
The <iomanip> library in C++ is used for formatting input and output operations. 
It provides tools to manipulate the formatting of numeric values, control the 
width and precision of output, align output, set fill characters, and more. 
This library is particularly useful when working with formatted input and output, 
such as when displaying data in tables or when precision and alignment are important.
*/

#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159;
    int width = 10;

    // Set the output precision to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Output a header for the table
    std::cout << std::setw(width) << "Radius"
        << std::setw(width) << "Area" << std::endl;

    // Output rows of radius and corresponding area
    for (int radius = 1; radius <= 5; radius++) {
        double area = pi * radius * radius;

        // Set the fill character to '-'
        std::cout << std::setw(width) << radius
            << std::setw(width) << area << std::endl;
    }

    return 0;
}
