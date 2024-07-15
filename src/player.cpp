#include "player.hpp"
#include <3ds.h>

Player::Player() : x(200), speed(2.0f), color(C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF)) {
}

void Player::setX(float n){
    x += n;
}

float Player::getX() const {
    return x;
}

float Player::getSpeed() const {
    return speed;
}

float Player::getColor() const {
    return color;
}
