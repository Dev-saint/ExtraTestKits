#include "Document.hpp"

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
    // TODO: парсинг файла
}