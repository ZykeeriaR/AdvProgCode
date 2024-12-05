// Copyright ZykeeriaR 2024

#ifndef HEIGHT_H
#define HEIGHT_H

#include <string>
#include <iostream>

class Height {
private:
    double value; // Stores the height value
    std::string units; 
public:

    Height(double value = 0, const std::string& units = "feet");

    bool SetValue(double val);

    double GetValue() const;

    bool SetUnits(const std::string& units);

    std::string GetUnits() const;

    // Convert height to different units
    bool ConvertUnits(const std::string& new_units);

    friend std::ostream& operator<<(std::ostream& out, const Height& h);
};

#endif
