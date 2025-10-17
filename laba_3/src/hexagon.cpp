#include "Hexagon.hpp"
#include <cmath>
#include <iostream>

Hexagon::Hexagon() : radius(1.0), center(0.0, 0.0) {}

Hexagon::Hexagon(double r, double x, double y) 
    : radius(r), center(x, y) {}

Hexagon::Hexagon(const Hexagon& other)
    : radius(other.radius), center(other.center) {
}

Hexagon::Hexagon(Hexagon&& other) noexcept
    : radius(other.radius), center(other.center) {
    other.radius = 0.0;
}

std::pair<double, double> Hexagon::getCenter() const {
    return center;
}

void Hexagon::print(std::ostream& os) const {
    auto vertices = calculateVertices();
    os << "Значения шестиугольника: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i < vertices.size() - 1) os << " ";
    }
}

void Hexagon::read(std::istream& is) {
    std::cout << "Введите радиус и центр шестиугольника (r x y): ";
    is >> radius >> center.first >> center.second;
}

Hexagon::operator double() const {
    return (3.0 * std::sqrt(3.0) * radius * radius) / 2.0;
}

Figure* Hexagon::clone() const {
    return new Hexagon(*this);
}


bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    if (!otherHexagon) return false;
    return radius == otherHexagon->radius && center == otherHexagon->center;
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        radius = other.radius;
        center = other.center;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        radius = other.radius;
        center = other.center;
        other.radius = 0.0;
    }
    return *this;
}

std::vector<std::pair<double, double>> Hexagon::calculateVertices() const {
    std::vector<std::pair<double, double>> vertices;
    for (int i = 0; i < 6; ++i) {
        double angle = 2.0 * M_PI * i / 6.0;
        vertices.emplace_back(
            center.first + radius * std::cos(angle),
            center.second + radius * std::sin(angle)
        );
    }
    return vertices;
}