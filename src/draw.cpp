#include "engine.hpp"

void Engine::draw() {
    if (top && bottom) {
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        // Disegna sullo schermo superiore
        C2D_TargetClear(top, clrClear);
        C2D_SceneBegin(top);

		/*
        // Walls
        for (int i = 0; i < 3; i++) {
            C2D_DrawRectSolid(walls[i].x, walls[i].y, 0.0f, walls[i].width, walls[i].height, walls[i].color);
        }
		*/

        // Ball
        C2D_DrawCircleSolid(ball.getX(), ball.getY(), 0.5f, ball.getRadius(), ball.getColor());

        // Player bar
        C2D_DrawRectSolid(player.getX(), 230.0f, 0.5f, 50.0f, 5.0f, player.getColor());

        // Disegna sullo schermo inferiore
        C2D_TargetClear(bottom, clrClear);
        C2D_SceneBegin(bottom);
        // Puoi aggiungere altri elementi da disegnare sullo schermo inferiore qui

        C3D_FrameEnd(0);
    }
}
