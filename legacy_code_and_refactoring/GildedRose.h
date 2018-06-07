#ifndef GILDEDROSE_H
#define GILDEDROSE_H
#include <iostream>
#include <string>
#include <vector>
#include "IItem.h"

class GildedRose
{
  private:
    using items_t = std::vector<ItemPointer>;

  public:
    void printItems(std::ostream& outstream = std::cout);
    void updateQuality();
    void addItem(ItemPointer item);
    using const_iterator = items_t::const_iterator;
    const_iterator begin() { return items_.cbegin(); }

  private:
    items_t items_;
};

#endif  // GILDEDROSE_H
