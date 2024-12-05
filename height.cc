// Copyright ZykeeriaR 2024

#include "height.h"

// Constructor
Height::Height(double val, const std::string& unit) {
    SetValue(val);
    if (!SetUnits(unit)) {  // If the unit is invalid sets a default
        units = "feet";  
    }
}

// Set the value
bool Height::SetValue(double val) {
    if (val >= 0) {
        value = val;
        return true;
    }
    return false;
}

// Get the value
double Height::GetValue() const {
    return value;
}

// Set the units
bool Height::SetUnits(const std::string& unit) {
    if (unit == "inches" || unit == "feet" || unit == "centimeters" || unit == "meters") {
        units = unit;
        return true;
    }
    return false;
}

// Get the units
std::string Height::GetUnits() const {
    return units;
}

// Convert between different units
bool Height::ConvertUnits(const std::string& new_units) {
    double conversionFactor = 1.0;

    if (units == "feet") {
        if (new_units == "inches") conversionFactor = 12.0;
        else if (new_units == "meters") conversionFactor = 0.3048;
        else if (new_units == "centimeters") conversionFactor = 30.48;
    } else if (units == "inches") {
        if (new_units == "feet") conversionFactor = 1.0 / 12.0;
        else if (new_units == "meters") conversionFactor = 0.0254;
        else if (new_units == "centimeters") conversionFactor = 2.54;
    } else if (units == "meters") {
        if (new_units == "feet") conversionFactor = 3.28084;
        else if (new_units == "inches") conversionFactor = 39.3701;
        else if (new_units == "centimeters") conversionFactor = 100.0;
    } else if (units == "centimeters") {
        if (new_units == "feet") conversionFactor = 0.0328084;
        else if (new_units == "inches") conversionFactor = 0.393701;
        else if (new_units == "meters") conversionFactor = 0.01;
    }

    if (conversionFactor == 1.0 && units != new_units) {
        return false;
    }

    value *= conversionFactor;
    units = new_units;
    return true;
}

std::ostream& operator<<(std::ostream& out, const Height& h) {
    out << h.value << " " << h.units;
    return out;
}
