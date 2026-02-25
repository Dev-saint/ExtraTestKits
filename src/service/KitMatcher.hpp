#pragma once

#include <vector>
#include <string>
#include <memory>
#include "../model/Document.hpp"
#include "../model/Kit.hpp"


class KitMatcher {
public:
    
    KitMatcher(std::unique_ptr<Document> doc, std::unique_ptr<Kit> kit);
    void setDocument(std::unique_ptr<Document> doc);
    void setKit(std::unique_ptr<Kit> kit);
    bool matchKit() const;

private:
    std::unique_ptr<Document> document;
    std::unique_ptr<Kit> kit;
};
