#include "KitMatcher.hpp"

KitMatcher::KitMatcher(std::unique_ptr<Document> doc, std::unique_ptr<Kit> kit)
    : document(std::move(doc)), kit(std::move(kit)) {}

void KitMatcher::setDocument(std::unique_ptr<Document> doc) {
    document = std::move(doc);
}

void KitMatcher::setKit(std::unique_ptr<Kit> kit) {
    this->kit = std::move(kit);
}

bool KitMatcher::matchKit() const {
    if (!document || !kit){
        return false; // Нет документа или набора для сравнения
    }
    
    std::vector<Position> positions = document->getPositions();

    for (const auto& requirement : kit->getRequirements()){
        const std::string& catalog = requirement.first;
        int needed = requirement.second;

        for (auto& pos : positions){
            if (needed <= 0) {
                break; // Требование уже выполнено
            }

            if (pos.hasCatalog(catalog) && pos.remaining > 0){
                int taken = std::min(pos.remaining, needed);
                pos.remaining -= taken;
                needed -= taken;
            }
        }
        if (needed > 0) {
            return false;
        }
    }
    
    return true;
}