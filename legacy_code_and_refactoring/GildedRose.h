#ifndef GILDEDROSE_H
#define GILDEDROSE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GildedRose;

class Item {
public:
  Item(string name, int days_remaining, int quality)
      : name(name), days_remaining(days_remaining), quality(quality) {}
  friend class GildedRose;
  friend std::ostream &operator<<(std::ostream &s, Item &item);

private:
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

const std::string item1 = "Aged Brie";
const std::string item2 = "Backstage passes to a TAFKAL80ETC concert";
const std::string item3 = "Sulfuras, Hand of Ragnaros";
#endif // GILDEDROSE_H
