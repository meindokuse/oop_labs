#pragma once

#include "Figure.hpp"

#include <vector> 
#include <utility>

class Hexagon : public Figure {
private:
    double radius;
    std::pair<double, double> center;
    std::vector<std::pair<double, double>> calculateVertices() const;

public:
    Hexagon();
    Hexagon(double r, double x, double y);
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;
    
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    

};