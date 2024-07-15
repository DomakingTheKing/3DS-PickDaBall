//
// Created by Domakingo on 14/07/2024.
//

#include "engine.hpp"

void Engine::update(){

	// Ball update
    ball.update();
    ball.checkCollision(player);
}

