// Copyright ZykeeriaR 2024

#include "heightrange.h"
#include <stdexcept>
#include <iostream> // For optional debugging

// Default constructor initializing heights to 0 feet
HeightRange::HeightRange() : smallest(0, "feet"), largest(0, "feet") {}

HeightRange::HeightRange(const Height& h1, const Height& h2) {
    Height converted_h1 = h1;  // Make a copy of h1
    Height converted_h2 = h2;  // Make a copy of h2

    if (!converted_h1.ConvertUnits("feet")) {
        throw std::invalid_argument("Invalid units in first height.");
    }
    if (!converted_h2.ConvertUnits("feet")) {
        throw std::invalid_argument("Invalid units in second height.");
    }

    // compare the heights in "feet"
    if (converted_h1.GetValue() <= converted_h2.GetValue()) {
        smallest = h1;  // Assign the original height object, not the converted one
        largest = h2;
    } else {
        smallest = h2;
        largest = h1;
    }
}

// Set the shortest height if valid
bool HeightRange::SetShortest(const Height& h) {
    // Convert the argument to the same units as the largest height
    Height converted_h = h; 
    if (!converted_h.ConvertUnits(largest.GetUnits())) {
        return false; 
    }

    //  compare values in the same unit
    if (converted_h.GetValue() <= largest.GetValue()) {
        smallest = h; 
        return true;
    }
    return false;
}

// Get the shortest height
Height HeightRange::GetShortest() const {
    return smallest;
}

// Set the tallest height if valid
bool HeightRange::SetTallest(const Height& h) {
    Height converted_h = h; // Make a copy of h
    if (!converted_h.ConvertUnits(smallest.GetUnits())) {
        return false; // Invalid conversion
    }

    if (converted_h.GetValue() >= smallest.GetValue()) {
        largest = h; 
        return true;
    }
    return false;
}

// Get the tallest height
Height HeightRange::GetTallest() const {
    return largest;
}

// Check if a height is in the range
bool HeightRange::InRange(const Height& h, bool inclusive) const {
    Height converted_h = h;

    if (!converted_h.ConvertUnits(largest.GetUnits())) {
        return false; 
    }

    const double epsilon = 1e-6;

    double smallestValue = smallest.GetValue();
    double largestValue = largest.GetValue();
    double hValue = converted_h.GetValue();

    if (inclusive) {
        return (hValue >= smallestValue - epsilon) && 
               (hValue <= largestValue + epsilon);
    } else {
        return (hValue > smallestValue + epsilon) && 
               (hValue < largestValue - epsilon);
    }
}

Height HeightRange::Width() const {

    Height converted_smallest = smallest;
    if (!converted_smallest.ConvertUnits(largest.GetUnits())) {
        throw std::invalid_argument("Invalid unit conversion in Width calculation.");
    }

    // Calculate the width
    double widthValue = largest.GetValue() - converted_smallest.GetValue();

    return Height(widthValue, largest.GetUnits());
}
