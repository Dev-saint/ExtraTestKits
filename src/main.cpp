#include "service/KitMatcher.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
   
    if (argc < 3) {
        std::cerr << "Использование: " << argv[0] << " <document.txt> <kit.txt>\n";
        return 1;
    }

    auto document = std::make_unique<Document>(argv[1]);
    auto kit = std::make_unique<Kit>(argv[2]);

    std::cout << document->getPositions().size() << " позиций в документе." << std::endl;
    std::cout << kit->getRequirements().size() << " требований в наборе." << std::endl;
    
    auto positions = document->getPositions();
    for (const auto& pos : positions) {
        std::cout << "ID: " << pos.id 
                << ", Quantity: " << pos.quantity 
                << ", Remaining: " << pos.remaining 
                << ", Catalogs: ";
        
        // Вывод вектора catalog
        for (const auto& cat : pos.catalog) {
            std::cout << "\"" << cat << "\" ";
        }
        std::cout << std::endl;
    }

    auto requirements = kit->getRequirements();
    for (const auto& pos : requirements) {
        std::cout << "ID: " << pos.first 
                << ", Quantity: " << pos.second 
                << ", Remaining: " << 0 
                << ", Catalogs: ";
        
        std::cout << std::endl;
    }
    

    KitMatcher matcher(std::move(document), std::move(kit));

    if (matcher.matchKit()) {
        std::cout << "Набор найден в документе." << std::endl;
        
    } else {
        std::cout << "Набор не найден в документе." << std::endl;
    }

    return 0;
}