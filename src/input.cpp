//
// Created by Domakingo on 14/07/2024.
//

#include <citro2d.h>
#include "engine.hpp"

void Engine::input() {
    // Handle general inputs
    hidScanInput();
    u32 kDown = hidKeysDown();
    u32 kHeld = hidKeysHeld();

    if (kDown & KEY_START) running = false; // Exit the loop if START is pressed

    if ((kHeld & KEY_LEFT) && (player.getX() > 25)) player.setX(-(player.getSpeed()));
    if ((kHeld & KEY_RIGHT) && (player.getX() < 325)) player.setX(player.getSpeed());
}

