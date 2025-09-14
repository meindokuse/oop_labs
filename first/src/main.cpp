#include "vowel_utils.h"
#include <iostream>
#include <string>

int main() {
    std::string text;
    
    std::cout << "Enter the comment: ";
    std::getline(std::cin, text); 
    
    std::string result = remove_vowels(text);
    std::cout << result << std::endl;
    
    return 0;
}