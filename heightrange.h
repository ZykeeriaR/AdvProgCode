// Copyright ZykeeriaR 2024

#ifndef HEIGHTRANGE_H
#define HEIGHTRANGE_H

#include "height.h"

class HeightRange {
private:
    Height smallest;
    Height largest;

public:
    // Default constructor
    HeightRange();

    HeightRange(const Height& h1, const Height& h2);

    // Set the shortest height
    bool SetShortest(const Height& h);

    // Get the shortest height
    Height GetShortest() const;

    // Set the tallest height
    bool SetTallest(const Height& h);

    // Get the tallest height
    Height GetTallest() const;

    // Check if a height is within the range
    bool InRange(const Height& h, bool inclusive = true) const;

    Height Width() const;
};

#endif
