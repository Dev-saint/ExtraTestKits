#pragma once

#include <memory>
#include "Document.hpp"
#include "Kit.hpp"

struct UsedPosition{
    int positionId;
    std::string catalog;
    int usedQuantity;
};

class KitMatcher {
public:
    
    KitMatcher(std::unique_ptr<Document> doc, std::unique_ptr<Kit> kit);
    void setDocument(std::unique_ptr<Document> doc);
    void setKit(std::unique_ptr<Kit> kit);
    bool matchKit();
    const std::vector<UsedPosition>& getUsedPositions() const;

private:
    std::unique_ptr<Document> document;
    std::unique_ptr<Kit> kit;
    std::vector<UsedPosition> usedPositions_;
};
