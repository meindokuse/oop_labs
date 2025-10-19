#pragma once

#include <iostream>
#include "Figure.hpp" 

class FigureVector {
private:
    size_t size;
    size_t capacity;
    Figure** figures;  
    void resize(size_t new_capacity);

public:
    void push(Figure* figure);     
    void pop();                    
    void clear();                  
    
    Figure* get(size_t index) const;      
    Figure* operator[](size_t index) const;
    
    void swap(size_t index1, size_t index2);
    void set(size_t index, Figure* figure); 
    
    void remove(size_t index);
    
    size_t len() const;
    size_t getSize() const;
      
    void printAllCentersAndAreas() const;  
    double calculateTotalArea() const;     
    
    FigureVector();
    FigureVector(size_t initial_size, Figure* value);
    FigureVector(const FigureVector &other);     
    FigureVector(FigureVector &&other) noexcept; 
    FigureVector& operator=(const FigureVector &other); 
    FigureVector& operator=(FigureVector &&other) noexcept; 
    
    ~FigureVector();
};