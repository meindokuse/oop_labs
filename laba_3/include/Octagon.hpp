#pragma once

#include "Figure.hpp"

#include <vector> 
#include <utility>

class Octagon : public Figure {
private:
    double radius;
    std::pair<double, double> center;
    std::vector<std::pair<double, double>> calculateVertices() const;

public:
    Octagon();
    Octagon(double r, double x, double y);
    Octagon(const Octagon& other);  
    Octagon(Octagon&& other) noexcept; 
    
    std::pair<double, double> getCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;
    
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;
    Octagon& operator=(const Octagon& other);  
    Octagon& operator=(Octagon&& other) noexcept; 
};