#pragma once

#include <vector>
#include <string>
#include <algorithm>

struct Position
{
    int id;
    int quantity;
    int remaining;
    std::vector<std::string> catalog;

    bool hasCatalog(const std::string& name) const {
        return std::find(catalog.begin(), catalog.end(), name) != catalog.end();
    }
};
