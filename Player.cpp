#include "Player.h"

void Player::drawCard(Card* drawnCard) {
    hand.push(drawnCard);
}

Card* Player::playCard() {
    return hand.pop();
}