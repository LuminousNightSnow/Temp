#include <gtest/gtest.h>

#include "BrieItem.h"
#include "GildedRose.h"
#include "NormalItem.h"

TEST(GildedRose, GildedRoseTest_OneNormalItem)
{
    std::string name = "Normal item";
    int days_remaining = 10;
    const int initial_quality = 20;
    ItemPointer normal_item{new NormalItem(name, days_remaining, initial_quality)};
    GildedRose unit;
    unit.addItem(normal_item);
    unit.updateQuality();
    EXPECT_EQ(normal_item->getDaysRemaining(), days_remaining - 1);
    EXPECT_EQ(normal_item->getQuality(), initial_quality - 1);
}

TEST(GildedRose, GildedRoseTest_TwoNormalItem)
{
    std::string name = "Normal item";
    int days_remaining = 10;
    const int initial_quality = 20;
    ItemPointer normal_item{new NormalItem(name, days_remaining, initial_quality)};
    ItemPointer brie_item{new BrieItem(name, days_remaining, initial_quality)};
    GildedRose unit;
    unit.addItem(normal_item);
    unit.addItem(brie_item);
    unit.updateQuality();
    EXPECT_EQ(normal_item->getDaysRemaining(), days_remaining - 1);
    EXPECT_EQ(normal_item->getQuality(), initial_quality - 1);
    EXPECT_EQ(brie_item->getDaysRemaining(), days_remaining - 1);
    EXPECT_EQ(brie_item->getQuality(), initial_quality + 1);
}
