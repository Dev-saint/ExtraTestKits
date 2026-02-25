#pragma once

#include <string>
#include <map>

class Kit
{
public:
    explicit Kit(const std::string& filePath);

    const std::map<std::string, int>& getRequirements() const;

private:
    std::map<std::string, int> requirements_;

    void loadFromFile(const std::string& filePath);
};