#pragma once
#include <ostream>
#include <string>
#include <utility>
#include "Stack.h"
#include "Card.h"

class Player {
public:
    Player(int id, std::string  name)
        : id_(id), name_(std::move(name)) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    void drawCard(Card* drawnCard);

    Card* playCard();


private:
    int id_;
    std::string name_;
    Stack<Card> hand;
};
