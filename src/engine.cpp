#include <citro2d.h>
#include "engine.hpp"

Engine::Engine() : running(true) {
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
    ball = Ball();

    // Initialize walls
    float verticalWallWidth = 10.0f;
    float verticalWallHeight = 240.0f; // Altezza dello schermo inferiore
    float horizontalWallWidth = 400.0f; // Larghezza dello schermo superiore
    float horizontalWallHeight = 10.0f;

    // Parete verticale sinistra
    walls[0] = {0.0f, 0.0f, verticalWallWidth, verticalWallHeight, C2D_Color32(255, 0, 0, 0)};

    // Parete verticale destra
    walls[1] = {400.0f - verticalWallWidth, 0.0f, verticalWallWidth, verticalWallHeight, C2D_Color32(255, 0, 0, 0)};

    // Parete orizzontale in alto
    walls[2] = {0.0f, 0.0f, horizontalWallWidth, horizontalWallHeight, C2D_Color32(255, 0, 0, 0)};
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
