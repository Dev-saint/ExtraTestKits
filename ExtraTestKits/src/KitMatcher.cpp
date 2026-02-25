#include "KitMatcher.hpp"

KitMatcher::KitMatcher(std::unique_ptr<Document> doc, std::unique_ptr<Kit> kit)
    : document(std::move(doc)), kit(std::move(kit)) {}

void KitMatcher::setDocument(std::unique_ptr<Document> doc) {
    document = std::move(doc);
}

void KitMatcher::setKit(std::unique_ptr<Kit> kit) {
    this->kit = std::move(kit);
}

const std::vector<UsedPosition>& KitMatcher::getUsedPositions() const {
    return usedPositions_;
}

bool KitMatcher::matchKit() {
    this->usedPositions_.clear();

    if (!document || !kit){
        return false; // Нет документа или набора для сравнения
    }
    
    const auto& docPositions = document->getPositions();
    const auto& requirements = kit->getRequirements();

    if (requirements.empty() || docPositions.empty()){
        return false;
    }

    std::vector<Position> positions = docPositions;

    for (const auto& requirement : requirements){
        const std::string& catalog = requirement.first;
        int needed = requirement.second;

        for (auto& pos : positions){
            if (needed <= 0) {
                break;
            }

            if (pos.hasCatalog(catalog) && pos.remaining > 0){
                int taken = std::min(pos.remaining, needed);
                pos.remaining -= taken;
                needed -= taken;

                usedPositions_.push_back({pos.id, catalog, taken});
            }
        }
        if (needed > 0) {
            usedPositions_.clear();
            return false;
        }
    };
    
    return true;
}
