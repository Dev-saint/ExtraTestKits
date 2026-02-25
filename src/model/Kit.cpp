#include "Kit.hpp"
#include "../utils/Utils.hpp"
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
        throw std::runtime_error("Не удалось открыть файл: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);

        std::string catalog;
        int quantity;

        std::getline(iss, catalog);
        catalog = removeQuotes(catalog);

        std::stringstream catStream(catalog);
        std::string catName;
        while (std::getline(catStream, catName, ',')) {
            if (!catName.empty()){
                requirements_[catName] += quantity;
            }
        }

        if(!iss >> quantity) {
            throw std::runtime_error("Неверный формат строки: " + line);
        }

        requirements_[catalog] = quantity;
    }
}