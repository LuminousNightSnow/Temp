#include "GildedRose.h"
#include "NormalItem.h"

using namespace std;

int main() {
  GildedRose app;

  app.addItem(ItemPointer(new NormalItem("+5 Dexterity Vest", 10, 20)));
  cout << "OMGHAI!" << endl;
  app.updateQuality();
  app.printItems();
}
