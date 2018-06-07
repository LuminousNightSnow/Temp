//
// Created by qq on 06.06.18.
//

#include <gtest/gtest.h>
#include <streambuf>
#include <fstream>

#include "GildedRose.h"
#include "NormalItem.h"
#include "BrieItem.h"
#include "ConcertPassItem.h"
#include "SulfurasItem.h"

std::string readGroundtruth(const std::string& filename)
{
    std::ifstream file{filename, std::ifstream::in};
    std::stringstream s;
    s << file.rdbuf();
    return s.str();

};

TEST(GildedRoseCharacterizationTest, Foo) {
  GildedRose app;

  app.addItem(ItemPointer {new NormalItem("+5 Dexterity Vest", 10, 20)});
  app.addItem(ItemPointer {new BrieItem("Aged Brie", 10, 20)});
  app.addItem(ItemPointer {new ConcertPassItem("Backstage passes to a TAFKAL80ETC concert", 10, 20)});
  app.addItem(ItemPointer {new SulfurasItem("Sulfuras, Hand of Ragnaros", 10, 20)});

    std::stringstream output;

    for (int day = 0; day<100; ++day){
        output << "Day is " << day << std::endl;
        app.updateQuality();
        app.printItems(output);
        output << std::endl;
    }

  //std::string groundtruth = readGroundtruth("../../smaller");
    //std::string groundtruth = readGroundtruth("/home/qq/git_repos/code_snippets/CharacterizationTestOutput.txt");
    std::string groundtruth = readGroundtruth("/home/bmwuser/github/playground/code_snippets/CharacterizationTestOutput.txt");

    EXPECT_EQ(groundtruth, output.str());

}

