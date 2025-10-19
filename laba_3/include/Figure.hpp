#pragma once

#include <iostream>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual std::pair<double, double> getCenter() const = 0;
    
    virtual void print(std::ostream& os) const = 0;
    
    virtual void read(std::istream& is) = 0;
    
    virtual operator double() const = 0;
    
    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    
};

inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}