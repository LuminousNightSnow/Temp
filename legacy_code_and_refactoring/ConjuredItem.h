//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_ConjuredItem_H
#define CPP_ConjuredItem_H

#include "IItem.h"

class ConjuredItem : public IItem
{
  public:
    ConjuredItem(const std::string& name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~ConjuredItem() = default;

    void update() override
    {

        const int quality_decrement = (getDaysRemaining() <= 0) ? 4 : 2;
        decreaseQualityBy(quality_decrement);
        decreaseDaysRemaining();
    };
};

#endif  // CPP_ConjuredItem_H
