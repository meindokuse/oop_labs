#pragma once
#include "Figure.hpp"

class Triangle : public Figure {
private:
    double radius;
    std::pair<double, double> center;

public:
    Triangle();
    Triangle(double r, double x, double y);
    Triangle(const Triangle& other);  
    Triangle(Triangle&& other) noexcept; 
    
    std::pair<double, double> getCenter() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;
    
    Figure* clone() const override;
    bool operator==(const Figure& other) const override;
    Triangle& operator=(const Triangle& other);  
    Triangle& operator=(Triangle&& other) noexcept; 
    
private:
    std::vector<std::pair<double, double>> calculateVertices() const;
};