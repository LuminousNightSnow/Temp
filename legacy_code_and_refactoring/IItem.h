//
// Created by bmwuser on 07.06.18.
//

#ifndef CPP_IITEM_H
#define CPP_IITEM_H
#include <memory>
#include <string>

class IItem;
using ItemPointer = std::shared_ptr<IItem>;

class IItem
{
  public:
    IItem(const std::string& name, int days_remaining, int quality)
        : name_{name}, days_remaining_{days_remaining}, quality_{quality}, max_quality_{50}, min_quality_{0}
    {
    }

    virtual ~IItem() = default;

    int getQuality() const { return quality_; };
    int getDaysRemaining() const { return days_remaining_; };
    std::string getName() const { return name_; };

    virtual void update() = 0;

  protected:
    void decreaseDaysRemaining() { days_remaining_ -= 1; }

    void decreaseQualityBy(const int quality_decrement)
    {
        quality_ = std::max(quality_ - quality_decrement, min_quality_);
    }

    void incrementQualityBy(const int quality_increment)
    {
        quality_ = std::min(quality_ + quality_increment, max_quality_);
    }

    void setToMinimumQuality() { quality_ = min_quality_; }

  private:
    std::string name_;
    int days_remaining_;
    int quality_;
    const int max_quality_;
    const int min_quality_;
};

#endif  // CPP_IITEM_H
