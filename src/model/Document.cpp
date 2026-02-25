#include "Document.hpp"
#include "../utils/Utils.hpp"
#include <fstream>
#include <sstream>

Document::Document(const std::string& filePath)
{
    loadFromFile(filePath);
}

const std::vector<Position>& Document::getPositions() const
{
    return positions_;
}

void Document::loadFromFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);

        Position pos;
        std::string catalogsStr;

        if(!(iss >> pos.id >> pos.quantity)) {
            throw std::runtime_error("Неверный формат строки: " + line);
        }
        
        std::getline(iss, catalogsStr);
        catalogsStr = removeQuotes(catalogsStr);

        std::stringstream catStream(catalogsStr);
        std::string catalog;

        while (std::getline(catStream, catalog, ',')) {
            if (!catalog.empty()){
                pos.catalog.push_back(catalog);
            }
        }

        pos.remaining = pos.quantity;
        positions_.push_back(pos);
    }
}