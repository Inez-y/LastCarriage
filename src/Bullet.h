#ifndef LASTCARRIAGE_BULLET_H
#define LASTCARRIAGE_BULLET_H

#pragma once

#include <SDL3/SDL.h>

class Bullet {
public:
    Bullet();

    void init(float startX, float startY, int direction);
    void update(float deltaTime);
    void render(SDL_Renderer* renderer, const SDL_FRect& camera);

    bool isActive() const;
    void deactivate();

    SDL_FRect getBounds() const;

private:
    SDL_FRect rect;
    float speed;
    int direction;
    bool active;
};
#endif //LASTCARRIAGE_BULLET_H