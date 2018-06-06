#include "GildedRose.h"

std::ostream& operator<<(std::ostream& s, Item& item)
{
    s << item.name << ", " << item.days_remaining << ", " << item.quality;
    return s;
}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items_.size(); i++)
    {
        if (items_[i].item_type == Item_Type::Normal_Item)
        {
            updateNormalItem(i);
            continue;
        }
        if (items_[i].item_type == Item_Type::Aged_Brie)
        {
            updateAgedBrieItem(i);
            continue;
        }
        if (items_[i].item_type == Item_Type::Concert_Pass)
        {
            updateConcertPassItem(i);
            continue;
        }
        if (items_[i].item_type == Item_Type::Sulfuras)
        {
            continue;
        }
    }
}

void GildedRose::updateAgedBrieItem(int i)
{
    const int max_quality_brie = 50;
    const int quality_increment = (items_[i].days_remaining <= 0) ? 2 : 1;
    items_[i].quality = std::min(items_[i].quality + quality_increment, max_quality_brie);

    items_[i].days_remaining -= 1;
}

void GildedRose::updateNormalItem(int i)
{
    const int quality_decrement = (items_[i].days_remaining <= 0) ? 2 : 1;
    const int min_quality_normal = 0;
    items_[i].quality = max(items_[i].quality - quality_decrement, min_quality_normal);

    items_[i].days_remaining -= 1;
}

void GildedRose::updateConcertPassItem(int i)
{
    if (items_[i].days_remaining <= 0)
    {
        items_[i].quality = 0;
    }
    else
    {
        int quality_increment;
        quality_increment = getQualityIncrementForConcertPass(items_[i].days_remaining);

        const int max_quality_pass = 50;
        items_[i].quality = min(items_[i].quality + quality_increment, max_quality_pass);
    }

    items_[i].days_remaining -= 1;
}

int GildedRose::getQualityIncrementForConcertPass(int days_remaining) const
{
    int quality_increment;
    if (days_remaining > 10)
        quality_increment = 1;
    else if (days_remaining > 5)
        quality_increment = 2;
    else
        quality_increment = 3;
    return quality_increment;
}

void GildedRose::addItem(const Item& item)
{
    items_.push_back(item);
}

void GildedRose::printItems(std::ostream& outstream)
{
    for (vector<Item>::iterator i = items_.begin(); i != items_.end(); i++)
    {
        outstream << *i << std::endl;
    }
}

Item_Type Item::getItemTypeFromName(const string& name)
{

    if (name == "Aged Brie")
    {
        return Item_Type::Aged_Brie;
    }
    if (name == "Backstage passes to a TAFKAL80ETC concert")
    {
        return Item_Type::Concert_Pass;
    }
    if (name == "Sulfuras, Hand of Ragnaros")
    {
        return Item_Type::Sulfuras;
    }

    return Item_Type::Normal_Item;
}