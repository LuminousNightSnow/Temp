//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_NORMALITEM_H
#define CPP_NORMALITEM_H

#include "IItem.h"

class NormalItem : public IItem{
public:
    NormalItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~NormalItem() = default;

    void update() override;
};

void NormalItem::update() {

    const int quality_decrement = (getDaysRemaining() <= 0) ? 2 : 1;

    decreaseQualityBy(quality_decrement);
    decreaseDaysRemaining();
}


#endif //CPP_NORMALITEM_H
