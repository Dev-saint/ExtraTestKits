#include "Kit.hpp"

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
    // TODO: парсинг файла
}