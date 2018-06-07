//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_IITEM_H
#define CPP_IITEM_H
#include <string>
#include <memory>

class IItem
{
public:
    IItem(const std::string& name, int days_remaining, int quality) : name_ {name}, days_remaining_ {days_remaining},
                                                               quality_ {quality}, max_quality_ {50}, min_quality_ {0}
    {
    }

    virtual ~IItem() = default;

    int getQuality() const { return quality_; };
    int getDaysRemaining() const { return days_remaining_; };
    std::string getName() const { return name_; };


    virtual void update() = 0;

//    friend std::ostream& operator<<(std::ostream& s, Item& item);
//    void setName(const std::string &name) {
//        IItem::name_ = name;
//    }


    int getMax_quality() const {
        return max_quality_;
    }

    int getMin_quality() const {
        return min_quality_;
    }

protected:
    void decreaseDaysRemaining()
    {
        days_remaining_ -= 1;
    }

    void decreaseQualityBy(const int quality_decrement)
    {
        quality_ = std::max(quality_ - quality_decrement, min_quality_);
    }

    void incrementQualityBy(const int quality_increment)
    {
        quality_ = std::min(quality_ + quality_increment, max_quality_);
    }

    void setToMinimumQuality(){
        quality_ =min_quality_;
    }

private:
    std::string name_;
    int days_remaining_;
    int quality_;
    const int max_quality_;
    const int min_quality_;
};

using ItemPointer = std::shared_ptr<IItem>;

#endif //CPP_IITEM_H
