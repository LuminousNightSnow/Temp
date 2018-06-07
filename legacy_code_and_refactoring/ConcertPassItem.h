//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_ConcertPassItem_H
#define CPP_ConcertPassItem_H

#include "IItem.h"

class ConcertPassItem : public IItem{
public:
    ConcertPassItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~ConcertPassItem() = default;

    void update() override;

private:
    int getQualityIncrementForConcertPass(int days_remaining) const;

};

void ConcertPassItem::update() {

    if (getDaysRemaining() <= 0)
    {
        setToMinimumQuality();
    }
    else
    {
        int quality_increment = getQualityIncrementForConcertPass(getDaysRemaining());
        incrementQualityBy(quality_increment);
    }

    decreaseDaysRemaining();
}


int ConcertPassItem::getQualityIncrementForConcertPass(int days_remaining) const
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


#endif //CPP_ConcertPassItem_H
