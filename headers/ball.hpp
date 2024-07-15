#ifndef BALL_HPP
#define BALL_HPP

#include <citro2d.h>
#include "player.hpp"

class Ball {
private:
    float x = 200.0f;
    float y = 120.0f;
    float vx = 0.0f;
    float vy = 0.0f;
    float ax = 0.0f;
    float ay = 9.81f;
    static constexpr float radius = 7.5f; // Radius of the ball
    static constexpr u32 color = C2D_Color32(255, 255, 0, 255); // Color of the ball
    static constexpr float frameTime = 1.0f / 30.0f; // Frame time for 30 FPS

public:
    Ball() = default;

    void update();
    void checkCollision(const Player& player);

    void setX(float n);
    void setY(float n);
    void setVelocity(float vx, float vy);
    void setAcceleration(float ax, float ay);

    float getX() const;
    float getY() const;
    float getVelocityX() const;
    float getVelocityY() const;
    float getAccelerationX() const;
    float getAccelerationY() const;
    u32 getColor() const;
    float getRadius() const;
};

#endif // BALL_HPP
