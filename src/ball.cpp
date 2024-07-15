#include "ball.hpp"
#include <3ds.h>

void Ball::update() {
    // Update velocity with acceleration
    vx += ax * frameTime;
    vy += ay * frameTime;

    // Update position with velocity
    x += vx * frameTime;
    y += vy * frameTime;
}

void Ball::checkCollision(const Player& player) {
    float playerWidth = 50.0f;
    const float playerHeight = 10.0f;
    float playerX = player.getX();
    float playerY = 240.0f - playerHeight;

    // Controlla se la palla interseca il player
    if (x + radius > playerX && x - radius < playerX + playerWidth &&
        y + radius > playerY && y - radius < playerY + playerHeight) {

        vy = -vy;

        // Calcola la posizione relativa della palla rispetto al centro del player
        float hitPosition = (x - playerX) / playerWidth - 0.25f;
        vx += hitPosition * 30.0f;

        // Sposta la palla sopra il player per evitare collisioni multiple
        y = playerY - radius;
    }

    // Controlla se la palla colpisce il muro sinistro o destro
    if (x - radius < 0) {
        // La palla ha colpito il muro sinistro, inverti la velocità orizzontale
        vx = -vx;
        // Sposta la palla all'interno del campo di gioco
        x = radius;
    } else if (x + radius > 400) {
        // La palla ha colpito il muro destro, inverti la velocità orizzontale
        vx = -vx;
        // Sposta la palla all'interno del campo di gioco
        x = 400 - radius;
    }
}



void Ball::setX(float n) {
    x = n;
}

void Ball::setY(float n) {
    y = n;
}

void Ball::setVelocity(float vx, float vy) {
    this->vx = vx;
    this->vy = vy;
}

void Ball::setAcceleration(float ax, float ay) {
    this->ax = ax;
    this->ay = ay;
}

float Ball::getX() const {
    return x;
}

float Ball::getY() const {
    return y;
}

float Ball::getVelocityX() const {
    return vx;
}

float Ball::getVelocityY() const {
    return vy;
}

float Ball::getAccelerationX() const {
    return ax;
}

float Ball::getAccelerationY() const {
    return ay;
}

u32 Ball::getColor() const {
    return color;
}

float Ball::getRadius() const {
    return radius;
}
