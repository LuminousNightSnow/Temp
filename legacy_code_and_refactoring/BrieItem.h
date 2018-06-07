//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_BrieItem_H
#define CPP_BrieItem_H

#include "IItem.h"

class BrieItem : public IItem{
public:
    BrieItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~BrieItem() = default;

    void update() override {

        const int quality_increment = (getDaysRemaining() <= 0) ? 2 : 1;
        incrementQualityBy(quality_increment);
        decreaseDaysRemaining();
    };
};




#endif //CPP_BrieItem_H
