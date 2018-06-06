#ifndef GILDEDROSE_H
#define GILDEDROSE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Item_Type{
    Aged_Brie,
    Concert_Pass,
    Sulfuras,
    Normal_Item
};

class GildedRose;

class Item {
public:
  Item(string name, int days_remaining, int quality)
      : name(name), days_remaining(days_remaining), quality(quality) {

      item_type = getItemTypeFromName(name);

  }

    int getQuality() const { return quality;};
    int getDaysRemaining() const { return  days_remaining;};

    friend class GildedRose;

  friend std::ostream &operator<<(std::ostream &s, Item &item);

private:
  Item_Type getItemTypeFromName(const string &name);

  Item_Type item_type;
  string name;
  int days_remaining;
  int quality;
};

class GildedRose {
private:
    using items_t = std::vector<Item>;
public:
  void printItems(std::ostream& outstream = std::cout);
  void addItem(const Item &item);
  void updateQuality();
using const_iterator = items_t::const_iterator;
const_iterator begin(){
    return items_.cbegin();
}

private:
  items_t items_;
};

#endif // GILDEDROSE_H
