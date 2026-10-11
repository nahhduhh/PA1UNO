#include "Card.h"

#include <utility>

Card::Card(std::string color, std::string value) {
    color_ = std::move(color);
    value_ = std::move(value);
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.color_ << " " << c.value_;
    return os;
}