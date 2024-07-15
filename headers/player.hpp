#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <citro2d.h>

class Player {
private:
    float x;
    float speed;
    u32 color;

public:
    Player();

    void setX(float n);

	float getX() const;
    float getSpeed() const;
	float getColor() const;
};

#endif // PLAYER_HPP
