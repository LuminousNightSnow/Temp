#include "GildedRose.h"

using namespace std;

#include "IItem.h"
#include "NormalItem.h"

//int main() {
//  GildedRose app;
//
//  app.addItem(Item("+5 Dexterity Vest", 10, 20));
//
//  cout << "OMGHAI!" << endl;
//  app.updateQuality();
//  app.printItems();
//}

class base{
public:
    
};

int main()
{
  IItem* p = new NormalItem("Foo", 5,20);
}