#include "FigureVector.hpp"
#include <iostream>

FigureVector::FigureVector() : size(0), capacity(10), figures(new Figure*[capacity]()) {}

FigureVector::FigureVector(size_t initial_size, Figure* value)
    : size(initial_size), capacity(std::max(initial_size * 2, size_t(10))),
      figures(new Figure*[capacity]()) {
    
    for (size_t i = 0; i < size; ++i) {
        figures[i] = (value != nullptr) ? value->clone() : nullptr;
    }
}

FigureVector::FigureVector(const FigureVector& other)
    : size(other.size), capacity(other.capacity),
      figures(new Figure*[capacity]()) {
    
    for (size_t i = 0; i < size; ++i) {
        if (other.figures[i] != nullptr) {
            figures[i] = other.figures[i]->clone();
        }
    }
}

FigureVector::FigureVector(FigureVector&& other) noexcept
    : size(other.size), capacity(other.capacity), figures(other.figures) {
    
    other.figures = nullptr;
    other.size = 0;
    other.capacity = 0;
}

FigureVector& FigureVector::operator=(const FigureVector& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete figures[i];
        }
        delete[] figures;

        size = other.size;
        capacity = other.capacity;
        figures = new Figure*[capacity]();
        
        for (size_t i = 0; i < size; ++i) {
            if (other.figures[i] != nullptr) {
                figures[i] = other.figures[i]->clone();
            }
        }
    }
    return *this;
}

FigureVector& FigureVector::operator=(FigureVector&& other) noexcept {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete figures[i];
        }
        delete[] figures;

        size = other.size;
        capacity = other.capacity;
        figures = other.figures;

        other.figures = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

FigureVector::~FigureVector() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

void FigureVector::resize(size_t new_capacity) {
    if (new_capacity < size) return;

    Figure** new_figures = new Figure*[new_capacity]();
    for (size_t i = 0; i < size; ++i) {
        new_figures[i] = figures[i];
    }
    
    delete[] figures;
    figures = new_figures;
    capacity = new_capacity;
}

void FigureVector::push(Figure* figure) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    figures[size++] = figure;
}

void FigureVector::pop() {
    if (size > 0) {
        delete figures[size - 1];
        figures[--size] = nullptr;
        
        if (size < capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }
}

void FigureVector::clear() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
    size = 0;
}

Figure* FigureVector::get(size_t index) const {
    return (index < size) ? figures[index] : nullptr;
}

Figure* FigureVector::operator[](size_t index) const {
    return get(index);
}

size_t FigureVector::len() const {
    return size;
}

size_t FigureVector::getSize() const {
    return size;  
}

void FigureVector::swap(size_t index1, size_t index2) {
    if (index1 < size && index2 < size) {
        Figure* temp = figures[index1];
        figures[index1] = figures[index2];
        figures[index2] = temp;
    }
}

void FigureVector::set(size_t index, Figure* figure) {
    if (index < size) {
        delete figures[index];  
        figures[index] = figure;
    }
}

void FigureVector::remove(size_t index) {
    if (index >= size) return;
    
    delete figures[index];  
    
    for (size_t i = index; i < size - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    figures[--size] = nullptr;
    
    if (size < capacity / 4 && capacity > 10) {
        resize(capacity / 2);
    }
}


void FigureVector::printAllCentersAndAreas() const {
    for (size_t i = 0; i < size; ++i) {
        if (figures[i] != nullptr) {
            auto center = figures[i]->getCenter();
            double area = static_cast<double>(*figures[i]);
            std::cout << "Фигура " << i << ": ";
            std::cout << "Центр(" << center.first << ", " << center.second << "), ";
            std::cout << "Площадь: " << area << std::endl;
        }
    }
}

double FigureVector::calculateTotalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        if (figures[i] != nullptr) {
            total += static_cast<double>(*figures[i]);
        }
    }
    return total;
}