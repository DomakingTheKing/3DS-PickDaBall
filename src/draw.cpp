#include "engine.hpp"

void Engine::draw() {
    if (top && bottom) {
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        // Disegna sullo schermo superiore
        C2D_TargetClear(top, clrClear);
        C2D_SceneBegin(top);
        C2D_DrawRectSolid(player.getX(), 230.0f, 0.5f, 50.0f, 5.0f, player.getColor());

        // Disegna sullo schermo inferiore
        C2D_TargetClear(bottom, clrClear);
        C2D_SceneBegin(bottom);
        // Puoi aggiungere altri elementi da disegnare sullo schermo inferiore qui

        C3D_FrameEnd(0);
    }
}
