#pragma once

#include "Position.hpp"

class Document
{
public:
    explicit Document(const std::string& filePath);

    const std::vector<Position>& getPositions() const;

private:
    std::vector<Position> positions_;

    void loadFromFile(const std::string& filePath);
};