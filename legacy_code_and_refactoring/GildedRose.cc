#include "GildedRose.h"

std::ostream& operator<<(std::ostream& s, ItemPointer item)
{
    s << item->getName() << ", " << item->getDaysRemaining() << ", " << item->getQuality();
    return s;
}

void GildedRose::updateQuality()
{
    for (auto item : items_)
    {
        item->update();
    }
}

void GildedRose::addItem(ItemPointer item)
{
    items_.push_back(item);
}

void GildedRose::printItems(std::ostream& outstream)
{
    for (const auto item : items_)
    {
        outstream << item << std::endl;
    }
}
