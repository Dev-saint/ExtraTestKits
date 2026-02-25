#include "Kit.hpp"
#include "Utils.hpp"
#include <fstream>
#include <sstream>

Kit::Kit(const std::string& filePath)
{
    loadFromFile(filePath);
}

const std::map<std::string, int>& Kit::getRequirements() const
{
    return requirements_;
}

void Kit::loadFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error(u8"Не удалось открыть файл: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);

        std::string catalogStr;
        int quantity;

        if(!(iss >> catalogStr >> quantity)){
            throw std::runtime_error(u8"Неверный формат строки: " + line);
        }
        
        catalogStr = removeQuotes(catalogStr);    

        std::stringstream catStream(catalogStr);
        std::string catalog;
        while (std::getline(catStream, catalog, ',')) {
            if (!catalog.empty()){
                requirements_[catalog] = quantity;
            }
        };
    }
}