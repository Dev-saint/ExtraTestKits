#include "service/KitMatcher.hpp"
#include <iostream>

int main() {
    
    auto document = std::make_unique<Document>("document.txt");
    auto kit = std::make_unique<Kit>("kit.txt");

    KitMatcher matcher(std::move(document), std::move(kit));

    if (matcher.matchKit()) {
        std::cout << "Набор найден в документе." << std::endl;
    } else {
        std::cout << "Набор не найден в документе." << std::endl;
    }

    return 0;
}