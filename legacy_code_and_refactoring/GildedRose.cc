#include "GildedRose.h"


std::ostream &operator<<(std::ostream &s, Item &item) {
  s << item.name << ", " << item.days_remaining << ", " << item.quality;
  return s;
}

void GildedRose::updateQuality() {
  for (int i = 0; i < items_.size(); i++) {
    if (items_[i].name != item1 && items_[i].name != item2) {
      if (items_[i].quality > 0) {
        if (items_[i].name != item3) {
          items_[i].quality -= 1;
        }
      }
    } else {
      if (items_[i].quality < 50) {
        items_[i].quality = items_[i].quality + 1;
        if (items_[i].name == item2) {
          if (items_[i].days_remaining < 11) {
            if (items_[i].quality < 50) {
              items_[i].quality += 1;
            }
          }
          if (items_[i].days_remaining < 6) {
            if (items_[i].quality < 50) {
              items_[i].quality++;
            }
          }
        }
      }
    }
    if (items_[i].name != item3) {
      --items_[i].days_remaining;
    }
    if (items_[i].days_remaining < 0) {
      if (items_[i].name != item1) {
        if (items_[i].name != item2) {
          if (items_[i].quality > 0) {
            if (items_[i].name != item3) {
              items_[i].quality = items_[i].quality - 1;
            }
          }
        } else {
          items_[i].quality = items_[i].quality - items_[i].quality;
        }
      } else {
        if (items_[i].quality < 50) {
          ++items_[i].quality;
        }
      }
    }
  }
}

void GildedRose::addItem(const Item &item) { items_.push_back(item); }

void GildedRose::printItems(std::ostream& outstream) {
  for (vector<Item>::iterator i = items_.begin(); i != items_.end(); i++) {
    outstream << *i << std::endl;
  }
}
