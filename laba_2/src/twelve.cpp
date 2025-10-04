#include "twelve.hpp"
#include <stdexcept>
#include <algorithm>

Twelve::Twelve() : digits(1, 0) {}

Twelve::Twelve(const size_t &n, unsigned char t) : digits(n, t) {
    if (t >= 12) {
        throw std::invalid_argument("Digit must be 0-11");
    }
}

Twelve::Twelve(const std::initializer_list<unsigned char>& t) : digits(t.size(), 0) {
    size_t i = 0;  
    for (auto it : t) {
        if (it >= 12) {
            throw std::invalid_argument("Digit must be 0-11");
        }
        digits.set(i, it);  
        ++i;
    }
}

Twelve::Twelve(const std::string &t) : digits(1, 0) {
    if (t.empty()) return;
    
    size_t start = 0;
    while (start < t.length() && t[start] == '0') {
        ++start;
    }
    
    size_t strSize = t.length() - start;
    if (strSize == 0) return;
    
    digits.clear();
    for (size_t i = 0; i < strSize; ++i) {
        digits.push(0);
    }
    
    for (size_t i = 0; i < strSize; ++i) {
        char c = t[i + start];
        unsigned char value;
        
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c == 'A' || c == 'a') {
            value = 10;
        } else if (c == 'B' || c == 'b') {
            value = 11;
        } else {
            throw std::invalid_argument("Invalid character");
        }
        
        digits.set(i, value);  
    }
}

Twelve::Twelve(const Twelve& other) : digits(other.digits) {}

Twelve::Twelve(Twelve&& other) noexcept : digits(std::move(other.digits)) {}

Twelve::~Twelve() noexcept {}

size_t Twelve::getSize(const Twelve& num) {
    return num.digits.len();
}

Twelve Twelve::copy(const Twelve& num) {
    return Twelve(num);
}

Twelve Twelve::add(const Twelve& a, const Twelve& b) {
    size_t maxSize = std::max(a.digits.len(), b.digits.len());
    Twelve result;
    result.digits.clear();
    
    for (size_t i = 0; i < maxSize + 1; ++i) {
        result.digits.push(0);
    }
    
    int carry = 0;
    for (int i = maxSize - 1; i >= 0; --i) {
        int a_index = i - (maxSize - a.digits.len());
        int b_index = i - (maxSize - b.digits.len());
        
        int digit_a = (a_index >= 0) ? a.digits.get(a_index) : 0;
        int digit_b = (b_index >= 0) ? b.digits.get(b_index) : 0;
        
        int sum = digit_a + digit_b + carry;
        result.digits.set(i + 1, sum % 12); 
        carry = sum / 12;
    }
    
    if (carry > 0) {
        result.digits.set(0, carry);
    } else {
        for (size_t i = 0; i < result.digits.len() - 1; ++i) {
            result.digits.set(i, result.digits.get(i + 1));
        }
        result.digits.pop();
    }
    
    return result;
}

Twelve Twelve::substract(const Twelve& a, const Twelve& b) {
    if (lessThan(a, b)) {
        throw std::invalid_argument("Result would be negative");
    }
    
    Twelve result;
    result.digits.clear();
    
    for (size_t i = 0; i < a.digits.len(); ++i) {
        result.digits.push(a.digits.get(i));
    }
    
    int borrow = 0;
    for (int i = result.digits.len() - 1; i >= 0; --i) {
        int digit_a = result.digits.get(i);
        
        int b_index = i - (a.digits.len() - b.digits.len());
        int digit_b = (b_index >= 0 && b_index < (int)b.digits.len()) ? b.digits.get(b_index) : 0;
        
        int diff = digit_a - digit_b - borrow;
        
        if (diff < 0) {
            diff += 12;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.digits.set(i, diff);
    }
    
    while (result.digits.len() > 1 && result.digits.get(0) == 0) {
        for (size_t i = 0; i < result.digits.len() - 1; ++i) {
            result.digits.set(i, result.digits.get(i + 1));
        }
        result.digits.pop();
    }
    
    return result;
}

int Twelve::compareAbsolute(const Twelve& a, const Twelve& b) {
    if (a.digits.len() > b.digits.len()) return 1;
    if (a.digits.len() < b.digits.len()) return -1;
    
    for (size_t i = 0; i < a.digits.len(); ++i) {
        if (a.digits.get(i) > b.digits.get(i)) return 1;
        if (a.digits.get(i) < b.digits.get(i)) return -1;
    }
    
    return 0;
}

bool Twelve::equals(const Twelve& a, const Twelve& b) {
    return compareAbsolute(a, b) == 0;
}

bool Twelve::lessThan(const Twelve& a, const Twelve& b) {
    return compareAbsolute(a, b) < 0;
}

bool Twelve::greaterThan(const Twelve& a, const Twelve& b) {
    return compareAbsolute(a, b) > 0;
}

std::string Twelve::toString(const Twelve& num) {
    if (num.digits.len() == 0 || (num.digits.len() == 1 && num.digits.get(0) == 0)) {
        return "0";
    }
    
    std::string result;
    for (size_t i = 0; i < num.digits.len(); ++i) {
        unsigned char digit = num.digits.get(i);
        if (digit < 10) {
            result += ('0' + digit);
        } else {
            result += ('A' + (digit - 10));
        }
    }
    return result;
}