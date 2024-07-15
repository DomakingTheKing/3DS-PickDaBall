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

    if ((kHeld & KEY_LEFT) && (player.getX() > 5)){
		if (kHeld & KEY_B){
			player.setX(-(player.getSpeed()*2));
		} else {
			player.setX(-(player.getSpeed()));
		}
	}

    if ((kHeld & KEY_RIGHT) && (player.getX() < 345)){
		if (kHeld & KEY_B){
			player.setX(player.getSpeed()*2);
		} else {
			player.setX(player.getSpeed());
		}
	}

}

