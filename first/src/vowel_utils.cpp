#include "vowel_utils.h"
#include <cctype>

bool is_vowel(char c) {
    char lower_c = std::tolower(c);
    
    switch (lower_c) {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
        case '\u0430': // а
        case '\u0435': // е  
        case '\u0451': // ё
        case '\u0438': // и
        case '\u043E': // о
        case '\u0443': // у
        case '\u044B': // ы
        case '\u044D': // э
        case '\u044E': // ю
        case '\u044F': // я
            return true;
        default:
            return false;
    }
}

std::string remove_vowels(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (!is_vowel(c)) {
            result += c;
        }
    }
    return result;
}