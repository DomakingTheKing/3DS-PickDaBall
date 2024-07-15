//
// Created by Domakingo on 14/07/2024.
//

#include <citro2d.h>
#include "engine.hpp"

Engine::Engine() : running(true){
    // Initialize graphics services
    romfsInit();
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();

    // Initialize buffers for both screens
    top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

    // Background color
    clrClear = C2D_Color32(0x68, 0xB0, 0xD8, 0xFF);

    // Initialize Player
    player = Player();
}

void Engine::run() {
    // Main loop
    while (aptMainLoop() && running) {
        input();
        update();
        draw();
    }

    // Deinitialize graphics services
    C2D_Fini();
    C3D_Fini();
    gfxExit();
}

