#pragma once

#include <iostream>
#include <string>

class Card {
    public:
    Card(std::string color, std::string value);

    friend std::ostream& operator<<(std::ostream& os, const Card& c);

    private:
        std::string color_;
        std::string value_;
};