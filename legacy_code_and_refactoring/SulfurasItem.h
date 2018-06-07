//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_SulfurasItem_H
#define CPP_SulfurasItem_H

#include "IItem.h"

class SulfurasItem : public IItem{
public:
    SulfurasItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~SulfurasItem() = default;

    void update() override {};
};



#endif //CPP_SulfurasItem_H
