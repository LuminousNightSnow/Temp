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
      if (name == "Aged Brie") {
          item_type = Item_Type::Aged_Brie;
      }
      else if(name == "Backstage passes to a TAFKAL80ETC concert") {
          item_type = Item_Type::Concert_Pass;
      }
      else if(name == "Sulfuras, Hand of Ragnaros") {
          item_type = Item_Type::Sulfuras;
      }
      else {
          item_type = Item_Type::Normal_Item;
      }
  }
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
