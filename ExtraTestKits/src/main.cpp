#include "KitMatcher.hpp"
#include <iostream>
#if defined(_WIN32)
#include <windows.h>
#endif

int main(int argc, char* argv[]) {
    
    std::setlocale(LC_ALL, "");
    std::locale::global(std::locale());

#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    if (argc < 3) {
        std::cerr << u8"Использование: " << argv[0] << u8" <document.txt> <kit.txt>\n";
        return 1;
    }

    try {
        auto document = std::make_unique<Document>(argv[1]);
        auto kit = std::make_unique<Kit>(argv[2]);
        

        KitMatcher matcher(std::move(document), std::move(kit));

        if (matcher.matchKit()) {
            std::cout << u8"Набор найден в документе!" << std::endl;
            std::cout << u8"Набор в составе документа:\n";
            for (const auto& up : matcher.getUsedPositions()) {
                std::cout << up.positionId << " " << up.usedQuantity << " " << up.catalog << "\n";
            } 
        } else {
            std::cout << u8"Набор не найден в документе." << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << u8"Ошибка: " << ex.what() << "\n";
        return 1;
    }
    
    return 0;
}