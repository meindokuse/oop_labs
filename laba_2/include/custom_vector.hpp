#pragma once
#include <iostream>


class CustomVector {
private:
  size_t size;
  size_t capacity;
  unsigned char *v;
  void resize(size_t new_capacity);

public:
  void push(unsigned char);
  void pop();
  void clear();
  
  unsigned char get(size_t) const;

  void swap(size_t, size_t);
  void set(int,unsigned char c);

  size_t len() const;
  CustomVector();
  CustomVector(size_t initial_size, unsigned char value);
  CustomVector(const CustomVector &other);
  CustomVector(CustomVector &&other) noexcept; 
 
  ~CustomVector();
};