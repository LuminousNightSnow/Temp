#include <gtest/gtest.h>

#include "GildedRose.h"

TEST(GildedRoseTest, UpdateQuality_WhenNormalItem) {
    GildedRose unit;

    auto it = unit.begin();

    Item item{"+5 Dexterity Vest", 10, 20};

    unit.addItem(item);
    unit.updateQuality();

    EXPECT_EQ(it->getQuality(), 19);
    EXPECT_EQ(it->getDaysRemaining(), 9);

}

