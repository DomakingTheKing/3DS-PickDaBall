//
// Created by Domakingo on 14/07/2024.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <citro2d.h>
#include "player.hpp"

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
};

#endif //ENGINE_HPP

