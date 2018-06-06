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

    Item_Type getItemTypeFromName(const string &name);

    friend class GildedRose;
  friend std::ostream &operator<<(std::ostream &s, Item &item);

private:
  Item_Type item_type;
  string name;
  int days_remaining;
  int quality;
};

class GildedRose {
public:
  void printItems(std::ostream& outstream = std::cout);
  void addItem(const Item &item);
  void updateQuality();

private:
  vector<Item> items_;
};

#endif // GILDEDROSE_H
