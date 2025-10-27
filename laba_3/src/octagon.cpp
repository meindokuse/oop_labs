#include "Octagon.hpp"

#include <cmath>
#include <iostream>

Octagon::Octagon() : radius(1.0), center(0.0, 0.0) {}

Octagon::Octagon(double r, double x, double y) 
    : radius(r), center(x, y) {}

Octagon::Octagon(const Octagon& other)
    : radius(other.radius), center(other.center) {
}

Octagon::Octagon(Octagon&& other) noexcept
    : radius(other.radius), center(other.center) {
    other.radius = 0.0;
}

std::pair<double, double> Octagon::getCenter() const {
    return center;
}

void Octagon::print(std::ostream& os) const {
    auto vertices = calculateVertices();
    os << "Значения восьмиугольника: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i < vertices.size() - 1) os << " ";
    }
}

void Octagon::read(std::istream& is) {
    std::cout << "Введите радиус и центр восьмиугольнка (r x y): ";
    is >> radius >> center.first >> center.second;
}

Octagon::operator double() const {
    return 2.0 * std::sqrt(2.0) * radius * radius;
}

Figure* Octagon::clone() const {
    return new Octagon(*this);
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    if (!otherOctagon) return false;
    return radius == otherOctagon->radius && center == otherOctagon->center;
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        radius = other.radius;
        center = other.center;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        radius = other.radius;
        center = other.center;
        other.radius = 0.0;
    }
    return *this;
}

std::vector<std::pair<double, double>> Octagon::calculateVertices() const {
    std::vector<std::pair<double, double>> vertices;
    for (int i = 0; i < 8; ++i) {
        double angle = 2.0 * M_PI * i / 8.0;
        vertices.emplace_back(
            center.first + radius * std::cos(angle),
            center.second + radius * std::sin(angle)
        );
    }
    return vertices;
}