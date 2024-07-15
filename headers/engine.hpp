#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <citro2d.h>
#include "player.hpp"
#include "ball.hpp"

struct Wall {
    float x, y, width, height;
    u32 color;
};

class Engine {
private:
    C3D_RenderTarget* top;
    C3D_RenderTarget* bottom;
    u32 clrClear;
    bool running;

public:
    Engine();
    void run();
    void update();
    void draw();
    void input();

    Player player;
    Ball ball;
    Wall walls[3];
};

#endif // ENGINE_HPP
