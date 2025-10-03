#include "custom_vector.hpp"

CustomVector::CustomVector(): size(0),capacity(1),v(new unsigned char[capacity]) {}

CustomVector::CustomVector(size_t initial_size,unsigned char value) 
    : size(initial_size), capacity(initial_size > 10 ? initial_size * 2 : 10), 
      v(new unsigned char[capacity]) {
    for (size_t i = 0; i < size; ++i) {
        v[i] = value;
    }
}

CustomVector::CustomVector(const CustomVector &other): size(other.size), capacity(other.capacity), v(new unsigned char[capacity]){
    for (size_t i = 0; i < size; ++i) {
        v[i] = other.v[i];
    }
}

CustomVector::CustomVector(CustomVector &&other) noexcept 
    : size(other.size), capacity(other.capacity), v(other.v) {
    other.v = nullptr;
    other.size = 0;
    other.capacity = 0;
}

CustomVector::~CustomVector() {
    delete[] v;
}

void CustomVector::resize(size_t newsize) {
  capacity = newsize;
  unsigned char *t = new unsigned char[capacity];
  std::copy(v, v + size, t);
  delete[] v;
  v = t;
}

void CustomVector::push(unsigned char c) {
  if (size >= capacity) {
    resize(2 * capacity);
  }
  v[size++] = c;
}

void CustomVector::pop() {
    if (size > 0) {
        size--;
        if (size < capacity / 4 && capacity > 10) {
            resize(capacity / 2);
        }
    }
}

void CustomVector::clear() {
  size = 0;
  capacity = 1;
  delete[] v;
  v = new unsigned char[capacity];
}

unsigned char CustomVector::get(size_t i) const { return v[i]; }

size_t CustomVector::len() const { return size; }

void CustomVector::swap(size_t i, size_t j) {
  unsigned char c = v[i];
  v[i] = v[j];
  v[j] = c;
}

void CustomVector::set(int i,unsigned char c) {
  if(i+1 > size) return;
  v[i] = c;
}