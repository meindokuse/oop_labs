#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle() : radius(1.0), center(0.0, 0.0) {}

Triangle::Triangle(double r, double x, double y) 
    : radius(r), center(x, y) {}

Triangle::Triangle(const Triangle& other) 
    : radius(other.radius), center(other.center) {
}

Triangle::Triangle(Triangle&& other) noexcept 
    : radius(other.radius), center(other.center) {
    other.radius = 0.0;
}

std::pair<double, double> Triangle::getCenter() const {
    return center;
}

void Triangle::print(std::ostream& os) const {
    auto vertices = calculateVertices();
    os << "Значения треугольника: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i < vertices.size() - 1) os << " ";
    }
}

void Triangle::read(std::istream& is) {
    std::cout << "Введите радиус и центр треугольника (r x y): ";
    is >> radius >> center.first >> center.second;
}

Triangle::operator double() const {
    return (3.0 * std::sqrt(3.0) * radius * radius) / 4.0;
}

Figure* Triangle::clone() const {
    return new Triangle(*this); 
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    return radius == otherTriangle->radius && center == otherTriangle->center;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        radius = other.radius;
        center = other.center;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        radius = other.radius;
        center = other.center;
        other.radius = 0.0;
    }
    return *this;
}

std::vector<std::pair<double, double>> Triangle::calculateVertices() const {
    std::vector<std::pair<double, double>> vertices;
    for (int i = 0; i < 3; ++i) {
        double angle = 2.0 * M_PI * i / 3.0;
        vertices.emplace_back(
            center.first + radius * std::cos(angle),
            center.second + radius * std::sin(angle)
        );
    }
    return vertices;
}